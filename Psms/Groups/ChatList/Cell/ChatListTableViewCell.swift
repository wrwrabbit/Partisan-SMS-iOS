import UIKit

class ChatListTableViewCell: UITableViewCell {

    // - UI
    @IBOutlet var dateLabel: UILabel!
    @IBOutlet var nameLabel: UILabel!

    override func awakeFromNib() {
        super.awakeFromNib()
        configure()
    }

    func setData(item: ChatListCellModel) {
        nameLabel.text = item.model.name
        dateLabel.text = item.model.lastMessage?.sentDate.getTimeAgo() ?? ""
    }

}

// MARK: -
// MARK: - Configure

private extension ChatListTableViewCell {

    func configure() {
        selectionStyle = .none
    }

}
