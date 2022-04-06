import UIKit

class ChatListLayoutManager: NSObject {

    // - UI
    private unowned let viewController: ChatListViewController
    
    init(viewController: ChatListViewController) {
        self.viewController = viewController
        super.init()
        configure()
    }

}

// MARK: -
// MARK: - ViewController Lifecycle

extension ChatListLayoutManager {

    func viewWillAppear(_ animated: Bool) {
    
    }
    
    func viewWillDisappear(_ animated: Bool) {
    
    }

}

// MARK: -
// MARK: - Configure

private extension ChatListLayoutManager {

    func configure() {

    }

}
