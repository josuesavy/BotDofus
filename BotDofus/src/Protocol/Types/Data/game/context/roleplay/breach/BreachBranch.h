#ifndef BREACHBRANCH_H
#define BREACHBRANCH_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/MonsterInGroupLightInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class BreachBranch : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachBranch(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachBranch(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachBranch(FuncTree tree);
  BreachBranch();
  bool operator==(const BreachBranch &compared);

  uint room;
  uint element;
  QList<MonsterInGroupLightInformations> bosses;
  double map;
  int score;
  int relativeScore;
  QList<MonsterInGroupLightInformations> monsters;

private:
  void _roomFunc(Reader *input);
  void _elementFunc(Reader *input);
  void _bossestreeFunc(Reader *input);
  void _bossesFunc(Reader *input);
  void _mapFunc(Reader *input);
  void _scoreFunc(Reader *input);
  void _relativeScoreFunc(Reader *input);
  void _monsterstreeFunc(Reader *input);
  void _monstersFunc(Reader *input);

  FuncTree _bossestree;
  FuncTree _monsterstree;
};

#endif // BREACHBRANCH_H