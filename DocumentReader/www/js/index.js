var app = {
    // Application Constructor
    initialize: function () {
        document.addEventListener('deviceready', this.onDeviceReady.bind(this), false);
    },

    onDeviceReady: function () {
        this.receivedEvent('deviceready');
        document.getElementById("status").innerHTML = "loading......";
        document.getElementById("status").style.backgroundColor = "grey";

        var DocumentReaderResults = DocumentReader.DocumentReaderResults;
        var Scenario = DocumentReader.Scenario;
        var doRfid = false;

        function postInitialize(scenarios, canRfid) {
            for (var index in scenarios) {
                var input = document.createElement("input");
                input.type = "radio";
                input.name = "scenario";
                input.value = Scenario.fromJson(typeof scenarios[index] === "string" ? JSON.parse(scenarios[index]) : scenarios[index]).name;
                if (index == 0) {
                    input.checked = true;
                }
                input.onclick = function () { DocumentReader.setConfig({ processParams: { scenario: this.value } }, function (m) { }, function (e) { console.log(error) }) }
                input.style.display = "inline-block";
                document.getElementById("scenariosRadioGroup").appendChild(input);
                var label = document.createElement("span");
                label.innerHTML = Scenario.fromJson(typeof scenarios[index] === "string" ? JSON.parse(scenarios[index]) : scenarios[index]).name;
                label.style.display = "inline-block";
                label.style.width = "200px";
                label.radioButton = input;
                label.onclick = function () { this.radioButton.click() }
                document.getElementById("scenariosRadioGroup").appendChild(label);
                document.getElementById("scenariosRadioGroup").appendChild(document.createElement("br"));
            }
            if (canRfid) {
                document.getElementById("rfidCheckbox").disabled = false;
                document.getElementById("rfidCheckboxText").style.color = "black";
                document.getElementById("rfidCheckboxText").innerHTML = "Process rfid reading";
                document.getElementById("rfidCheckboxText").onclick = function () { document.getElementById("rfidCheckbox").click() }
                document.getElementById("rfidCheckbox").onchange = function () { doRfid = this.checked }
            }
        }

        function scan() {
            DocumentReader.showScanner(
                function (message) { handleResults(message) },
                function (error) { console.log(error) });
        }

        function recognizeAndroid() {
            DocumentReader.permissionRead(function (m) {
                window.imagePicker.getPictures(
                    function (results) {
                        if (results.length > 0) {
                            clearResults();
                            document.getElementById("status").innerHTML = "copying image......";
                            document.getElementById("status").style.backgroundColor = "grey";
                        }
                        window.resolveLocalFileSystemURL(
                            results[0],
                            function gotFile(fileEntry) {
                                fileEntry.file(function (file) {
                                    var reader = new FileReader();
                                    reader.onloadend = function (e) {
                                        var base64 = this.result.substring(23);
                                        document.getElementById("status").innerHTML = "processing image......";
                                        document.getElementById("status").style.backgroundColor = "grey";
                                        DocumentReader.recognizeImage(
                                            base64,
                                            function (message) { handleResults(message) },
                                            function (error) { console.log(error) });
                                    };
                                    reader.readAsDataURL(file);
                                });
                            },
                            function fail(e) { console.log('Cannot found requested file'); });
                    }, function (e) { console.log(error) }, { maximumImagesCount: 1 });
            }, function (err) {
                if (err == "no permission")
                    recognizeAndroid();
            });
        }

        function recognizeIOS() {
            window.imagePicker.getPictures(
                function (results) {
                    if (results.length > 0) {
                        clearResults();
                        document.getElementById("status").innerHTML = "copying image......";
                        document.getElementById("status").style.backgroundColor = "grey";
                    }
                    window.resolveLocalFileSystemURL(
                        results[0],
                        function gotFile(fileEntry) {
                            fileEntry.file(function (file) {
                                var reader = new FileReader();
                                reader.onloadend = function (e) {
                                    var base64 = this.result.substring(23);
                                    document.getElementById("status").innerHTML = "processing image......";
                                    document.getElementById("status").style.backgroundColor = "grey";
                                    DocumentReader.recognizeImage(
                                        base64,
                                        function (message) { handleResults(message) },
                                        function (error) { console.log(error) });
                                };
                                reader.readAsDataURL(file);
                            });
                        },
                        function fail(e) { console.log('Cannot found requested file'); });
                }, function (e) { console.log(error) }, { maximumImagesCount: 1 });
        }

        function handleResults(jstring) {
            clearResults();
            var results = DocumentReaderResults.fromJson(JSON.parse(jstring));
            if (doRfid && results != null && results.chipPage != 0) {
                accessKey = null;
                accessKey = results.getTextFieldValueByType(DocumentReader.Enum.eVisualFieldType.FT_MRZ_STRINGS);
                if (accessKey != null && accessKey != "") {
                    accessKey = accessKey.replace(/^/g, '').replace(/\n/g, '');
                    DocumentReader.setRfidScenario({
                        mrz: accessKey,
                        pacePasswordType: DocumentReader.Enum.eRFID_Password_Type.PPT_MRZ,
                    }, function (m) { }, function (e) { console.log(e) });
                } else {
                    accessKey = null;
                    accessKey = results.getTextFieldValueByType(DocumentReader.Enum.eVisualFieldType.FT_CARD_ACCESS_NUMBER);
                    if (accessKey != null && accessKey != "") {
                        DocumentReader.setRfidScenario({
                            password: accessKey,
                            pacePasswordType: DocumentReader.Enum.eRFID_Password_Type.PPT_CAN,
                        }, function (m) { }, function (e) { console.log(e) });
                    }
                }
                DocumentReader.startRFIDReader(
                    function (jstring) { displayResults(DocumentReaderResults.fromJson(JSON.parse(jstring))) },
                    function (e) { console.log(e) });
            } else {
                displayResults(results);
            }
        }

        function displayResults(results) {
            document.getElementById("status").innerHTML = results.getTextFieldValueByType(DocumentReader.Enum.eVisualFieldType.FT_SURNAME_AND_GIVEN_NAMES);
            document.getElementById("status").style.backgroundColor = "green";
            if (results.getGraphicFieldImageByType(DocumentReader.Enum.eGraphicFieldType.GF_DOCUMENT_IMAGE) != null) {
                var base64DocFront = "data:image/png;base64," + results.getGraphicFieldImageByType(DocumentReader.Enum.eGraphicFieldType.GF_DOCUMENT_IMAGE);
                document.getElementById("documentImage").src = base64DocFront;
            }
            if (results.getGraphicFieldImageByType(DocumentReader.Enum.eGraphicFieldType.GF_PORTRAIT) != null) {
                var base64Portrait = "data:image/png;base64," + results.getGraphicFieldImageByType(DocumentReader.Enum.eGraphicFieldType.GF_PORTRAIT);
                document.getElementById("portraitImage").src = base64Portrait;
            }
        }

        function clearResults() {
            document.getElementById("status").innerHTML = "Ready";
            document.getElementById("documentImage").src = "img/id.png";
            document.getElementById("portraitImage").src = "img/portrait.png";
        }

        window.resolveLocalFileSystemURL(
            cordova.file.applicationDirectory + "www/regula.license",
            function (fileEntry) {
                fileEntry.file(function (file) {
                    var reader = new FileReader();
                    reader.onloadend = function (e) {
                        var license = this.result;
                        DocumentReader.prepareDatabase(
                            "Full",
                            function (message) {
                                if (message.substring(0, 11) == "Downloading") {
                                    console.log(message);
                                    document.getElementById("status").innerHTML = message;
                                } else {
                                    console.log(message);
                                    document.getElementById("status").innerHTML = "Loading......";
                                    DocumentReader.initializeReader(
                                        license,
                                        function (message) {
                                            console.log(message);
                                            document.getElementById("status").innerHTML = "Ready";
                                            document.getElementById("status").style.backgroundColor = "green";
                                            document.getElementById("showScannerButton").addEventListener("click", scan);
                                            if (window.cordova.platformId == "android") {
                                                document.getElementById("showImagePicker").addEventListener("click", recognizeAndroid);
                                            }
                                            if (window.cordova.platformId == "ios") {
                                                document.getElementById("showImagePicker").addEventListener("click", recognizeIOS);
                                            }
                                            DocumentReader.setConfig({
                                                functionality: {
                                                    videoCaptureMotionControl: true,
                                                    showCaptureButton: true
                                                }, customization: {
                                                    showResultStatusMessages: true,
                                                    showStatusMessages: true
                                                }, processParams: {
                                                    scenario: "Mrz",
                                                    doRfid: false,
                                                },
                                            }, function (m) { }, function (e) { console.log(e); });
                                            DocumentReader.getAvailableScenarios(
                                                function (scenariosJSONString) {
                                                    var scenarios = JSON.parse(scenariosJSONString);
                                                    DocumentReader.getCanRFID(
                                                        function (canRfid) { postInitialize(scenarios, canRfid) },
                                                        function (error) { console.log(error) });
                                                },
                                                function (error) { console.log(error) });
                                        },
                                        function (error) {
                                            console.log(error);
                                            document.getElementById("status").innerHTML = error;
                                            document.getElementById("status").style.backgroundColor = "red";
                                        });
                                }
                            },
                            function (error) {
                                console.log(error);
                                document.getElementById("status").innerHTML = "Error preparing dabatase";
                                document.getElementById("status").style.backgroundColor = "red";
                            });
                    }
                    reader.readAsArrayBuffer(file);
                });
            },
            function (e) {
                console.log("FileSystem Error");
                console.dir(e);
                document.getElementById("status").innerHTML = "Error reading license";
                document.getElementById("status").style.backgroundColor = "red";
            });
    },

    // Update DOM on a Received Event
    receivedEvent: function (id) {
        var parentElement = document.getElementById(id);
        var listeningElement = parentElement.querySelector('.listening');
        var receivedElement = parentElement.querySelector('.received');

        listeningElement.setAttribute('style', 'display:none;');
        receivedElement.setAttribute('style', 'display:block;');

        console.log('Received Event: ' + id);
    },
};

app.initialize();
