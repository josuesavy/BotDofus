#ifndef ACQUAINTANCESERVERLISTMESSAGE_H
#define ACQUAINTANCESERVERLISTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AcquaintanceServerListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AcquaintanceServerListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AcquaintanceServerListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AcquaintanceServerListMessage(FuncTree tree);
  AcquaintanceServerListMessage();

  QList<uint> servers;

private:
  void _serverstreeFunc(Reader *input);
  void _serversFunc(Reader *input);

  FuncTree _serverstree;
};

#endif // ACQUAINTANCESERVERLISTMESSAGE_H