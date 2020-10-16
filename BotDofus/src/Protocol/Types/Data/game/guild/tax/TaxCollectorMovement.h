#ifndef TAXCOLLECTORMOVEMENT_H
#define TAXCOLLECTORMOVEMENT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorBasicInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class TaxCollectorMovement : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorMovement(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorMovement(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorMovement(FuncTree tree);
  TaxCollectorMovement();
  bool operator==(const TaxCollectorMovement &compared);

  uint movementType;
  TaxCollectorBasicInformations basicInfos;
  double playerId;
  QString playerName;

private:
  void _movementTypeFunc(Reader *input);
  void _basicInfostreeFunc(Reader *input);
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);

  FuncTree _basicInfostree;
};

#endif // TAXCOLLECTORMOVEMENT_H