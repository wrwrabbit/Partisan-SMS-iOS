
import RealmSwift

class ChatDataBaseManager {
    
    // - Realm
    private lazy var realm = try! Realm()
    
    func addMessage(_ message: MessageDTOModel) {
        try? realm.write {
            realm.add(message)
        }
    }
    
    func getMessages() -> Results<MessageDTOModel> {
        let items = realm.objects(MessageDTOModel.self)
        return items
    }
    
    func updateChatEncryption(chat: ChatDTOModel, scheme: EncryptionSchemeType) {
        try? realm.write {
            chat.encryptionScheme = scheme.rawValue
        }
    }
    
    func deleteMessage(id: String) {
        if let message = realm.object(ofType: MessageDTOModel.self, forPrimaryKey: id) {
            try? realm.write {
                realm.delete(message)
            }
        }
    }
    
}
