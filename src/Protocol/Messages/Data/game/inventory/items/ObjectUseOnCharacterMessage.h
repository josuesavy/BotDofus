#ifndef OBJECTUSEONCHARACTERMESSAGE_H
#define OBJECTUSEONCHARACTERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/ObjectUseMessage.h"

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