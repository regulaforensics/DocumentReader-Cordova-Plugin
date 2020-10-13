#import <Foundation/Foundation.h>
#import "RGLAuthenticityElement.h"

@class RGLElementRect;

NS_SWIFT_NAME(SecurityFeatureCheck)
@interface RGLSecurityFeatureCheck : RGLAuthenticityElement

@property(nonatomic, strong, readonly, nonnull) RGLElementRect *elementRect;

@end
