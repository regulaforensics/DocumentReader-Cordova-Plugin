#import <Foundation/Foundation.h>

NS_SWIFT_NAME(ElementRect)
@interface RGLElementRect : NSObject

@property(nonatomic, assign, readonly) NSInteger bottom;
@property(nonatomic, assign, readonly) NSInteger left;
@property(nonatomic, assign, readonly) NSInteger right;
@property(nonatomic, assign, readonly) NSInteger top;

- (instancetype _Nonnull)initWithLeft:(NSInteger)left top:(NSInteger)top right:(NSInteger)right bottom:(NSInteger)bottom;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
