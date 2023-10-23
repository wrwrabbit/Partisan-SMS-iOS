//
//  ChatEncryptionSelectionLayoutManager.swift
//  Psms
//
//  Created by BillyGatesNew on 23/10/2023.
//

import UIKit

final class ChatEncryptionSelectionLayoutManager: NSObject {

    // - UI
    private unowned let viewController: ChatEncryptionSelectionViewController
    
    private var isCopyButtonAnimating = false

    init(viewController: ChatEncryptionSelectionViewController) {
        self.viewController = viewController
        super.init()
        configure()
    }
    
    @objc func copyButtonPressed(sender: UIButton) {
        if isCopyButtonAnimating { return }
        
        isCopyButtonAnimating = true
        UIView.animate(withDuration: 0.1, animations: {
            sender.transform = CGAffineTransform(scaleX: 1.2, y: 1.2)
        }) { _ in
            self.isCopyButtonAnimating = false
        }
    }
    
    @objc func copyButtonReleased(sender: UIButton) {
        if isCopyButtonAnimating {
            DispatchQueue.main.asyncAfter(deadline: .now() + 0.1) {
                self.copyButtonReleased(sender: sender)
            }
            return
        }
        
        UIView.animate(withDuration: 0.1, animations: {
            sender.transform = CGAffineTransform.identity
        })
    }

}



// MARK: -
// MARK: - ViewController Lifecycle

extension ChatEncryptionSelectionLayoutManager {

    func viewWillAppear(_ animated: Bool) {
    
    }
    
    func viewWillDisappear(_ animated: Bool) {
    
    }

}

// MARK: -
// MARK: - Configure

private extension ChatEncryptionSelectionLayoutManager {

    func configure() {
        viewController.copyButton.addTarget(self, action: #selector(copyButtonPressed), for: .touchDown)
        viewController.copyButton.addTarget(self, action: #selector(copyButtonReleased), for: .touchUpInside)
        viewController.copyButton.addTarget(self, action: #selector(copyButtonReleased), for: .touchUpOutside)
    }

}
