#import <Foundation/Foundation.h>

NS_SWIFT_NAME(FileData)
@interface RGLFileData : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *data;
@property(nonatomic, assign, readonly) NSInteger length;
@property(nonatomic, assign, readonly) double status;
@property(nonatomic, assign, readonly) NSInteger type;


- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
