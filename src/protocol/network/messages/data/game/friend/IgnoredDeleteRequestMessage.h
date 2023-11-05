#ifndef IGNOREDDELETEREQUESTMESSAGE_H
#define IGNOREDDELETEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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