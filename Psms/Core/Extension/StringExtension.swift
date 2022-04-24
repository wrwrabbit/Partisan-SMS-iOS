import Foundation

extension String {
    var localized: String {
        let value = NSLocalizedString(self, tableName: nil, bundle: Bundle.main, value: "", comment: "")
        if value != self || NSLocale.preferredLanguages.first == "en" {
            return value
        }

        // Fall back to en
        guard
            let path = Bundle.main.path(forResource: "en", ofType: "lproj"),
            let bundle = Bundle(path: path)
        else { return value }
        return value
    }
}
