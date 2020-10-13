#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, RGLBarcodeResult) {
  RGLBarcodeResultNoErr                                 = 0,
  RGLBarcodeResultNullPtrErr                            = -6001,
  RGLBarcodeResultBadArgErr                             = -6002,
  RGLBarcodeResultSizeErr                               = -6003,
  RGLBarcodeResultRangeErr                              = -6004,
  RGLBarcodeResultInternalErr                           = -6005,
  RGLBarcodeResultTryExceptErr                          = -6006,
  RGLBarcodeResultBarCodeNotFound                       = -6008,
  RGLBarcodeResultBarCodeDecodeErr                      = -6010,
  RGLBarcodeResultNoUserDLLFound                        = -6019,
  RGLBarcodeResultNoIPPDLLFound                         = -6020,
  RGLBarcodeResultIppExecErr                            = -6024,
  RGLBarcodeResultIppTryExceptErr                       = -6025,
  RGLBarcodeResultBARCODE_ERROR_Inputparam              = -11001,
  RGLBarcodeResultBARCODE_ERROR_FInit                   = -11006,
  RGLBarcodeResultBARCODE_ERROR_NotLoadIpDecodedll      = -11012,
  RGLBarcodeResultBARCODE_ERROR_InnerProblem            = -11100,
  RGLBarcodeResultBARCODE_ERROR_Decode_1D_BadDecode     = -11200,
  RGLBarcodeResultBARCODE_ERROR_FindRowOrColumn         = -11201,
  RGLBarcodeResultBARCODE_ERROR_Find3X8_2D_X            = -11202,
  RGLBarcodeResultBARCODE_ERROR_Find3X8_2D_Y            = -11203,
  RGLBarcodeResultBARCODE_ERROR_2D_UgolMax              = -11204,
  RGLBarcodeResultBARCODE_ERROR_INDEFINITELY_DECODED    = -11210,
  RGLBarcodeResultBARCODE_ERROR_Dllnotinit              = -11300,
  RGLBarcodeResultBARCODE_ERROR_IPDECODE_DLL_Try_Except = -11400,
  RGLBarcodeResultIPDECODE_ERROR_LARGEERRORS            = -4503,
  RGLBarcodeResultIPDECODE_ERROR_FAULTCOLUMNS           = -4504,
  RGLBarcodeResultIPDECODE_ERROR_FAULTROWS              = -4505,
  RGLBarcodeResultIPDECODE_ERROR_INCORRECT_ERROR_LEVEL  = -4511,
  RGLBarcodeResultIPDECODE_ERROR_LOADING_DEV_TABLE      = -4512
} NS_SWIFT_NAME(BarcodeResult);

@class RGLDocumentReaderBarcodeField;

NS_SWIFT_NAME(DocumentReaderBarcodeResult)
@interface RGLDocumentReaderBarcodeResult : NSObject

@property(nonatomic, strong, readonly, nullable) NSArray <RGLDocumentReaderBarcodeField *> *fields;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithFields:(NSArray <RGLDocumentReaderBarcodeField *> *_Nonnull)fields;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
