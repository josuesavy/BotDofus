#ifndef SOCIALFIGHT_H
#define SOCIALFIGHT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/protocol/types/data/game/context/fight/FightPhase.h"
#include "src/engines/io/network/utils/FuncTree.h"

class SocialFight : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialFight(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialFight(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialFight(FuncTree tree);
  SocialFight();
  bool operator==(const SocialFight &compared);

   socialFightInfo;
  QList<CharacterMinimalPlusLookInformations> attackers;
  QList<CharacterMinimalPlusLookInformations> defenders;
  FightPhase phase;

private:
  void _socialFightInfotreeFunc(Reader *input);
  void _attackerstreeFunc(Reader *input);
  void _attackersFunc(Reader *input);
  void _defenderstreeFunc(Reader *input);
  void _defendersFunc(Reader *input);
  void _phasetreeFunc(Reader *input);

  FuncTree _socialFightInfotree;
  FuncTree _attackerstree;
  FuncTree _defenderstree;
  FuncTree _phasetree;
};

#endif // SOCIALFIGHT_H