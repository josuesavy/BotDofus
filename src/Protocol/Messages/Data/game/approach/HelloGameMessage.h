#ifndef HELLOGAMEMESSAGE_H
#define HELLOGAMEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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