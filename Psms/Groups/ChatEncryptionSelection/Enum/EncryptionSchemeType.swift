import Foundation

enum EncryptionSchemeType: Int32, CaseIterable {
    
    case base64 = 0
    case base64Cyrillic = 1
    case text = 2
    
    var name: String {
        switch self {
        case .base64:
            return "Base64".localized
        case .base64Cyrillic:
            return "Base64Cyrillic".localized
        case .text:
            return "RussianWords".localized
        }
    }
    
    static var lastChoosenEncryptionScheme: EncryptionSchemeType {
        get {
            EncryptionSchemeType(rawValue: (Int32(UserDefaults.standard.integer(forKey: #function)))) ?? .base64
        }
        set {
            UserDefaults.standard.set(newValue.rawValue, forKey: #function)
        }
    }
    
}
