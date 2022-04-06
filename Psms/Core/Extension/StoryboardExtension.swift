import UIKit

extension UIStoryboard {

    convenience init(storyboard: Storyboard, bundle: Bundle? = nil) {
        self.init(name: storyboard.fileName, bundle: bundle)
    }

}
