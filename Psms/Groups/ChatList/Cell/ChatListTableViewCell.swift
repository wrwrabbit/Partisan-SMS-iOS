import UIKit

final class ChatListTableViewCell: UITableViewCell {

    // - UI
    @IBOutlet weak var avatarView: UIView!
    @IBOutlet weak var avatarLabel: UILabel!
    @IBOutlet var dateLabel: UILabel!
    @IBOutlet var nameLabel: UILabel!

    override func awakeFromNib() {
        super.awakeFromNib()
        configure()
    }

    func setData(item: ChatListCellModel) {
        let name = item.model.name
        nameLabel.text = name
        dateLabel.text = item.model.lastMessage?.sentDate.getTimeAgo() ?? ""
        let initials = getInitials(from: name)
        avatarLabel.text = initials
        avatarView.backgroundColor = getColorForCharacter(initials.first!)
    }
    
    private func getInitials(from name: String) -> String {
        var initials = ""
        initials = String(name.first ?? Character("a"))
        let components = name.components(separatedBy: " ")
        if components.count > 1,
           let secondLetter = components[1].first
        {
            initials += String(secondLetter)
        }
        return initials.uppercased()
    }
    
    private func getColorForCharacter(_ character: Character) -> UIColor {
        let alphabetColors = [0x5A8770, 0xB2B7BB, 0x6FA9AB, 0xF5AF29, 0x0088B9, 0xF18636, 0xD93A37, 0xA6B12E, 0x5C9BBC, 0xF5888D, 0x9A89B5, 0x407887, 0x9A89B5, 0x5A8770, 0xD33F33, 0xA2B01F, 0xF0B126, 0x0087BF, 0xF18636, 0x0087BF, 0xB2B7BB, 0x72ACAE, 0x9C8AB4, 0x5A8770, 0xEEB424, 0x407887]
        let str = String(character).unicodeScalars
        let unicode = Int(str[str.startIndex].value)
        let hex = alphabetColors[unicode % 26]
        return UIColor(red: CGFloat(Double((hex >> 16) & 0xFF)) / 255.0, green: CGFloat(Double((hex >> 8) & 0xFF)) / 255.0, blue: CGFloat(Double((hex >> 0) & 0xFF)) / 255.0, alpha: 1.0)
    }

}

// MARK: -
// MARK: - Configure

private extension ChatListTableViewCell {

    func configure() {
        selectionStyle = .none
        avatarLabel.minimumScaleFactor = 0.2
        avatarLabel.baselineAdjustment = .alignCenters
        avatarLabel.adjustsFontSizeToFitWidth = true
    }

}
