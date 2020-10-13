#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, RGLDocReaderFrame) {
    RGLDocReaderFrameScenarioDefault = 0,
    RGLDocReaderFrameMax = 1,
    RGLDocReaderFrameNone = 2,
    RGLDocReaderFrameDocument = 3
} NS_SWIFT_NAME(DocReaderFrame);

typedef NS_ENUM(NSInteger, RGLDocReaderOrientation) {
    RGLDocReaderOrientationRotate = 0,
    RGLDocReaderOrientationPortrait = 1,
    RGLDocReaderOrientationLandscape = 2
} NS_SWIFT_NAME(DocReaderOrientation);

typedef NS_ENUM(NSInteger, RGLCameraFrameShapeType) {
    RGLCameraFrameShapeTypeLine,
    RGLCameraFrameShapeTypeCorners
} NS_SWIFT_NAME(CameraFrameShapeType);

NS_SWIFT_NAME(Scenario)
@interface RGLScenario : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *identifier;
@property(nonatomic, assign, readonly) RGLDocReaderFrame frame;
@property(nonatomic, assign, readonly) double frameKWHLandscape;
@property(nonatomic, assign, readonly) double frameKWHPortrait;
@property(nonatomic, assign, readonly) double frameKWHDoublePageSpreadPortrait;
@property(nonatomic, assign, readonly) double frameKWHDoublePageSpreadLandscape;
@property(nonatomic, strong, readonly, nonnull) NSString *scenarioDescription;
@property(nonatomic, assign, readonly) BOOL barcodeExt;
@property(nonatomic, assign, readonly) BOOL faceExt;
@property(nonatomic, assign, readonly) BOOL multiPageOff;
@property(nonatomic, assign, readonly) BOOL seriesProcessMode;
@property(nonatomic, strong, readonly, nonnull) NSString *caption;
@property(nonatomic, assign, readonly) BOOL uvTorch;
@property(nonatomic, assign, readonly) RGLDocReaderOrientation frameOrientation;

- (instancetype _Nonnull)initWithIdentifier:(NSString *_Nonnull)identifier frame:(RGLDocReaderFrame)frame frameKWHLandscape:(double)frameKWHLandscape frameKWHPortrait:(double)frameKWHPortrait frameKWHDoublePageSpreadPortrait:(double)frameKWHDoublePageSpreadPortrait frameKWHDoublePageSpreadLandscape:(double)frameKWHDoublePageSpreadLandscape scenarioDescription:(NSString *_Nonnull)scenarioDescription barcodeExt:(BOOL)barcodeExt faceExt:(BOOL)faceExt multiPageOff:(BOOL)multiPageOff caption:(NSString *_Nonnull)caption uvTorch:(BOOL)uvTorch frameOrientation:(RGLDocReaderOrientation)frameOrientation seriesProcessMode:(BOOL)seriesProcessMode;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
+ (NSArray * _Nullable)arrayFromJSON:(NSDictionary * _Nonnull)json;

@end
