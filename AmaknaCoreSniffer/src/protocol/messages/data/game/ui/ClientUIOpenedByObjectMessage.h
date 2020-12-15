#ifndef CLIENTUIOPENEDBYOBJECTMESSAGE_H
#define CLIENTUIOPENEDBYOBJECTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/ui/ClientUIOpenedMessage.h"

class ClientUIOpenedByObjectMessage : public ClientUIOpenedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ClientUIOpenedByObjectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ClientUIOpenedByObjectMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ClientUIOpenedByObjectMessage(FuncTree tree);
  ClientUIOpenedByObjectMessage();

  uint uid;

private:
  void _uidFunc(Reader *input);
};

#endif // CLIENTUIOPENEDBYOBJECTMESSAGE_H