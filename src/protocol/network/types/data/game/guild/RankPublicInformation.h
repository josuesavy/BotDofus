#ifndef RANKPUBLICINFORMATION_H
#define RANKPUBLICINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/rank/RankMinimalInformation.h"
#include "src/utils/io/type/FuncTree.h"

class RankPublicInformation : public RankMinimalInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RankPublicInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RankPublicInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RankPublicInformation(FuncTree tree);
  RankPublicInformation();
  bool operator==(const RankPublicInformation &compared);

  uint order;
  uint gfxId;

private:
  void _orderFunc(Reader *input);
  void _gfxIdFunc(Reader *input);
};

#endif // RANKPUBLICINFORMATION_H