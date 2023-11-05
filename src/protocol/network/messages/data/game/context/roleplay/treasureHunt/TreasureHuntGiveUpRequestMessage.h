#ifndef TREASUREHUNTGIVEUPREQUESTMESSAGE_H
#define TREASUREHUNTGIVEUPREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TreasureHuntGiveUpRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntGiveUpRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntGiveUpRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntGiveUpRequestMessage(FuncTree tree);
  TreasureHuntGiveUpRequestMessage();

  uint questType;

private:
  void _questTypeFunc(Reader *input);
};

#endif // TREASUREHUNTGIVEUPREQUESTMESSAGE_H