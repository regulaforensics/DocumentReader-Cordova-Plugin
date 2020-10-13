#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

NS_SWIFT_NAME(AuthenticityElement)
@interface RGLAuthenticityElement : NSObject

@property(nonatomic, assign, readonly) RGLCheckResult status;
@property(nonatomic, assign, readonly) RGLSecurityFeatureType elementType;
@property(nonatomic, strong, readonly, nonnull) NSString *elementTypeName;
@property(nonatomic, assign, readonly) RGLCheckDiagnose elementDiagnose;
@property(nonatomic, strong, readonly, nonnull) NSString *elementDiagnoseName;

- (instancetype _Nonnull)initWithStatus:(RGLCheckResult)status elementType:(RGLSecurityFeatureType)elementType elementDiagnose:(RGLCheckDiagnose)elementDiagnose;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
