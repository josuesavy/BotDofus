#ifndef TREASUREHUNTDIGREQUESTMESSAGE_H
#define TREASUREHUNTDIGREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TreasureHuntDigRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntDigRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntDigRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntDigRequestMessage(FuncTree tree);
  TreasureHuntDigRequestMessage();

  uint questType;

private:
  void _questTypeFunc(Reader *input);
};

#endif // TREASUREHUNTDIGREQUESTMESSAGE_H