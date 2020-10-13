#import <Foundation/Foundation.h>

typedef enum {
    RGLRFIDSdkProfilerTypeDoc9303Edition2006 = 0x00000001,
    RGLRFIDSdkProfilerTypeDoc9303LdsPkiMaintenance = 0x00000002
} RGLRFIDSdkProfilerType NS_SWIFT_NAME(RFIDSdkProfilerType);

typedef NS_ENUM(NSInteger, RGLRFIDAuthenticationProcedureType) {
    RGLRFIDAuthenticationProcedureTypeUndefined = 0,
    RGLRFIDAuthenticationProcedureTypeStandard = 1,
    RGLRFIDAuthenticationProcedureTypeAdvanced = 2,
    RGLRFIDAuthenticationProcedureTypeGeneral = 3
} NS_SWIFT_NAME(RFIDAuthenticationProcedureType);

typedef NS_ENUM(NSInteger, RGLRFIDAccessControlProcedureType) {
    RGLRFIDAccessControlProcedureTypeUndefined = 0,
    RGLRFIDAccessControlProcedureTypeBac = 1,
    RGLRFIDAccessControlProcedureTypePace = 2,
    RGLRFIDAccessControlProcedureTypeCa = 3,
    RGLRFIDAccessControlProcedureTypeTa = 4,
    RGLRFIDAccessControlProcedureTypeAa = 5,
    RGLRFIDAccessControlProcedureTypeRi = 6,
    RGLRFIDAccessControlProcedureTypeCardInfo = 7
} NS_SWIFT_NAME(RFIDAccessControlProcedureType);

typedef NS_ENUM(NSInteger, RGLRFIDPasswordType) {
    RGLRFIDPasswordTypeUnknown = 0,
    RGLRFIDPasswordTypeMrz = 1,
    RGLRFIDPasswordTypeCan = 2,
    RGLRFIDPasswordTypePin = 3,
    RGLRFIDPasswordTypePuk = 4,
    RGLRFIDPasswordTypePinEsign = 5,
    RGLRFIDPasswordTypeSai = 6
} NS_SWIFT_NAME(RFIDPasswordType);

typedef NS_ENUM(NSInteger, RGLRFIDTerminalType) {
    RGLRFIDTerminalTypeUndefined = 0,
    RGLRFIDTerminalTypeInspectionSystem = 1,
    RGLRFIDTerminalTypeAuthenticationTerminal = 2,
    RGLRFIDTerminalTypeSignatureTerminal = 3,
    RGLRFIDTerminalTypeUnauthenticatedTerminal = 4
} NS_SWIFT_NAME(RFIDTerminalType);

typedef NS_ENUM(NSInteger, RGLESignManagementAction) {
    RGLESignManagementActionUndefined = 0,
    RGLESignManagementActionCreatePIN = 1,
    RGLESignManagementActionChangePIN = 2,
    RGLESignManagementActionUnblockPIN = 3,
    RGLESignManagementActionTerminatePIN = 4,
    RGLESignManagementActionGenerateKeys = 5,
    RGLESignManagementActionTerminateKeys = 6,
    RGLESignManagementActionSignData = 7
} NS_SWIFT_NAME(ESignManagementAction);

@class RGLePassportDataGroup, RGLeIDDataGroup, RGLeDLDataGroup, RGLDocumentReaderResults;

NS_SWIFT_NAME(RFIDScenario)
@interface RGLRFIDScenario : NSObject

@property(nonatomic, assign) BOOL autoSettings;
@property(nonatomic, assign) RGLESignManagementAction signManagementAction;
@property(nonatomic, assign) int readingBuffer;
@property(nonatomic, assign) int onlineTAToSignDataType;
@property(nonatomic, assign) BOOL onlineTA;
@property(nonatomic, assign) BOOL writeEid;
@property(nonatomic, assign) RGLRFIDSdkProfilerType profilerType;
@property(nonatomic, assign) RGLRFIDAuthenticationProcedureType authProcType;
@property(nonatomic, assign) RGLRFIDAccessControlProcedureType baseSMProcedure;
@property(nonatomic, assign) RGLRFIDPasswordType pacePasswordType;
@property(nonatomic, assign) RGLRFIDTerminalType terminalType;
@property(nonatomic, assign) BOOL universalAccessRights;
@property(nonatomic, assign) BOOL authorizedRestrictedIdentification;
@property(nonatomic, assign) BOOL auxVerificationCommunityID;
@property(nonatomic, assign) BOOL auxVerificationDateOfBirth;
@property(nonatomic, assign) BOOL skipAA;
@property(nonatomic, assign) BOOL strictProcessing;
@property(nonatomic, assign) BOOL pkdDSCertPriority;
@property(nonatomic, assign) BOOL pkdUseExternalCSCA;
@property(nonatomic, assign) BOOL trustedPKD;
@property(nonatomic, assign) BOOL passiveAuth;
@property(nonatomic, assign) BOOL paceStaticBinding;
@property(nonatomic, strong, nonnull) NSString *password;
@property(nonatomic, assign) BOOL useSFI;
@property(nonatomic, strong, nonnull) NSString *pkdPA;
@property(nonatomic, strong, nonnull) NSString *pkdEAC;
@property(nonatomic, assign) BOOL readEPassport;
@property(nonatomic, assign) BOOL readEID;
@property(nonatomic, assign) BOOL readEDL;
@property(nonatomic, strong, nonnull) RGLePassportDataGroup *ePassportDataGroups;
@property(nonatomic, strong, nonnull) RGLeIDDataGroup *eIDDataGroups;
@property(nonatomic, strong, nonnull) RGLeDLDataGroup *eDLDataGroups;
@property(nonatomic, strong, nonnull) NSString *mrz;
@property(nonatomic, strong, nonnull) NSString *eSignPINDefault;
@property(nonatomic, strong, nonnull) NSString *eSignPINNewValue;
@property(nonatomic, assign) BOOL authorizedSTSignature;
@property(nonatomic, assign) BOOL authorizedSTQSignature;
@property(nonatomic, assign) BOOL authorizedWriteDG17;
@property(nonatomic, assign) BOOL authorizedWriteDG18;
@property(nonatomic, assign) BOOL authorizedWriteDG19;
@property(nonatomic, assign) BOOL authorizedWriteDG20;
@property(nonatomic, assign) BOOL authorizedWriteDG21;
@property(nonatomic, assign) BOOL authorizedVerifyAge;
@property(nonatomic, assign) BOOL authorizedVerifyCommunityID;
@property(nonatomic, assign) BOOL authorizedPrivilegedTerminal;
@property(nonatomic, assign) BOOL authorizedCANAllowed;
@property(nonatomic, assign) BOOL authorizedPINManagment;
@property(nonatomic, assign) BOOL authorizedInstallCert;
@property(nonatomic, assign) BOOL authorizedInstallQCert;
@property(nonatomic, assign) BOOL applyAmendments;

- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
- (NSDictionary *_Nonnull)rfidScenarioDictionary;
- (NSDictionary *_Nonnull)correctedDictionaryByAutosettings:(RGLDocumentReaderResults *_Nonnull)results;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
