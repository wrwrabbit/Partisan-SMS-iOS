import Foundation

protocol ChatEncryptionSelectionDelegate: AnyObject {
    
    func didSelectEncryptionScheme(_ scheme: EncryptionSchemeType)
    
}
