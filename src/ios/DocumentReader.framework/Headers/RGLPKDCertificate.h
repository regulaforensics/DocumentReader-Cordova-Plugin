#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, RGLPKDResourceType) {
    RGLPKDResourceTypeCertificate_PA          = 0,
    RGLPKDResourceTypeCertificate_TA          = 1,
    RGLPKDResourceTypeLDIF                    = 2,
    RGLPKDResourceTypeCRL                     = 3,
    RGLPKDResourceTypeML                      = 4,
    RGLPKDResourceTypeDefL                    = 5,
    RGLPKDResourceTypeDevL                    = 6,
    RGLPKDResourceTypeBL                      = 7,
} NS_SWIFT_NAME(PKDResourceType);

NS_SWIFT_NAME(PKDCertificate)
@interface RGLPKDCertificate : NSObject

@property(nonatomic, strong, readonly, nonnull) NSData *binaryData;
@property(nonatomic, assign, readonly) RGLPKDResourceType resourceType;
@property(nonatomic, strong, readonly, nullable) NSData *privateKey;

- (instancetype _Nonnull)initWithBinaryData:(NSData * _Nonnull)binaryData
                               resourceType:(RGLPKDResourceType)resourceType
                                 privateKey:(NSData *_Nullable)privateKey;

@end
