#import <Foundation/Foundation.h>

@class RGLDocReader, RGLPAResourcesIssuer, RGLPKDCertificate, RGLTAChallenge;

typedef void (^RGLRFIDCertificatesCallback)(NSArray <RGLPKDCertificate *> *certificates) NS_SWIFT_NAME(RFIDCertificatesCallback);

@protocol RGLDocReaderRFIDDelegate <NSObject>
@optional
- (void)onRequestPACertificatesWithSerial:(NSData *)serialNumber
                                   issuer:(RGLPAResourcesIssuer *)issuer
                                 callback:(RGLRFIDCertificatesCallback)callback;

- (void)onRequestTACertificatesWithKey:(NSString *)keyCAR
                                 callback:(RGLRFIDCertificatesCallback)callback;

- (void)onRequestTASignatureWithChallenge:(RGLTAChallenge *)challenge
                              callback:(void(^)(NSData *signature))callback;
@end
