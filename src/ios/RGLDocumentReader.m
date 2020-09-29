@import UIKit;
#import "RGLDocumentReader.h"
@import DocumentReader;

@implementation RGLDocumentReader

static NSNumber * _databasePercentageDownloaded;

+ (NSNumber*)databasePercentageDownloaded{ return _databasePercentageDownloaded; }
+ (void)setDatabasePercentageDownloaded:(NSNumber *)number { _databasePercentageDownloaded = number; }

- (void) result:(NSString*)message :(CDVInvokedUrlCommand*)command{
    [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:message] callbackId:command.callbackId];
}

- (void) error:(NSString*)error :(CDVInvokedUrlCommand*)command{
    [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error] callbackId:command.callbackId];
}

- (void) startRFIDReader:(CDVInvokedUrlCommand*)command{
    if([RGLDocReader.shared isDocumentReaderIsReady])
        dispatch_async(dispatch_get_main_queue(), ^{
            [RGLDocReader.shared startRFIDReaderFromPresenter:[[[UIApplication sharedApplication] keyWindow] rootViewController] completion:[self getCompletion: command]];
        });
    else
        [self result:@"document reader not ready" :command];
}

- (void) initializeReader:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared initializeReader:[[command arguments] objectAtIndex:0] completion:[self getInitCompletion: command]];
}

- (void) initializeReaderWithDatabasePath:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared initializeReader:[[NSData alloc] initWithBase64EncodedString:[[command arguments] objectAtIndex:0] options:0] databasePath:[[command arguments] objectAtIndex:1] completion:[self getInitCompletion: command]];
}

- (void) prepareDatabase:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared prepareDatabase:[[command arguments] objectAtIndex:0] progressHandler:[self getProgressHandler:command] completion:[self getPrepareCompletion: command]];
}

- (void) removeDatabase:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared removeDatabase:^(BOOL successful, NSString * _Nullable error) {
        if (successful)
            [self result:@"database removed" :command];
        else
            [self error:[NSString stringWithFormat:@"%@/%@", @"database removal failed: ", error] :command];
    }];
}

- (void) cancelDBUpdate:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared cancelDBUpdate];
    [self result:@"" :command];
}

-(void) runAutoUpdate:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared runAutoUpdate:[[command arguments] objectAtIndex:0] progressHandler:[self getProgressHandler:command] completion:[self getPrepareCompletion: command]];
}

- (void) showScanner:(CDVInvokedUrlCommand*)command{
    if([RGLDocReader.shared isDocumentReaderIsReady]){
        dispatch_async(dispatch_get_main_queue(), ^{
            [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent animated:YES];
            UIViewController *currentViewController = [[[UIApplication sharedApplication] keyWindow] rootViewController];
            [RGLDocReader.shared showScanner:currentViewController completion:[self getCompletion: command]];
        });
    }else
        [self result:@"document reader not ready" :command];
}

- (void) recognizeImage:(CDVInvokedUrlCommand*)command{
    [self recognizeImageWith:command :[[command arguments] objectAtIndex:0] :false];
}

- (void) recognizeImages:(CDVInvokedUrlCommand*)command{
    if([RGLDocReader.shared isDocumentReaderIsReady]){
        dispatch_async(dispatch_get_main_queue(), ^{
            NSArray* input = [[command arguments] objectAtIndex:0];
            NSMutableArray<UIImage*>* images = [[NSMutableArray alloc] init];
            for(__strong NSMutableString* base64 in input)
                [images addObject:[UIImage imageWithData:[[NSData alloc]initWithBase64EncodedString:base64 options:NSDataBase64DecodingIgnoreUnknownCharacters]]];
            [RGLDocReader.shared recognizeImages:images completion:[self getCompletion: command]];
        });
    }else
        [self result:@"document reader not ready" :command];
}

- (void) recognizeImageWithCameraMode:(CDVInvokedUrlCommand*)command{
    [self recognizeImageWith:command :[[command arguments] objectAtIndex:0] :[[command arguments] objectAtIndex:1]];
}

- (void) recognizeImageWith:(CDVInvokedUrlCommand*)command :(NSMutableString*)base64 :(BOOL)cameraMode{
    if([RGLDocReader.shared isDocumentReaderIsReady])
        [RGLDocReader.shared recognizeImage:[UIImage imageWithData:[[NSData alloc]initWithBase64EncodedString:base64 options:NSDataBase64DecodingIgnoreUnknownCharacters]] cameraMode:cameraMode completion:[self getCompletion: command]];
    else
        [self result:@"document reader not ready" :command];
}

- (void) setConfig:(CDVInvokedUrlCommand*)command{
        [RegulaConfig setConfig:[[command arguments] objectAtIndex:0] :RGLDocReader.shared];
        [self result:@"" :command];
}

- (void) getConfig:(CDVInvokedUrlCommand*)command{
    [self result:[[NSString alloc] initWithData:[NSJSONSerialization dataWithJSONObject:[RegulaConfig getConfig:RGLDocReader.shared] options:NSJSONWritingPrettyPrinted error:nil] encoding:NSUTF8StringEncoding] :command];
}

- (void) setRfidScenario:(CDVInvokedUrlCommand*)command{
        [RegulaConfig setRfidScenario:[[command arguments] objectAtIndex:0] : RGLDocReader.shared.rfidScenario];
        [self result:@"" :command];
}

- (void) getRfidScenario:(CDVInvokedUrlCommand*)command{
        [self result:[[NSString alloc] initWithData:[NSJSONSerialization dataWithJSONObject:RGLDocReader.shared.rfidScenario.rfidScenarioDictionary options:NSJSONWritingPrettyPrinted error:nil] encoding:NSUTF8StringEncoding] :command];
}

- (void) readRFID:(CDVInvokedUrlCommand*)command{
    if([RGLDocReader.shared isDocumentReaderIsReady])
        [RGLDocReader.shared readRFID:nil completion:[self getRFIDCompletion: command]];
    else
        [self result:@"document reader not ready" :command];
}

- (void) stopRFIDReader:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared stopRFIDReader:^(){[self result:@"" :command];}];
}

- (void) clearPKDCertificates:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared clearPKDCertificates];
    [self result:@"" :command];
}

- (void) addPKDCertificates:(CDVInvokedUrlCommand*)command{
    NSArray* input = [[command arguments] objectAtIndex:0];
    NSMutableArray<RGLPKDCertificate*>* certificates = [[RGLPKDCertificate init] alloc];
    for(NSDictionary* certificateJSON in input)
        [certificates addObject:[JsonConstructor RGLPKDCertificateFromJson:certificateJSON]];
    [RGLDocReader.shared addPKDCertificates:certificates];
    [self result:@"" :command];
}

- (void) deinitializeReader:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared deinitializeReader];
    [self result:@"" :command];
}

- (void) selectedScenario:(CDVInvokedUrlCommand*)command{
    [self result:[JsonConstructor generateScenario:RGLDocReader.shared.selectedScenario] :command];
}

- (void) stopScanner:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared stopScanner:^(){[self result:@"" :command];}];
}

- (void) startNewSession:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared startNewSession];
    [self result:@"" :command];
}

- (void) startNewPage:(CDVInvokedUrlCommand*)command{
    [RGLDocReader.shared startNewPage];
    [self result:@"" :command];
}

- (void) getDocumentReaderIsReady:(CDVInvokedUrlCommand*)command{
    [self result:[RGLDocReader.shared isDocumentReaderIsReady] ? @YES : @NO :command];
}

- (void) getAPIVersion:(CDVInvokedUrlCommand*)command{
    [self result:[[RGLDocReader.shared version] api] :command];
}

- (void) getCoreVersion:(CDVInvokedUrlCommand*)command{
    [self result:[[RGLDocReader.shared version] core] :command];
}

- (void) getCoreMode:(CDVInvokedUrlCommand*)command{
    [self result:[[RGLDocReader.shared version] coreMode] :command];
}

- (void) getDatabaseID:(CDVInvokedUrlCommand*)command{
    [self result:[[[RGLDocReader.shared version] database] databaseID] :command];
}

- (void) getDatabaseVersion:(CDVInvokedUrlCommand*)command{
    [self result:[[[RGLDocReader.shared version] database] version] :command];
}

- (void) getDatabaseDate:(CDVInvokedUrlCommand*)command{
    [self result:[[[RGLDocReader.shared version] database] date] :command];
}

- (void) getDatabaseDescription:(CDVInvokedUrlCommand*)command{
    [self result:[[[RGLDocReader.shared version] database] databaseDescription] :command];
}

- (void) getDatabaseCountriesNumber:(CDVInvokedUrlCommand*)command{
    [self result:[NSString stringWithFormat: @"%ld", (long)RGLDocReader.shared.version.database.countriesNumber] :command];
}

- (void) getDatabaseDocumentsNumber:(CDVInvokedUrlCommand*)command{
    [self result:[NSString stringWithFormat: @"%ld", (long)RGLDocReader.shared.version.database.documentsNumber] :command];
}

- (void) getLicenseExpiryDate:(CDVInvokedUrlCommand*)command{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setFormatterBehavior:NSDateFormatterBehaviorDefault];
    [formatter setDateStyle:NSDateFormatterShortStyle];
    [formatter setTimeStyle:NSDateFormatterNoStyle];
    [self result:[formatter stringFromDate:RGLDocReader.shared.license.expiryDate] :command];
}

- (void) getLicenseCountryFilter:(CDVInvokedUrlCommand*)command{
    if(RGLDocReader.shared.license.countryFilter == nil)
        [self result:@"nil" :command];
    else
        [self result:[[NSString alloc] initWithData:[NSJSONSerialization dataWithJSONObject:RGLDocReader.shared.license.countryFilter options:NSJSONWritingPrettyPrinted error:nil] encoding:NSUTF8StringEncoding] :command];
}

- (void) licenseIsRfidAvailable:(CDVInvokedUrlCommand*)command{
    [self result:RGLDocReader.shared.license.isRfidAvailable ? @YES : @NO :command];
}

- (void) getLicenseMessage:(CDVInvokedUrlCommand*)command{
    [self result:@"nil" :command];
}

- (void) getDocumentReaderStatus:(CDVInvokedUrlCommand*)command{
    [self result:RGLDocReader.shared.documentReaderStatus :command];
}

- (void) getRfidSessionStatus:(CDVInvokedUrlCommand*)command{
    [self result:RGLDocReader.shared.rfidSessionStatus :command];
}

- (void) getCurrentScenario:(CDVInvokedUrlCommand*)command{
    [self result:RGLDocReader.shared.processParams.scenario :command];
}

- (void) getCameraSessionIsPaused:(CDVInvokedUrlCommand*)command{
    [self result:RGLDocReader.shared.isCameraSessionIsPaused ? @YES : @NO :command];
}

- (void) setCameraSessionIsPaused:(CDVInvokedUrlCommand*)command{
    RGLDocReader.shared.cameraSessionIsPaused = [[command arguments] objectAtIndex:0];
    [self result:@"" :command];
}

- (void) isRFIDAvailableForUse:(CDVInvokedUrlCommand*)command{
    [self result:RGLDocReader.shared.isRFIDAvailableForUse ? @YES : @NO :command];
}

- (void) getSessionLogFolder:(CDVInvokedUrlCommand*)command{
    [self result:RGLDocReader.shared.processParams.sessionLogFolder :command];
}

- (void) getAvailableScenarios:(CDVInvokedUrlCommand*)command{
    NSMutableArray *availableScenarios = [[NSMutableArray alloc] init];
    for(RGLScenario *scenario in [RGLDocReader.shared availableScenarios])
        [availableScenarios addObject:[JsonConstructor generateScenario:scenario]];
    [self result:[[NSString alloc] initWithData:[NSJSONSerialization dataWithJSONObject:availableScenarios options:NSJSONWritingPrettyPrinted error:nil] encoding:NSUTF8StringEncoding] :command];
}

-(RGLDocumentReaderInitializationCompletion)getInitCompletion:(CDVInvokedUrlCommand*)command{
    return ^(BOOL successful, NSString * _Nullable error ) {
        if (successful)
            [self result:@"init complete" :command];
        else
            [self error:[NSString stringWithFormat:@"%@/%@", @"init failed: ", error] :command];
    };
}

-(void (^_Nullable)(NSProgress * _Nonnull progress))getProgressHandler:(CDVInvokedUrlCommand*)command{
    return ^(NSProgress * _Nonnull progress) {
        if(RGLDocumentReader.databasePercentageDownloaded != [NSNumber numberWithDouble:progress.fractionCompleted * 100]){
            CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:[NSString stringWithFormat:@"%@%.1f%@", @"Downloading database: ", progress.fractionCompleted * 100, @"%"]];
            [result setKeepCallbackAsBool:YES];
            [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
            [RGLDocumentReader setDatabasePercentageDownloaded:[NSNumber numberWithDouble:progress.fractionCompleted * 100]];
        }
    };
}

-(RGLDocumentReaderPrepareCompletion _Nonnull)getPrepareCompletion:(CDVInvokedUrlCommand*)command{
    return ^(BOOL successful, NSString * _Nullable error) {
        if (successful)
            [self result:@"database prepared" :command];
        else
            [self error:[NSString stringWithFormat:@"%@/%@", @"database preparation failed: ", error] :command];
    };
}

-(RGLDocumentReaderCompletion _Nonnull)getCompletion:(CDVInvokedUrlCommand*)command{
    return ^(RGLDocReaderAction action, RGLDocumentReaderResults * _Nullable results, NSString * _Nullable error) {
        switch (action) {
            case RGLDocReaderActionCancel: {
                [self error:@"Cancelled by user" :command];
                break;
            }
                
            case RGLDocReaderActionComplete: {
                [self result:[JsonConstructor resultsToJsonString:results] :command];
                break;
            }
                
            case RGLDocReaderActionError: {
                [self error:[NSString stringWithFormat:@"%@/%@", @"error: ", error] :command];
                break;
            }
                
            case RGLDocReaderActionProcess:
            case RGLDocReaderActionMorePagesAvailable: {
                break;
            }
        }
    };
}

-(RGLRFIDProcessCompletion _Nonnull)getRFIDCompletion:(CDVInvokedUrlCommand*)command{
    return ^(RGLRFIDCompleteAction action, RGLDocumentReaderResults * _Nullable results, NSString * _Nullable error, RGLRFIDErrorCodes errorCode) {
        switch (action) {
            case RGLRFIDCompleteActionCancel: {
                [self error:@"Cancelled by user" :command];
                break;
            }
                
            case RGLRFIDCompleteActionComplete: {
                [self result:[JsonConstructor resultsToJsonString:results] :command];
                break;
            }
                
            case RGLRFIDCompleteActionError: {
                [self error:[NSString stringWithFormat:@"%@/%@", @"error: ", error] :command];
                break;
            }
            case RGLRFIDCompleteActionSessionRestarted: {
                break;
            }
        }
    };
}

@end
