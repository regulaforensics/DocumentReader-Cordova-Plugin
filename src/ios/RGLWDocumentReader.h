#import <Cordova/CDVPlugin.h>
#import <Foundation/Foundation.h>
#import "RGLWJSONConstructor.h"
#import "RGLWRegulaConfig.h"
#import <DocumentReader/DocumentReader.h>

@class DocReader;

typedef void (^RGLWCallback)(NSString* _Nullable response);

@interface RGLWDocumentReader : CDVPlugin<RGLRecordScanningProcessDelegate,
                                            RGLDocReaderRFIDDelegate,
                                            RGLCustomizationActionDelegate>

@property (class) CDVInvokedUrlCommand* _Nullable command;
@property (class) NSNumber* _Nullable databasePercentageDownloaded;

- (void) sendEvent:(NSString*_Nullable)data :(NSString*_Nonnull)callbackId;

@end

typedef void (^RGLWRFIDSignatureCallback)(NSData * _Nonnull signature);

@interface RGLWRFIDDelegateNoPA : NSObject<RGLDocReaderRFIDDelegate>
@end
