#import <Foundation/Foundation.h>

NS_SWIFT_NAME(DocReaderDocumentsDatabase)
@interface RGLDocReaderDocumentsDatabase : NSObject

@property (nonatomic, strong, readonly, nullable) NSString *databaseID;
@property (nonatomic, strong, readonly, nullable) NSString *version;
@property (nonatomic, strong, readonly, nullable) NSString *date;
@property (nonatomic, strong, readonly, nullable) NSString *databaseDescription;
@property (nonatomic, assign, readonly) NSInteger countriesNumber;
@property (nonatomic, assign, readonly) NSInteger documentsNumber;

- (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
