// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "@regulaforensics/cordova-plugin-document-reader-api",
    platforms: [.iOS(.v16)],
    products: [
        .library(
            name: "@regulaforensics/cordova-plugin-document-reader-api",
            targets: ["DocumentReaderCordovaPlugin"]
        )
    ],
    dependencies: [
        .package(url: "https://github.com/apache/cordova-ios.git", branch: "master"),
        .package(
            url: "https://github.com/regulaforensics/DocumentReader-Swift-Package",
            exact: "9.10.7343"
        )
    ],
    targets: [
        .target(
            name: "DocumentReaderCordovaPlugin",
            dependencies: [
                .product(name: "Cordova", package: "cordova-ios"),
                .product(name: "DocumentReader", package: "DocumentReader-Swift-Package")
            ],
            path: "src/ios"
        )
    ]
)
