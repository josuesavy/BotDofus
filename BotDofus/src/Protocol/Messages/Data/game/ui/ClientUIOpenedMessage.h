#ifndef CLIENTUIOPENEDMESSAGE_H
#define CLIENTUIOPENEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ClientUIOpenedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ClientUIOpenedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ClientUIOpenedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ClientUIOpenedMessage(FuncTree tree);
  ClientUIOpenedMessage();

  uint type;

private:
  void _typeFunc(Reader *input);
};

#endif // CLIENTUIOPENEDMESSAGE_H