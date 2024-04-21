var app = {
    initialize: function () {
        document.addEventListener('deviceready', this.onDeviceReady.bind(this), false)
    },

    onDeviceReady: function () {
        function onInitialized() {
            document.getElementById("status").innerHTML = "Ready"
            document.getElementById("status").style.backgroundColor = "green"
            
            var functionality = new Functionality()
            functionality.showCaptureButton = true
            DocumentReader.setFunctionality(functionality, function (s) { }, function (e) { })
        }

        this.receivedEvent('deviceready')
        document.getElementById("status").innerHTML = "loading......"
        document.getElementById("status").style.backgroundColor = "grey"
        var http = cordova.plugin.http

        // This way you can import any class declared in DocumentReaderPlugin
        var DocumentReader = DocumentReaderPlugin.DocumentReader
        var DocumentReaderResults = DocumentReaderPlugin.DocumentReaderResults
        var DocumentReaderNotification = DocumentReaderPlugin.DocumentReaderNotification
        var DocumentReaderScenario = DocumentReaderPlugin.DocumentReaderScenario
        var DocumentReaderCompletion = DocumentReaderPlugin.DocumentReaderCompletion
        var ScannerConfig = DocumentReaderPlugin.ScannerConfig
        var RecognizeConfig = DocumentReaderPlugin.RecognizeConfig
        var DocReaderConfig = DocumentReaderPlugin.DocReaderConfig
        var Functionality = DocumentReaderPlugin.Functionality
        var Enum = DocumentReaderPlugin.Enum

        var selectedScenario = "Mrz"
        var doRfid = false
        var encryption = false
        const ENCRYPTED_RESULT_SERVICE = "https://api.regulaforensics.com/api/process"
        var isReadingRfidCustomUi = false
        var isReadingRfid = false
        var rfidUIHeader = "Reading RFID"
        var rfidUIHeaderColor = "black"
        var rfidDescription = "Place your phone on top of the NFC tag"
        var rfidProgress = -1
        document.getElementById("rfidUI").style.display = isReadingRfidCustomUi ? "" : "none"
        document.getElementById("mainUI").style.display = !isReadingRfidCustomUi ? "" : "none"
        document.getElementById("rfidUIHeader").innerHTML = rfidUIHeader
        document.getElementById("rfidUIHeader").style.color = rfidUIHeaderColor
        document.getElementById("rfidDescription").innerHTML = rfidDescription
        document.getElementById("rfidProgress").value = rfidProgress
        document.getElementById("cancelButton").addEventListener("click", hideRfidUI)

        function postInitialize(scenarios, canRfid) {
            for (var index in scenarios) {
                var input = document.createElement("input")
                input.type = "radio"
                input.name = "scenario"
                input.value = DocumentReaderScenario.fromJson(typeof scenarios[index] === "string" ? JSON.parse(scenarios[index]) : scenarios[index]).name
                if (index == 0)
                    input.checked = true
                input.onclick = function () { selectedScenario = this.value }
                input.style.display = "inline-block"
                document.getElementById("scenariosRadioGroup").appendChild(input)
                var label = document.createElement("span")
                label.innerHTML = DocumentReaderScenario.fromJson(typeof scenarios[index] === "string" ? JSON.parse(scenarios[index]) : scenarios[index]).name
                label.style.display = "inline-block"
                label.style.width = "200px"
                label.radioButton = input
                label.onclick = function () { this.radioButton.click() }
                document.getElementById("scenariosRadioGroup").appendChild(label)
                document.getElementById("scenariosRadioGroup").appendChild(document.createElement("br"))
            }
            if (canRfid) {
                document.getElementById("rfidCheckbox").disabled = false
                document.getElementById("rfidCheckboxText").style.color = "black"
                document.getElementById("rfidCheckboxText").innerHTML = " Process rfid reading"
                document.getElementById("rfidCheckboxText").onclick = function () { document.getElementById("rfidCheckbox").click() }
                document.getElementById("rfidCheckbox").onchange = function () { doRfid = this.checked }
            }
            document.getElementById("encryptionCheckbox").disabled = false
            document.getElementById("encryptionCheckboxText").style.color = "black"
            document.getElementById("encryptionCheckboxText").innerHTML = " Data encryption"
            document.getElementById("encryptionCheckboxText").onclick = function () { document.getElementById("encryptionCheckbox").click() }
            document.getElementById("encryptionCheckbox").onchange = function () { encryption = this.checked }
        }

        function scan() {
            var config = new ScannerConfig()
            config.scenario = selectedScenario
            DocumentReader.scan(config, function (m) {
                handleCompletion(DocumentReaderCompletion.fromJson(JSON.parse(m)))
            }, function (e) { })
        }

        function recognize() {
            navigator.camera.getPicture(function (result) {
                document.getElementById("status").innerHTML = "processing image......"
                document.getElementById("status").style.backgroundColor = "grey"
                var config = new RecognizeConfig()
                config.scenario = selectedScenario
                config.image = result
                DocumentReader.recognize(config, function (m) {
                    handleCompletion(DocumentReaderCompletion.fromJson(JSON.parse(m)))
                }, function (e) { })
            }, function (e) { }, {
                destinationType: Camera.DestinationType.DATA_URL,
                sourceType: Camera.PictureSourceType.PHOTOLIBRARY,
                mediaType: Camera.MediaType.PICTURE
            })
        }

        function handleCompletion(completion) {
            if (isReadingRfidCustomUi) {
                if (completion.action == Enum.DocReaderAction.ERROR) restartRfidUI()
                if (actionSuccess(completion.action) || actionError(completion.action)) {
                    hideRfidUI()
                    displayResults(completion.results)
                }
            } else if (actionSuccess(completion.action) || actionError(completion.action))
                handleResults(completion.results)
        }

        function actionSuccess(action) {
            if (action == Enum.DocReaderAction.COMPLETE || action == Enum.DocReaderAction.TIMEOUT) return true
            return false
        }

        function actionError(action) {
            if (action == Enum.DocReaderAction.CANCEL || action == Enum.DocReaderAction.ERROR) return true
            return false
        }

        function showRfidUI() {
            // show animation
            isReadingRfidCustomUi = true
            document.getElementById("rfidUI").style.display = isReadingRfidCustomUi ? "" : "none"
            document.getElementById("mainUI").style.display = !isReadingRfidCustomUi ? "" : "none"
        }

        function hideRfidUI() {
            // show animation
            DocumentReader.stopRFIDReader(function (s) { }, function (e) { });
            restartRfidUI()
            isReadingRfidCustomUi = false
            document.getElementById("rfidUI").style.display = isReadingRfidCustomUi ? "" : "none"
            document.getElementById("mainUI").style.display = !isReadingRfidCustomUi ? "" : "none"
            document.getElementById("rfidUIHeader").innerHTML = "Reading RFID"
            document.getElementById("rfidUIHeader").style.color = "black"
        }

        function restartRfidUI() {
            document.getElementById("rfidUIHeader").style.color = "red"
            document.getElementById("rfidUIHeader").innerHTML = "Failed!"
            document.getElementById("rfidDescription").innerHTML = "Place your phone on top of the NFC tag"
            document.getElementById("rfidProgress").value = -1
        }

        function updateRfidUI(notification) {
            if (notification.notificationCode === Enum.eRFID_NotificationCodes.RFID_NOTIFICATION_PCSC_READING_DATAGROUP) {
                rfidDescription = "ERFIDDataFileType: " + notification.dataFileType
                document.getElementById("rfidDescription").innerHTML = rfidDescription
            }
            document.getElementById("rfidUIHeader").innerHTML = "Reading RFID"
            document.getElementById("rfidUIHeader").style.color = "black"
            if (notification.progress != null)
                document.getElementById("rfidProgress").value = notification.progress
        }

        function customRFID() {
            showRfidUI()
            DocumentReader.readRFID(false, false, false, function (m) { handleRfidCompletion(m) }, function (e) { })
        }

        function usualRFID() {
            isReadingRfid = true
            DocumentReader.startRFIDReader(false, false, false, function (m) { handleRfidCompletion(m) }, function (e) { })
        }

        function handleRfidCompletion(raw) {
            var id = "rfidOnProgressCompletion"
            if (raw.substring(0, id.length) === id) {
                raw = raw.substring(id.length, raw.length)
                updateRfidUI(DocumentReaderNotification.fromJson(JSON.parse(raw)))
            } else
                handleCompletion(DocumentReaderCompletion.fromJson(JSON.parse(raw)))
        }

        function handleResults(results) {
            clearResults()
            if (doRfid && !isReadingRfid && results != null && results.chipPage != 0) {
                // customRFID()
                usualRFID()
            } else {
                isReadingRfid = false
                if (encryption) {
                    var input = JSON.parse(results.rawResult)
                    var processParam = {
                        alreadyCropped: true,
                        scenario: "FullProcess"
                    }
                    var body = {
                        List: input["ContainerList"]["List"],
                        processParam: processParam
                    }
                    postRequest(body)
                } else
                    displayResults(results)
            }
        }

        function postRequest(body) {
            document.getElementById("status").innerHTML = "Getting results from server......"
            document.getElementById("status").style.backgroundColor = "grey"
            http.setDataSerializer('utf8')
            http.post(ENCRYPTED_RESULT_SERVICE, JSON.stringify(body), { "content-type": "application/json; utf-8" }, function (response) {
                DocumentReader.parseCoreResults(response.data, function (m) {
                    displayResults(DocumentReaderResults.fromJson(JSON.parse(m)))
                }, function (e) { })
            }, function (response) {
                console.error(response.error)
                document.getElementById("status").innerHTML = "Something went wrong!"
                document.getElementById("status").style.backgroundColor = "red"
            })
        }

        function displayResults(results) {
            if (results == null) return

            DocumentReader.textFieldValueByType(results, Enum.eVisualFieldType.FT_SURNAME_AND_GIVEN_NAMES, function (value) {
                document.getElementById("status").style.backgroundColor = "green"
                document.getElementById("status").innerHTML = value
            }, function (error) { console.log(error) })

            DocumentReader.graphicFieldImageByType(results, Enum.eGraphicFieldType.GF_DOCUMENT_IMAGE, function (value) {
                if (value != null)
                    document.getElementById("documentImage").src = "data:image/png;base64," + value
            }, function (error) { console.log(error) })

            DocumentReader.graphicFieldImageByType(results, Enum.eGraphicFieldType.GF_PORTRAIT, function (value) {
                if (value != null)
                    document.getElementById("portraitImage").src = "data:image/png;base64," + value
            }, function (error) { console.log(error) })
        }

        function clearResults() {
            document.getElementById("status").innerHTML = "Ready"
            document.getElementById("documentImage").src = "img/id.png"
            document.getElementById("portraitImage").src = "img/portrait.png"
        }

        function readFile(path, callback, ...items) {
            if (path.substring(0, 8) !== "file:///")
                path = cordova.file.applicationDirectory + path
            window.resolveLocalFileSystemURL(path, function (fileEntry) {
                fileEntry.file(function (file) {
                    var reader = new FileReader()
                    reader.onloadend = function (e) {
                        callback(this.result.substring(this.result.indexOf(',') + 1), items)
                    }
                    reader.readAsDataURL(file)
                })
            }, function (e) { console.log(JSON.stringify(e)) })
        }

        readFile("www/regula.license", function (license) {
            var config = new DocReaderConfig()
            config.license = license
            config.delayedNNLoad = true
            DocumentReader.initializeReader(config, function (message) {
                callback = JSON.parse(message)
                if (!callback.success) {
                    console.log("Init error: " + callback.error.message)
                    document.getElementById("status").innerHTML = "Init error: " + callback.error.message
                    return
                }
                console.log("Init complete")
                document.getElementById("showScannerButton").addEventListener("click", scan)
                document.getElementById("showImagePicker").addEventListener("click", recognize)
                DocumentReader.getAvailableScenarios(function (s) {
                    DocumentReader.getIsRFIDAvailableForUse(function (r) { postInitialize(JSON.parse(s), r) }, function (e) { })
                }, function (e) { })
                onInitialized()
            }, function (error) {
                console.log(error)
                document.getElementById("status").innerHTML = error
                document.getElementById("status").style.backgroundColor = "red"
            })
        })
    },

    receivedEvent: function (id) {
        var parentElement = document.getElementById(id)
        var listeningElement = parentElement.querySelector('.listening')
        var receivedElement = parentElement.querySelector('.received')
        listeningElement.setAttribute('style', 'display:none;')
        receivedElement.setAttribute('style', 'display:block;')
        console.log('Received Event: ' + id)
    },
}

app.initialize()
