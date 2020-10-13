#import <Foundation/Foundation.h>

@class RGLDataGroup;

NS_SWIFT_NAME(eIDDataGroup)
@interface RGLeIDDataGroup : RGLDataGroup

@property(nonatomic, assign) BOOL dG15;
@property(nonatomic, assign) BOOL dG16;
@property(nonatomic, assign) BOOL dG17;
@property(nonatomic, assign) BOOL dG18;
@property(nonatomic, assign) BOOL dG19;
@property(nonatomic, assign) BOOL dG20;
@property(nonatomic, assign) BOOL dG21;

+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
