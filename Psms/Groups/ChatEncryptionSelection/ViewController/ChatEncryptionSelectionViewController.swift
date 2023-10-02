import UIKit

final class ChatEncryptionSelectionViewController: PopUpViewController {
    // - UI
    @IBOutlet weak var picker: UIPickerView!
    
    // - DataSource
    private var dataSource: EncryptionPickerDataSource!
    
    // - Delegate
    private weak var delegate: ChatEncryptionSelectionDelegate?
    
    private var selectedScheme = EncryptionSchemeType.text
    
    override func viewDidLoad() {
        super.viewDidLoad()
        configure()
    }
    
    @IBAction func applyButtonAction(_ sender: Any) {
        delegate?.didSelectEncryptionScheme(selectedScheme)
        dismiss(animated: true, completion: nil)
    }
    
    func setup(initialEncryptionScheme: EncryptionSchemeType, delegate: ChatEncryptionSelectionDelegate) {
        self.selectedScheme = initialEncryptionScheme
        self.delegate = delegate
    }
    
}


// MARK: -
// MARK: - Configure

private extension ChatEncryptionSelectionViewController {

    func configure() {
        configureDataSource()
    }
    
    func configureDataSource() {
        dataSource = EncryptionPickerDataSource(picker: picker)
        dataSource.delegate = self
        dataSource.updateItems(items: EncryptionSchemeType.allCases)
        picker.selectRow(EncryptionSchemeType.allCases.firstIndex(of: selectedScheme) ?? 0, inComponent: 0, animated: false)
    }

}

// MARK: -
// MARK: - ChatEncryptionSelectionDelegate

extension ChatEncryptionSelectionViewController: ChatEncryptionSelectionDelegate {
    
    func didSelectEncryptionScheme(_ scheme: EncryptionSchemeType) {
        selectedScheme = scheme
    }
    
}
