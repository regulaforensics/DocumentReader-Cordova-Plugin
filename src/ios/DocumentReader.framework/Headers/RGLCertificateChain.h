#import <Foundation/Foundation.h>
#import "RGLRFIDNotify.h"

@class RGLExtension, RGLAuthority, RGLValidity, RGLRFIDValue;

NS_SWIFT_NAME(CertificateChain)
@interface RGLCertificateChain : NSObject

@property(nonatomic, strong, readonly, nonnull) NSArray <RGLExtension *> *extensions;
@property(nonatomic, strong, readonly, nonnull) RGLRFIDValue *fileName;
@property(nonatomic, strong, readonly, nonnull) RGLAuthority *issuer;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *notifications;
@property(nonatomic, assign, readonly) NSInteger origin;
@property(nonatomic, assign, readonly) double paStatus;
@property(nonatomic, strong, readonly, nonnull) NSString *serialNumber;
@property(nonatomic, strong, readonly, nonnull) NSString *signatureAlgorithm;
@property(nonatomic, strong, readonly, nonnull) RGLAuthority *subject;
@property(nonatomic, strong, readonly, nonnull) NSString *subjectPKAlgorithm;
@property(nonatomic, assign, readonly) RGLRFIDCertificateType type;
@property(nonatomic, strong, readonly, nonnull) RGLValidity *validity;
@property(nonatomic, assign, readonly) NSInteger version;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
