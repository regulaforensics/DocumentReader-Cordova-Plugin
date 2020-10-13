#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class RGLDocumentReaderGraphicField;

NS_SWIFT_NAME(DocumentReaderGraphicResult)
@interface RGLDocumentReaderGraphicResult : NSObject

@property(nonatomic, strong, readonly, nonnull) NSArray <RGLDocumentReaderGraphicField *> *fields;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithFields:(NSArray <RGLDocumentReaderGraphicField *> *_Nonnull)fields;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
