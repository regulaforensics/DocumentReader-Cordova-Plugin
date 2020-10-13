#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

@class RGLAuthenticityElement;

NS_SWIFT_NAME(AuthenticityCheck)
@interface RGLAuthenticityCheck : NSObject

@property(nonatomic, assign, readonly) RGLAuthenticity type;
@property(nonatomic, strong, readonly, nonnull) NSString *typeName;
@property(nonatomic, assign, readonly) RGLCheckResult status;
@property(nonatomic, strong, readonly, nullable) NSArray <RGLAuthenticityElement *> *elements;
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (instancetype _Nonnull)initWithAuthenticity:(RGLAuthenticity)type elements:(NSArray <RGLAuthenticityElement *> *_Nullable)elements pageIndex:(NSInteger)pageIndex;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
