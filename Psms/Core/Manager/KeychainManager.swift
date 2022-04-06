import KeychainSwift
import CommonCrypto

class KeychainManager {
    
    static let shared = KeychainManager()
    let keychain = KeychainSwift()
    var encryptor: EncryptionManagerProtocol = EncryptionManager()
    var appPassword: String?
    
    var fakePassword: String? {
        get {
            keychain.get(#function)
        }
        set {
            keychain.set(newValue ?? "", forKey: #function)
        }
    }
    
    func getPasswordForChat(chatId: String) -> String? {
        if let encryptedPassword = keychain.get("chatPassword\(chatId)"),
           let appPassword = appPassword,
           let decryptedPassword = encryptor.decryptPasswordForChat(encrypted: encryptedPassword, stringKey: appPassword)
        {
            return decryptedPassword
        }
        return nil
    }
    
    func setPasswordForChat(chatId: String, password: String) {
        if let appPassword = appPassword,
        let encryptedPassword = encryptor.encryptPasswordForChat(str: password, stringKey: appPassword)
        {
            keychain.set(encryptedPassword, forKey: "chatPassword\(chatId)")
        }
    }
    
    func clearKeychain() {
        keychain.clear()
    }
}
