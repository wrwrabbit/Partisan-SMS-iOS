import Foundation

enum Storyboard: String {

    case chatList = "ChatList"
    case createChat = "CreateChat"
    case unlockPassword = "UnlockPassword"
    case securitySetup = "SecuritySetup"
    case chatEncryptionSelection = "ChatEncryptionSelection"
    case launchScreen = "LaunchScreen"
    case onboarding = "Onboarding"

    var fileName: String {
        return rawValue
    }

}
