#ifndef TREASUREHUNTFLAG_H
#define TREASUREHUNTFLAG_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class TreasureHuntFlag : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntFlag(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntFlag(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntFlag(FuncTree tree);
  TreasureHuntFlag();
  bool operator==(const TreasureHuntFlag &compared);

  double mapId;
  uint state;

private:
  void _mapIdFunc(Reader *input);
  void _stateFunc(Reader *input);
};

#endif // TREASUREHUNTFLAG_H