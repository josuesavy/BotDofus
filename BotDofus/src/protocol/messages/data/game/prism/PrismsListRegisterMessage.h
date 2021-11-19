#ifndef PRISMSLISTREGISTERMESSAGE_H
#define PRISMSLISTREGISTERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismsListRegisterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismsListRegisterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismsListRegisterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismsListRegisterMessage(FuncTree tree);
  PrismsListRegisterMessage();

  uint listen;

private:
  void _listenFunc(Reader *input);
};

#endif // PRISMSLISTREGISTERMESSAGE_H