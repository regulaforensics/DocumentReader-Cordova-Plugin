#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"
#import "RGLImageQualityGroup.h"

NS_SWIFT_NAME(ImageQuality)
@interface RGLImageQuality : NSObject

@property(nonatomic, assign, readonly) RGLImageQualityCheckType type;
@property(nonatomic, assign, readonly) RGLCheckResult result;
@property(nonatomic, assign, readonly) RGLSecurityFeatureType featureType;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

