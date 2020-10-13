#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RGLDocumentReaderResults.h"
#import "RGLDocumentReaderDocumentType.h"

NS_SWIFT_NAME(Position)
@interface RGLPosition : NSObject

@property(nonatomic, assign, readonly) CGSize size;
@property(nonatomic, assign, readonly) CGPoint center;
@property(nonatomic, assign, readonly) CGPoint leftTop;
@property(nonatomic, assign, readonly) CGPoint leftBottom;
@property(nonatomic, assign, readonly) CGPoint rightTop;
@property(nonatomic, assign, readonly) CGPoint rightBottom;
@property(nonatomic, assign, readonly) double angle;

@property(nonatomic, assign, readonly) double perspectiveTr;
@property(nonatomic, assign, readonly) double objArea;
@property(nonatomic, assign, readonly) double objIntAngleDev;
@property(nonatomic, assign, readonly) RGLCheckResult resultStatus;
@property(nonatomic, assign, readonly) RGLDocFormat docFormat;
@property(nonatomic, assign, readonly) NSInteger pageIndex;
@property(nonatomic, assign, readonly) NSInteger dpi;
@property(nonatomic, assign, readonly) NSInteger inverse;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
