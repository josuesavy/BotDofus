#ifndef RSAMANAGER_H
#define RSAMANAGER_H

#include "src/utils/io/Reader.h"
#include "src/utils/io/Writer.h"

#include <QPointer>

#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"
#include "openssl/rsa.h"
#include "openssl/pem.h"
#include "ostream"
#include "sstream"

class RsaManager
{
public:
    RsaManager();

    /**
     * @brief publicKeyDecrypt
     * @param signature
     * @return
     *
     * Decrypt the key with Dofus's public key
     */
    QByteArray publicKeyDecrypt(const QByteArray &signature);

    /**
     * @brief loginPublicKeyEncrypt
     * @param credentials
     * @return
     *
     * Encrypt the datas by the new key generate from setLoginPublicKey
     */
    QByteArray loginPublicKeyEncrypt(const QByteArray &credentials);

    /**
     * @brief generateCredentials
     * @param salt
     * @param aesKey
     * @param username
     * @param password
     * @return
     *
     * Concatenation the login, password, salt and aesKey in the data and crypt the data
     */
    QList<int> generateCredentials(const QString &salt, QByteArray aesKey, const QString &username, const QString &password);

    /**
     * @brief setLoginPublicKey
     * @param lPKey
     *
     * Generate the new key to encrypt the data for send to server Dofus
     */
    void setLoginPublicKey(const QByteArray &lPKey);

    QByteArray getDecodedKey() const;
    QString getPurifiedKey() const;
    QByteArray getEncryptedCredentials() const;
    QList<int> getCredentials() const;

private:
    QString m_publicKey;
    QString m_loginPublicKey;
    QByteArray m_outputSignatureVector;
    QByteArray m_outputCredentialsVector;
    QList<int> m_credentials;
};

#endif
