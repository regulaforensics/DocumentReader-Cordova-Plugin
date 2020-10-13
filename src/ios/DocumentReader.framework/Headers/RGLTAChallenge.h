#import <Foundation/Foundation.h>

NS_SWIFT_NAME(TAChallenge)
@interface RGLTAChallenge : NSObject

@property(nonatomic, strong, readonly, nonnull) NSData *data;
@property(nonatomic, strong, readonly, nonnull) NSString *auxPCD;
@property(nonatomic, strong, readonly, nonnull) NSString *challengePICC;
@property(nonatomic, strong, readonly, nonnull) NSString *hashPK;
@property(nonatomic, strong, readonly, nonnull) NSString *idPICC;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
