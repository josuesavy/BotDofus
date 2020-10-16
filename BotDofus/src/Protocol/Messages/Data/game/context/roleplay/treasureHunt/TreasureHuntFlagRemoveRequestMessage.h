#ifndef TREASUREHUNTFLAGREMOVEREQUESTMESSAGE_H
#define TREASUREHUNTFLAGREMOVEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TreasureHuntFlagRemoveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntFlagRemoveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntFlagRemoveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntFlagRemoveRequestMessage(FuncTree tree);
  TreasureHuntFlagRemoveRequestMessage();

  uint questType;
  uint index;

private:
  void _questTypeFunc(Reader *input);
  void _indexFunc(Reader *input);
};

#endif // TREASUREHUNTFLAGREMOVEREQUESTMESSAGE_H