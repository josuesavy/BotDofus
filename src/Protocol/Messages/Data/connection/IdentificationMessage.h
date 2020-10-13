#ifndef IDENTIFICATIONMESSAGE_H
#define IDENTIFICATIONMESSAGE_H

#include "src/Protocol/Types/Data/version/Version.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class IdentificationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdentificationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdentificationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdentificationMessage(FuncTree tree);
  IdentificationMessage();

  Version version;
  QString lang;
  QList<int> credentials;
  int serverId;
  bool autoconnect;
  bool useCertificate;
  bool useLoginToken;
  double sessionOptionalSalt;
  QList<uint> failedAttempts;

private:
  void deserializeByteBoxes(Reader *input);
  void _versiontreeFunc(Reader *input);
  void _langFunc(Reader *input);
  void _credentialstreeFunc(Reader *input);
  void _credentialsFunc(Reader *input);
  void _serverIdFunc(Reader *input);
  void _sessionOptionalSaltFunc(Reader *input);
  void _failedAttemptstreeFunc(Reader *input);
  void _failedAttemptsFunc(Reader *input);

  FuncTree _versiontree;
  FuncTree _credentialstree;
  FuncTree _failedAttemptstree;
};

#endif // IDENTIFICATIONMESSAGE_H