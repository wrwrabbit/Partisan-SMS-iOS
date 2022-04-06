#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class P_smsKotlinThrowable, P_smsKotlinArray<T>, P_smsKotlinException, P_smsMessage, P_smsMetaInfo, P_smsKotlinByteArray, P_smsMode, P_smsNotAlignedEncoderCode, P_smsNotAlignedEncoder, P_smsKotlinStringBuilder, P_smsShortEncoder, P_smsHuffmanEncoder, P_smsKotlinEnum<E>, P_smsScheme, P_smsDecodeResult, P_smsEncodeResult, P_smsBignumBigInteger, P_smsTextEncoder, P_smsWordsSubEncoder, P_smsKotlinByteIterator, P_smsKotlinCharArray, P_smsKotlinPair<__covariant A, __covariant B>, P_smsBignumBigIntegerQuotientAndRemainder, P_smsBignumBigIntegerBigIntegerRange, P_smsBignumBigIntegerSqareRootAndRemainder, P_smsBignumModularBigInteger, P_smsKotlinCharIterator, P_smsBignumModularQuotientAndRemainder;

@protocol P_smsPlainDataEncoderFactory, P_smsEncryptedDataEncoderFactory, P_smsEncryptor, P_smsPlainDataEncoder, P_smsKotlinComparable, P_smsEncryptedDataEncoder, P_smsSubEncoder, P_smsKotlinIterator, P_smsKotlinCharSequence, P_smsKotlinAppendable, P_smsBignumBigNumber, P_smsBignumBigNumberCreator, P_smsBignumBitwiseCapable, P_smsBignumByteArraySerializable, P_smsKotlinClosedRange, P_smsKotlinIterable;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

__attribute__((swift_name("KotlinBase")))
@interface P_smsBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end;

@interface P_smsBase (P_smsBaseCopying) <NSCopying>
@end;

__attribute__((swift_name("KotlinMutableSet")))
@interface P_smsMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end;

__attribute__((swift_name("KotlinMutableDictionary")))
@interface P_smsMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end;

@interface NSError (NSErrorP_smsKotlinException)
@property (readonly) id _Nullable kotlinException;
@end;

__attribute__((swift_name("KotlinNumber")))
@interface P_smsNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end;

__attribute__((swift_name("KotlinByte")))
@interface P_smsByte : P_smsNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end;

__attribute__((swift_name("KotlinUByte")))
@interface P_smsUByte : P_smsNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end;

__attribute__((swift_name("KotlinShort")))
@interface P_smsShort : P_smsNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end;

__attribute__((swift_name("KotlinUShort")))
@interface P_smsUShort : P_smsNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end;

__attribute__((swift_name("KotlinInt")))
@interface P_smsInt : P_smsNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end;

__attribute__((swift_name("KotlinUInt")))
@interface P_smsUInt : P_smsNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end;

__attribute__((swift_name("KotlinLong")))
@interface P_smsLong : P_smsNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end;

__attribute__((swift_name("KotlinULong")))
@interface P_smsULong : P_smsNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end;

__attribute__((swift_name("KotlinFloat")))
@interface P_smsFloat : P_smsNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end;

__attribute__((swift_name("KotlinDouble")))
@interface P_smsDouble : P_smsNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end;

__attribute__((swift_name("KotlinBoolean")))
@interface P_smsBoolean : P_smsNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end;

__attribute__((swift_name("KotlinThrowable")))
@interface P_smsKotlinThrowable : P_smsBase
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(P_smsKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(P_smsKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (P_smsKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) P_smsKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
@end;

__attribute__((swift_name("KotlinException")))
@interface P_smsKotlinException : P_smsKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(P_smsKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(P_smsKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InvalidDataException")))
@interface P_smsInvalidDataException : P_smsKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(P_smsKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(P_smsKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InvalidVersionException")))
@interface P_smsInvalidVersionException : P_smsKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(P_smsKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(P_smsKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Message")))
@interface P_smsMessage : P_smsBase
- (instancetype)initWithText:(NSString *)text channelId:(P_smsInt * _Nullable)channelId __attribute__((swift_name("init(text:channelId:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (P_smsInt * _Nullable)component2 __attribute__((swift_name("component2()")));
- (P_smsMessage *)doCopyText:(NSString *)text channelId:(P_smsInt * _Nullable)channelId __attribute__((swift_name("doCopy(text:channelId:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) P_smsInt * _Nullable channelId __attribute__((swift_name("channelId")));
@property (readonly) NSString *text __attribute__((swift_name("text")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MetaInfo")))
@interface P_smsMetaInfo : P_smsBase
- (instancetype)initWithMode:(int32_t)mode version:(int32_t)version isChannel:(BOOL)isChannel __attribute__((swift_name("init(mode:version:isChannel:)"))) __attribute__((objc_designated_initializer));
- (int8_t)toByte __attribute__((swift_name("toByte()")));
@property (readonly) BOOL isChannel __attribute__((swift_name("isChannel")));
@property (readonly) int32_t mode __attribute__((swift_name("mode")));
@property (readonly) int32_t version __attribute__((swift_name("version")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MetaInfo.Companion")))
@interface P_smsMetaInfoCompanion : P_smsBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (P_smsMetaInfo *)parseMetaInfoByte:(int8_t)metaInfoByte __attribute__((swift_name("parse(metaInfoByte:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PSmsEncryptor")))
@interface P_smsPSmsEncryptor : P_smsBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithPlainDataEncoderFactory:(id<P_smsPlainDataEncoderFactory>)plainDataEncoderFactory encryptedDataEncoderFactory:(id<P_smsEncryptedDataEncoderFactory>)encryptedDataEncoderFactory encryptor:(id<P_smsEncryptor>)encryptor __attribute__((swift_name("init(plainDataEncoderFactory:encryptedDataEncoderFactory:encryptor:)"))) __attribute__((objc_designated_initializer));
- (P_smsMessage *)decodeStr:(NSString *)str key:(P_smsKotlinByteArray *)key encryptionSchemeId:(int32_t)encryptionSchemeId __attribute__((swift_name("decode(str:key:encryptionSchemeId:)")));
- (NSString *)encodeMessage:(P_smsMessage *)message key:(P_smsKotlinByteArray *)key encryptionSchemeId:(int32_t)encryptionSchemeId __attribute__((swift_name("encode(message:key:encryptionSchemeId:)")));
- (NSString *)encodeMessage:(P_smsMessage *)message key:(P_smsKotlinByteArray *)key encryptionSchemeId:(int32_t)encryptionSchemeId plainDataEncoderMode:(P_smsMode *)plainDataEncoderMode __attribute__((swift_name("encode(message:key:encryptionSchemeId:plainDataEncoderMode:)")));
- (NSString *)encodeMessage:(P_smsMessage *)message key:(P_smsKotlinByteArray *)key encryptionSchemeId:(int32_t)encryptionSchemeId plainDataEncoder:(id<P_smsPlainDataEncoder>)plainDataEncoder __attribute__((swift_name("encode(message:key:encryptionSchemeId:plainDataEncoder:)")));
- (NSString *)encodeMessage:(P_smsMessage *)message key:(P_smsKotlinByteArray *)key encryptionSchemeId:(int32_t)encryptionSchemeId plainDataEncoderMode_:(int32_t)plainDataEncoderMode __attribute__((swift_name("encode(message:key:encryptionSchemeId:plainDataEncoderMode_:)")));
- (BOOL)isEncryptedStr:(NSString *)str key:(P_smsKotlinByteArray *)key __attribute__((swift_name("isEncrypted(str:key:)")));
- (P_smsMessage *)tryDecodeStr:(NSString *)str key:(P_smsKotlinByteArray *)key __attribute__((swift_name("tryDecode(str:key:)")));
@end;

__attribute__((swift_name("Encryptor")))
@protocol P_smsEncryptor
@required
- (P_smsKotlinByteArray *)decryptKey:(P_smsKotlinByteArray *)key encryptedData:(P_smsKotlinByteArray *)encryptedData __attribute__((swift_name("decrypt(key:encryptedData:)")));
- (P_smsKotlinByteArray *)encryptKey:(P_smsKotlinByteArray *)key plainData:(P_smsKotlinByteArray *)plainData __attribute__((swift_name("encrypt(key:plainData:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AesEncryptor")))
@interface P_smsAesEncryptor : P_smsBase <P_smsEncryptor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (P_smsKotlinByteArray *)decryptKey:(P_smsKotlinByteArray *)key encryptedData:(P_smsKotlinByteArray *)encryptedData __attribute__((swift_name("decrypt(key:encryptedData:)")));
- (P_smsKotlinByteArray *)encryptKey:(P_smsKotlinByteArray *)key plainData:(P_smsKotlinByteArray *)plainData __attribute__((swift_name("encrypt(key:plainData:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InvalidKeyException")))
@interface P_smsInvalidKeyException : P_smsKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(P_smsKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(P_smsKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end;

__attribute__((swift_name("PlainDataEncoder")))
@protocol P_smsPlainDataEncoder
@required
- (NSString *)decodeData:(P_smsKotlinByteArray *)data __attribute__((swift_name("decode(data:)")));
- (P_smsKotlinByteArray *)encodeS:(NSString *)s __attribute__((swift_name("encode(s:)")));
- (int32_t)getMode __attribute__((swift_name("getMode()")));
@end;

__attribute__((swift_name("NotAlignedEncoder")))
@interface P_smsNotAlignedEncoder : P_smsBase <P_smsPlainDataEncoder>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)beforeDecode __attribute__((swift_name("beforeDecode()")));
- (NSString *)decodeData:(P_smsKotlinByteArray *)data __attribute__((swift_name("decode(data:)")));
- (P_smsKotlinByteArray *)encodeS:(NSString *)s __attribute__((swift_name("encode(s:)")));
- (P_smsNotAlignedEncoderCode *)encodeCharChar:(unichar)char_ __attribute__((swift_name("encodeChar(char:)")));
- (NSString *)getDecodedString __attribute__((swift_name("getDecodedString()")));
- (void)processDecodingValueValue:(int32_t)value __attribute__((swift_name("processDecodingValue(value:)")));
@property (readonly) int32_t decodingShifting __attribute__((swift_name("decodingShifting")));
@end;

__attribute__((swift_name("ShortEncoder")))
@interface P_smsShortEncoder : P_smsNotAlignedEncoder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)beforeDecode __attribute__((swift_name("beforeDecode()")));
- (unichar)decodeCharCode:(int32_t)code __attribute__((swift_name("decodeChar(code:)")));
- (NSString *)getDecodedString __attribute__((swift_name("getDecodedString()")));
- (void)processDecodingValueValue:(int32_t)value __attribute__((swift_name("processDecodingValue(value:)")));
@property (readonly) int32_t decodingShifting __attribute__((swift_name("decodingShifting")));
@property P_smsKotlinStringBuilder * _Nullable stringBuilder __attribute__((swift_name("stringBuilder")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ascii")))
@interface P_smsAscii : P_smsShortEncoder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (unichar)decodeCharCode:(int32_t)code __attribute__((swift_name("decodeChar(code:)")));
- (P_smsNotAlignedEncoderCode *)encodeCharChar:(unichar)char_ __attribute__((swift_name("encodeChar(char:)")));
- (int32_t)getMode __attribute__((swift_name("getMode()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Cp1251")))
@interface P_smsCp1251 : P_smsBase <P_smsPlainDataEncoder>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString *)decodeData:(P_smsKotlinByteArray *)data __attribute__((swift_name("decode(data:)")));
- (P_smsKotlinByteArray *)encodeS:(NSString *)s __attribute__((swift_name("encode(s:)")));
- (int32_t)getMode __attribute__((swift_name("getMode()")));
@end;

__attribute__((swift_name("HuffmanEncoder")))
@interface P_smsHuffmanEncoder : P_smsNotAlignedEncoder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)beforeDecode __attribute__((swift_name("beforeDecode()")));
- (P_smsNotAlignedEncoderCode *)encodeCharChar:(unichar)char_ __attribute__((swift_name("encodeChar(char:)")));
- (NSString *)getDecodedString __attribute__((swift_name("getDecodedString()")));
- (void)processDecodingValueValue:(int32_t)value __attribute__((swift_name("processDecodingValue(value:)")));
@property (readonly) NSDictionary<id, P_smsNotAlignedEncoderCode *> *charToCode __attribute__((swift_name("charToCode")));
@property (readonly) int32_t decodingShifting __attribute__((swift_name("decodingShifting")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HuffmanCyrillic")))
@interface P_smsHuffmanCyrillic : P_smsHuffmanEncoder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (int32_t)getMode __attribute__((swift_name("getMode()")));
@property (readonly) NSDictionary<id, P_smsNotAlignedEncoderCode *> *charToCode __attribute__((swift_name("charToCode")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HuffmanLatin")))
@interface P_smsHuffmanLatin : P_smsHuffmanEncoder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (int32_t)getMode __attribute__((swift_name("getMode()")));
@property (readonly) NSDictionary<id, P_smsNotAlignedEncoderCode *> *charToCode __attribute__((swift_name("charToCode")));
@end;

__attribute__((swift_name("KotlinComparable")))
@protocol P_smsKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end;

__attribute__((swift_name("KotlinEnum")))
@interface P_smsKotlinEnum<E> : P_smsBase <P_smsKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Mode")))
@interface P_smsMode : P_smsKotlinEnum<P_smsMode *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) P_smsMode *shortCp1251PreferCyrillic __attribute__((swift_name("shortCp1251PreferCyrillic")));
@property (class, readonly) P_smsMode *shortCp1251PreferLatin __attribute__((swift_name("shortCp1251PreferLatin")));
@property (class, readonly) P_smsMode *cp1251 __attribute__((swift_name("cp1251")));
@property (class, readonly) P_smsMode *utf8 __attribute__((swift_name("utf8")));
@property (class, readonly) P_smsMode *ascii __attribute__((swift_name("ascii")));
@property (class, readonly) P_smsMode *huffmanCyrillic __attribute__((swift_name("huffmanCyrillic")));
@property (class, readonly) P_smsMode *huffmanLatin __attribute__((swift_name("huffmanLatin")));
+ (P_smsKotlinArray<P_smsMode *> *)values __attribute__((swift_name("values()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NotAlignedEncoder.Code")))
@interface P_smsNotAlignedEncoderCode : P_smsBase
- (instancetype)initWithValue:(int32_t)value size:(int32_t)size __attribute__((swift_name("init(value:size:)"))) __attribute__((objc_designated_initializer));
- (int32_t)component1 __attribute__((swift_name("component1()")));
- (int32_t)component2 __attribute__((swift_name("component2()")));
- (P_smsNotAlignedEncoderCode *)doCopyValue:(int32_t)value size:(int32_t)size __attribute__((swift_name("doCopy(value:size:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property int32_t size __attribute__((swift_name("size")));
@property int32_t value __attribute__((swift_name("value")));
@end;

__attribute__((swift_name("PlainDataEncoderFactory")))
@protocol P_smsPlainDataEncoderFactory
@required
- (id<P_smsPlainDataEncoder>)createMode:(P_smsMode *)mode __attribute__((swift_name("create(mode:)")));
- (id<P_smsPlainDataEncoder>)createMode_:(int32_t)mode __attribute__((swift_name("create(mode_:)")));
- (id<P_smsPlainDataEncoder>)createBestEncoderS:(NSString *)s __attribute__((swift_name("createBestEncoder(s:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlainDataEncoderFactoryImpl")))
@interface P_smsPlainDataEncoderFactoryImpl : P_smsBase <P_smsPlainDataEncoderFactory>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id<P_smsPlainDataEncoder>)createMode:(P_smsMode *)mode __attribute__((swift_name("create(mode:)")));
- (id<P_smsPlainDataEncoder>)createMode_:(int32_t)mode __attribute__((swift_name("create(mode_:)")));
- (id<P_smsPlainDataEncoder>)createBestEncoderS:(NSString *)s __attribute__((swift_name("createBestEncoder(s:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ShortCp1251Cyrillic")))
@interface P_smsShortCp1251Cyrillic : P_smsShortEncoder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (unichar)decodeCharCode:(int32_t)code __attribute__((swift_name("decodeChar(code:)")));
- (P_smsNotAlignedEncoderCode *)encodeCharChar:(unichar)char_ __attribute__((swift_name("encodeChar(char:)")));
- (int32_t)getMode __attribute__((swift_name("getMode()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ShortCp1251Latin")))
@interface P_smsShortCp1251Latin : P_smsShortEncoder
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (unichar)decodeCharCode:(int32_t)code __attribute__((swift_name("decodeChar(code:)")));
- (P_smsNotAlignedEncoderCode *)encodeCharChar:(unichar)char_ __attribute__((swift_name("encodeChar(char:)")));
- (int32_t)getMode __attribute__((swift_name("getMode()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Utf8")))
@interface P_smsUtf8 : P_smsBase <P_smsPlainDataEncoder>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString *)decodeData:(P_smsKotlinByteArray *)data __attribute__((swift_name("decode(data:)")));
- (P_smsKotlinByteArray *)encodeS:(NSString *)s __attribute__((swift_name("encode(s:)")));
- (int32_t)getMode __attribute__((swift_name("getMode()")));
@end;

__attribute__((swift_name("EncryptedDataEncoder")))
@protocol P_smsEncryptedDataEncoder
@required
- (P_smsKotlinByteArray *)decodeStr:(NSString *)str __attribute__((swift_name("decode(str:)")));
- (NSString *)encodeData:(P_smsKotlinByteArray *)data __attribute__((swift_name("encode(data:)")));
- (BOOL)hasFrontPadding __attribute__((swift_name("hasFrontPadding()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Base64")))
@interface P_smsBase64 : P_smsBase <P_smsEncryptedDataEncoder>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (P_smsKotlinByteArray *)decodeStr:(NSString *)str __attribute__((swift_name("decode(str:)")));
- (NSString *)encodeData:(P_smsKotlinByteArray *)data __attribute__((swift_name("encode(data:)")));
- (BOOL)hasFrontPadding __attribute__((swift_name("hasFrontPadding()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CyrillicBase64")))
@interface P_smsCyrillicBase64 : P_smsBase <P_smsEncryptedDataEncoder>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (P_smsKotlinByteArray *)decodeStr:(NSString *)str __attribute__((swift_name("decode(str:)")));
- (NSString *)encodeData:(P_smsKotlinByteArray *)data __attribute__((swift_name("encode(data:)")));
- (BOOL)hasFrontPadding __attribute__((swift_name("hasFrontPadding()")));
@end;

__attribute__((swift_name("EncryptedDataEncoderFactory")))
@protocol P_smsEncryptedDataEncoderFactory
@required
- (id<P_smsEncryptedDataEncoder>)createSchemeId:(int32_t)schemeId __attribute__((swift_name("create(schemeId:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EncryptedDataEncoderFactoryImpl")))
@interface P_smsEncryptedDataEncoderFactoryImpl : P_smsBase <P_smsEncryptedDataEncoderFactory>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id<P_smsEncryptedDataEncoder>)createSchemeId:(int32_t)schemeId __attribute__((swift_name("create(schemeId:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Scheme")))
@interface P_smsScheme : P_smsKotlinEnum<P_smsScheme *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) P_smsScheme *base64 __attribute__((swift_name("base64")));
@property (class, readonly) P_smsScheme *cyrillicBase64 __attribute__((swift_name("cyrillicBase64")));
@property (class, readonly) P_smsScheme *text __attribute__((swift_name("text")));
+ (P_smsKotlinArray<P_smsScheme *> *)values __attribute__((swift_name("values()")));
@end;

__attribute__((swift_name("SubEncoder")))
@protocol P_smsSubEncoder
@required
- (P_smsDecodeResult * _Nullable)decodeStr:(NSString *)str index:(int32_t)index __attribute__((swift_name("decode(str:index:)")));
- (P_smsEncodeResult *)encodeCurrentValue:(P_smsBignumBigInteger *)currentValue __attribute__((swift_name("encode(currentValue:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeSubEncoder")))
@interface P_smsDateTimeSubEncoder : P_smsBase <P_smsSubEncoder>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (P_smsDecodeResult * _Nullable)decodeStr:(NSString *)str index:(int32_t)index __attribute__((swift_name("decode(str:index:)")));
- (P_smsEncodeResult *)encodeCurrentValue:(P_smsBignumBigInteger *)currentValue __attribute__((swift_name("encode(currentValue:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DecodeResult")))
@interface P_smsDecodeResult : P_smsBase
- (instancetype)initWithSize:(int32_t)size value:(int32_t)value newPosition:(int32_t)newPosition needSpaceBefore:(BOOL)needSpaceBefore needSpaceAfter:(BOOL)needSpaceAfter __attribute__((swift_name("init(size:value:newPosition:needSpaceBefore:needSpaceAfter:)"))) __attribute__((objc_designated_initializer));
- (int32_t)component1 __attribute__((swift_name("component1()")));
- (int32_t)component2 __attribute__((swift_name("component2()")));
- (int32_t)component3 __attribute__((swift_name("component3()")));
- (BOOL)component4 __attribute__((swift_name("component4()")));
- (BOOL)component5 __attribute__((swift_name("component5()")));
- (P_smsDecodeResult *)doCopySize:(int32_t)size value:(int32_t)value newPosition:(int32_t)newPosition needSpaceBefore:(BOOL)needSpaceBefore needSpaceAfter:(BOOL)needSpaceAfter __attribute__((swift_name("doCopy(size:value:newPosition:needSpaceBefore:needSpaceAfter:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL needSpaceAfter __attribute__((swift_name("needSpaceAfter")));
@property (readonly) BOOL needSpaceBefore __attribute__((swift_name("needSpaceBefore")));
@property (readonly, getter=doNewPosition) int32_t newPosition __attribute__((swift_name("newPosition")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EncodeResult")))
@interface P_smsEncodeResult : P_smsBase
- (instancetype)initWithSize:(P_smsBignumBigInteger *)size word:(NSString *)word needSpaceBefore:(BOOL)needSpaceBefore needSpaceAfter:(BOOL)needSpaceAfter __attribute__((swift_name("init(size:word:needSpaceBefore:needSpaceAfter:)"))) __attribute__((objc_designated_initializer));
- (P_smsBignumBigInteger *)component1 __attribute__((swift_name("component1()")));
- (NSString *)component2 __attribute__((swift_name("component2()")));
- (BOOL)component3 __attribute__((swift_name("component3()")));
- (BOOL)component4 __attribute__((swift_name("component4()")));
- (P_smsEncodeResult *)doCopySize:(P_smsBignumBigInteger *)size word:(NSString *)word needSpaceBefore:(BOOL)needSpaceBefore needSpaceAfter:(BOOL)needSpaceAfter __attribute__((swift_name("doCopy(size:word:needSpaceBefore:needSpaceAfter:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL needSpaceAfter __attribute__((swift_name("needSpaceAfter")));
@property (readonly) BOOL needSpaceBefore __attribute__((swift_name("needSpaceBefore")));
@property (readonly) P_smsBignumBigInteger *size __attribute__((swift_name("size")));
@property (readonly) NSString *word __attribute__((swift_name("word")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PunctuationSubEncoder")))
@interface P_smsPunctuationSubEncoder : P_smsBase <P_smsSubEncoder>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (P_smsDecodeResult * _Nullable)decodeStr:(NSString *)str index:(int32_t)index __attribute__((swift_name("decode(str:index:)")));
- (P_smsEncodeResult *)encodeCurrentValue:(P_smsBignumBigInteger *)currentValue __attribute__((swift_name("encode(currentValue:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TextEncoder")))
@interface P_smsTextEncoder : P_smsBase <P_smsEncryptedDataEncoder>
- (instancetype)initWithNonSpacesSubEncoders:(NSArray<id<P_smsSubEncoder>> *)nonSpacesSubEncoders spacedSubEncoders:(NSArray<id<P_smsSubEncoder>> *)spacedSubEncoders __attribute__((swift_name("init(nonSpacesSubEncoders:spacedSubEncoders:)"))) __attribute__((objc_designated_initializer));
- (P_smsKotlinByteArray *)decodeStr:(NSString *)str __attribute__((swift_name("decode(str:)")));
- (NSString *)encodeData:(P_smsKotlinByteArray *)data __attribute__((swift_name("encode(data:)")));
- (BOOL)hasFrontPadding __attribute__((swift_name("hasFrontPadding()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TextEncoder.Companion")))
@interface P_smsTextEncoderCompanion : P_smsBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (readonly) P_smsTextEncoder *instance __attribute__((swift_name("instance")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WordsSubEncoder")))
@interface P_smsWordsSubEncoder : P_smsBase <P_smsSubEncoder>
- (instancetype)initWithWords:(NSArray<NSString *> *)words __attribute__((swift_name("init(words:)"))) __attribute__((objc_designated_initializer));
- (P_smsDecodeResult * _Nullable)decodeStr:(NSString *)str index:(int32_t)index __attribute__((swift_name("decode(str:index:)")));
- (P_smsEncodeResult *)encodeCurrentValue:(P_smsBignumBigInteger *)currentValue __attribute__((swift_name("encode(currentValue:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WordsSubEncoderInstances")))
@interface P_smsWordsSubEncoderInstances : P_smsBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)wordsSubEncoderInstances __attribute__((swift_name("init()")));
@property (readonly) NSArray<P_smsWordsSubEncoder *> *instances __attribute__((swift_name("instances")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WordsSubEncoderInstances10")))
@interface P_smsWordsSubEncoderInstances10 : P_smsBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)wordsSubEncoderInstances10 __attribute__((swift_name("init()")));
- (NSArray<NSString *> *)getPart1 __attribute__((swift_name("getPart1()")));
- (NSArray<NSString *> *)getPart2 __attribute__((swift_name("getPart2()")));
- (NSArray<NSString *> *)getPart3 __attribute__((swift_name("getPart3()")));
@property (readonly) NSArray<P_smsWordsSubEncoder *> *instances __attribute__((swift_name("instances")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WordsSubEncoderInstances9")))
@interface P_smsWordsSubEncoderInstances9 : P_smsBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)wordsSubEncoderInstances9 __attribute__((swift_name("init()")));
- (NSArray<NSString *> *)getPart1 __attribute__((swift_name("getPart1()")));
- (NSArray<NSString *> *)getPart2 __attribute__((swift_name("getPart2()")));
- (NSArray<NSString *> *)getPart3 __attribute__((swift_name("getPart3()")));
@property (readonly) NSArray<P_smsWordsSubEncoder *> *instances __attribute__((swift_name("instances")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PSmsEncryptorKt")))
@interface P_smsPSmsEncryptorKt : P_smsBase
@property (class, readonly) int32_t CHANNEL_ID_SIZE __attribute__((swift_name("CHANNEL_ID_SIZE")));
@property (class, readonly) int32_t HASH_SIZE __attribute__((swift_name("HASH_SIZE")));
@property (class, readonly) int32_t VERSION __attribute__((swift_name("VERSION")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IsLetterKt")))
@interface P_smsIsLetterKt : P_smsBase
+ (BOOL)isDigitChar:(unichar)char_ __attribute__((swift_name("isDigit(char:)")));
+ (BOOL)isLetterChar:(unichar)char_ __attribute__((swift_name("isLetter(char:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Md5Kt")))
@interface P_smsMd5Kt : P_smsBase
+ (P_smsKotlinByteArray *)md5Arr:(P_smsKotlinByteArray *)arr __attribute__((swift_name("md5(arr:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AesEncryptorKt")))
@interface P_smsAesEncryptorKt : P_smsBase
@property (class, readonly) int32_t IV_SIZE __attribute__((swift_name("IV_SIZE")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PunctuationSubEncoderKt")))
@interface P_smsPunctuationSubEncoderKt : P_smsBase
@property (class, readonly) NSString *chars __attribute__((swift_name("chars")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeSubEncoderKt")))
@interface P_smsDateTimeSubEncoderKt : P_smsBase
@property (class, readonly) int32_t size __attribute__((swift_name("size")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface P_smsKotlinArray<T> : P_smsBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(P_smsInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<P_smsKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface P_smsKotlinByteArray : P_smsBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(P_smsByte *(^)(P_smsInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (P_smsKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end;

__attribute__((swift_name("KotlinCharSequence")))
@protocol P_smsKotlinCharSequence
@required
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id)subSequenceStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("subSequence(startIndex:endIndex:)")));
@property (readonly) int32_t length __attribute__((swift_name("length")));
@end;

__attribute__((swift_name("KotlinAppendable")))
@protocol P_smsKotlinAppendable
@required
- (id<P_smsKotlinAppendable>)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));
- (id<P_smsKotlinAppendable>)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));
- (id<P_smsKotlinAppendable>)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinStringBuilder")))
@interface P_smsKotlinStringBuilder : P_smsBase <P_smsKotlinCharSequence, P_smsKotlinAppendable>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithCapacity:(int32_t)capacity __attribute__((swift_name("init(capacity:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent:(NSString *)content __attribute__((swift_name("init(content:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent_:(id)content __attribute__((swift_name("init(content_:)"))) __attribute__((objc_designated_initializer));
- (P_smsKotlinStringBuilder *)appendValue__:(id _Nullable)value __attribute__((swift_name("append(value__:)")));
- (P_smsKotlinStringBuilder *)appendValue___:(BOOL)value __attribute__((swift_name("append(value___:)")));
- (P_smsKotlinStringBuilder *)appendValue____:(int8_t)value __attribute__((swift_name("append(value____:)")));
- (P_smsKotlinStringBuilder *)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));
- (P_smsKotlinStringBuilder *)appendValue_____:(P_smsKotlinCharArray *)value __attribute__((swift_name("append(value_____:)")));
- (P_smsKotlinStringBuilder *)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));
- (P_smsKotlinStringBuilder *)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));
- (P_smsKotlinStringBuilder *)appendValue______:(double)value __attribute__((swift_name("append(value______:)")));
- (P_smsKotlinStringBuilder *)appendValue_______:(float)value __attribute__((swift_name("append(value_______:)")));
- (P_smsKotlinStringBuilder *)appendValue________:(int32_t)value __attribute__((swift_name("append(value________:)")));
- (P_smsKotlinStringBuilder *)appendValue_________:(int64_t)value __attribute__((swift_name("append(value_________:)")));
- (P_smsKotlinStringBuilder *)appendValue__________:(int16_t)value __attribute__((swift_name("append(value__________:)")));
- (P_smsKotlinStringBuilder *)appendValue___________:(NSString * _Nullable)value __attribute__((swift_name("append(value___________:)")));
- (P_smsKotlinStringBuilder *)appendRangeValue:(P_smsKotlinCharArray *)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("appendRange(value:startIndex:endIndex:)")));
- (P_smsKotlinStringBuilder *)appendRangeValue:(id)value startIndex:(int32_t)startIndex endIndex_:(int32_t)endIndex __attribute__((swift_name("appendRange(value:startIndex:endIndex_:)")));
- (int32_t)capacity __attribute__((swift_name("capacity()")));
- (P_smsKotlinStringBuilder *)deleteAtIndex:(int32_t)index __attribute__((swift_name("deleteAt(index:)")));
- (P_smsKotlinStringBuilder *)deleteRangeStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("deleteRange(startIndex:endIndex:)")));
- (void)ensureCapacityMinimumCapacity:(int32_t)minimumCapacity __attribute__((swift_name("ensureCapacity(minimumCapacity:)")));
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (int32_t)indexOfString:(NSString *)string __attribute__((swift_name("indexOf(string:)")));
- (int32_t)indexOfString:(NSString *)string startIndex:(int32_t)startIndex __attribute__((swift_name("indexOf(string:startIndex:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value:(id _Nullable)value __attribute__((swift_name("insert(index:value:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value_:(BOOL)value __attribute__((swift_name("insert(index:value_:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value__:(int8_t)value __attribute__((swift_name("insert(index:value__:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value___:(unichar)value __attribute__((swift_name("insert(index:value___:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value____:(P_smsKotlinCharArray *)value __attribute__((swift_name("insert(index:value____:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value_____:(id _Nullable)value __attribute__((swift_name("insert(index:value_____:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value______:(double)value __attribute__((swift_name("insert(index:value______:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value_______:(float)value __attribute__((swift_name("insert(index:value_______:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value________:(int32_t)value __attribute__((swift_name("insert(index:value________:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value_________:(int64_t)value __attribute__((swift_name("insert(index:value_________:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value__________:(int16_t)value __attribute__((swift_name("insert(index:value__________:)")));
- (P_smsKotlinStringBuilder *)insertIndex:(int32_t)index value___________:(NSString * _Nullable)value __attribute__((swift_name("insert(index:value___________:)")));
- (P_smsKotlinStringBuilder *)insertRangeIndex:(int32_t)index value:(P_smsKotlinCharArray *)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("insertRange(index:value:startIndex:endIndex:)")));
- (P_smsKotlinStringBuilder *)insertRangeIndex:(int32_t)index value:(id)value startIndex:(int32_t)startIndex endIndex_:(int32_t)endIndex __attribute__((swift_name("insertRange(index:value:startIndex:endIndex_:)")));
- (int32_t)lastIndexOfString:(NSString *)string __attribute__((swift_name("lastIndexOf(string:)")));
- (int32_t)lastIndexOfString:(NSString *)string startIndex:(int32_t)startIndex __attribute__((swift_name("lastIndexOf(string:startIndex:)")));
- (P_smsKotlinStringBuilder *)reverse __attribute__((swift_name("reverse()")));
- (void)setIndex:(int32_t)index value:(unichar)value __attribute__((swift_name("set(index:value:)")));
- (void)setLengthNewLength:(int32_t)newLength __attribute__((swift_name("setLength(newLength:)")));
- (P_smsKotlinStringBuilder *)setRangeStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex value:(NSString *)value __attribute__((swift_name("setRange(startIndex:endIndex:value:)")));
- (id)subSequenceStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("subSequence(startIndex:endIndex:)")));
- (NSString *)substringStartIndex:(int32_t)startIndex __attribute__((swift_name("substring(startIndex:)")));
- (NSString *)substringStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("substring(startIndex:endIndex:)")));
- (void)toCharArrayDestination:(P_smsKotlinCharArray *)destination destinationOffset:(int32_t)destinationOffset startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("toCharArray(destination:destinationOffset:startIndex:endIndex:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (void)trimToSize __attribute__((swift_name("trimToSize()")));
@property (readonly) int32_t length __attribute__((swift_name("length")));
@end;

__attribute__((swift_name("BignumBigNumber")))
@protocol P_smsBignumBigNumber
@required
- (id<P_smsBignumBigNumber>)abs __attribute__((swift_name("abs()")));
- (id<P_smsBignumBigNumber>)addOther:(id<P_smsBignumBigNumber>)other __attribute__((swift_name("add(other:)")));
- (int32_t)compareToOther_:(id)other __attribute__((swift_name("compareTo(other_:)")));
- (id<P_smsBignumBigNumber>)divideOther:(id<P_smsBignumBigNumber>)other __attribute__((swift_name("divide(other:)")));
- (P_smsKotlinPair<id<P_smsBignumBigNumber>, id<P_smsBignumBigNumber>> *)divideAndRemainderOther:(id<P_smsBignumBigNumber>)other __attribute__((swift_name("divideAndRemainder(other:)")));
- (id<P_smsBignumBigNumberCreator>)getCreator __attribute__((swift_name("getCreator()")));
- (BOOL)isZero __attribute__((swift_name("isZero()")));
- (id<P_smsBignumBigNumber>)multiplyOther:(id<P_smsBignumBigNumber>)other __attribute__((swift_name("multiply(other:)")));
- (id<P_smsBignumBigNumber>)negate __attribute__((swift_name("negate()")));
- (int64_t)numberOfDecimalDigits __attribute__((swift_name("numberOfDecimalDigits()")));
- (id<P_smsBignumBigNumber>)powExponent:(int32_t)exponent __attribute__((swift_name("pow(exponent:)")));
- (id<P_smsBignumBigNumber>)powExponent_:(int64_t)exponent __attribute__((swift_name("pow(exponent_:)")));
- (id<P_smsBignumBigNumber>)remainderOther:(id<P_smsBignumBigNumber>)other __attribute__((swift_name("remainder(other:)")));
- (void)secureOverwrite __attribute__((swift_name("secureOverwrite()")));
- (int32_t)signum __attribute__((swift_name("signum()")));
- (id<P_smsBignumBigNumber>)subtractOther:(id<P_smsBignumBigNumber>)other __attribute__((swift_name("subtract(other:)")));
- (NSString *)toStringBase:(int32_t)base __attribute__((swift_name("toString(base:)")));
- (id<P_smsBignumBigNumber>)unaryMinus __attribute__((swift_name("unaryMinus()")));
@property (readonly) BOOL isNegative __attribute__((swift_name("isNegative")));
@property (readonly) BOOL isPositive __attribute__((swift_name("isPositive")));
@end;

__attribute__((swift_name("BignumBitwiseCapable")))
@protocol P_smsBignumBitwiseCapable
@required
- (id _Nullable)andOther:(id _Nullable)other __attribute__((swift_name("and(other:)")));
- (BOOL)bitAtPosition:(int64_t)position __attribute__((swift_name("bitAt(position:)")));
- (id _Nullable)not __attribute__((swift_name("not()")));
- (id _Nullable)orOther:(id _Nullable)other __attribute__((swift_name("or(other:)")));
- (id _Nullable)setBitAtPosition:(int64_t)position bit:(BOOL)bit __attribute__((swift_name("setBitAt(position:bit:)")));
- (id _Nullable)shlPlaces:(int32_t)places __attribute__((swift_name("shl(places:)")));
- (id _Nullable)shrPlaces:(int32_t)places __attribute__((swift_name("shr(places:)")));
- (id _Nullable)xorOther:(id _Nullable)other __attribute__((swift_name("xor(other:)")));
@end;

__attribute__((swift_name("BignumByteArraySerializable")))
@protocol P_smsBignumByteArraySerializable
@required
- (P_smsKotlinByteArray *)toByteArray __attribute__((swift_name("toByteArray()")));
- (id)toUByteArray __attribute__((swift_name("toUByteArray()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BignumBigInteger")))
@interface P_smsBignumBigInteger : P_smsBase <P_smsBignumBigNumber, P_smsBignumBitwiseCapable, P_smsKotlinComparable, P_smsBignumByteArraySerializable>
- (instancetype)initWithLong:(int64_t)long_ __attribute__((swift_name("init(long:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithInt:(int32_t)int_ __attribute__((swift_name("init(int:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithShort:(int16_t)short_ __attribute__((swift_name("init(short:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithByte:(int8_t)byte __attribute__((swift_name("init(byte:)"))) __attribute__((objc_designated_initializer));
- (P_smsBignumBigInteger *)abs __attribute__((swift_name("abs()")));
- (P_smsBignumBigInteger *)addOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("add(other:)")));
- (P_smsBignumBigInteger *)andOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("and(other:)")));
- (BOOL)bitAtPosition:(int64_t)position __attribute__((swift_name("bitAt(position:)")));
- (int8_t)byteValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("byteValue(exactRequired:)")));
- (int32_t)compareOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("compare(other:)")));
- (int32_t)compareDoubleAndBigIntDouble:(double)double_ comparisonBlock:(P_smsInt *(^)(P_smsBignumBigInteger *))comparisonBlock __attribute__((swift_name("compareDoubleAndBigInt(double:comparisonBlock:)")));
- (int32_t)compareFloatAndBigIntFloat:(float)float_ comparisonBlock:(P_smsInt *(^)(P_smsBignumBigInteger *))comparisonBlock __attribute__((swift_name("compareFloatAndBigInt(float:comparisonBlock:)")));
- (int32_t)compareToOther_:(id)other __attribute__((swift_name("compareTo(other_:)")));
- (int32_t)compareToOther:(id)other __attribute__((swift_name("compareTo(other:)")));
- (P_smsBignumBigInteger *)dec __attribute__((swift_name("dec()")));
- (P_smsBignumBigInteger *)divideOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("divide(other:)")));
- (P_smsKotlinPair<P_smsBignumBigInteger *, P_smsBignumBigInteger *> *)divideAndRemainderOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("divideAndRemainder(other:)")));
- (P_smsBignumBigIntegerQuotientAndRemainder *)divremOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("divrem(other:)")));
- (double)doubleValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("doubleValue(exactRequired:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (float)floatValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("floatValue(exactRequired:)")));
- (P_smsBignumBigInteger *)gcdOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("gcd(other:)")));
- (id<P_smsBignumBigNumberCreator>)getCreator __attribute__((swift_name("getCreator()")));
- (P_smsBignumBigInteger *)getInstance __attribute__((swift_name("getInstance()")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (P_smsBignumBigInteger *)inc __attribute__((swift_name("inc()")));
- (int32_t)intValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("intValue(exactRequired:)")));
- (BOOL)isZero __attribute__((swift_name("isZero()")));
- (int64_t)longValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("longValue(exactRequired:)")));
- (P_smsBignumBigInteger *)modModulo:(P_smsBignumBigInteger *)modulo __attribute__((swift_name("mod(modulo:)")));
- (P_smsBignumBigInteger *)modInverseModulo:(P_smsBignumBigInteger *)modulo __attribute__((swift_name("modInverse(modulo:)")));
- (P_smsBignumBigInteger *)multiplyOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("multiply(other:)")));
- (P_smsBignumBigInteger *)negate __attribute__((swift_name("negate()")));
- (P_smsBignumBigInteger *)not __attribute__((swift_name("not()")));
- (int64_t)numberOfDecimalDigits __attribute__((swift_name("numberOfDecimalDigits()")));
- (P_smsBignumBigInteger *)orOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("or(other:)")));
- (P_smsBignumBigInteger *)powExponent__:(P_smsBignumBigInteger *)exponent __attribute__((swift_name("pow(exponent__:)")));
- (P_smsBignumBigInteger *)powExponent:(int32_t)exponent __attribute__((swift_name("pow(exponent:)")));
- (P_smsBignumBigInteger *)powExponent_:(int64_t)exponent __attribute__((swift_name("pow(exponent_:)")));
- (P_smsBignumBigIntegerBigIntegerRange *)rangeToOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("rangeTo(other:)")));
- (P_smsBignumBigInteger *)remainderOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("remainder(other:)")));
- (void)secureOverwrite __attribute__((swift_name("secureOverwrite()")));
- (P_smsBignumBigInteger *)setBitAtPosition:(int64_t)position bit:(BOOL)bit __attribute__((swift_name("setBitAt(position:bit:)")));
- (P_smsBignumBigInteger *)shlPlaces:(int32_t)places __attribute__((swift_name("shl(places:)")));
- (int16_t)shortValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("shortValue(exactRequired:)")));
- (P_smsBignumBigInteger *)shrPlaces:(int32_t)places __attribute__((swift_name("shr(places:)")));
- (int32_t)signum __attribute__((swift_name("signum()")));
- (P_smsBignumBigInteger *)sqrt __attribute__((swift_name("sqrt()")));
- (P_smsBignumBigIntegerSqareRootAndRemainder *)sqrtAndRemainder __attribute__((swift_name("sqrtAndRemainder()")));
- (P_smsBignumBigInteger *)subtractOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("subtract(other:)")));
- (NSString *)timesChar:(unichar)char_ __attribute__((swift_name("times(char:)")));
- (P_smsKotlinByteArray *)toByteArray __attribute__((swift_name("toByteArray()")));
- (P_smsBignumModularBigInteger *)toModularBigIntegerModulo:(P_smsBignumBigInteger *)modulo __attribute__((swift_name("toModularBigInteger(modulo:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (NSString *)toStringBase:(int32_t)base __attribute__((swift_name("toString(base:)")));
- (id)toUByteArray __attribute__((swift_name("toUByteArray()")));
- (uint8_t)ubyteValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("ubyteValue(exactRequired:)")));
- (uint32_t)uintValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("uintValue(exactRequired:)")));
- (uint64_t)ulongValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("ulongValue(exactRequired:)")));
- (P_smsBignumBigInteger *)unaryMinus __attribute__((swift_name("unaryMinus()")));
- (uint16_t)ushortValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("ushortValue(exactRequired:)")));
- (P_smsBignumBigInteger *)xorOther:(P_smsBignumBigInteger *)other __attribute__((swift_name("xor(other:)")));
@property (readonly) int32_t numberOfWords __attribute__((swift_name("numberOfWords")));
@property NSString * _Nullable stringRepresentation __attribute__((swift_name("stringRepresentation")));
@end;

__attribute__((swift_name("KotlinIterator")))
@protocol P_smsKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end;

__attribute__((swift_name("KotlinByteIterator")))
@interface P_smsKotlinByteIterator : P_smsBase <P_smsKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (P_smsByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinCharArray")))
@interface P_smsKotlinCharArray : P_smsBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(id (^)(P_smsInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (P_smsKotlinCharIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(unichar)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface P_smsKotlinPair<__covariant A, __covariant B> : P_smsBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (A _Nullable)component1 __attribute__((swift_name("component1()")));
- (B _Nullable)component2 __attribute__((swift_name("component2()")));
- (P_smsKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end;

__attribute__((swift_name("BignumBigNumberCreator")))
@protocol P_smsBignumBigNumberCreator
@required
- (id _Nullable)fromBigIntegerBigInteger:(P_smsBignumBigInteger *)bigInteger __attribute__((swift_name("fromBigInteger(bigInteger:)")));
- (id _Nullable)fromByteByte:(int8_t)byte __attribute__((swift_name("fromByte(byte:)")));
- (id _Nullable)fromIntInt:(int32_t)int_ __attribute__((swift_name("fromInt(int:)")));
- (id _Nullable)fromLongLong:(int64_t)long_ __attribute__((swift_name("fromLong(long:)")));
- (id _Nullable)fromShortShort:(int16_t)short_ __attribute__((swift_name("fromShort(short:)")));
- (id _Nullable)fromUByteUByte:(uint8_t)uByte __attribute__((swift_name("fromUByte(uByte:)")));
- (id _Nullable)fromUIntUInt:(uint32_t)uInt __attribute__((swift_name("fromUInt(uInt:)")));
- (id _Nullable)fromULongULong:(uint64_t)uLong __attribute__((swift_name("fromULong(uLong:)")));
- (id _Nullable)fromUShortUShort:(uint16_t)uShort __attribute__((swift_name("fromUShort(uShort:)")));
- (id _Nullable)parseStringString:(NSString *)string base:(int32_t)base __attribute__((swift_name("parseString(string:base:)")));
- (id _Nullable)tryFromDoubleDouble:(double)double_ exactRequired:(BOOL)exactRequired __attribute__((swift_name("tryFromDouble(double:exactRequired:)")));
- (id _Nullable)tryFromFloatFloat:(float)float_ exactRequired:(BOOL)exactRequired __attribute__((swift_name("tryFromFloat(float:exactRequired:)")));
@property (readonly) id _Nullable ONE __attribute__((swift_name("ONE")));
@property (readonly) id _Nullable TEN __attribute__((swift_name("TEN")));
@property (readonly) id _Nullable TWO __attribute__((swift_name("TWO")));
@property (readonly) id _Nullable ZERO __attribute__((swift_name("ZERO")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BignumBigInteger.QuotientAndRemainder")))
@interface P_smsBignumBigIntegerQuotientAndRemainder : P_smsBase
- (instancetype)initWithQuotient:(P_smsBignumBigInteger *)quotient remainder:(P_smsBignumBigInteger *)remainder __attribute__((swift_name("init(quotient:remainder:)"))) __attribute__((objc_designated_initializer));
- (P_smsBignumBigInteger *)component1 __attribute__((swift_name("component1()")));
- (P_smsBignumBigInteger *)component2 __attribute__((swift_name("component2()")));
- (P_smsBignumBigIntegerQuotientAndRemainder *)doCopyQuotient:(P_smsBignumBigInteger *)quotient remainder:(P_smsBignumBigInteger *)remainder __attribute__((swift_name("doCopy(quotient:remainder:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) P_smsBignumBigInteger *quotient __attribute__((swift_name("quotient")));
@property (readonly) P_smsBignumBigInteger *remainder __attribute__((swift_name("remainder")));
@end;

__attribute__((swift_name("KotlinClosedRange")))
@protocol P_smsKotlinClosedRange
@required
- (BOOL)containsValue:(id)value __attribute__((swift_name("contains(value:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
@property (readonly) id endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly) id start __attribute__((swift_name("start")));
@end;

__attribute__((swift_name("KotlinIterable")))
@protocol P_smsKotlinIterable
@required
- (id<P_smsKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BignumBigInteger.BigIntegerRange")))
@interface P_smsBignumBigIntegerBigIntegerRange : P_smsBase <P_smsKotlinClosedRange, P_smsKotlinIterable>
- (instancetype)initWithStart:(P_smsBignumBigInteger *)start endInclusive:(P_smsBignumBigInteger *)endInclusive __attribute__((swift_name("init(start:endInclusive:)"))) __attribute__((objc_designated_initializer));
- (id<P_smsKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@property (readonly) P_smsBignumBigInteger *endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly) P_smsBignumBigInteger *start __attribute__((swift_name("start")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BignumBigInteger.SqareRootAndRemainder")))
@interface P_smsBignumBigIntegerSqareRootAndRemainder : P_smsBase
- (instancetype)initWithSquareRoot:(P_smsBignumBigInteger *)squareRoot remainder:(P_smsBignumBigInteger *)remainder __attribute__((swift_name("init(squareRoot:remainder:)"))) __attribute__((objc_designated_initializer));
- (P_smsBignumBigInteger *)component1 __attribute__((swift_name("component1()")));
- (P_smsBignumBigInteger *)component2 __attribute__((swift_name("component2()")));
- (P_smsBignumBigIntegerSqareRootAndRemainder *)doCopySquareRoot:(P_smsBignumBigInteger *)squareRoot remainder:(P_smsBignumBigInteger *)remainder __attribute__((swift_name("doCopy(squareRoot:remainder:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) P_smsBignumBigInteger *remainder __attribute__((swift_name("remainder")));
@property (readonly) P_smsBignumBigInteger *squareRoot __attribute__((swift_name("squareRoot")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BignumModularBigInteger")))
@interface P_smsBignumModularBigInteger : P_smsBase <P_smsBignumBigNumber, P_smsBignumByteArraySerializable>
- (P_smsBignumModularBigInteger *)abs __attribute__((swift_name("abs()")));
- (P_smsBignumModularBigInteger *)addOther:(P_smsBignumModularBigInteger *)other __attribute__((swift_name("add(other:)")));
- (int8_t)byteValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("byteValue(exactRequired:)")));
- (int32_t)compareOther:(P_smsBignumModularBigInteger *)other __attribute__((swift_name("compare(other:)")));
- (int32_t)compareToOther_:(id)other __attribute__((swift_name("compareTo(other_:)")));
- (P_smsBignumModularBigInteger *)divideOther:(P_smsBignumModularBigInteger *)other __attribute__((swift_name("divide(other:)")));
- (P_smsKotlinPair<P_smsBignumModularBigInteger *, P_smsBignumModularBigInteger *> *)divideAndRemainderOther:(P_smsBignumModularBigInteger *)other __attribute__((swift_name("divideAndRemainder(other:)")));
- (P_smsBignumModularQuotientAndRemainder *)divremOther:(P_smsBignumModularBigInteger *)other __attribute__((swift_name("divrem(other:)")));
- (double)doubleValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("doubleValue(exactRequired:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (float)floatValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("floatValue(exactRequired:)")));
- (id<P_smsBignumBigNumberCreator>)getCreator __attribute__((swift_name("getCreator()")));
- (P_smsBignumModularBigInteger *)getInstance __attribute__((swift_name("getInstance()")));
- (int32_t)intValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("intValue(exactRequired:)")));
- (P_smsBignumModularBigInteger *)inverse __attribute__((swift_name("inverse()")));
- (BOOL)isZero __attribute__((swift_name("isZero()")));
- (int64_t)longValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("longValue(exactRequired:)")));
- (P_smsBignumModularBigInteger *)multiplyOther:(P_smsBignumModularBigInteger *)other __attribute__((swift_name("multiply(other:)")));
- (P_smsBignumModularBigInteger *)negate __attribute__((swift_name("negate()")));
- (int64_t)numberOfDecimalDigits __attribute__((swift_name("numberOfDecimalDigits()")));
- (P_smsBignumModularBigInteger *)powExponent__:(P_smsBignumBigInteger *)exponent __attribute__((swift_name("pow(exponent__:)")));
- (P_smsBignumModularBigInteger *)powExponent___:(P_smsBignumModularBigInteger *)exponent __attribute__((swift_name("pow(exponent___:)")));
- (P_smsBignumModularBigInteger *)powExponent:(int32_t)exponent __attribute__((swift_name("pow(exponent:)")));
- (P_smsBignumModularBigInteger *)powExponent_:(int64_t)exponent __attribute__((swift_name("pow(exponent_:)")));
- (P_smsBignumModularBigInteger *)remOther:(P_smsBignumModularBigInteger *)other __attribute__((swift_name("rem(other:)")));
- (P_smsBignumModularBigInteger *)remainderOther:(P_smsBignumModularBigInteger *)other __attribute__((swift_name("remainder(other:)")));
- (void)secureOverwrite __attribute__((swift_name("secureOverwrite()")));
- (int16_t)shortValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("shortValue(exactRequired:)")));
- (int32_t)signum __attribute__((swift_name("signum()")));
- (P_smsBignumModularBigInteger *)subtractOther:(P_smsBignumModularBigInteger *)other __attribute__((swift_name("subtract(other:)")));
- (P_smsBignumBigInteger *)toBigInteger __attribute__((swift_name("toBigInteger()")));
- (P_smsKotlinByteArray *)toByteArray __attribute__((swift_name("toByteArray()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (NSString *)toStringBase:(int32_t)base __attribute__((swift_name("toString(base:)")));
- (NSString *)toStringWithModuloBase:(int32_t)base __attribute__((swift_name("toStringWithModulo(base:)")));
- (id)toUByteArray __attribute__((swift_name("toUByteArray()")));
- (uint8_t)ubyteValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("ubyteValue(exactRequired:)")));
- (uint32_t)uintValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("uintValue(exactRequired:)")));
- (uint64_t)ulongValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("ulongValue(exactRequired:)")));
- (P_smsBignumModularBigInteger *)unaryMinus __attribute__((swift_name("unaryMinus()")));
- (uint16_t)ushortValueExactRequired:(BOOL)exactRequired __attribute__((swift_name("ushortValue(exactRequired:)")));
@property (readonly) P_smsBignumBigInteger *modulus __attribute__((swift_name("modulus")));
@property (readonly) P_smsBignumBigInteger *residue __attribute__((swift_name("residue")));
@end;

__attribute__((swift_name("KotlinCharIterator")))
@interface P_smsKotlinCharIterator : P_smsBase <P_smsKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id)next __attribute__((swift_name("next()")));
- (unichar)nextChar __attribute__((swift_name("nextChar()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BignumModularQuotientAndRemainder")))
@interface P_smsBignumModularQuotientAndRemainder : P_smsBase
- (instancetype)initWithQuotient:(P_smsBignumModularBigInteger *)quotient remainder:(P_smsBignumModularBigInteger *)remainder __attribute__((swift_name("init(quotient:remainder:)"))) __attribute__((objc_designated_initializer));
- (P_smsBignumModularBigInteger *)component1 __attribute__((swift_name("component1()")));
- (P_smsBignumModularBigInteger *)component2 __attribute__((swift_name("component2()")));
- (P_smsBignumModularQuotientAndRemainder *)doCopyQuotient:(P_smsBignumModularBigInteger *)quotient remainder:(P_smsBignumModularBigInteger *)remainder __attribute__((swift_name("doCopy(quotient:remainder:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) P_smsBignumModularBigInteger *quotient __attribute__((swift_name("quotient")));
@property (readonly) P_smsBignumModularBigInteger *remainder __attribute__((swift_name("remainder")));
@end;

#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
