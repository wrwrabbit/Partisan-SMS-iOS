import KeychainSwift
import CommonCrypto

final class KeychainManager {
    
    static let shared = KeychainManager()
    private let keychain = KeychainSwift()
    private var encryptor: EncryptionManagerProtocol = EncryptionManager()
    var appPassword: String?
    
    var fakePassword: String? {
        get {
            UserDefaults.standard.string(forKey: #function)
        }
        set {
            UserDefaults.standard.setValue(newValue ?? "", forKey: #function)
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
