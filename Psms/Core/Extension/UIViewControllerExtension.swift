import UIKit

// MARK: -
// MARK: - presentation style

extension UIViewController {

    func presentInFullScreen(_ viewController: UIViewController,
                             animated: Bool,
                             completion: (() -> Void)? = nil) {
        viewController.modalPresentationStyle = .fullScreen
        present(viewController, animated: animated, completion: completion)
    }

    func pushInFullScreen(_ viewController: UIViewController,
                          animated: Bool) {
        viewController.modalPresentationStyle = .fullScreen
        navigationController?.pushViewController(viewController, animated: true)
    }

}

// MARK: -
// MARK: - loading animation

extension UIViewController {

    func showSpinner() {
        let spinnerView = UIView(frame: view.bounds)
        spinnerView.tag = 105
        spinnerView.backgroundColor = UIColor.clear
        let activityIndicator = UIActivityIndicatorView()
        if #available(iOS 13.0, *) {
            activityIndicator.style = .large
        } else {
            activityIndicator.style = .gray
        }
        activityIndicator.startAnimating()
        activityIndicator.center = spinnerView.center
        spinnerView.addSubview(activityIndicator)
        view.addSubview(spinnerView)
    }

    func removeSpinner() {
        DispatchQueue.main.async {
            [weak self] in
            for subview in self?.view.subviews ?? [] {
                if subview.tag == 105 {
                    subview.removeFromSuperview()
                }
            }
        }
    }

}

// MARK: -
// MARK: - displayError

extension UIViewController {

    func displayError(error: String, title: String = "Error") {
        let alert = UIAlertController(title: title, message: error, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Ok", style: .cancel, handler: nil))
        self.present(alert, animated: true)
    }

}

// MARK: -
// MARK: - Popover presentation

extension UIViewController {
    
    @objc public func popoverPresentationControllerDidDismissPopover(_ popoverPresentationController: UIPopoverPresentationController) {
        self.setAlphaOfBackgroundViews(alpha: 1)
        self.navigationController?.navigationBar.backgroundColor = .white
    }

    @objc public func prepareForPopoverPresentation(_ popoverPresentationController: UIPopoverPresentationController) {
        self.setAlphaOfBackgroundViews(alpha: 0.7)
        self.navigationController?.navigationBar.backgroundColor = .clear
    }

    func setAlphaOfBackgroundViews(alpha: CGFloat) {
        UIView.animate(withDuration: 0.2) {
            self.view.alpha = alpha
            self.navigationController?.navigationBar.alpha = alpha
        }
    }

    func dismissPopover(_ completion: (() -> Void)? = nil) {
        self.dismiss(animated: true, completion: completion)
        popoverPresentationController?.delegate?.popoverPresentationControllerDidDismissPopover?(popoverPresentationController!)
    }

}
