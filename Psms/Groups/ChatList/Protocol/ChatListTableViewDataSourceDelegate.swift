import UIKit

protocol ChatListTableViewDataSourceDelegate: class {

    func didTapOnCell(item: ChatListCellModel)
    func didTapActions(item: ChatListCellModel)

}
