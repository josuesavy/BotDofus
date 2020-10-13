#ifndef IGNOREDDELETEREQUESTMESSAGE_H
#define IGNOREDDELETEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class IgnoredDeleteRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IgnoredDeleteRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IgnoredDeleteRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IgnoredDeleteRequestMessage(FuncTree tree);
  IgnoredDeleteRequestMessage();

  uint accountId;
  bool session;

private:
  void _accountIdFunc(Reader *input);
  void _sessionFunc(Reader *input);
};

#endif // IGNOREDDELETEREQUESTMESSAGE_H