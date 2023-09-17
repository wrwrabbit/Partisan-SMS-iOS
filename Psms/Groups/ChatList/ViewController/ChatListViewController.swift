import Actions
import EmptyDataSet_Swift
import RealmSwift
import UIKit

final class ChatListViewController: UIViewController {

    // - UI
    @IBOutlet var tableView: UITableView!

    // - Data source
    private var tableViewDataSource: ChatListTableViewDataSource!

    // - Data
    private var chats: Results<ChatDTOModel>?
    private var chatsToken: NotificationToken?

    // - Manager
    private var layoutManager: ChatListLayoutManager!
    private var coordinatorManager: ChatListCoordinatorManager!

    override func viewDidLoad() {
        super.viewDidLoad()
        configure()
    }

    deinit {
        chatsToken?.invalidate()
    }

}

// MARK: -
// MARK: - ViewController Lifecycle

extension ChatListViewController {

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
// MARK: - Data source delegate

extension ChatListViewController: ChatListTableViewDataSourceDelegate {
    
    func didTapActions(item: ChatListCellModel) {
        let actionSheetController = UIAlertController(title: "Actions".localized, message: nil, preferredStyle: .actionSheet)
        let deleteAction = UIAlertAction(title: "Delete".localized, style: .destructive) {
            [weak self] _ in
            guard let self = self else { return }
            let realm = try! Realm()
            try? realm.write {
                realm.delete(realm.objects(MessageDTOModel.self).filter({ $0.chatId == item.model.chatId }))
                realm.delete(item.model)
            }
        }
        actionSheetController.addAction(deleteAction)
        let cancelAction = UIAlertAction(title: "Cancel".localized, style: .cancel) {
            _ in
        }
        actionSheetController.addAction(cancelAction)
        self.presentInFullScreen(actionSheetController, animated: true, completion: nil)
    }
    

    func didTapOnCell(item: ChatListCellModel) {
        coordinatorManager.showChat(chat: item.model)
    }

}

// MARK: -
// MARK: - Configure

private extension ChatListViewController {

    func configure() {
        configureLayoutManager()
        configureDataSourceManager()
        configureCoordinatorManager()
        configureObserver()
        configureNavigationBar()
    }

    func configureLayoutManager() {
        layoutManager = ChatListLayoutManager(viewController: self)
    }

    func configureDataSourceManager() {
        tableViewDataSource = ChatListTableViewDataSource(tableView: tableView)
        tableViewDataSource.delegate = self
        tableView.emptyDataSetSource = self
    }

    func configureCoordinatorManager() {
        coordinatorManager = ChatListCoordinatorManager(viewController: self)
    }

    func configureObserver() {
        chats = try? Realm().objects(ChatDTOModel.self)
        chatsToken = chats?.observe {
            [weak self] _ in
            guard let self = self else { return }
            var cellData = [ChatListCellModel]()
            for item in self.chats! {
                if let _ = KeychainManager.shared.getPasswordForChat(chatId: item.chatId) {
                    cellData.append(ChatListCellModel(model: item))
                }
            }
            self.tableViewDataSource.update(with: cellData)
        }
    }

    func configureNavigationBar() {
        let rightItem = UIBarButtonItem(barButtonSystemItem: .add) {
            [weak self] in guard let self = self else { return }
            self.coordinatorManager.showCreateChat()
        }
        navigationItem.rightBarButtonItem = rightItem
    }

}

// MARK: -
// MARK: - DefaultEmptyDataSource

extension ChatListViewController: EmptyDataSetSource {

    func title(forEmptyDataSet scrollView: UIScrollView) -> NSAttributedString? {
        return NSAttributedString(string: "NoChats".localized, attributes: [:])
    }

}

// MARK: -
// MARK: - CreateChatViewControllerDelegate

extension ChatListViewController: CreateChatViewControllerDelegate {
    
    func chatCreated(chat: ChatDTOModel) {
        coordinatorManager.showChat(chat: chat)
    }
    
}
