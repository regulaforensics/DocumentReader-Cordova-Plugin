#import <Cordova/CDVPlugin.h>
#import <Foundation/Foundation.h>
#import "RGLWJSONConstructor.h"
#import "RegulaConfig.h"
#import <DocumentReader/DocumentReader.h>

@class DocReader;

@interface RGLDocumentReader : CDVPlugin<RGLRecordScanningProcessDelegate, RGLDocReaderRFIDDelegate>

@property (class) CDVInvokedUrlCommand* _Nullable command;
@property (class) NSNumber* _Nullable databasePercentageDownloaded;

- (void) sendEvent:(NSString*_Nullable)data :(NSString*_Nonnull)callbackId;

@end

@interface RFIDDelegateNoPA : NSObject<RGLDocReaderRFIDDelegate>
@end
