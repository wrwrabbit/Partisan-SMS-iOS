import UIKit

class ChatListTableViewDataSource: NSObject {

       // - Init
       private unowned let tableView: UITableView

       // - Data
       private var items = [ChatListCellModel]()

       // - Delegate
       weak var delegate: ChatListTableViewDataSourceDelegate?
       
       // - Lifecycle
       init(tableView: UITableView) {
           self.tableView = tableView
           super.init()
           configure()
       }

       func update(with items: [ChatListCellModel]) {
           self.items = items
           tableView.reloadData()
       }

       func update() {
           tableView.reloadData()
       }

}

// MARK: -
// MARK: - UITableViewDataSource

extension ChatListTableViewDataSource: UITableViewDataSource {

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return items.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: Cell.item.rawValue, for: indexPath) as! ChatListTableViewCell
        for gesture in cell.gestureRecognizers ?? [] {
            cell.removeGestureRecognizer(gesture)
        }
        let row = indexPath.row
        let cellData = items[row]
        let longPressRecognizer = UILongPressGestureRecognizer {
            [weak self] in
            self?.delegate?.didTapActions(item: cellData)
        }
        cell.addGestureRecognizer(longPressRecognizer)
        cell.setData(item: cellData)
        return cell
    }

}

// MARK: -
// MARK: - UITableViewDelegate

extension ChatListTableViewDataSource: UITableViewDelegate {

    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        delegate?.didTapOnCell(item: items[indexPath.row])
    }

}

// MARK: -
// MARK: - Configure

private extension ChatListTableViewDataSource {

    enum Cell: String {
        case item = "ChatListTableViewCell"
    }

    func configure() {
        setupDataSource()
    }

    func setupDataSource() {
        tableView.dataSource = self
        tableView.delegate = self
    }

}
