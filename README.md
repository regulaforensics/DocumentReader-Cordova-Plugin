#  Regula Document Reader (Cordova version)
Regula Document Reader SDK allows you to read various kinds of identification documents, passports, driving licenses, ID cards, etc. All processing is performed completely  _**offline**_  on your device. No any data leaving your device.

You can use native camera to scan the documents or image from gallery for extract all data from it.

We have provided a simple application that demonstrates the  _**API**_  calls you can use to interact with the Document Reader Library.

# Content
* [How to build the demo application](#how-to-build-the-demo-application)
* [How to add the SDK to the project](#how-to-add-the-sdk-to-the-project)
* [Troubleshooting license issues](#troubleshooting-license-issues)
* [Documentation](#documentation)
* [Additional information](#additional-information)

## How to build the demo application
1. Get a trial license for demo application at  [licensing.regulaforensics.com](https://licensing.regulaforensics.com/)  (`regula.license`  file).
2. Download or clone current repository using the command `git clone https://github.com/regulaforensics/DocumentReader-Cordova-Plugin.git`.
3. Run the following commands in Terminal:
```bash
$ cd DocumentReader
$ npm install
$ cordova prepare
```

4. Copy the `regula.license` file to the `DocumentReader/www` folder.
5. Android:
  * Run `cordova run android` inside `DocumentReader` folder - this is just one way to run the app. You can also run it directly from within Android Studio.
6. iOS:
  * Run `cordova run ios` inside `DocumentReader` folder - this is just one way to run the app. You can also run it directly from within Xcode.

## How to add the SDK to the project
Document Reader libraries are available on [npm](https://www.npmjs.com/~regula).
First of all, install **API** library, simply running the following command:
```bash
$ cordova plugin add cordova-plugin-document-reader-api --variable CAMERA_USAGE_DESCRIPTION="To take photo" --variable READ_EXTERNAL_STORAGE="To choose photo"
```

And then add one of the [Core](https://docs.regulaforensics.com/cordova/core) libraries depend on the functionality that you wish and the license capabilities:

* Install **bounds** library edition:
```bash
$ cordova plugin add cordova-plugin-document-reader-core-bounds
```

* Install **mrz** library edition:
```bash
$ cordova plugin add cordova-plugin-document-reader-core-mrz
```

* Install **mrzrfid** library edition:
```bash
$ cordova plugin add cordova-plugin-document-reader-core-mrzrfid
```

* Install **barcode** library edition:
```bash
$ cordova plugin add cordova-plugin-document-reader-core-barcode
```

* Install **barcodemrz** library edition:
```bash
$ cordova plugin add cordova-plugin-document-reader-core-barcodemrz
```

* Install **doctype** library edition:
```bash
$ cordova plugin add cordova-plugin-document-reader-core-doctype
```

* Install **ocrandmrz** library edition:
```bash
$ cordova plugin add cordova-plugin-document-reader-core-ocrandmrz
```

* Install **full** library edition:
```bash
$ cordova plugin add cordova-plugin-document-reader-core-full
```

* Install **fullrfid** library edition:
```bash
$ cordova plugin add cordova-plugin-document-reader-core-fullrfid
```

## Troubleshooting license issues
If you have issues with license verification when running the application, please verify that next is true:
1. The OS, which you use, is specified in the license (e.g., Android and/or iOS).
2. The application (Bundle) ID, which you use, is specified in the license.
3. The license is valid (not expired).
4. The date and time on the device, where you run the application, are valid.
5. You use the latest release version of the Document Reader SDK.
6. You placed the license into the project.

## Documentation
The documentation on the SDK can be found [here](https://docs.regulaforensics.com/cordova).

## Additional information
If you have any technical questions, feel free to [contact](mailto:cordova.support@regulaforensics.com) us or create issue [here](https://github.com/regulaforensics/DocumentReader-Cordova-Plugin/issues).

To use our SDK in your own app you need to [purchase](https://pipedrivewebforms.com/form/394a3706041290a04fbd0d18e7d7810f1841159) a commercial license.