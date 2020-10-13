#import <Foundation/Foundation.h>

NS_SWIFT_NAME(PDF417Info)
@interface RGLPDF417Info : NSObject

@property(nonatomic, assign, readonly) NSInteger errorLevel;
@property(nonatomic, assign, readonly) NSInteger columns;
@property(nonatomic, assign, readonly) NSInteger rows;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
