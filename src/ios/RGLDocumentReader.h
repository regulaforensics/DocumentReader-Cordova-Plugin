#import <Cordova/CDVPlugin.h>
#import <Foundation/Foundation.h>
#import "JsonConstructor.h"
#import "RegulaConfig.h"
#import <DocumentReader/DocumentReader.h>

@class DocReader;

@interface RGLDocumentReader : CDVPlugin

@property (nonatomic, strong) RGLDocReader *docReader;
@property (class) NSNumber* _Nullable databasePercentageDownloaded;

@end
