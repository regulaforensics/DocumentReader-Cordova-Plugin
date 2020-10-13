#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class RGLDocumentReaderJsonResultGroup;

NS_SWIFT_NAME(DocumentReaderJsonResult)
@interface RGLDocumentReaderJsonResult : NSObject

@property(nonatomic, strong, readonly, nonnull) NSArray <RGLDocumentReaderJsonResultGroup *> *results;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithResults:(NSArray <RGLDocumentReaderJsonResultGroup *> *_Nonnull)results;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
