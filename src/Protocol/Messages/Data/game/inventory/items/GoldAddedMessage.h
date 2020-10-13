#ifndef GOLDADDEDMESSAGE_H
#define GOLDADDEDMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/GoldItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GoldAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GoldAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GoldAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GoldAddedMessage(FuncTree tree);
  GoldAddedMessage();

  GoldItem gold;

private:
  void _goldtreeFunc(Reader *input);

  FuncTree _goldtree;
};

#endif // GOLDADDEDMESSAGE_H