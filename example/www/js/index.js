var app = {
    initialize: function () {
        document.addEventListener('deviceready', this.onDeviceReady.bind(this), false)
    },

    onDeviceReady: function () {
        this.receivedEvent('deviceready')
        document.getElementById("status").innerHTML = "loading......"
        document.getElementById("status").style.backgroundColor = "grey"
        var http = cordova.plugin.http

        // This way you can import any class declared in DocumentReaderPlugin
        var DocumentReader = DocumentReaderPlugin.DocumentReader
        var DocumentReaderResults = DocumentReaderPlugin.DocumentReaderResults
        var DocumentReaderScenario = DocumentReaderPlugin.DocumentReaderScenario
        var DocumentReaderCompletion = DocumentReaderPlugin.DocumentReaderCompletion
        var Enum = DocumentReaderPlugin.Enum

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
        document.getElementById("cancelButton").addEventListener("click", stopRfid)

        function postInitialize(scenarios, canRfid) {
            for (var index in scenarios) {
                var input = document.createElement("input")
                input.type = "radio"
                input.name = "scenario"
                input.value = DocumentReaderScenario.fromJson(typeof scenarios[index] === "string" ? JSON.parse(scenarios[index]) : scenarios[index]).name
                if (index == 0)
                    input.checked = true
                input.onclick = function () { DocumentReader.setConfig({ processParams: { scenario: this.value } }, function (m) { }, function (e) { }) }
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
            DocumentReader.showScanner(function (m) {
                handleCompletion(DocumentReaderCompletion.fromJson(JSON.parse(m)))
            }, function (e) { })
        }

        function recognizeAndroid() {
            var permissions = cordova.plugins.permissions
            permissions.checkPermission(permissions.READ_EXTERNAL_STORAGE, function (status) {
                if (status.hasPermission)
                    recognize()
                else {
                    permissions.requestPermission(permissions.READ_EXTERNAL_STORAGE, function success(status) {
                        if (status.hasPermission)
                            recognize()
                    }, function error() {
                        console.warn('READ_EXTERNAL_STORAGE permission denied')
                    })
                }
            })
        }

        function stopRfid() {
            hideRfidUI()
            DocumentReader.stopRFIDReader(function (e) { }, function (e) { })
        }

        function recognize() {
            window.imagePicker.getPictures(function (images) {
                document.getElementById("status").innerHTML = "processing image......"
                document.getElementById("status").style.backgroundColor = "grey"
                DocumentReader.recognizeImages(images, function (m) { handleCompletion(DocumentReaderCompletion.fromJson(JSON.parse(m))) }, function (e) { })
            }, function (e) { }, { maximumImagesCount: 10, outputType: window.imagePicker.OutputType.BASE64_STRING })
        }

        function handleCompletion(completion) {
            if (isReadingRfidCustomUi && (completion.action === Enum.DocReaderAction.CANCEL || completion.action === Enum.DocReaderAction.ERROR))
                hideRfidUI()
            if (isReadingRfidCustomUi && completion.action === Enum.DocReaderAction.NOTIFICATION)
                updateRfidUI(completion.results.documentReaderNotification)
            if (completion.action === Enum.DocReaderAction.COMPLETE)
                if (isReadingRfidCustomUi)
                    if (completion.results.rfidResult !== 1)
                        restartRfidUI()
                    else {
                        hideRfidUI()
                        displayResults(completion.results)
                    }
                else
                    handleResults(completion.results)
            if (completion.action === Enum.DocReaderAction.TIMEOUT)
                handleResults(completion.results)
        }

        function showRfidUI() {
            // show animation
            isReadingRfidCustomUi = true
            document.getElementById("rfidUI").style.display = isReadingRfidCustomUi ? "" : "none"
            document.getElementById("mainUI").style.display = !isReadingRfidCustomUi ? "" : "none"
        }

        function hideRfidUI() {
            // show animation
            restartRfidUI()
            isReadingRfidCustomUi = false
            document.getElementById("rfidUI").style.display = isReadingRfidCustomUi ? "" : "none"
            document.getElementById("mainUI").style.display = !isReadingRfidCustomUi ? "" : "none"
            rfidUIHeader = "Reading RFID"
            document.getElementById("rfidUIHeader").innerHTML = rfidUIHeader
            rfidUIHeaderColor = "black"
            document.getElementById("rfidUIHeader").style.color = rfidUIHeaderColor
        }

        function restartRfidUI() {
            rfidUIHeaderColor = "red"
            document.getElementById("rfidUIHeader").style.color = rfidUIHeaderColor
            rfidUIHeader = "Failed!"
            document.getElementById("rfidUIHeader").innerHTML = rfidUIHeader
            rfidDescription = "Place your phone on top of the NFC tag"
            document.getElementById("rfidDescription").innerHTML = rfidDescription
            rfidProgress = -1
            document.getElementById("rfidProgress").value = rfidProgress
        }

        function updateRfidUI(results) {
            if (results.value == null) return
            if (results.code === Enum.eRFID_NotificationCodes.RFID_NOTIFICATION_PCSC_READING_DATAGROUP) {
                rfidDescription = Enum.eRFID_DataFile_Type.getTranslation(results.dataFileType)
                document.getElementById("rfidDescription").innerHTML = rfidDescription
            }
            rfidUIHeader = "Reading RFID"
            document.getElementById("rfidUIHeader").innerHTML = rfidUIHeader
            rfidUIHeaderColor = "black"
            document.getElementById("rfidUIHeader").style.color = rfidUIHeaderColor
            rfidProgress = results.value
            document.getElementById("rfidProgress").value = rfidProgress
            if (window.cordova.platformId === 'ios')
                DocumentReader.setRfidSessionStatus(rfidDescription + "\n" + results.value + "%", function (e) { }, function (e) { })
        }

        function customRFID() {
            showRfidUI()
            DocumentReader.readRFID(function (m) { handleRfidCompletion(m) }, function (e) { })
        }

        function usualRFID() {
            isReadingRfid = true
            DocumentReader.startRFIDReader(function (m) { handleRfidCompletion(m) }, function (e) { })
        }

        function handleRfidCompletion(raw) {
            var notification = "rfidNotificationCompletionEvent"
            var paCert = "paCertificateCompletionEvent"
            var taCert = "taCertificateCompletionEvent"
            var taSig = "taSignatureCompletionEvent"
            if (raw.substring(0, notification.length) === notification) {
                raw = raw.substring(notification.length, raw.length)
                console.log(notification + ": " + raw)
            } else if (raw.substring(0, paCert.length) === paCert) {
                raw = raw.substring(paCert.length, raw.length)
                console.log(paCert + ": " + raw)
            } else if (raw.substring(0, taCert.length) === taCert) {
                raw = raw.substring(taCert.length, raw.length)
                console.log(taCert + ": " + raw)
            } else if (raw.substring(0, taSig.length) === taSig) {
                raw = raw.substring(taSig.length, raw.length)
                console.log(taSig + ": " + raw)
            } else
                handleCompletion(DocumentReaderCompletion.fromJson(JSON.parse(raw)))
        }

        function handleResults(results) {
            clearResults()
            if (doRfid && !isReadingRfid && results != null && results.chipPage != 0) {
                //customRFID()
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
                this.setState({ fullName: value })
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

        function addCertificates() {
            window.resolveLocalFileSystemURL(cordova.file.applicationDirectory + "www/certificates/", function (fileSystem) {
                fileSystem.createReader().readEntries(function (entries) {
                    for (var i in entries) {
                        var item = entries[i]
                        if (item.isFile) {
                            var findExt = item.name.split('.')
                            var pkdResourceType = 0
                            if (findExt.length > 0)
                                pkdResourceType = Enum.PKDResourceType.getType(findExt[findExt.length - 1].toLowerCase())
                            readFile("www/certificates/" + item.name, function (file, resType) {
                                resType = resType[0]
                                var certificates = []
                                certificates.push({
                                    'binaryData': file,
                                    'resourceType': resType
                                })
                                DocumentReader.addPKDCertificates(certificates, function (s) {
                                    console.log("certificate added")
                                }, function (e) { console.log(e) })
                            }, pkdResourceType)
                        }
                    }
                }, function (err) { console.log(err) })
            }, function (err) { console.log(err) })
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
            DocumentReader.prepareDatabase("Full", function (message) {
                if (message != "database prepared")
                    document.getElementById("status").innerHTML = "Downloading database: " + message + "%"
                else {
                    document.getElementById("status").innerHTML = "Loading......"
                    DocumentReader.initializeReader({
                        license: license,
                        delayedNNLoad: true
                    }, function (message) {
                        document.getElementById("status").innerHTML = "Ready"
                        document.getElementById("status").style.backgroundColor = "green"
                        document.getElementById("showScannerButton").addEventListener("click", scan)
                        if (window.cordova.platformId == "android")
                            document.getElementById("showImagePicker").addEventListener("click", recognizeAndroid)
                        if (window.cordova.platformId == "ios")
                            document.getElementById("showImagePicker").addEventListener("click", recognize)
                        DocumentReader.setConfig({
                            functionality: {
                                videoCaptureMotionControl: true,
                                showCaptureButton: true
                            },
                            customization: {
                                showResultStatusMessages: true,
                                showStatusMessages: true
                            },
                            processParams: {
                                scenario: "Mrz",
                                doRfid: false,
                            },
                        }, function (m) { }, function (e) { })
                        DocumentReader.getAvailableScenarios(function (s) {
                            DocumentReader.isRFIDAvailableForUse(function (r) { postInitialize(JSON.parse(s), r) }, function (e) { })
                        }, function (e) { })
                        DocumentReader.setRfidDelegate(Enum.RFIDDelegate.NO_PA, function (r) { }, function (e) { })
                        // addCertificates()
                    }, function (error) {
                        console.log(error)
                        document.getElementById("status").innerHTML = error
                        document.getElementById("status").style.backgroundColor = "red"
                    })
                }
            }, function (e) { console.log(e) })
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