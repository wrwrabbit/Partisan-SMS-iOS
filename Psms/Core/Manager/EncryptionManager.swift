import Foundation
import CommonCrypto
import p_sms

final class EncryptionManager: EncryptionManagerProtocol {
    
    func generateKey() -> String {
        var bytes = [UInt8](repeating: 0, count: 32)
        let _ = SecRandomCopyBytes(kSecRandomDefault, bytes.count, &bytes)
        let data = Data(bytes: bytes, count: bytes.count)
        return data.base64EncodedString(options: .endLineWithLineFeed)
    }
    
    func isEncrypted(str: String, stringKey: String) -> Bool {
        PSmsEncryptor().isEncrypted(str: str, key: chatKeyToKotlinByteArray(keyStr: stringKey))
    }
    
    func tryDecode(str: String, stringKey: String) -> String {
        PSmsEncryptor().tryDecode(str: str, key: chatKeyToKotlinByteArray(keyStr: stringKey)).text
    }
    
    func encode(str: String, stringKey: String, encryptionSchemeId: Int32) -> String {
        PSmsEncryptor().encode(message: Message(text: str, channelId: 0), key: chatKeyToKotlinByteArray(keyStr: stringKey), encryptionSchemeId: encryptionSchemeId)
    }
    
    func decryptPasswordForChat(encrypted: String, stringKey: String) -> String? {
        guard let encryptedData = Data(base64Encoded: encrypted),
              let aes = try? AES(data: sha256(string: stringKey)),
              let decryptedString = try? aes.decrypt(encryptedData) else { return nil }
        return decryptedString
    }
    
    func encryptPasswordForChat(str: String, stringKey: String) -> String? {
        let keyData = sha256(string: stringKey)
        guard
            let aes = try? AES(data: keyData),
            let encryptedStrData = try? aes.encrypt(str) else { return nil }
        return encryptedStrData.base64EncodedString()
    }
    
    private func sha256(string: String) -> Data {
        let data = string.data(using: .utf8) ?? Data()
        var hash = [UInt8](repeating: 0,  count: Int(CC_SHA256_DIGEST_LENGTH))
        data.withUnsafeBytes {
            _ = CC_SHA256($0.baseAddress, CC_LONG(data.count), &hash)
        }
        return Data(hash)
    }
    
    private func chatKeyToKotlinByteArray(keyStr: String) -> KotlinByteArray {
        if let nsdata = NSData(base64Encoded: keyStr, options: .ignoreUnknownCharacters)
        {
            var bytes = [UInt8](repeating: 0, count: nsdata.count)
            nsdata.getBytes(&bytes, length: nsdata.count)
            let intArray : [Int8] = bytes.map { Int8(bitPattern: $0) }
            let kotlinByteArray: KotlinByteArray = KotlinByteArray.init(size: Int32(intArray.count))
            for (index, element) in intArray.enumerated() {
                kotlinByteArray.set(index: Int32(index), value: element)
            }
            return kotlinByteArray
        }
        return KotlinByteArray.init(size: Int32(32))
    }
    
}
