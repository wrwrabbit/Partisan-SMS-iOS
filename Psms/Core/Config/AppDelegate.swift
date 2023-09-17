import UIKit
import RealmSwift
import p_sms
import IQKeyboardManagerSwift

@main
final class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    var appCoordinator = AppCoordinator()

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        appCoordinator.start()
        configure()
        return true
    }
    
    func applicationWillResignActive(_ application: UIApplication) {
        appCoordinator.hideSensitiveInfo()
    }
    
    func applicationDidBecomeActive(_ application: UIApplication) {
        appCoordinator.start()
    }

}

// MARK: -
// MARK: - Configure

private extension AppDelegate {
    
    func configure() {
        configureDataBase()
        configureIQKeyboard()
    }
    
    func configureDataBase() {
        let config = Realm.Configuration(
            schemaVersion: 4,
            migrationBlock: { _, oldSchemaVersion in
                if oldSchemaVersion < 1 {}
            })
        Realm.Configuration.defaultConfiguration = config
        _ = try! Realm()
    }
    
    func configureIQKeyboard() {
        IQKeyboardManager.shared.enable = true
        IQKeyboardManager.shared.disabledDistanceHandlingClasses = [
            ChatViewController.self
        ]
    }
    
}


