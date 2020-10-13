#import <Foundation/Foundation.h>

NS_SWIFT_NAME(CardProperties)
@interface RGLCardProperties : NSObject

@property(nonatomic, assign, readonly) NSInteger aTQA;
@property(nonatomic, strong, readonly, nonnull) NSString *aTQB;
@property(nonatomic, strong, readonly, nonnull) NSString *aTR;
@property(nonatomic, strong, readonly, nonnull) NSString *baudrate1;
@property(nonatomic, strong, readonly, nonnull) NSString *baudrate2;
@property(nonatomic, assign, readonly) NSInteger bitRateR;
@property(nonatomic, assign, readonly) NSInteger bitRateS;
@property(nonatomic, assign, readonly) NSInteger chipTypeA;
@property(nonatomic, assign, readonly) NSInteger mifareMemory;
@property(nonatomic, assign, readonly) NSInteger rfidType;
@property(nonatomic, assign, readonly) NSInteger sAK;
@property(nonatomic, assign, readonly) BOOL support4;
@property(nonatomic, assign, readonly) BOOL supportMifare;
@property(nonatomic, strong, readonly, nonnull) NSString *uID;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
