import UIKit

final class ChatListCoordinatorManager {

    // - UI
    private unowned let viewController: ChatListViewController

    init(viewController: ChatListViewController) {
        self.viewController = viewController
    }

    func showCreateChat() {
        let vc = UIStoryboard(storyboard: .createChat).instantiateInitialViewController() as! CreateChatViewController
        vc.delegate = viewController
        vc.modalPresentationStyle = .custom
        viewController.present(vc, animated: true, completion: nil)
    }
    
    func showChat(chat: ChatDTOModel) {
        if let key = KeychainManager.shared.getPasswordForChat(chatId: chat.chatId) {
            let vc = ChatViewController()
            vc.setup(chat: chat, key: key)
            viewController.pushInFullScreen(vc, animated: true)
        }
    }

}
