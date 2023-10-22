import UIKit
import EFQRCode

final class ChatEncryptionSelectionViewController: UIViewController {
    // - UI
    @IBOutlet weak var copyButton: UIButton!
    @IBOutlet weak var qrCodeImageView: UIImageView!
    @IBOutlet weak var picker: UIPickerView!
    
    // - DataSource
    private var dataSource: EncryptionPickerDataSource!
    
    // - Delegate
    private weak var delegate: ChatEncryptionSelectionDelegate?
    
    // - Manager
    private var layoutManager: ChatEncryptionSelectionLayoutManager!
    
    private var selectedScheme = EncryptionSchemeType.text
    private var securityKey = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        configure()
    }
    
    @IBAction func applyButtonAction(_ sender: Any) {
        delegate?.didSelectEncryptionScheme(selectedScheme)
        dismiss(animated: true, completion: nil)
    }
    
    func setup(initialEncryptionScheme: EncryptionSchemeType, delegate: ChatEncryptionSelectionDelegate, securityKey: String) {
        self.selectedScheme = initialEncryptionScheme
        self.delegate = delegate
        self.securityKey = securityKey
    }

    @IBAction func copyKeyButtonAction(_ sender: Any) {
        UIPasteboard.general.string = securityKey
    }
    
}


// MARK: -
// MARK: - Configure

private extension ChatEncryptionSelectionViewController {

    func configure() {
        configureDataSource()
        configureQRCodeImageView()
        configureLayoutManager()
    }
    
    func configureDataSource() {
        dataSource = EncryptionPickerDataSource(picker: picker)
        dataSource.delegate = self
        dataSource.updateItems(items: EncryptionSchemeType.allCases)
        picker.selectRow(EncryptionSchemeType.allCases.firstIndex(of: selectedScheme) ?? 0, inComponent: 0, animated: false)
    }
    
    func configureQRCodeImageView() {
        if let image = EFQRCode.generate(
            for: securityKey
        ) {
            qrCodeImageView.image = UIImage(cgImage: image)
        }
    }
    
    func configureLayoutManager() {
        layoutManager = ChatEncryptionSelectionLayoutManager(viewController: self)
    }

}

// MARK: -
// MARK: - ViewController Lifecycle

extension ChatEncryptionSelectionViewController {

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
// MARK: - ChatEncryptionSelectionDelegate

extension ChatEncryptionSelectionViewController: ChatEncryptionSelectionDelegate {
    
    func didSelectEncryptionScheme(_ scheme: EncryptionSchemeType) {
        selectedScheme = scheme
    }
    
}
