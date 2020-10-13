#import <Foundation/Foundation.h>
#import "RGLAuthenticityElement.h"
#import <UIKit/UIKit.h>

@class RGLElementRect;

NS_SWIFT_NAME(IdentResult)
@interface RGLIdentResult : RGLAuthenticityElement

@property(nonatomic, strong, readonly, nonnull) UIImage *etalonImage;
@property(nonatomic, strong, readonly, nonnull) UIImage *image;
@property(nonatomic, assign, readonly) NSInteger percentValue;
@property(nonatomic, assign, readonly) NSInteger lightIndex;
@property(nonatomic, strong, readonly, nonnull) RGLElementRect *area;

- (instancetype _Nonnull)initWithEtalonImage:(UIImage *_Nonnull)etalonImage image:(UIImage *_Nonnull)image percentValue:(NSInteger)percentValue status:(RGLCheckResult)status elementType:(RGLSecurityFeatureType)elementType area:(RGLElementRect *)area elementDiagnose:(RGLCheckDiagnose)elementDiagnose;

@end
