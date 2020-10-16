#ifndef CLIENTKEYMESSAGE_H
#define CLIENTKEYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ClientKeyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ClientKeyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ClientKeyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ClientKeyMessage(FuncTree tree);
  ClientKeyMessage();

  QString key;

private:
  void _keyFunc(Reader *input);
};

#endif // CLIENTKEYMESSAGE_H