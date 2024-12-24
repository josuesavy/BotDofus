#ifndef TREASUREHUNTFLAGREMOVEREQUESTMESSAGE_H
#define TREASUREHUNTFLAGREMOVEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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