#ifndef OBJECTUSEMESSAGE_H
#define OBJECTUSEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ObjectUseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectUseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectUseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectUseMessage(FuncTree tree);
  ObjectUseMessage();

  uint objectUID;

private:
  void _objectUIDFunc(Reader *input);
};

#endif // OBJECTUSEMESSAGE_H