import UIKit

class CreateChatLayoutManager: NSObject {

    // - UI
    private unowned let viewController: CreateChatViewController
    
    init(viewController: CreateChatViewController) {
        self.viewController = viewController
        super.init()
        configure()
    }

}

// MARK: -
// MARK: - ViewController Lifecycle

extension CreateChatLayoutManager {

    func viewWillAppear(_ animated: Bool) {
    
    }
    
    func viewWillDisappear(_ animated: Bool) {
    
    }

}

// MARK: -
// MARK: - Configure

private extension CreateChatLayoutManager {

    func configure() {

    }

}
