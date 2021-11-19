#ifndef PRISMINFORMATION_H
#define PRISMINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PrismInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismInformation(FuncTree tree);
  PrismInformation();
  bool operator==(const PrismInformation &compared);

  uint typeId;
  uint state;
  uint nextVulnerabilityDate;
  uint placementDate;
  uint rewardTokenCount;

private:
  void _typeIdFunc(Reader *input);
  void _stateFunc(Reader *input);
  void _nextVulnerabilityDateFunc(Reader *input);
  void _placementDateFunc(Reader *input);
  void _rewardTokenCountFunc(Reader *input);
};

#endif // PRISMINFORMATION_H