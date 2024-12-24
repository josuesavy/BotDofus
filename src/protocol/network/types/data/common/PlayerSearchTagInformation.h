#ifndef PLAYERSEARCHTAGINFORMATION_H
#define PLAYERSEARCHTAGINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/common/AccountTagInformation.h"
#include "src/protocol/network/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/utils/io/type/FuncTree.h"

class PlayerSearchTagInformation : public AbstractPlayerSearchInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PlayerSearchTagInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PlayerSearchTagInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PlayerSearchTagInformation(FuncTree tree);
  PlayerSearchTagInformation();
  bool operator==(const PlayerSearchTagInformation &compared);

  AccountTagInformation tag;

private:
  void _tagtreeFunc(Reader *input);

  FuncTree _tagtree;
};

#endif // PLAYERSEARCHTAGINFORMATION_H