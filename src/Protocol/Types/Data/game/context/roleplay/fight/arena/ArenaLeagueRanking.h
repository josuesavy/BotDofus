#ifndef ARENALEAGUERANKING_H
#define ARENALEAGUERANKING_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ArenaLeagueRanking : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ArenaLeagueRanking(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ArenaLeagueRanking(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ArenaLeagueRanking(FuncTree tree);
  ArenaLeagueRanking();
  bool operator==(const ArenaLeagueRanking &compared);

  uint rank;
  uint leagueId;
  int leaguePoints;
  int totalLeaguePoints;
  int ladderPosition;

private:
  void _rankFunc(Reader *input);
  void _leagueIdFunc(Reader *input);
  void _leaguePointsFunc(Reader *input);
  void _totalLeaguePointsFunc(Reader *input);
  void _ladderPositionFunc(Reader *input);
};

#endif // ARENALEAGUERANKING_H