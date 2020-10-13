#import <Foundation/Foundation.h>

typedef enum {
    RGLRFIDNotificationCodesError                        = 0x00010000,
    RGLRFIDNotificationCodesDocumentReady                = 0x00010001,
    
    RGLRFIDNotificationCodesReadProtocol4                = 0x00010003,
    RGLRFIDNotificationCodesReadProtocol3                = 0x0001000A,
    RGLRFIDNotificationCodesProgress                     = 0x0001000B,
    
    RGLRFIDNotificationCodesPaRequest                    = 0x00013000,
    
    RGLRFIDNotificationCodesTaStep                       = 0x0001000E,
    
    RGLRFIDNotificationCodesSmRequired                   = 0x0001000F,
    RGLRFIDNotificationCodesSmEtablished                 = 0x0001400F,
    
    RGLRFIDNotificationCodesISOError                     = 0x00011000,
    RGLRFIDNotificationCodesPCSCReaderDisconnected       = 0x00020000,
    RGLRFIDNotificationCodesPCSCReaderListChanged        = 0x00020001,
    RGLRFIDNotificationCodesPCSCReaderListChanging       = 0x00020008,
    
    RGLRFIDNotificationCodesPCSCBytesReceived            = 0x00020002,
    RGLRFIDNotificationCodesPCSCTotalReadingTime         = 0x00020003,
    RGLRFIDNotificationCodesPCSCDataReceived             = 0x00020004,
    RGLRFIDNotificationCodesPCSCBytesSent                = 0x00020005,
    RGLRFIDNotificationCodesPCSCTotalReadingSpeed        = 0x00020006,
    RGLRFIDNotificationCodesPCSCTotalProcessTime         = 0x00020007,
    
    RGLRFIDNotificationCodesPCSCExtLengthSupport         = 0x00020010,
    
    RGLRFIDNotificationCodesPaCertificateChain           = 0x00020011,
    RGLRFIDNotificationCodesPaCertificateChainItem       = 0x00020012,
    
    RGLRFIDNotificationCodesScenario                     = 0x00020020,
    
    RGLRFIDNotificationCodesPCSCReadingDatagroup         = 0x00030000,
    RGLRFIDNotificationCodesPCSCFileNotFound             = 0x00040000,
    RGLRFIDNotificationCodesPCSCEndOfFile                = 0x00050000,
    RGLRFIDNotificationCodesPCSCFileAccessDenied         = 0x00060000,
    RGLRFIDNotificationCodesPCSCApplicationSelected      = 0x00070000,
    RGLRFIDNotificationCodesACProcedureStart             = 0x00080000,
    RGLRFIDNotificationCodesACProcedureFinish            = 0x00090000,
    RGLRFIDNotificationCodesPASecurityObjectCheck        = 0x000A0000,
    RGLRFIDNotificationCodesPAFileCheck                  = 0x000B0000,
    RGLRFIDNotificationCodesPCSCUpdatingDatagroup        = 0x000C0000,
    RGLRFIDNotificationCodesAuxiliaryDataValidation      = 0x000D0000,
    
    RGLRFIDNotificationCodesRISectorID                   = 0x000E0000,
    
    RGLRFIDNotificationCodesBiometricsEmptyPlaceholder   = 0x000F0000
} RGLRFIDNotificationCode NS_SWIFT_NAME(RFIDNotificationCodes);

typedef NS_ENUM(NSInteger, RGLRFIDDataFileType) {
    RGLRFIDDataFileTypeUnspecified                 = 0,
    RGLRFIDDataFileTypePassportDG1                 = 1,
    RGLRFIDDataFileTypePassportDG2                 = 2,
    RGLRFIDDataFileTypePassportDG3                 = 3,
    RGLRFIDDataFileTypePassportDG4                 = 4,
    RGLRFIDDataFileTypePassportDG5                 = 5,
    RGLRFIDDataFileTypePassportDG6                 = 6,
    RGLRFIDDataFileTypePassportDG7                 = 7,
    RGLRFIDDataFileTypePassportDG8                 = 8,
    RGLRFIDDataFileTypePassportDG9                 = 9,
    RGLRFIDDataFileTypePassportDG10                = 10,
    RGLRFIDDataFileTypePassportDG11                = 11,
    RGLRFIDDataFileTypePassportDG12                = 12,
    RGLRFIDDataFileTypePassportDG13                = 13,
    RGLRFIDDataFileTypePassportDG14                = 14,
    RGLRFIDDataFileTypePassportDG15                = 15,
    RGLRFIDDataFileTypePassportDG16                = 16,
    RGLRFIDDataFileTypePassportDG17                = 17,
    RGLRFIDDataFileTypePassportDG18                = 18,
    RGLRFIDDataFileTypePassportDG19                = 19,
    RGLRFIDDataFileTypePassportDG20                = 20,
    RGLRFIDDataFileTypePassportSOD                 = 21,
    RGLRFIDDataFileTypePassportCVCA                = 22,
    RGLRFIDDataFileTypePassportCOM                 = 23,
    RGLRFIDDataFileTypeIDDG1                       = 101,
    RGLRFIDDataFileTypeIDDG2                       = 102,
    RGLRFIDDataFileTypeIDDG3                       = 103,
    RGLRFIDDataFileTypeIDDG4                       = 104,
    RGLRFIDDataFileTypeIDDG5                       = 105,
    RGLRFIDDataFileTypeIDDG6                       = 106,
    RGLRFIDDataFileTypeIDDG7                       = 107,
    RGLRFIDDataFileTypeIDDG8                       = 108,
    RGLRFIDDataFileTypeIDDG9                       = 109,
    RGLRFIDDataFileTypeIDDG10                      = 110,
    RGLRFIDDataFileTypeIDDG11                      = 111,
    RGLRFIDDataFileTypeIDDG12                      = 112,
    RGLRFIDDataFileTypeIDDG13                      = 113,
    RGLRFIDDataFileTypeIDDG14                      = 114,
    RGLRFIDDataFileTypeIDDG15                      = 115,
    RGLRFIDDataFileTypeIDDG16                      = 116,
    RGLRFIDDataFileTypeIDDG17                      = 117,
    RGLRFIDDataFileTypeIDDG18                      = 118,
    RGLRFIDDataFileTypeIDDG19                      = 119,
    RGLRFIDDataFileTypeIDDG20                      = 120,
    RGLRFIDDataFileTypeIDDG21                      = 121,
    RGLRFIDDataFileTypeDLCOM                       = 150,
    RGLRFIDDataFileTypeDLDG1                       = 151,
    RGLRFIDDataFileTypeDLDG2                       = 152,
    RGLRFIDDataFileTypeDLDG3                       = 153,
    RGLRFIDDataFileTypeDLDG4                       = 154,
    RGLRFIDDataFileTypeDLDG5                       = 155,
    RGLRFIDDataFileTypeDLDG6                       = 156,
    RGLRFIDDataFileTypeDLDG7                       = 157,
    RGLRFIDDataFileTypeDLDG8                       = 158,
    RGLRFIDDataFileTypeDLDG9                       = 159,
    RGLRFIDDataFileTypeDLDG10                      = 160,
    RGLRFIDDataFileTypeDLDG11                      = 161,
    RGLRFIDDataFileTypeDLDG12                      = 162,
    RGLRFIDDataFileTypeDLDG13                      = 163,
    RGLRFIDDataFileTypeDLDG14                      = 164,
    RGLRFIDDataFileTypeDLSOD                       = 165,
    RGLRFIDDataFileTypeDLCE                        = 166,
    RGLRFIDDataFileTypeDLCVCA                      = 167,
    RGLRFIDDataFileTypePACECardAccess              = 200,
    RGLRFIDDataFileTypePACECardSecurity            = 201,
    RGLRFIDDataFileTypePACEChipSecurity            = 202,
    RGLRFIDDataFileTypeMIFAREData                  = 300,
    RGLRFIDDataFileTypeMIFAREValidity              = 301,
    RGLRFIDDataFileTypeAuthenticityV2              = 302,
    RGLRFIDDataFileTypeATR                         = 400,
    RGLRFIDDataFileTypeESignPK                     = 500,
    RGLRFIDDataFileTypeESignSignedData             = 501,
    RGLRFIDDataFileTypeCertificate                 = 600,
    RGLRFIDDataFileTypeMasterList                  = 601,
    RGLRFIDDataFileTypeDefectList                  = 602,
    RGLRFIDDataFileTypeDeviationList               = 603,
    RGLRFIDDataFileTypeAppDirectory                = 700,
    RGLRFIDDataFileTypeSession                     = 701,
    RGLRFIDDataFileTypeLogData                     = 702,
    RGLRFIDDataFileTypeChipProperties              = 703,
    RGLRFIDDataFileTypeUserDefined                 = 1000
} NS_SWIFT_NAME(RFIDDataFileType);

typedef enum {
    RGLRFIDErrorCodesNoError                          = 0x00000001,
    RGLRFIDErrorCodesAlreadyDone                      = 0x00000002,
    
    RGLRFIDErrorCodesFailed                           = 0xffffffff,
    
    //  RFID_Error_GraphManager                     = 0x80010000,
    RGLRFIDErrorCodesNoChipDetected                   = 0x80010001,
    RGLRFIDErrorCodesNotAvailable                     = 0x80010002,
    
    RGLRFIDErrorCodesInvalidParameter                 = 0x80010004,
    RGLRFIDErrorCodesNotInitialized                   = 0x80010005,
    RGLRFIDErrorCodesNotEnoughMemory                  = 0x80010006,
    RGLRFIDErrorCodesInvalidDirectory                 = 0x80010008,
    RGLRFIDErrorCodesUnknownCommand                   = 0x80010009,
    RGLRFIDErrorCodesFileIOError                      = 0x8001000A,
    RGLRFIDErrorCodesBusy                             = 0x8001000B,
    RGLRFIDErrorCodesOldFirmware                      = 0x8001000C,
    
    RGLRFIDErrorCodesPCSCFailed                      = 0x80020000,
    RGLRFIDErrorCodesPCSCReaderNotAvailable          = 0x80020001,
    RGLRFIDErrorCodesPCSCCantConnectCard             = 0x80020002,
    RGLRFIDErrorCodesPCSCCardIsNotConnected          = 0x80020003,
    RGLRFIDErrorCodesPCSCOperationCancelled          = 0x80020004,
    RGLRFIDErrorCodesPCSCCardIsBusy                  = 0x80020005,
    RGLRFIDErrorCodesPCSCFailedSCard                 = 0x80020006,
    RGLRFIDErrorCodesPCSCExtLeFailed                 = 0x80020010,
    
    RGLRFIDErrorCodesLayer6SecurityManager              = 0x86000000,
    
    RGLRFIDErrorCodesLayer6AppSelectionFailure          = 0x86000001,
    
    RGLRFIDErrorCodesLayer6MutualAuthMacFail            = 0x86000100,
    RGLRFIDErrorCodesLayer6MutualAuthEncFail            = 0x86000101,
    RGLRFIDErrorCodesLayer6MutualAuthFailure            = 0x86000102,
    RGLRFIDErrorCodesLayer6MutualAuthFailureData        = 0x86000103,
    
    RGLRFIDErrorCodesLayer6SmDo8eMissing                 = 0x86000200,
    RGLRFIDErrorCodesLayer6SmDo87Missing                 = 0x86000201,
    RGLRFIDErrorCodesLayer6SmDo99Missing                 = 0x86000202,
    RGLRFIDErrorCodesLayer6SmMacIncorrect                = 0x86000203,
    RGLRFIDErrorCodesLayer6SmDo87Incorrect               = 0x86000204,
    //RFID_LAYER6_SM_DO85_TLV_INCORRECT           = 0x8600000A,
    
    RGLRFIDErrorCodesLayer6NonTlvResponseData           = 0x86000300,
    RGLRFIDErrorCodesLayer6WrongRndIccLength            = 0x86000301,
    RGLRFIDErrorCodesLayer6IntAuthFailure               = 0x86000302,
    RGLRFIDErrorCodesLayer6MseSetKatFailure             = 0x86000303,
    RGLRFIDErrorCodesLayer6MseSetDstFailure             = 0x86000304,
    RGLRFIDErrorCodesLayer6PsoCertificateFailure        = 0x86000305,
    RGLRFIDErrorCodesLayer6MseSetAtFailure              = 0x86000306,
    RGLRFIDErrorCodesLayer6GetChallengeFailure          = 0x86000307,
    RGLRFIDErrorCodesLayer6ExtAuthFailure               = 0x86000308,
    
    RGLRFIDErrorCodesLayer6GeneralAuthFailure           = 0x86000309,
    
    RGLRFIDErrorCodesLayer6FileNotFound                 = 0x80006A82,
    RGLRFIDErrorCodesLayer6FileEof1                     = 0x80006282,
    RGLRFIDErrorCodesLayer6FileEof2                     = 0x80006B00,
    
    RGLRFIDErrorCodesLayer6IncorrectParams              = 0x80006A80,

    RGLRFIDErrorCodesLayer6NoReferenceData              = 0x80006A88,
    
    RGLRFIDErrorCodesLayer6PwdSuspend                   = 0x800063C1,
    RGLRFIDErrorCodesLayer6PwdBlocked                   = 0x800063C0,
    RGLRFIDErrorCodesLayer6PwdDeactivated               = 0x80006283,
    
    RGLRFIDErrorCodesLayer6PwdBlocked2                  = 0x80006983,
    RGLRFIDErrorCodesLayer6PwdDeactivated2              = 0x80006984,

    RGLRFIDErrorCodesLayer6PwdSuspend2                  = 0x80006985,
    
    RGLRFIDErrorCodesLayer6PwdFailed                    = 0x801063C0,
    
    RGLRFIDErrorCodesNotPerformed                          = 0x83000000,
    RGLRFIDErrorCodesSessionIsClosed                       = 0x83000001,
    RGLRFIDErrorCodesSessionTerminalUnsupportedOperation   = 0x83000002,
    
    RGLRFIDErrorCodesSessionTerminalTypeUnknown            = 0x83000010,
    RGLRFIDErrorCodesSessionTerminalTypeBadCertificate     = 0x83000011,
    
    RGLRFIDErrorCodesSessionTerminalTypeNotSet             = 0x83000012,
    
    RGLRFIDErrorCodesSessionProcedureTypeUnknown           = 0x83000013,
    RGLRFIDErrorCodesessionProcedureTypeUnsupported        = 0x83000014,
    
    RGLRFIDErrorCodesSessionProcedureTypeNotSet            = 0x83000015,
    
    RGLRFIDErrorCodesSessionAccessKeyUnknownType           = 0x83000016,
    RGLRFIDErrorCodesSessionAccessKeyUnsupportedSMType     = 0x83000017,
    RGLRFIDErrorCodesSessionAccessKeyIncorrectSMType       = 0x83000018,
    RGLRFIDErrorCodesSession_AccessKey_Restricted          = 0x83000019,
    RGLRFIDErrorCodesSessionAccessKeyIncorrectData         = 0x8300001A,
    
    RGLRFIDErrorCodesSessionAccessKeyNotSet                = 0x8300001B,
    
    RGLRFIDErrorCodesSessionPwdManagementNotAuthorized     = 0x8300001C,
    
    RGLRFIDErrorCodesSessionAccessControlUnknownType       = 0x83000020,
    RGLRFIDErrorCodesSessionAccessControlRequiresSM        = 0x83000021,
    RGLRFIDErrorCodesSessionAccessControlRequiresPACE      = 0x83000022,
    RGLRFIDErrorCodesSessionAccessControlRequiresCAKeys    = 0x83000023,
    RGLRFIDErrorCodesSessionAccessControlRequiresTA        = 0x83000024,
    RGLRFIDErrorCodesSessionAccessControlRequiresCA        = 0x83000025,
    
    RGLRFIDErrorCodesSessionAccessControlIncorrectOptionCA = 0x83000026,
    
    RGLRFIDErrorCodesSessionAccessControlCaFailed         = 0x83000027,
    RGLRFIDErrorCodesSessionAccessControlTaFailed         = 0x83000028,
    RGLRFIDErrorCodesSessionAccessControlAaFailed         = 0x83000029,
    RGLRFIDErrorCodesSessionAccessControlRiFailed         = 0x8300002A,
    
    RGLRFIDErrorCodesSessionPaSignatureCheckFailed         = 0x83000030,
    RGLRFIDErrorCodesSessionPaHashCheckFailed              = 0x83000031,
    
    RGLRFIDErrorCodesSessionInvalidAuxDataDateOfExpiry     = 0x83000040,
    RGLRFIDErrorCodesSessionInvalidAuxDataDateOfBirth      = 0x83000041,
    RGLRFIDErrorCodesSessionInvalidAuxDataCommunityID      = 0x83000042,
    
    RGLRFIDErrorCodesSessionESignRequiresAppSelection      = 0x83000050,
    RGLRFIDErrorCodesSessionESignPinNotSet                 = 0x83000051,
    RGLRFIDErrorCodesSessionESignPinNotVerified            = 0x83000052,
    
    RGLRFIDErrorCodesSessionIncorrectData                  = 0x83000060,
    
    RGLRFIDErrorCodesSessionFileNotEnoughData              = 0x83010000,
    RGLRFIDErrorCodesSessionFileIncorrectData              = 0x83020000,
    RGLRFIDErrorCodesSessionFileUnexpectedData             = 0x83030000,
    RGLRFIDErrorCodesSessionFileContentsUnexpectedData     = 0x83040000,
    RGLRFIDErrorCodesSessionFileWrongTag                   = 0x83050000,
    RGLRFIDErrorCodesSessionFileCantUseData                = 0x83060000,
    RGLRFIDErrorCodesSessionFileCantReadData               = 0x83070000,
    RGLRFIDErrorCodesSessionFileAccessDenied               = 0x83080000,
    
    RGLRFIDErrorCodesLayer34NoError                         = 0x84000000,
    RGLRFIDErrorCodesLayer34TimeOut                         = 0x84010000,
    RGLRFIDErrorCodesLayer34Collision                       = 0x84020000,
    RGLRFIDErrorCodesLayer34CRC                             = 0x84030000,
    RGLRFIDErrorCodesLayer34DataIntegrity                   = 0x84040000,
    RGLRFIDErrorCodesLayer34DataLength                      = 0x84050000,
    RGLRFIDErrorCodesLayer34RFU                             = 0x84060000,
    RGLRFIDErrorCodesLayer34CollisionTooMany                = 0x84070000,
    RGLRFIDErrorCodesLayer34ProtocolB                       = 0x84080000,
    RGLRFIDErrorCodesLayer34DataContents                    = 0x84090000,
    RGLRFIDErrorCodesLayer34Protocol                        = 0x840A0000,
    RGLRFIDErrorCodesLayer34GlobalTimeOut                   = 0x840B0000,
    RGLRFIDErrorCodesLayer34MifareAuth                      = 0x840C0000
} RGLRFIDErrorCodes NS_SWIFT_NAME(RFIDErrorCodes);

typedef NS_ENUM(NSInteger, RGLRFIDCertificateType) {
  RGLRFIDCertificateTypeUndefined  = 0,
  RGLRFIDCertificateTypeCSCA       = 1,
  RGLRFIDCertificateTypeCSCALink   = 2,
  RGLRFIDCertificateTypeDS         = 3,
  RGLRFIDCertificateTypeMLS        = 4,
  RGLRFIDCertificateTypeDevLS      = 5,
  RGLRFIDCertificateTypeDefLS      = 6
} NS_SWIFT_NAME(RFIDCertificateType);

NS_SWIFT_NAME(RFIDNotify)
@interface RGLRFIDNotify: NSObject

@property(nonatomic, assign, readonly) RGLRFIDNotificationCode code;
@property(nonatomic, assign, readonly) double value;
@property(nonatomic, assign, readonly) UInt32 number;

- (instancetype)initWithCode:(UInt32)code value:(UInt32)value;

+ (NSString *)rfidDataFileTypeName:(RGLRFIDDataFileType)type;
+ (NSString *)rfidErrorCodesName:(RGLRFIDErrorCodes)errorCode;

@end
