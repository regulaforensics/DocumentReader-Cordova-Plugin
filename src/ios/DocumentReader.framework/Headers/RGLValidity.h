#import <Foundation/Foundation.h>

@class RGLRFIDValue;

NS_SWIFT_NAME(Validity)
@interface RGLValidity : NSObject

@property(nonatomic, strong, readonly, nonnull) RGLRFIDValue *notAfter;
@property(nonatomic, strong, readonly, nonnull) RGLRFIDValue *notBefore;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
