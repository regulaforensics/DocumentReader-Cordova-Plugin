#import <Foundation/Foundation.h>

NS_SWIFT_NAME(License)
@interface RGLLicense : NSObject

@property(nonatomic, strong, readonly, nullable) NSDate *expiryDate;
@property(nonatomic, strong, readonly, nullable) NSArray <NSString *> *countryFilter;
@property(nonatomic, assign, readonly, getter=isRfidAvailable) BOOL rfidAvailable;

- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;

@end
