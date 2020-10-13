#import <Foundation/Foundation.h>

NS_SWIFT_NAME(Extension)
@interface RGLExtension : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *data;
@property(nonatomic, strong, readonly, nonnull) NSString *type;
- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
