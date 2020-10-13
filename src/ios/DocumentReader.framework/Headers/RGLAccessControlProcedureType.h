#import <Foundation/Foundation.h>
#import "RGLRFIDNotify.h"
#import "RGLRFIDScenario.h"

NS_SWIFT_NAME(AccessControlProcedureType)
@interface RGLAccessControlProcedureType : NSObject

@property(nonatomic, assign, readonly) NSInteger activeOptionIdx;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *notifications;
@property(nonatomic, assign, readonly) RGLRFIDErrorCodes status;
@property(nonatomic, assign, readonly) RGLRFIDAccessControlProcedureType type;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
