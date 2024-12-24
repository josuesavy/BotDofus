#ifndef ARENALEAGUERANKING_H
#define ARENALEAGUERANKING_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

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

  int rating;
  int leagueId;
  int ladderPosition;

private:
  void _ratingFunc(Reader *input);
  void _leagueIdFunc(Reader *input);
  void _ladderPositionFunc(Reader *input);
};

#endif // ARENALEAGUERANKING_H