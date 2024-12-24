#ifndef GAMEDATAPLAYFARMOBJECTANIMATIONMESSAGE_H
#define GAMEDATAPLAYFARMOBJECTANIMATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameDataPlayFarmObjectAnimationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameDataPlayFarmObjectAnimationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameDataPlayFarmObjectAnimationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameDataPlayFarmObjectAnimationMessage(FuncTree tree);
  GameDataPlayFarmObjectAnimationMessage();

  QList<uint> cellId;

private:
  void _cellIdtreeFunc(Reader *input);
  void _cellIdFunc(Reader *input);

  FuncTree _cellIdtree;
};

#endif // GAMEDATAPLAYFARMOBJECTANIMATIONMESSAGE_H