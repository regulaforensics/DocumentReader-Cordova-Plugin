#import <Foundation/Foundation.h>

@class RGLAuthority, RGLExtension, RGLCertificateChain, RGLRFIDValue;

NS_SWIFT_NAME(SignerInfo)
@interface RGLSignerInfo : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *dataToHash;
@property(nonatomic, strong, readonly, nonnull) NSString *digestAlgorithm;
@property(nonatomic, assign, readonly) double paStatus;
@property(nonatomic, strong, readonly, nonnull) NSString *signatureAlgorithm;
@property(nonatomic, assign, readonly) NSInteger version;
@property(nonatomic, strong, readonly, nonnull) RGLAuthority *issuer;
@property(nonatomic, strong, readonly, nonnull) RGLRFIDValue *serialNumber;
@property(nonatomic, strong, readonly, nonnull) RGLRFIDValue *signature;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLExtension *> *signedAttributes;
@property(nonatomic, strong, readonly, nonnull) RGLRFIDValue *subjectKeyIdentifier;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLCertificateChain *> *certificateChain;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *notifications;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
