#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

NS_SWIFT_NAME(RFIDSessionDataStatus)
@interface RGLRFIDSessionDataStatus : NSObject

@property(nonatomic, assign) RGLCheckResult AA;
@property(nonatomic, assign) RGLCheckResult BAC;
@property(nonatomic, assign) RGLCheckResult CA;
@property(nonatomic, assign) RGLCheckResult PA;
@property(nonatomic, assign) RGLCheckResult PACE;
@property(nonatomic, assign) RGLCheckResult TA;
@property(nonatomic, assign) RGLCheckResult overallStatus;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
