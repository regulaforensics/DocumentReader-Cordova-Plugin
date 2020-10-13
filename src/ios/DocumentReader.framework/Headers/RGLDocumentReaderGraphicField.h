#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RGLDocumentReaderJsonResultGroup.h"

NS_SWIFT_NAME(DocumentReaderGraphicField)
@interface RGLDocumentReaderGraphicField : NSObject

@property(nonatomic, assign, readonly) RGLResultType sourceType;
@property(nonatomic, assign, readonly) RGLGraphicFieldType fieldType;
@property(nonatomic, strong, readonly, nonnull) NSString *fieldName;
@property(nonatomic, assign, readonly) CGRect boundRect;
@property(nonatomic, strong, readonly, nonnull) UIImage *value;
@property(nonatomic, assign, readonly) RGLGraphicFieldLight lightType;
@property(nonatomic, strong, readonly, nonnull) NSString *lightName;
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithSourceType:(RGLResultType)sourceType fieldType:(RGLGraphicFieldType)fieldType boundRect:(CGRect)boundRect value:(UIImage *_Nonnull)value light:(RGLGraphicFieldLight) light pageIndex:(NSInteger)pageIndex;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

+ (NSString *_Nullable)graphicFieldTypeName:(RGLGraphicFieldType)graphicFieldType;
+ (NSString *_Nullable)graphicFieldLightName:(RGLGraphicFieldLight)graphicFieldLight;

@end
