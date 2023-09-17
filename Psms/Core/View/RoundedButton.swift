import UIKit

final class RoundedButton: UIButton {

    override var isEnabled: Bool {
        didSet {
            alpha = isEnabled ? 1.0 : 0.3
        }
    }

    override func awakeFromNib() {
        super.awakeFromNib()
        configure()
    }

}

// MARK: -
// MARK: - Configure

private extension RoundedButton {

    func configure() {
        backgroundColor = .systemBlue
        setTitleColor(.white, for: .normal)
        layer.cornerRadius = 7
        clipsToBounds = true
    }

}
