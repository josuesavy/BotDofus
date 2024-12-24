#ifndef SERVERSELECTIONMESSAGE_H
#define SERVERSELECTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ServerSelectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerSelectionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerSelectionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerSelectionMessage(FuncTree tree);
  ServerSelectionMessage();

  uint serverId;

private:
  void _serverIdFunc(Reader *input);
};

#endif // SERVERSELECTIONMESSAGE_H