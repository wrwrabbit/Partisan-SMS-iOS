import UIKit
import Contacts
import MessageUI

final class ChatCoordinatorManager {

    // - UI
    private unowned let viewController: ChatViewController

    init(viewController: ChatViewController) {
        self.viewController = viewController
    }
    
    func showSendSMS(phones: [String], text: String) {
        let messageVC = MFMessageComposeViewController()
        messageVC.body = text
        messageVC.recipients = phones
        messageVC.messageComposeDelegate = viewController
        viewController.present(messageVC, animated: true, completion: nil)
    }
    
    func showEncryptionSelection(initialEncryptionScheme: EncryptionSchemeType) {
        let vc = UIStoryboard(storyboard: .chatEncryptionSelection).instantiateInitialViewController() as! ChatEncryptionSelectionViewController
        vc.setup(initialEncryptionScheme: initialEncryptionScheme, delegate: viewController)
        vc.modalPresentationStyle = .custom
        viewController.present(vc, animated: true, completion: nil)
    }

}
