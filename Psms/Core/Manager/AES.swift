import Foundation
import CommonCrypto


protocol Cryptable {

    /// Encrypts the given `String` and returns it as `Data`.
    ///
    /// - Parameter string: The information to be encrypted.
    /// - Returns: The encrypted information as `Data`.
    /// - Throws: Any `Error` during the encryption operation.
    func encrypt(_ string: String) throws -> Data

    /// Decrypts the given `Data` and returns it as `String`.
    ///
    /// - Parameter data: `Data` object to be decrypted.
    /// - Returns: The decrypted information as `String`.
    /// - Throws: Any `Error` during the decryption operation.
    func decrypt(_ data: Data) throws -> String
}

public struct AES {

    // MARK: - Internal Properties
    // MARK: Key Related
    public let key: Data

    // MARK: CCCrypt Related
    internal let ivSize: Int            = kCCBlockSizeAES128
    internal let options: UInt32        = CCOptions(kCCOptionPKCS7Padding)

    // MARK: - Lifecycle
    /// Initializes the `AES struct` with the given key, which must match the `kCCKeySizeAES256` size
    /// (256 bit AES key size).
    ///
    /// There is an interesting discussion on the 128 vs 256 topic [here](http://bit.ly/128vs256).
    ///
    /// - Parameter keyString: 256 bit AES key size.
    /// - Throws: `AESError`
    public init(keyString: String) throws {

        guard keyString.count == kCCKeySizeAES256 else {
            throw AES.Error.invalidKeySize
        }

        self.key = Data(keyString.utf8)
    }
    
    public init(data: Data) throws {

        guard data.count == kCCKeySizeAES256 else {
            throw AES.Error.invalidKeySize
        }

        self.key = data
    }
}


// MARK: - Cryptable Protocol
extension AES: Cryptable {

    // MARK: - Encrypt
    public func encrypt(_ string: String) throws -> Data {

        let dataToEncrypt: Data = Data(string.utf8)

        let bufferSize: Int = ivSize + dataToEncrypt.count + kCCBlockSizeAES128
        var buffer = Data(count: bufferSize)
        try generateRandomIV(for: &buffer)

        var numberBytesEncrypted: Int = 0

        do {
            try key.withUnsafeBytes { keyBytes in
                try dataToEncrypt.withUnsafeBytes { dataToEncryptBytes in
                    try buffer.withUnsafeMutableBytes { bufferBytes in

                        guard let keyBytesBaseAddress = keyBytes.baseAddress,
                            let dataToEncryptBytesBaseAddress = dataToEncryptBytes.baseAddress,
                            let bufferBytesBaseAddress = bufferBytes.baseAddress else {
                                throw Error.encryptionFailed
                        }

                        let cryptStatus: CCCryptorStatus = CCCrypt( // Stateless, one-shot encrypt operation
                            CCOperation(kCCEncrypt),                // op: CCOperation
                            CCAlgorithm(kCCAlgorithmAES),           // alg: CCAlgorithm
                            options,                                // options: CCOptions
                            keyBytesBaseAddress,                    // key: the "password"
                            key.count,                              // keyLength: the "password" size
                            bufferBytesBaseAddress,                 // iv: Initialization Vector
                            dataToEncryptBytesBaseAddress,          // dataIn: Data to encrypt bytes
                            dataToEncryptBytes.count,               // dataInLength: Data to encrypt size
                            bufferBytesBaseAddress + ivSize,        // dataOut: encrypted Data buffer
                            bufferSize,                             // dataOutAvailable: encrypted Data buffer size
                            &numberBytesEncrypted                   // dataOutMoved: the number of bytes written
                        )

                        guard cryptStatus == CCCryptorStatus(kCCSuccess) else {
                            throw Error.encryptionFailed
                        }
                    }
                }
            }
        } catch {
            throw Error.encryptionFailed
        }

        let encryptedData: Data = buffer[..<(numberBytesEncrypted + ivSize)]
        return encryptedData
    }

    // MARK: - Decrypt
    public func decrypt(_ data: Data) throws -> String {

        let bufferSize: Int = data.count - ivSize
        var buffer = Data(count: bufferSize)

        var numberBytesDecrypted: Int = 0

        do {
            try key.withUnsafeBytes { keyBytes in
                try data.withUnsafeBytes { dataToDecryptBytes in
                    try buffer.withUnsafeMutableBytes { bufferBytes in

                        guard let keyBytesBaseAddress = keyBytes.baseAddress,
                            let dataToDecryptBytesBaseAddress = dataToDecryptBytes.baseAddress,
                            let bufferBytesBaseAddress = bufferBytes.baseAddress else {
                                throw Error.encryptionFailed
                        }

                        let cryptStatus: CCCryptorStatus = CCCrypt( // Stateless, one-shot encrypt operation
                            CCOperation(kCCDecrypt),                // op: CCOperation
                            CCAlgorithm(kCCAlgorithmAES128),        // alg: CCAlgorithm
                            options,                                // options: CCOptions
                            keyBytesBaseAddress,                    // key: the "password"
                            key.count,                              // keyLength: the "password" size
                            dataToDecryptBytesBaseAddress,          // iv: Initialization Vector
                            dataToDecryptBytesBaseAddress + ivSize, // dataIn: Data to decrypt bytes
                            bufferSize,                             // dataInLength: Data to decrypt size
                            bufferBytesBaseAddress,                 // dataOut: decrypted Data buffer
                            bufferSize,                             // dataOutAvailable: decrypted Data buffer size
                            &numberBytesDecrypted                   // dataOutMoved: the number of bytes written
                        )

                        guard cryptStatus == CCCryptorStatus(kCCSuccess) else {
                            throw Error.decryptionFailed
                        }
                    }
                }
            }
        } catch {
            throw Error.encryptionFailed
        }

        let decryptedData: Data = buffer[..<numberBytesDecrypted]

        guard let decryptedString = String(data: decryptedData, encoding: .utf8) else {
            throw Error.dataToStringFailed
        }

        return decryptedString
    }
}



public extension AES {

    /// Encapsulates errors that may occur during AES encrypt / decrypt operations.
    ///
    /// - invalidKeySize: The given key `String` count isn't equal to `kCCKeySizeAES256`.
    /// - emptyStringToEncrypt: The given `String` to encrypt is empty.
    /// - generateRandomIVFailed: Could not generate a random `iv` via `SecRandomCopyBytes(_:_:_:)`.
    /// - encryptDataFailed: `CCCryptorStatus` was different than `kCCSuccess` during an encryption operation.
    /// - stringToDataFailed: Failed to convert `String` into `Data` via `data(using:allowLossyConversion:)`.
    /// - decryptDataFailed: `CCCryptorStatus` was different than `kCCSuccess` during a decryption operation.
    /// - dataToStringFailed: Failed to convert `Data` into `String`. E.g.: via `String.init(bytes:encoding:)`.
    enum Error: Swift.Error {
        case invalidKeySize
        case emptyStringToEncrypt
        case generateRandomIVFailed
        case encryptionFailed
        case decryptionFailed
        case dataToStringFailed
    }
}

// MARK: - Internal Extension
internal extension AES {

    /// Generates an `Initialization Vector` with random data for the `Cipher Block Chaining (CBC)` mode with
    /// block size `kCCBlockSizeAES128` and append it to the give `Data`.
    ///
    /// - Parameter data: The `Data` in which the generated `iv` will be attached into.
    /// - Throws: `AESError`
    func generateRandomIV(for data: inout Data) throws {

        try data.withUnsafeMutableBytes { dataBytes in

            guard let dataBytesBaseAddress = dataBytes.baseAddress else {
                throw Error.generateRandomIVFailed
            }

            let status: Int32 = SecRandomCopyBytes(
                kSecRandomDefault,
                kCCBlockSizeAES128,
                dataBytesBaseAddress
            )

            guard status == 0 else {
                throw Error.generateRandomIVFailed
            }
        }
    }
}
