import UIKit

class PopUpViewController: UIViewController {

    private var isPresenting = false
    var mainView: UIView!

    override func viewDidLoad() {
        super.viewDidLoad()
        configurePopUp()
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
        modalPresentationStyle = .custom
        transitioningDelegate = self
    }

}

// MARK: -
// MARK: - Configure

private extension PopUpViewController {

    func configurePopUp() {
        mainView = view
        for subview in view.subviews {
            if subview.subviews.count > mainView.subviews.count {
                mainView = subview
            }
        }
        mainView = mainView!
        mainView.layer.cornerRadius = 20
        mainView.layer.shadowRadius = 4
        mainView.layer.shadowOffset = CGSize(width: 0, height: 4)
        mainView.layer.shadowOpacity = 0.25
        view.backgroundColor = UIColor.black.withAlphaComponent(0)
        let tapGesture = UITapGestureRecognizer(target: self, action: #selector(close))
        tapGesture.cancelsTouchesInView = false
        tapGesture.delegate = self
        view.addGestureRecognizer(tapGesture)
    }

    @objc private func close() {
        dismiss(animated: true, completion: nil)
    }

}

// MARK: -
// MARK: - UIViewControllerAnimatedTransitioning

extension PopUpViewController: UIViewControllerAnimatedTransitioning {

    func transitionDuration(using transitionContext: UIViewControllerContextTransitioning?) -> TimeInterval {
        return 1
    }

    func animateTransition(using transitionContext: UIViewControllerContextTransitioning) {
        let containerView = transitionContext.containerView
        let toViewController = transitionContext.viewController(forKey: UITransitionContextViewControllerKey.to)
        guard let toVC = toViewController else { return }
        isPresenting = !isPresenting
        if isPresenting == true {
            containerView.addSubview(toVC.view)
            mainView.frame.origin.y += mainView.frame.height
            view.backgroundColor = UIColor.black.withAlphaComponent(0)
            UIView.animate(withDuration: 0.4, delay: 0, options: [.curveEaseOut], animations: {
                self.mainView.frame.origin.y -= self.mainView.frame.height
                self.view.backgroundColor = UIColor.black.withAlphaComponent(0.5)
            }, completion: { _ in
                transitionContext.completeTransition(true)
            })
        }
        else {
            UIView.animate(withDuration: 0.4, delay: 0, options: [.curveEaseOut], animations: {
                self.mainView.frame.origin.y += self.mainView.frame.height
                self.view.backgroundColor = UIColor.black.withAlphaComponent(0)
            }, completion: { _ in
                transitionContext.completeTransition(true)
            })
        }

    }

}

// MARK: -
// MARK: - UIViewControllerTransitioningDelegate

extension PopUpViewController: UIViewControllerTransitioningDelegate {

    func animationController(forPresented presented: UIViewController, presenting: UIViewController, source: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        return self
    }

    func animationController(forDismissed dismissed: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        return self
    }

}

// MARK: -
// MARK: - UIGestureRecognizerDelegate

extension PopUpViewController: UIGestureRecognizerDelegate {

    func gestureRecognizer(_ gestureRecognizer: UIGestureRecognizer, shouldReceive touch: UITouch) -> Bool {
        if touch.view == view {
            return true
        }
        return false
    }

}
