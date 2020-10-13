#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

@class RGLImageQuality;

typedef NS_ENUM(NSInteger, RGLImageQualityCheckType) {
  RGLEImageQualityCheckTypeImageGlares       = 0,
  RGLEImageQualityCheckTypeImageFocus        = 1,
  RGLEImageQualityCheckTypeImageResolution   = 2
} NS_SWIFT_NAME(ImageQualityCheckType);

NS_SWIFT_NAME(ImageQualityGroup)
@interface RGLImageQualityGroup : NSObject

@property(nonatomic, assign, readonly) NSInteger count;
@property(nonatomic, assign, readonly) RGLCheckResult result;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLImageQuality *> *imageQualityList;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (RGLCheckResult)getQualityResultWithType:(RGLImageQualityCheckType)type;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

