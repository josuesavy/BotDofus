#ifndef PRISMFIGHTERSINFORMATION_H
#define PRISMFIGHTERSINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/fight/ProtectedEntityWaitingForHelpInfo.h"
#include "src/protocol/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PrismFightersInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismFightersInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismFightersInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismFightersInformation(FuncTree tree);
  PrismFightersInformation();
  bool operator==(const PrismFightersInformation &compared);

  uint subAreaId;
  ProtectedEntityWaitingForHelpInfo waitingForHelpInfo;
  QList<QSharedPointer<CharacterMinimalPlusLookInformations>> allyCharactersInformations;
  QList<QSharedPointer<CharacterMinimalPlusLookInformations>> enemyCharactersInformations;

private:
  void _subAreaIdFunc(Reader *input);
  void _waitingForHelpInfotreeFunc(Reader *input);
  void _allyCharactersInformationstreeFunc(Reader *input);
  void _allyCharactersInformationsFunc(Reader *input);
  void _enemyCharactersInformationstreeFunc(Reader *input);
  void _enemyCharactersInformationsFunc(Reader *input);

  FuncTree _waitingForHelpInfotree;
  FuncTree _allyCharactersInformationstree;
  FuncTree _enemyCharactersInformationstree;
};

#endif // PRISMFIGHTERSINFORMATION_H