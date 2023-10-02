import Foundation
import UIKit
import RealmSwift

final class UnlockPasswordViewController: UIViewController {
    @IBOutlet weak var passwordTextField: UITextField!
    @IBOutlet weak var goButton: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        configure()
    }
    
    @IBAction func goButtonAction(_ sender: Any) {
        if let password = passwordTextField.text,
           password.count > 3 {
            if KeychainManager.shared.fakePassword == password {
                KeychainManager.shared.clearKeychain()
                let realm = try! Realm()
                try? realm.write {
                    realm.deleteAll()
                }
            }
            else {
                KeychainManager.shared.appPassword = password
            }
            let appDelegate = UIApplication.shared.delegate as! AppDelegate
            appDelegate.window?.rootViewController = UINavigationController(rootViewController: UIStoryboard(storyboard: .chatList).instantiateInitialViewController()!)
        }
    }
    
}

// MARK: -
// MARK: - Configure

private extension UnlockPasswordViewController {
    
    func configure() {
        configureTextFields()
    }
    
    func configureTextFields() {
        passwordTextField.delegate = self
        goButton.isEnabled = false
    }
    
}

// MARK: -
// MARK: - UITextView Delegate

extension UnlockPasswordViewController: UITextFieldDelegate {
    
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        if let text = textField.text,
           let textRange = Range(range, in: text) {
            let updatedText = text.replacingCharacters(in: textRange,
                                                       with: string)
            if textField == passwordTextField {
                goButton.isEnabled = updatedText.count > 3
            }
        }
        return true
    }
    
}
