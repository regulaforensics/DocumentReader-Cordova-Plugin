#import <Foundation/Foundation.h>
#import "RGLDocReaderDocumentsDatabase.h"

NS_SWIFT_NAME(DocReaderVersion)
@interface RGLDocReaderVersion : NSObject

@property (nonatomic, strong, nullable) NSString *api;
@property (nonatomic, strong, nullable) NSString *core;
@property (nonatomic, strong, nullable) NSString *coreMode;
@property (nonatomic, strong, nonnull) RGLDocReaderDocumentsDatabase *database;

- (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
