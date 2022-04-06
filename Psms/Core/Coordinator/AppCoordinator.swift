import UIKit

class AppCoordinator {
    
    func start() {
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        appDelegate.window = UIWindow(frame: UIScreen.main.bounds)
        appDelegate.window?.makeKeyAndVisible()
        if KeychainManager.shared.fakePassword == nil {
            appDelegate.window?.rootViewController = UIStoryboard(storyboard: .securitySetup).instantiateInitialViewController()!
        }
        else {
            appDelegate.window?.rootViewController = UIStoryboard(storyboard: .unlockPassword).instantiateInitialViewController()!
        }
    }
    
    func hideSensitiveInfo() {
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        appDelegate.window?.rootViewController = UIStoryboard(storyboard: .launchScreen).instantiateInitialViewController()!
    }
    
}
