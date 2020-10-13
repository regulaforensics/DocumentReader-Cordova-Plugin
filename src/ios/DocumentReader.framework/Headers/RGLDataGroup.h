#import <Foundation/Foundation.h>

NS_SWIFT_NAME(DataGroup)
@interface RGLDataGroup : NSObject

@property(nonatomic, assign) BOOL dG1;
@property(nonatomic, assign) BOOL dG2;
@property(nonatomic, assign) BOOL dG3;
@property(nonatomic, assign) BOOL dG4;
@property(nonatomic, assign) BOOL dG5;
@property(nonatomic, assign) BOOL dG6;
@property(nonatomic, assign) BOOL dG7;
@property(nonatomic, assign) BOOL dG8;
@property(nonatomic, assign) BOOL dG9;
@property(nonatomic, assign) BOOL dG10;
@property(nonatomic, assign) BOOL dG11;
@property(nonatomic, assign) BOOL dG12;
@property(nonatomic, assign) BOOL dG13;
@property(nonatomic, assign) BOOL dG14;

- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
- (NSDictionary *_Nonnull)dataGroupsDictionary;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
