import Foundation

protocol EncryptionManagerProtocol: AnyObject {
    
    func generateKey() -> String
    func isEncrypted(str: String, stringKey: String) -> Bool
    func tryDecode(str: String, stringKey: String) -> String
    func encode(str: String, stringKey: String, encryptionSchemeId: Int32) -> String
    func decryptPasswordForChat(encrypted: String, stringKey: String) -> String?
    func encryptPasswordForChat(str: String, stringKey: String) -> String?
    func isKeyValid(stringKey: String) -> Bool
    
    
}
