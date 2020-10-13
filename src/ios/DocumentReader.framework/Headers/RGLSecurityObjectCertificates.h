#import <Foundation/Foundation.h>

@class RGLCertificateData;

NS_SWIFT_NAME(SecurityObjectCertificates)
@interface RGLSecurityObjectCertificates : NSObject

@property(nonatomic, strong, readonly, nonnull) RGLCertificateData *securityObject;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
