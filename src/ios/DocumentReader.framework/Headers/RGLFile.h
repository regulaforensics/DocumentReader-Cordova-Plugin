#import <Foundation/Foundation.h>
#import "RGLRFIDNotify.h"

@class RGLFileData, RGLSecurityObjectCertificates;

NS_SWIFT_NAME(File)
@interface RGLFile : NSObject

@property(nonatomic, strong, readonly, nonnull) RGLFileData *fileData;
@property(nonatomic, strong, readonly, nonnull) NSString *fileID;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *notifications;
@property(nonatomic, assign, readonly) RGLRFIDErrorCodes pAStatus;
@property(nonatomic, assign, readonly) RGLRFIDErrorCodes readingStatus;
@property(nonatomic, assign, readonly) NSInteger readingTime;
@property(nonatomic, assign, readonly) RGLRFIDDataFileType type;
@property(nonatomic, strong, readonly, nonnull) NSString *typeName;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *docFieldsText;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *docFieldsGraphics;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *docFieldsOriginals;
@property(nonatomic, strong, readonly, nonnull) RGLSecurityObjectCertificates *certificates;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
