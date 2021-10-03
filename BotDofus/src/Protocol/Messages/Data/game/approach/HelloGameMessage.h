#ifndef HELLOGAMEMESSAGE_H
#define HELLOGAMEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HelloGameMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HelloGameMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HelloGameMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HelloGameMessage(FuncTree tree);
  HelloGameMessage();
};

#endif // HELLOGAMEMESSAGE_H