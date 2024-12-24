#ifndef GAMEREFRESHMONSTERBOOSTSMESSAGE_H
#define GAMEREFRESHMONSTERBOOSTSMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/MonsterBoosts.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRefreshMonsterBoostsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRefreshMonsterBoostsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRefreshMonsterBoostsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRefreshMonsterBoostsMessage(FuncTree tree);
  GameRefreshMonsterBoostsMessage();

  QList<MonsterBoosts> monsterBoosts;
  QList<MonsterBoosts> familyBoosts;

private:
  void _monsterBooststreeFunc(Reader *input);
  void _monsterBoostsFunc(Reader *input);
  void _familyBooststreeFunc(Reader *input);
  void _familyBoostsFunc(Reader *input);

  FuncTree _monsterBooststree;
  FuncTree _familyBooststree;
};

#endif // GAMEREFRESHMONSTERBOOSTSMESSAGE_H