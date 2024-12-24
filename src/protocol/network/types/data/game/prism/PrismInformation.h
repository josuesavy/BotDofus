#ifndef PRISMINFORMATION_H
#define PRISMINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

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

  uint state;
  uint placementDate;
  uint nuggetsCount;
  uint durability;
  double nextEvolutionDate;

private:
  void _stateFunc(Reader *input);
  void _placementDateFunc(Reader *input);
  void _nuggetsCountFunc(Reader *input);
  void _durabilityFunc(Reader *input);
  void _nextEvolutionDateFunc(Reader *input);
};

#endif // PRISMINFORMATION_H