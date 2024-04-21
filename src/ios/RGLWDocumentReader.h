#import <Cordova/CDVPlugin.h>
#import <Foundation/Foundation.h>
#import "RGLWJSONConstructor.h"
#import "RGLWConfig.h"
#import <DocumentReader/DocumentReader.h>

@class DocReader;

typedef void (^RGLWCallback)(id _Nullable response);
typedef void (^RGLWEventSender)(NSString* _Nonnull event, id _Nullable data);
typedef void (^RGLWRFIDSignatureCallback)(NSData * _Nonnull signature);

@interface RGLWDocumentReader : CDVPlugin<RGLRecordScanningProcessDelegate,
                                          RGLDocReaderRFIDDelegate,
                                          RGLCustomizationActionDelegate,
                                          RGLDocReaderDatabaseFetchDelegate>

@property (class) CDVInvokedUrlCommand* _Nullable command;
@property NSNumber* _Nonnull doRequestPACertificates;
@property NSNumber* _Nonnull doRequestTACertificates;
@property NSNumber* _Nonnull doRequestTASignature;

@end

NSString* _Nonnull RGLWCompletionEvent;
NSString* _Nonnull RGLWDatabaseProgressEvent;
NSString* _Nonnull RGLWVideoEncoderCompletionEvent;
NSString* _Nonnull RGLWOnCustomButtonTappedEvent;
