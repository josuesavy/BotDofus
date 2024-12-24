#ifndef RANKINFORMATION_H
#define RANKINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/rank/RankMinimalInformation.h"
#include "src/utils/io/type/FuncTree.h"

class RankInformation : public RankMinimalInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RankInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RankInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RankInformation(FuncTree tree);
  RankInformation();
  bool operator==(const RankInformation &compared);

  uint order;
  uint gfxId;
  bool modifiable;
  QList<uint> rights;

private:
  void _orderFunc(Reader *input);
  void _gfxIdFunc(Reader *input);
  void _modifiableFunc(Reader *input);
  void _rightstreeFunc(Reader *input);
  void _rightsFunc(Reader *input);

  FuncTree _rightstree;
};

#endif // RANKINFORMATION_H