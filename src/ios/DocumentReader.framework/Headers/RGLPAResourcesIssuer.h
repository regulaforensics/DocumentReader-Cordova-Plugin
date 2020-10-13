#import <Foundation/Foundation.h>

@class RGLPAAttribute;

NS_SWIFT_NAME(PAResourcesIssuer)
@interface RGLPAResourcesIssuer : NSObject

@property(nonatomic, strong, readonly, nullable) NSData *data;
@property(nonatomic, strong, readonly, nullable) NSString *friendlyName;
@property(nonatomic, strong, readonly, nullable) NSArray <RGLPAAttribute*> *attributes;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
