#ifndef TAXCOLLECTORFIGHTERSINFORMATION_H
#define TAXCOLLECTORFIGHTERSINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class TaxCollectorFightersInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorFightersInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorFightersInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorFightersInformation(FuncTree tree);
  TaxCollectorFightersInformation();
  bool operator==(const TaxCollectorFightersInformation &compared);

  double collectorId;
  QList<QSharedPointer<CharacterMinimalPlusLookInformations>> allyCharactersInformations;
  QList<QSharedPointer<CharacterMinimalPlusLookInformations>> enemyCharactersInformations;

private:
  void _collectorIdFunc(Reader *input);
  void _allyCharactersInformationstreeFunc(Reader *input);
  void _allyCharactersInformationsFunc(Reader *input);
  void _enemyCharactersInformationstreeFunc(Reader *input);
  void _enemyCharactersInformationsFunc(Reader *input);

  FuncTree _allyCharactersInformationstree;
  FuncTree _enemyCharactersInformationstree;
};

#endif // TAXCOLLECTORFIGHTERSINFORMATION_H