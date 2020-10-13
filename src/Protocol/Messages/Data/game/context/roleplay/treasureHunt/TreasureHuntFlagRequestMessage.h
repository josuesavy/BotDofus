#ifndef TREASUREHUNTFLAGREQUESTMESSAGE_H
#define TREASUREHUNTFLAGREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TreasureHuntFlagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntFlagRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntFlagRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntFlagRequestMessage(FuncTree tree);
  TreasureHuntFlagRequestMessage();

  uint questType;
  uint index;

private:
  void _questTypeFunc(Reader *input);
  void _indexFunc(Reader *input);
};

#endif // TREASUREHUNTFLAGREQUESTMESSAGE_H