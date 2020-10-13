#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

NS_SWIFT_NAME(PreviewView)
@interface RGLPreviewView : UIView

@property(nonatomic,readonly,strong) AVCaptureVideoPreviewLayer *videoPreviewLayer;
@property(nonatomic,readwrite,strong) AVCaptureSession *session;

-(void)showCaptureEffect;

@end
