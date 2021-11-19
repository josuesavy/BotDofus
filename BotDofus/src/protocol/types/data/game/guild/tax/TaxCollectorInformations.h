#ifndef TAXCOLLECTORINFORMATIONS_H
#define TAXCOLLECTORINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/tax/AdditionalTaxCollectorInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class TaxCollectorInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorInformations(FuncTree tree);
  TaxCollectorInformations();
  bool operator==(const TaxCollectorInformations &compared);

  double uniqueId;
  uint firtNameId;
  uint lastNameId;
  AdditionalTaxCollectorInformations additionalInfos;
  int worldX;
  int worldY;
  uint subAreaId;
  uint state;
  QSharedPointer<EntityLook> look;
  QList<QSharedPointer<TaxCollectorComplementaryInformations>> complements;

private:
  void _uniqueIdFunc(Reader *input);
  void _firtNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
  void _additionalInfostreeFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _stateFunc(Reader *input);
  void _looktreeFunc(Reader *input);
  void _complementstreeFunc(Reader *input);
  void _complementsFunc(Reader *input);

  FuncTree _additionalInfostree;
  FuncTree _looktree;
  FuncTree _complementstree;
};

#endif // TAXCOLLECTORINFORMATIONS_H