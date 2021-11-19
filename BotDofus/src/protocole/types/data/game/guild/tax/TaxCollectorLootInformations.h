#ifndef TAXCOLLECTORLOOTINFORMATIONS_H
#define TAXCOLLECTORLOOTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class TaxCollectorLootInformations : public TaxCollectorComplementaryInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorLootInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorLootInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorLootInformations(FuncTree tree);
  TaxCollectorLootInformations();
  bool operator==(const TaxCollectorLootInformations &compared);

  double kamas;
  double experience;
  uint pods;
  double itemsValue;

private:
  void _kamasFunc(Reader *input);
  void _experienceFunc(Reader *input);
  void _podsFunc(Reader *input);
  void _itemsValueFunc(Reader *input);
};

#endif // TAXCOLLECTORLOOTINFORMATIONS_H