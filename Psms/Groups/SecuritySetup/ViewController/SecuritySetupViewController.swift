import UIKit
import KeychainSwift

final class SecuritySetupViewController: UIViewController {
    
    // - UI
    @IBOutlet weak var fakePasswordTextField: UITextField!
    @IBOutlet weak var passwordTextField: UITextField!
    @IBOutlet weak var saveButton: UIButton!
    
    @IBAction func saveButtonAction(_ sender: Any) {
        if let appPassword = passwordTextField.text,
           appPassword.count > 3 {
            KeychainManager.shared.fakePassword = fakePasswordTextField.text
            KeychainManager.shared.appPassword = appPassword
            let appDelegate = UIApplication.shared.delegate as! AppDelegate
            appDelegate.window?.rootViewController = UINavigationController(rootViewController: UIStoryboard(storyboard: .chatList).instantiateInitialViewController()!)
        }
    }
    
    @objc private func textFieldDidChange(_ textField: UITextField) {
        let password = passwordTextField.text ?? ""
        let fakePassword = fakePasswordTextField.text ?? ""
        let isEnabled = password.count > 3 && fakePassword.count > 3
        saveButton.isEnabled = isEnabled
    }
    
}

// MARK: -
// MARK: - Configure

private extension SecuritySetupViewController {
    
    func configure() {
        configureTextFields()
    }
    
    func configureTextFields() {
        passwordTextField.addTarget(self, action: #selector(textFieldDidChange(_:)), for: .editingChanged)
        fakePasswordTextField.addTarget(self, action: #selector(textFieldDidChange(_:)), for: .editingChanged)
        saveButton.isEnabled = false
    }
    
}
