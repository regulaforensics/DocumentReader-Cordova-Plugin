#import <Foundation/Foundation.h>
#import "RGLRFIDNotify.h"

@class RGLAccessControlProcedureType, RGLApplication,
RGLSecurityObject, RGLCardProperties, RGLRFIDSessionDataStatus;

NS_SWIFT_NAME(RFIDSessionData)
@interface RGLRFIDSessionData : NSObject

@property(nonatomic, strong, readonly, nonnull) NSArray <RGLAccessControlProcedureType *> *accessControls;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLApplication *> *applications;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLSecurityObject *> *securityObjects;
@property(nonatomic, strong, readonly, nonnull) RGLCardProperties *cardProperties;
@property(nonatomic, assign, readonly) NSInteger totalBytesReceived;
@property(nonatomic, assign, readonly) NSInteger totalBytesSent;
@property(nonatomic, assign, readonly) RGLRFIDErrorCodes status;
@property(nonatomic, assign, readonly) RGLRFIDErrorCodes extLeSupport;
@property(nonatomic, assign, readonly) double processTime;
@property(nonatomic, strong, readonly, nonnull) RGLRFIDSessionDataStatus *sessionDataStatus;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
