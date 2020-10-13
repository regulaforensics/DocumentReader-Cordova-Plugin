#import <UIKit/UIKit.h>
#import "RGLScenario.h"

NS_SWIFT_NAME(CornerView)
@interface RGLCornerView : UIView

@property(nonatomic) CGFloat lineLength;
@property(nonatomic) CGFloat lineWidth;
@property(nonatomic) CGFloat cornerRadius;
@property(nonatomic) CGLineCap lineCap;
@property(nonatomic, strong) UIColor *lineColor;
@property(nonatomic, assign) RGLCameraFrameShapeType shapeType;

@end
