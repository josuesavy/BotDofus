#ifndef OBJECTUSEONCHARACTERMESSAGE_H
#define OBJECTUSEONCHARACTERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/items/ObjectUseMessage.h"

class ObjectUseOnCharacterMessage : public ObjectUseMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectUseOnCharacterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectUseOnCharacterMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectUseOnCharacterMessage(FuncTree tree);
  ObjectUseOnCharacterMessage();

  double characterId;

private:
  void _characterIdFunc(Reader *input);
};

#endif // OBJECTUSEONCHARACTERMESSAGE_H