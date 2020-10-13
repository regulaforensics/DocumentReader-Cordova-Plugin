#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

@class RGLDocumentReaderValue;

NS_SWIFT_NAME(DocumentReaderTextField)
@interface RGLDocumentReaderTextField : NSObject

@property(nonatomic, assign, readonly) RGLFieldType fieldType;
@property(nonatomic, strong, readonly, nonnull) NSString *fieldName;
@property(nonatomic, assign, readonly) RGLLCID lcid;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLDocumentReaderValue *> *values;
@property(nonatomic, assign, readonly) RGLCheckResult status;

- (RGLDocumentReaderValue *_Nullable)getValue;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithFieldType:(RGLFieldType)fieldType;
- (instancetype _Nonnull)initWithFieldType:(RGLFieldType)fieldType lcid:(RGLLCID)lcid;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

+ (NSString *_Nonnull)fieldTypeName:(RGLFieldType) fieldType;
+ (NSString *_Nonnull)lcidName:(RGLLCID) lcid;

@end
