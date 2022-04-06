import Foundation
import RealmSwift
import MessageKit
import p_sms

@objcMembers class MessageDTOModel: Object {
    
    dynamic var isOwner: Bool = true
    dynamic var encryptedMessage: String = ""
    dynamic var decryptedMessage: String = ""
    dynamic var chatId: String = UUID().uuidString
    dynamic var sentDate: Date = Date(timeIntervalSince1970: 0)
    dynamic var messageId: String = UUID().uuidString
    
    override static func primaryKey() -> String? {
        return "messageId"
    }
    
}

struct ChatCellModel: MessageType {
    
    var user: ChatUser
    var messageId: String
    var sentDate: Date
    var kind: MessageKind
    
    var sender: SenderType {
        return user
    }
    
    private init(kind: MessageKind, user: ChatUser, messageId: String, date: Date) {
        self.kind = kind
        self.user = user
        self.messageId = messageId
        self.sentDate = date
    }
    
    private init(text: String, user: ChatUser, messageId: String, date: Date) {
        self.init(kind: .text(text), user: user, messageId: messageId, date: date)
    }
    
    init?(message: MessageDTOModel, key: String) {
        if key.isEmpty {
            return nil
        }
        let decryptedMessage = EncryptionManager().tryDecode(str: message.encryptedMessage, stringKey: key)
        if decryptedMessage == message.encryptedMessage {
            return nil
        }
        let user = ChatUser(senderId: message.isOwner ? "1": "0", displayName: "")
        self.init(text: decryptedMessage, user: user, messageId: message.messageId, date: message.sentDate)
    }
    
}


@objcMembers class ChatDTOModel: Object {
    
    dynamic var name: String = ""
    dynamic var phone: String = ""
    dynamic var lastMessage: MessageDTOModel? = nil
    dynamic var chatId: String = UUID().uuidString
    dynamic var encryptionScheme: Int32 = 0
    
    var encryptionType: EncryptionSchemeType {
        return EncryptionSchemeType(rawValue: encryptionScheme) ?? .base64
    }
    
}

struct ChatUser: SenderType, Equatable {

    var senderId: String
    var displayName: String

}
