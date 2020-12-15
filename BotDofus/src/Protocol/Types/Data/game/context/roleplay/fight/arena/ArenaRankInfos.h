#ifndef ARENARANKINFOS_H
#define ARENARANKINFOS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/fight/arena/ArenaRanking.h"
#include "src/protocol/types/data/game/context/roleplay/fight/arena/ArenaLeagueRanking.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ArenaRankInfos : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ArenaRankInfos(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ArenaRankInfos(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ArenaRankInfos(FuncTree tree);
  ArenaRankInfos();
  bool operator==(const ArenaRankInfos &compared);

  ArenaRanking *ranking;
  ArenaLeagueRanking *leagueRanking;
  uint victoryCount;
  uint fightcount;
  uint numFightNeededForLadder;

private:
  void _rankingtreeFunc(Reader *input);
  void _leagueRankingtreeFunc(Reader *input);
  void _victoryCountFunc(Reader *input);
  void _fightcountFunc(Reader *input);
  void _numFightNeededForLadderFunc(Reader *input);

  FuncTree _rankingtree;
  FuncTree _leagueRankingtree;
};

#endif // ARENARANKINFOS_H