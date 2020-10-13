#ifndef IDENTIFICATIONACCOUNTFORCEMESSAGE_H
#define IDENTIFICATIONACCOUNTFORCEMESSAGE_H

#include "src/Protocol/Types/Data/version/Version.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/connection/IdentificationMessage.h"

class IdentificationAccountForceMessage : public IdentificationMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdentificationAccountForceMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdentificationAccountForceMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdentificationAccountForceMessage(FuncTree tree);
  IdentificationAccountForceMessage();

  QString forcedAccountLogin;

private:
  void _forcedAccountLoginFunc(Reader *input);
};

#endif // IDENTIFICATIONACCOUNTFORCEMESSAGE_H