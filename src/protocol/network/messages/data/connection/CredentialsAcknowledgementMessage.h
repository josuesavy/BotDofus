#ifndef CREDENTIALSACKNOWLEDGEMENTMESSAGE_H
#define CREDENTIALSACKNOWLEDGEMENTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CredentialsAcknowledgementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CredentialsAcknowledgementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CredentialsAcknowledgementMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CredentialsAcknowledgementMessage(FuncTree tree);
  CredentialsAcknowledgementMessage();
};

#endif // CREDENTIALSACKNOWLEDGEMENTMESSAGE_H