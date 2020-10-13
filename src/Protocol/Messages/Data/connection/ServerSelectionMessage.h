#ifndef SERVERSELECTIONMESSAGE_H
#define SERVERSELECTIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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