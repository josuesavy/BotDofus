#ifndef ARENARANKINFOS_H
#define ARENARANKINFOS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/fight/arena/ArenaLeagueRanking.h"
#include "src/utils/io/type/FuncTree.h"

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

  uint arenaType;
  ArenaLeagueRanking *leagueRanking;
  int bestLeagueId;
  int bestRating;
  uint dailyVictoryCount;
  uint seasonVictoryCount;
  uint dailyFightcount;
  uint seasonFightcount;
  uint numFightNeededForLadder;

private:
  void _arenaTypeFunc(Reader *input);
  void _leagueRankingtreeFunc(Reader *input);
  void _bestLeagueIdFunc(Reader *input);
  void _bestRatingFunc(Reader *input);
  void _dailyVictoryCountFunc(Reader *input);
  void _seasonVictoryCountFunc(Reader *input);
  void _dailyFightcountFunc(Reader *input);
  void _seasonFightcountFunc(Reader *input);
  void _numFightNeededForLadderFunc(Reader *input);

  FuncTree _leagueRankingtree;
};

#endif // ARENARANKINFOS_H
