#import "RGLProcessParams.h"
#import "RGLDocReaderRFIDDelegate.h"
#import "RGLRFIDNotify.h"

@import UIKit;

@class RGLDocReaderVersion, RGLScenario,
RGLDocumentReaderResults, RGLFunctionality,
RGLCustomization, RGLInitializationResponse,
RGLDocumentReaderCameraViewController, RGLLicense, RGLPKDCertificate, RGLRFIDNotify, RGLRFIDScenario;

typedef NS_ENUM(NSInteger, RGLDocReaderAction) {
  RGLDocReaderActionComplete = 0,
  RGLDocReaderActionProcess = 1,
  RGLDocReaderActionMorePagesAvailable = 2,
  RGLDocReaderActionCancel = 3,
  RGLDocReaderActionError = 4,
} NS_SWIFT_NAME(DocReaderAction);

typedef NS_ENUM(NSInteger, RGLCommand) {
    RGLCommandUnknown = 0,
    RGLCommandRfidSendData = 100,
    RGLCommandRfidNotify = 101,
    RGLCommandRfidGetDataForScenario = 102,
    RGLCommandTorchGetUVFoto = 200,
    RGLCommandCommandInternetSend = 300
} NS_SWIFT_NAME(Command);

typedef NS_ENUM(NSInteger, RGLRFIDNotificationAction) {
  RGLRFIDNotificationActionConnecting = 0,
  RGLRFIDNotificationActionSearchingTag = 1,
  RGLRFIDNotificationActionStartReading = 2,
  RGLRFIDNotificationActionNotification = 3
} NS_SWIFT_NAME(RFIDNotificationAction);

typedef NS_ENUM(NSInteger, RGLRFIDCompleteAction) {
  RGLRFIDCompleteActionComplete = 0,
  RGLRFIDCompleteActionError = 1,
  RGLRFIDCompleteActionCancel = 2,
  RGLRFIDCompleteActionSessionRestarted = 3
} NS_SWIFT_NAME(RFIDCompleteAction);

typedef void (^RGLDocumentReaderInitializationCompletion)(BOOL success,
                                                          NSString * _Nullable error) NS_SWIFT_NAME(DocumentReaderInitializationCompletion);
typedef void (^RGLDocumentReaderPrepareCompletion)(BOOL success, NSString * _Nullable error) NS_SWIFT_NAME(DocumentReaderPrepareCompletion);
typedef void (^RGLDocumentReaderCompletion)(RGLDocReaderAction action,
                                            RGLDocumentReaderResults * _Nullable results,
                                            NSString * _Nullable error) NS_SWIFT_NAME(DocumentReaderCompletion);
typedef void (^RGLCallbackCompletionBlock)(NSInteger command, NSData * _Nonnull data, NSString * _Nonnull string) NS_SWIFT_NAME(CallbackCompletionBlock);
typedef void (^RGLRFIDCallbackCompletionBlock)(RGLCommand command, NSData * _Nonnull data, NSString * _Nonnull json, RGLCallbackCompletionBlock _Nonnull completionBlock) NS_SWIFT_NAME(RFIDCallbackCompletionBlock);
typedef void (^RGLRFIDProcessCompletion)(RGLRFIDCompleteAction action,
                                         RGLDocumentReaderResults * _Nullable results,
                                         NSString * _Nullable error, RGLRFIDErrorCodes errorCode) NS_SWIFT_NAME(RFIDProcessCompletion);
typedef void (^RGLRFIDNotificationCallback)(RGLRFIDNotificationAction notificationAction, RGLRFIDNotify* _Nullable notification) NS_SWIFT_NAME(RFIDNotificationCallback);

NS_SWIFT_NAME(DocReader)
@interface RGLDocReader : NSObject

- (instancetype _Nonnull)init NS_UNAVAILABLE;

@property(readonly, class, nonatomic, strong, nonnull) RGLDocReader *shared;

@property(nonatomic, strong, nonnull) RGLProcessParams *processParams;
@property(nonatomic, strong, readonly, nullable) RGLDocReaderVersion *version;
@property(nonatomic, strong, readonly, nonnull) NSArray<RGLScenario *> *availableScenarios;
@property(nonatomic, assign, readonly, getter=isDocumentReaderIsReady) BOOL documentReaderIsReady;
@property(nonatomic, assign, readonly, getter=isRFIDAvailableForUse) BOOL rfidAvailable;
@property(nonatomic, assign, readonly, getter=isAuthenticatorAvailableForUse) BOOL useAuthenticatorAvailable;
@property(nonatomic, assign, readwrite, getter=isCameraSessionIsPaused) BOOL cameraSessionIsPaused;
@property(nonatomic, strong, readonly, nonnull) NSString *documentReaderStatus;
@property(nonatomic, strong, nullable) NSString *rfidSessionStatus;
@property(nonatomic, nonnull) dispatch_queue_t scanPhotoQueue;
@property(nonatomic, strong, nullable) RGLLicense *license;
@property(nonatomic, weak, nullable) id <RGLDocReaderRFIDDelegate> rfidDelegate;

@property(nonatomic, strong, nonnull) RGLFunctionality *functionality;
@property(nonatomic, strong, nonnull) RGLCustomization *customization;
@property(nonatomic, strong, nonnull) RGLRFIDScenario *rfidScenario;

@property(nonatomic, strong) _Nullable Class localizationClassName;

- (void)initializeReader:(nonnull NSData *)license
              completion:(RGLDocumentReaderInitializationCompletion _Nonnull)completion NS_SWIFT_NAME(initializeReader(license:completion:));
- (void)initializeReader:(nonnull NSData *)license
            databasePath:(nonnull NSString *)databasePath
              completion:(RGLDocumentReaderInitializationCompletion _Nonnull)completion NS_SWIFT_NAME(initializeReader(license:databasePath:completion:));
- (void)prepareDatabase:(nonnull NSString *)databaseID
        progressHandler:(void (^_Nullable)(NSProgress * _Nonnull progress))progress
             completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion NS_SWIFT_NAME(prepareDatabase(databaseID:progressHandler:completion:));
- (void)prepareDatabase:(nonnull NSString *)databaseID
             completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion NS_SWIFT_NAME(prepareDatabase(databaseID:completion:));
- (void)runAutoUpdate:(nonnull NSString *)databaseID
      progressHandler:(void (^_Nullable)(NSProgress * _Nonnull progress))progress
           completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion NS_SWIFT_NAME(runAutoUpdate(databaseID:progressHandler:completion:));
- (void)runAutoUpdate:(nonnull NSString *)databaseID
           completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion NS_SWIFT_NAME(runAutoUpdate(databaseID:completion:));
- (UIViewController * _Nullable)prepareCameraViewController:(RGLDocumentReaderCameraViewController *_Nullable)controller cameraHandler:(RGLDocumentReaderCompletion _Nonnull)completion NS_SWIFT_NAME(prepareCameraViewController(cameraViewController:cameraHandler:));
- (UIViewController * _Nullable)prepareCameraViewController:(RGLDocumentReaderCompletion _Nonnull)completion NS_SWIFT_NAME(prepareCameraViewController(cameraHandler:));
- (void)removeDatabase:(RGLDocumentReaderPrepareCompletion _Nullable)completion NS_SWIFT_NAME(removeDatabase(completion:));
- (void)cancelDBUpdate;

- (void)startNewPage;
- (void)startNewSession;
- (void)recognizeImage:(UIImage * _Nonnull)image
            completion:(RGLDocumentReaderCompletion _Nonnull)completion;
- (void)recognizeImage:(UIImage * _Nonnull)image
            cameraMode:(BOOL)cameraMode
            completion:(RGLDocumentReaderCompletion _Nonnull)completion;
- (void)recognizeImages:(NSArray<UIImage *> *_Nonnull)images completion:(RGLDocumentReaderCompletion _Nonnull)completion;
- (void)showScanner:(UIViewController * _Nonnull)presenter
         completion:(RGLDocumentReaderCompletion _Nonnull)completion;
- (void)startRFIDReaderFromPresenter:(UIViewController * _Nonnull)presenter
                          completion:(RGLDocumentReaderCompletion _Nonnull)completion;
- (void)readRFID:(RGLRFIDNotificationCallback _Nullable)notificationCallback
      completion:(RGLRFIDProcessCompletion _Nonnull)completion;
- (void)stopScanner:(void(^_Nullable)(void))completion;
- (void)stopRFIDReader:(void(^_Nullable)(void))completion;
- (void)addPKDCertificates:(NSArray <RGLPKDCertificate *> * _Nonnull)certificates NS_SWIFT_NAME(addPKDCertificates(certificates:));
- (void)clearPKDCertificates;

- (RGLScenario * _Nullable)selectedScenario;

- (void)deinitializeReader;

@end
