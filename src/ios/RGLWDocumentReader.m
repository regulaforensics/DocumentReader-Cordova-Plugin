@import UIKit;
@import DocumentReader;
#import "RGLWDocumentReader.h"

RGLWDocumentReader* RGLWPlugin;

@implementation RGLWDocumentReader
static CDVInvokedUrlCommand* _command;
+ (CDVInvokedUrlCommand*)command { return _command; }
+ (void) setCommand:(CDVInvokedUrlCommand*)command { _command = command; }

UIViewController*(^RGLWRootViewController)(void) = ^UIViewController*(){
    for (UIWindow *window in UIApplication.sharedApplication.windows)
        if (window.isKeyWindow)
            return window.rootViewController;
    return nil;
};

static RGLWEventSender sendEvent = ^(NSString* event, id data) {
    NSArray *skippedEvents = @[videoEncoderCompletionEvent, onCustomButtonTappedEvent];
    if([skippedEvents containsObject:event]) return;

    NSArray *singleEvents = @[completionEvent, databaseProgressEvent];
    if(![singleEvents containsObject:event]) data = [NSString stringWithFormat:@"%@%@", event, data];

    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:data];
    [result setKeepCallbackAsBool:YES];
    [RGLWPlugin.commandDelegate sendPluginResult:result callbackId:RGLWDocumentReader.command.callbackId];
};

- (void) exec:(CDVInvokedUrlCommand*)command {
    [RGLWDocumentReader setCommand:command];
    RGLWPlugin = self;
    NSMutableArray* args = [[NSMutableArray alloc] init];
    NSString* action = [[command arguments] objectAtIndex:0];
    for (int i = 1;i<[command arguments].count;i++)
        [args addObject:[[command arguments] objectAtIndex:i]];
    [RGLWMain methodCall:action :args :^(id data) { [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:data] callbackId:command.callbackId]; } :sendEvent];
}

@end
