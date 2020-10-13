#import <Foundation/Foundation.h>
#import "RGLRFIDNotify.h"

@class RGLFile;

NS_SWIFT_NAME(Application)
@interface RGLApplication : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *applicationID;
@property(nonatomic, strong, readonly, nonnull) NSString *dataHashAlgorithm;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLFile *> *files;
@property(nonatomic, assign, readonly) NSInteger type;
@property(nonatomic, assign, readonly) RGLRFIDErrorCodes status;
@property(nonatomic, strong, readonly, nonnull) NSString *unicodeVersion;
@property(nonatomic, strong, readonly, nonnull) NSString *version;


- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
