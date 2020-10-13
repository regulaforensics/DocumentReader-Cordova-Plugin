#import <Foundation/Foundation.h>

NS_SWIFT_NAME(PAAttribute)
@interface RGLPAAttribute : NSObject

@property(nonatomic, strong, readonly, nullable) NSString *value;
@property(nonatomic, strong, readonly, nullable) NSString *type;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
