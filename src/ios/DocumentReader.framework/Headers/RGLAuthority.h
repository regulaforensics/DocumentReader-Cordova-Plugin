#import <Foundation/Foundation.h>

@class RGLAttribute, RGLRFIDValue;

NS_SWIFT_NAME(Authority)
@interface RGLAuthority : NSObject

@property(nonatomic, strong, readonly, nonnull) NSArray <RGLAttribute *> *attributes;
@property(nonatomic, strong, readonly, nonnull) NSString *data;
@property(nonatomic, strong, readonly, nonnull) RGLRFIDValue *friendlyName;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
