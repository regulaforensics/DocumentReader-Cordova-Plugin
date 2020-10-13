#import <Foundation/Foundation.h>

@class RGLRFIDValue;

NS_SWIFT_NAME(Attribute)
@interface RGLAttribute : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *type;
@property(nonatomic, strong, readonly, nonnull) RGLRFIDValue *value;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
