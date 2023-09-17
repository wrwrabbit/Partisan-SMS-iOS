# Partisan-SMS-iOS

IOS application for encrypted messages exchange with functionality of sending SMS.

# Features
- Encrypt/Decrypt message with secret password
- Send SMS or copy message
- Multiple encryption methods(message can be encrypted in a way that provides undercover appearance of encrypted message)
- Crossplatform(IOS&Android compatibility)
- Chat history
- Double bottom protection
- Localized

# Supported platforms
IOS >= 12

# How it works?
User installs application, creates pin code password and fake one. Every time app opens it asks user for pin. If somebody enters fake pin app automatically deletes all the data. If pin is ok then list of chats screen is opened.

Chats: user can create multiple chats. To create a chat user should fill name of a chat and security key(If its new conversation user can generate security key).
Security key is a key that decrypts encrypted messages. Keys are stored in Keychain and can only be accessed if user entered correct app password.
Encrypted messages are stored in DB.
Application support multiple ways of encryption and every chat has its own encryption scheme(This is configurable in chat encryption settings)

Message exchange: if user wants to send new encrypted message he enters it in some chat and clicks "send" button. After that message is encrypted with chat security key and can be copied to clipboard or sent by SMS(with native IOS SMS dialog).
If user receives somewhere encrypted message(in Messages app for example) he copies it and then goes to chat where it supposed to be stored. Application automatically prefills text input from clipboard and after user taps "send" button its automatically decrypted and inserted into chat history(Of course if it can be decrypted with chat security key).
User can see all chats outgoing/incoming decrypted messages.

# Installation
    1. Install CocoaPods
    2. Run "pod install" in project directory

# Technical information
- Architecture: MVC
- Swift 5
- UIKit, Storyboard
- Localized strings
- Kotlin Multi Platform

# Third party libraries
- Realm DB
- MessageKit for chat UI
- KeychainSwift
- IQKeyboardManagerSwift
- EmptyDataSet-Swift

# KMM
We use Kotlin Multi Platform for crosslpatform compatibility and unification.
In order to update KMM framework you firstly should build our [KMM library](https://github.com/wrwrabbit/p-sms-lib) in Android Studio/IntelliJ IDEA/VSC, then go to ios build folder of the library and grab framework file to IOS PSMS project folder(replace it).

# Encryption
We delegated encryption of messages to KMM library so we just call PSMSLib methods directly from swift code. But we use AES encryption to encrypt/decrypt chats security key(we use application pin password as encryption key)
