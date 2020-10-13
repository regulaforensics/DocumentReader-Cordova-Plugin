#import <Foundation/Foundation.h>

@import AVFoundation;

#import "RGLScenario.h"
#import "RGLDocumentReaderCameraViewController.h"

@class RGLDocumentReaderCameraViewController;

NS_SWIFT_NAME(Functionality)
@interface RGLFunctionality : NSObject

@property(nonatomic, weak, nullable) RGLDocumentReaderCameraViewController *cameraViewController;
@property(nonatomic, assign) RGLDocReaderFrame cameraFrame;
@property(nonatomic, assign) BOOL showTorchButton;
@property(nonatomic, assign) BOOL showCloseButton;
@property(nonatomic, assign) BOOL showCaptureButton;
@property(nonatomic, assign) BOOL showChangeFrameButton;
@property(nonatomic, assign) BOOL showCameraSwitchButton;
@property(nonatomic, assign) BOOL showSkipNextPageButton;
@property(nonatomic, assign) BOOL skipFocusingFrames;
@property(nonatomic, strong, nullable) AVCaptureSessionPreset videoSessionPreset;
@property(nonatomic, assign) BOOL videoCaptureMotionControl;
@property(nonatomic, assign) UIInterfaceOrientationMask orientation;
@property(nonatomic, assign) BOOL onlineMode;
@property(nonatomic, strong, nullable) NSString *serviceURL;
@property(nonatomic, assign) BOOL singleResult;
@property(nonatomic, assign) AVCaptureDevicePosition cameraPosition;
@property(nonatomic, strong, nullable) NSString *btDeviceName;
@property(nonatomic, assign, getter=isUseAuthenticator) BOOL useAuthenticator;
@property(nonatomic, assign) BOOL rfidEnabled;
@property(nonatomic, assign) NSTimeInterval showCaptureButtonDelayFromDetect;
@property(nonatomic, assign) NSTimeInterval showCaptureButtonDelayFromStart;


@end
