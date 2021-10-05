#ifndef PLAYERSEARCHTAGINFORMATION_H
#define PLAYERSEARCHTAGINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/common/AccountTagInformation.h"
#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

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