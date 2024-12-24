#ifndef GOLDADDEDMESSAGE_H
#define GOLDADDEDMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/GoldItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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