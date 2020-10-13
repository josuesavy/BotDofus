#ifndef PRISMFIGHTERSINFORMATION_H
#define PRISMFIGHTERSINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/fight/ProtectedEntityWaitingForHelpInfo.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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