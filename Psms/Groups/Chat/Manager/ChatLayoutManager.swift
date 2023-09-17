import UIKit

final class ChatLayoutManager: NSObject {

    // - UI
    private unowned let viewController: ChatViewController

    init(viewController: ChatViewController) {
        self.viewController = viewController
        super.init()
        configure()
    }

}

// MARK: -
// MARK: - ViewController Lifecycle

extension ChatLayoutManager {

    func viewWillAppear(_ animated: Bool) {
//        viewController.navigationController?.setNavigationBarHidden(false, animated: animated)
//        viewController.tabBarController?.tabBar.isHidden = true
//        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow), name: UIResponder.keyboardDidShowNotification, object: nil)
//        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide), name: UIResponder.keyboardDidHideNotification, object: nil)
    }

    func viewWillDisappear(_ animated: Bool) {
//        NotificationCenter.default.removeObserver(self)
    }

}

// MARK: -
// MARK: - Configure

private extension ChatLayoutManager {

    func configure() {
        //viewController.messagesCollectionView.removeAllConstraints()
    }

}

// MARK: -
// MARK: - Keyboard management

//private extension ChatLayoutManager {
//
//    @objc func keyboardWillShow(notification: NSNotification) {
//        if let keyboardSize = (notification.userInfo?[UIResponder.keyboardFrameEndUserInfoKey] as? NSValue)?.cgRectValue {
//            let height = keyboardSize.height
//            UIView.animate(withDuration: 0.15) {
//                self.resizeCommentCollection(keyboardHeight: height)
//                self.viewController.view.layoutIfNeeded()
//            }
//        }
//    }
//
//    @objc func keyboardWillHide(notification: NSNotification) {
//        if ((notification.userInfo?[UIResponder.keyboardFrameBeginUserInfoKey] as? NSValue)?.cgRectValue) != nil {
//            isKeyboardOpened = false
//            UIView.animate(withDuration: 0.15) {
//                self.resizeCommentCollection()
//                self.viewController.view.layoutIfNeeded()
//            }
//        }
//    }
//
//}
