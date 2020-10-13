#import <Foundation/Foundation.h>

@class RGLDataGroup;

NS_SWIFT_NAME(ePassportDataGroup)
@interface RGLePassportDataGroup : RGLDataGroup

@property(nonatomic, assign) BOOL dG15;
@property(nonatomic, assign) BOOL dG16;

+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
