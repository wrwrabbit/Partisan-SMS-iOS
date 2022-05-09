import EmptyDataSet_Swift
import InputBarAccessoryView
import MessageKit
import RealmSwift
import p_sms
import MessageUI

class ChatViewController: MessagesViewController {

    // - UI
    @IBOutlet var containerView: UIView!

    // - Manager
    private var layoutManager: ChatLayoutManager!
    private var coordinatorManager: ChatCoordinatorManager!
    private var encryptor: EncryptionManagerProtocol = EncryptionManager()
    private var dataBaseManager = ChatDataBaseManager()

    // - Data
    private var items = [ChatCellModel]()
    private var messages: Results<MessageDTOModel>?
    private var messagesToken: NotificationToken?

    var key: String!
    var chat: ChatDTOModel!

    func setup(chat: ChatDTOModel, key: String) {
        self.key = key
        self.chat = chat
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        configure()
        NotificationCenter.default.addObserver(self, selector: #selector(checkPasteBoardMessage), name: UIApplication.willEnterForegroundNotification, object: nil)
    }

    func insertItems(_ items: [ChatCellModel]) {
        if !items.isEmpty {
            for item in items {
                if !self.items.contains(where: { $0.messageId == item.messageId }) {
                    self.items.append(item)
                }
            }
            messagesCollectionView.reloadData()
        }
    }

    deinit {
        messagesToken?.invalidate()
        NotificationCenter.default.removeObserver(self)
    }

    @objc private func checkPasteBoardMessage() {
        if let string = UIPasteboard.general.string,
           isTextEncrypted(text: string)
        {
            messageInputBar.inputTextView.text = string
        }
    }

    private func isTextEncrypted(text: String) -> Bool {
        return encryptor.isEncrypted(str: text, stringKey: key)
    }
    
    // - cell Actions
    
    override func collectionView(_ collectionView: UICollectionView, canPerformAction action: Selector, forItemAt indexPath: IndexPath, withSender sender: Any?) -> Bool {
        if action == NSSelectorFromString("delete:") {
            return true
        } else {
            return super.collectionView(collectionView, canPerformAction: action, forItemAt: indexPath, withSender: sender)
        }
    }
    
    override func collectionView(_ collectionView: UICollectionView, performAction action: Selector, forItemAt indexPath: IndexPath, withSender sender: Any?) {
        if action == NSSelectorFromString("delete:") {
            dataBaseManager.deleteMessage(id: items[indexPath.section].messageId)
        } else {
            super.collectionView(collectionView, performAction: action, forItemAt: indexPath, withSender: sender)
        }
    }

}

extension MessageCollectionViewCell {

    override open func delete(_ sender: Any?) {
        
        // Get the collectionView
        if let collectionView = self.superview as? UICollectionView {
            // Get indexPath
            if let indexPath = collectionView.indexPath(for: self) {
                // Trigger action
                collectionView.delegate?.collectionView?(collectionView, performAction: NSSelectorFromString("delete:"), forItemAt: indexPath, withSender: sender)
            }
        }
    }
}

// MARK: -
// MARK: - ViewController Lifecycle

extension ChatViewController {

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        layoutManager.viewWillAppear(animated)
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        layoutManager.viewWillDisappear(animated)
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        becomeFirstResponder()
        checkPasteBoardMessage()
    }

    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        if !UIApplication.shared.isKeyboardPresented {
            // layoutManager.resizeCommentCollection()
        }
        messagesCollectionView.scrollIndicatorInsets.bottom = 0
    }

}

// MARK: -
// MARK: - MessageInputBarDelegate

extension ChatViewController: InputBarAccessoryViewDelegate {

    func inputBar(_ inputBar: InputBarAccessoryView, didPressSendButtonWith text: String) {
        showSpinner()
        messageInputBar.inputTextView.resignFirstResponder()
        messageInputBar.inputTextView.text = String()
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.3) {
            [weak self] in guard let self = self else { return }
            let message = MessageDTOModel()
            message.chatId = self.chat.chatId
            let isEncrypted = self.isTextEncrypted(text: text)
            message.isOwner = isEncrypted ? false : true
            message.sentDate = Date()
            if isEncrypted {
                if self.encryptor.tryDecode(str: text, stringKey: self.key) == text {
                    self.messageInputBar.inputTextView.resignFirstResponder()
                    self.displayError(error: "Incorrect message")
                    return
                }
                message.encryptedMessage = text
            }
            else {
                message.encryptedMessage = self.encryptor.encode(str: text, stringKey: self.key, encryptionSchemeId: self.chat.encryptionScheme)
                self.coordinatorManager.showSendSMS(phones: [self.chat.phone], text: message.encryptedMessage)
            }
            self.dataBaseManager.addMessage(message)
            self.removeSpinner()
        }
    }

}

// MARK: -
// MARK: - Configure

private extension ChatViewController {

    func configure() {
        configureLayoutManager()
        configureCoordinatorManager()
        configureMessageInputBar()
        configureMessageCollectionView()
        configureNavigationBar()
        configureObserver()
    }

    func configureLayoutManager() {
        layoutManager = ChatLayoutManager(viewController: self)
    }

    func configureCoordinatorManager() {
        coordinatorManager = ChatCoordinatorManager(viewController: self)
    }

    func configureMessageInputBar() {
        let tapGesture = UITapGestureRecognizer {}
        tapGesture.delegate = self
        view.addGestureRecognizer(tapGesture)
        messageInputBar.delegate = self
        messageInputBar.sendButton.image = UIImage(named: "sendButton")
        messageInputBar.inputTextView.textColor = .black
        messageInputBar.inputTextView.placeholderTextColor = UIColor(hexString: "D8D8D8", alpha: 0.8)
        messageInputBar.isTranslucent = false
        messageInputBar.separatorLine.isHidden = true
        messageInputBar.inputTextView.tintColor = UIColor(hexString: "D8D8D8", alpha: 1)
        messageInputBar.inputTextView.textContainerInset = UIEdgeInsets(top: 8, left: 16, bottom: 8, right: 36)
        messageInputBar.inputTextView.placeholderLabelInsets = UIEdgeInsets(top: 8, left: 20, bottom: 8, right: 36)
        messageInputBar.inputTextView.layer.borderColor = UIColor(hexString: "#BEC4D9").cgColor
        messageInputBar.inputTextView.layer.borderWidth = 0.7
        messageInputBar.inputTextView.layer.cornerRadius = 19
        messageInputBar.inputTextView.layer.masksToBounds = true
        messageInputBar.inputTextView.scrollIndicatorInsets = UIEdgeInsets(top: 8, left: 0, bottom: 8, right: 0)
        messageInputBar.padding = UIEdgeInsets(top: 0, left: 17, bottom: 10, right: 17)
        messageInputBar.inputTextView.enablesReturnKeyAutomatically = false
        configureInputBarItems()
    }

    func configureInputBarItems() {
        messageInputBar.setRightStackViewWidthConstant(to: 36, animated: false)
        messageInputBar.sendButton.imageView?.backgroundColor = UIColor(white: 0.85, alpha: 1)
        messageInputBar.sendButton.contentEdgeInsets = UIEdgeInsets(top: 2, left: 2, bottom: 3, right: 2)
        messageInputBar.sendButton.setSize(CGSize(width: 36, height: 36), animated: false)
        messageInputBar.sendButton.title = "Comment"
        messageInputBar.sendButton.imageView?.layer.cornerRadius = 16
        messageInputBar.middleContentViewPadding.right = 17
        messageInputBar.inputTextView.placeholderLabel.text = "Message".localized
        messageInputBar.sendButton
            .onEnabled {
                [weak self] item in
                UIView.animate(withDuration: 0.3, animations: {
                    item.imageView?.backgroundColor = .white
                    self?.messageInputBar.sendButton.image = UIImage(named: "sendButton")
                })
            }.onDisabled { _ in }
    }

    func configureMessageCollectionView() {
        messagesCollectionView.messagesDataSource = self
        messagesCollectionView.messagesLayoutDelegate = self
        messagesCollectionView.messagesDisplayDelegate = self
        messagesCollectionView.backgroundColor = .clear
        let layout = messagesCollectionView.collectionViewLayout as? MessagesCollectionViewFlowLayout
        layout?.sectionInset = UIEdgeInsets(top: 8, left: 16, bottom: 8, right: 16)
        layout?.setMessageIncomingAvatarSize(CGSize(width: 0, height: 0))
        layout?.setMessageOutgoingAvatarSize(CGSize(width: 0, height: 0))
        layout?.attributedTextMessageSizeCalculator.outgoingMessageLabelInsets = UIEdgeInsets(top: 10, left: 16, bottom: 10, right: 16)
        layout?.attributedTextMessageSizeCalculator.incomingMessageLabelInsets = UIEdgeInsets(top: 10, left: 16, bottom: 10, right: 16)
        layout?.setMessageIncomingAvatarPosition(AvatarPosition(horizontal: .cellLeading, vertical: .messageTop))
        layout?.setMessageOutgoingAvatarPosition(AvatarPosition(horizontal: .cellTrailing, vertical: .messageTop))
    }

    func configureObserver() {
        showSpinner()
        messages = dataBaseManager.getMessages()
       // DispatchQueue.main.asyncAfter(deadline: .now() + 0.2) {
          
            self.messagesToken = self.messages?.observe {
                [weak self] _ in
                guard let self = self else { return }
                var cellData = [ChatCellModel]()
                for item in self.messages!.filter({ $0.chatId == self.chat.chatId }) {
                    if let cellModel = self.items.first(where: { $0.messageId == item.messageId }) {
                        cellData.append(cellModel)
                    }
                    else if let cellModel = ChatCellModel(message: item, key: self.key) {
                        cellData.append(cellModel)
                    }
                }
                self.items = cellData
                self.messagesCollectionView.reloadData()
                self.messagesCollectionView.scrollToLastItem()
                self.removeSpinner()
            }
       // }
    }

    func configureNavigationBar() {
        title = chat.name
        let button = UIButton()
        button.setImage(UIImage(named: "lockIcon"), for: .normal)
        button.addAction {
            [weak self] in guard let self = self else { return }
            self.coordinatorManager.showEncryptionSelection(initialEncryptionScheme: self.chat.encryptionType)
        }
        let rightItem = UIBarButtonItem(customView: button)
        navigationItem.rightBarButtonItem = rightItem
    }

}

// MARK: -
// MARK: - UITextViewDelegate

extension ChatViewController: UITextViewDelegate {

    func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
        if text == "\n" {
            textView.resignFirstResponder()
            return false
        }
        return true
    }

}

// MARK: -
// MARK: - EmptyDataSetSource & EmptyDataSetDelegate

extension ChatViewController: EmptyDataSetSource, EmptyDataSetDelegate {

    func title(forEmptyDataSet scrollView: UIScrollView) -> NSAttributedString? {
        return NSAttributedString(string: "No messages", attributes: [NSAttributedString.Key.font: UIFont.systemFont(ofSize: 20),
                                                                      NSAttributedString.Key.foregroundColor: UIColor.black])
    }

}

extension UIApplication {
    /// Checks if view hierarchy of application contains `UIRemoteKeyboardWindow` if it does, keyboard is presented
    var isKeyboardPresented: Bool {
        if let keyboardWindowClass = NSClassFromString("UIRemoteKeyboardWindow"),
           self.windows.contains(where: { $0.isKind(of: keyboardWindowClass) })
        {
            return true
        } else {
            return false
        }
    }
}

// MARK: -
// MARK: - MessagesDataSource

extension ChatViewController: MessagesDataSource {

    func isTimeLabelVisible(at indexPath: IndexPath) -> Bool {
        return indexPath.section % 3 == 0 && !isPreviousMessageSameSender(at: indexPath)
    }

    func isPreviousMessageSameSender(at indexPath: IndexPath) -> Bool {
        guard indexPath.section - 1 >= 0 else { return false }
        return items[indexPath.section].user == items[indexPath.section - 1].user
    }

    func isNextMessageSameSender(at indexPath: IndexPath) -> Bool {
        guard indexPath.section + 1 < items.count else { return false }
        return items[indexPath.section].user == items[indexPath.section + 1].user
    }

    func isLastSectionVisible() -> Bool {

        guard !items.isEmpty else { return false }

        let lastIndexPath = IndexPath(item: 0, section: items.count - 1)

        return messagesCollectionView.indexPathsForVisibleItems.contains(lastIndexPath)
    }

    // MARK: - MessagesDataSource

    func currentSender() -> SenderType {
        return ChatUser(senderId: "1", displayName: "")
    }

    func numberOfSections(in messagesCollectionView: MessagesCollectionView) -> Int {
        return items.count
    }

    func messageForItem(at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> MessageType {
        return items[indexPath.section]
    }

    func messageTopLabelAttributedText(for message: MessageType, at indexPath: IndexPath) -> NSAttributedString? {
        return nil
    }

    func messageBottomLabelAttributedText(for message: MessageType, at indexPath: IndexPath) -> NSAttributedString? {
        return nil
    }

    func cellTopLabelAttributedText(for message: MessageType, at indexPath: IndexPath) -> NSAttributedString? {
        if isTimeLabelVisible(at: indexPath) {
            return NSAttributedString(string: MessageKitDateFormatter.shared.string(from: message.sentDate), attributes: [NSAttributedString.Key.font: UIFont.systemFont(ofSize: 13), NSAttributedString.Key.foregroundColor: UIColor.gray])
        }
        return nil
    }

}

// MARK: -
// MARK: - MessagesLayoutDelegate

extension ChatViewController: MessagesLayoutDelegate {

    func cellTopLabelHeight(for message: MessageType, at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> CGFloat {
        return isTimeLabelVisible(at: indexPath) ? 30 : 0
    }

    func cellBottomLabelHeight(for message: MessageType, at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> CGFloat {
        return 0
    }

    func messageTopLabelHeight(for message: MessageType, at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> CGFloat {
        return 0
    }

    func messageBottomLabelHeight(for message: MessageType, at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> CGFloat {
        return 0
    }

}

// MARK: -
// MARK: - Text Messages

extension ChatViewController: MessagesDisplayDelegate {

    func textColor(for message: MessageType, at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> UIColor {
        return UIColor.black
    }

    func detectorAttributes(for detector: DetectorType, and message: MessageType, at indexPath: IndexPath) -> [NSAttributedString.Key: Any] {
        switch detector {
        case .hashtag, .mention: return [.foregroundColor: UIColor.gray]
        default: return MessageLabel.defaultAttributes
        }
    }

    func enabledDetectors(for message: MessageType, at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> [DetectorType] {
        return [.url, .address, .phoneNumber, .date, .transitInformation, .mention, .hashtag]
    }

    // MARK: -
    // MARK: - All Messages

    func backgroundColor(for message: MessageType, at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> UIColor {
        if message.sender.senderId == "1" {
            return UIColor(hexString: "FEDBD9", alpha: 0.7)
        } else {
            return UIColor(hexString: "F5F5F5", alpha: 1)
        }
    }

    func messageStyle(for message: MessageType, at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> MessageStyle {
        return .custom { view in
            let radius: CGFloat = 5
            let path = UIBezierPath(roundedRect: view.bounds, byRoundingCorners: .allCorners, cornerRadii: CGSize(width: radius, height: radius))
            let mask = CAShapeLayer()
            mask.path = path.cgPath
            view.layer.mask = mask
        }
    }

}


// MARK: -
// MARK: - MFMessageComposeViewControllerDelegate

extension ChatViewController: MFMessageComposeViewControllerDelegate {

    func messageComposeViewController(_ controller: MFMessageComposeViewController, didFinishWith result: MessageComposeResult) {
        dismiss(animated: true, completion: nil)
    }

}

// MARK: -
// MARK: - ChatEncryptionSelectionDelegate

extension ChatViewController: ChatEncryptionSelectionDelegate {
    
    func didSelectEncryptionScheme(_ scheme: EncryptionSchemeType) {
        EncryptionSchemeType.lastChoosenEncryptionScheme = scheme
        dataBaseManager.updateChatEncryption(chat: chat, scheme: scheme)
    }

}
