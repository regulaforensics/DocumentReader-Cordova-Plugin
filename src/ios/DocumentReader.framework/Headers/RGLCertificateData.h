#import <Foundation/Foundation.h>

NS_SWIFT_NAME(CertificateData)
@interface RGLCertificateData : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *data;
@property(nonatomic, assign, readonly) NSInteger length;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
