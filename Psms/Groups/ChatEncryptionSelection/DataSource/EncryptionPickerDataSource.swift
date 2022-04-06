import UIKit

class EncryptionPickerDataSource: NSObject {

    // - UI
    private var picker: UIPickerView!

    // - Delegate
    weak var delegate: ChatEncryptionSelectionDelegate?

    private var items: [EncryptionSchemeType] = []

    // - Lifecycle
    init(picker: UIPickerView) {
        super.init()
        self.picker = picker
        configure()
    }

}

// MARK: -
// MARK: - Configure

private extension EncryptionPickerDataSource {

    func configure() {
        picker.delegate = self
        picker.dataSource = self
    }

}

// MARK: -
// MARK: - UIPickerViewDataSource, UIPickerViewDelegate

extension EncryptionPickerDataSource: UIPickerViewDataSource {

    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }

    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return items.count
    }

    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return items[row].name
    }

}

// MARK: -
// MARK: - UIPickerViewDelegate

extension EncryptionPickerDataSource: UIPickerViewDelegate {

    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        let item = items[row]
        delegate?.didSelectEncryptionScheme(item)
    }

}

// MARK: -
// MARK: - updateItems

extension EncryptionPickerDataSource {

    func updateItems(items: [EncryptionSchemeType]) {
        self.items = items
        picker.reloadAllComponents()
    }

}


