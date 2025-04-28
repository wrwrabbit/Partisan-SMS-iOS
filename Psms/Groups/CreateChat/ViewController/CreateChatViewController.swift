import RealmSwift
import UIKit

final class CreateChatViewController: PopUpViewController {

    // - UI
    @IBOutlet weak var copyButton: UIButton!
    @IBOutlet weak var passwordTextField: UITextField!
    @IBOutlet var createButton: UIButton!
    @IBOutlet var nameTextField: UITextField!

    // - Manager
    private var layoutManager: CreateChatLayoutManager!
    private var coordinatorManager: CreateChatCoordinatorManager!
    private var encryptor: EncryptionManagerProtocol = EncryptionManager()

    // - Delegate
    weak var delegate: CreateChatViewControllerDelegate?
    
    private var isCopyButtonActivated = true {
        didSet {
            copyButton.setTitle(isCopyButtonActivated ? "Copy".localized : "Create".localized, for: .normal)
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        configure()
    }

    @IBAction func createButtonAction(_ sender: Any) {
        let chat = ChatDTOModel()
        chat.name = nameTextField.text ?? ""
        let realm = try! Realm()
        try? realm.write {
            [weak self] in guard let self = self else { return }
            realm.add(chat)
            self.delegate?.chatCreated(chat: chat)
            KeychainManager.shared.setPasswordForChat(chatId: chat.chatId, password: passwordTextField.text ?? encryptor.generateKey())
            self.dismiss(animated: true, completion: nil)
        }
    }
    
    @IBAction func copyButtonAction(_ sender: Any) {
        UIView.animate(withDuration: 0.6,
                       animations: {
            self.copyButton.transform = CGAffineTransform(scaleX: 0.6, y: 0.6)
        },
                       completion: { _ in
            UIView.animate(withDuration: 0.6) {
                self.copyButton.transform = CGAffineTransform.identity
            }
        })
        if isCopyButtonActivated {
            UIPasteboard.general.string = passwordTextField.text
        }
        else {
            passwordTextField.text = encryptor.generateKey()
            isCopyButtonActivated = true
            createButton.isEnabled = (nameTextField.text ?? "").count > 1
        }
    }
    
    @objc private func textFieldDidChange(_ textField: UITextField) {
        let name = nameTextField.text ?? ""
        let password = (passwordTextField.text ?? "").trimmingCharacters(in: .whitespacesAndNewlines)
        let isEnabled = name.count > 1 && encryptor.isKeyValid(stringKey: password)
        createButton.isEnabled = isEnabled
        if textField == passwordTextField, password.isEmpty {
            isCopyButtonActivated = false
        }
    }
    
}

// MARK: -
// MARK: - ViewController Lifecycle

extension CreateChatViewController {

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        layoutManager.viewWillAppear(animated)
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        layoutManager.viewWillDisappear(animated)
    }

}

// MARK: -
// MARK: - Configure

private extension CreateChatViewController {
    
    func configure() {
        configureLayoutManager()
        configureCoordinatorManager()
        configureTextFields()
    }
    
    func configureLayoutManager() {
        layoutManager = CreateChatLayoutManager(viewController: self)
    }
    
    func configureCoordinatorManager() {
        coordinatorManager = CreateChatCoordinatorManager(viewController: self)
    }
    
    func configureTextFields() {
        passwordTextField.addTarget(self, action: #selector(textFieldDidChange(_:)), for: .editingChanged)
        nameTextField.addTarget(self, action: #selector(textFieldDidChange(_:)), for: .editingChanged)
        createButton.isEnabled = false
        isCopyButtonActivated.toggle()
        createButton.setTitle("Save".localized, for: .normal)
    }
    
}
