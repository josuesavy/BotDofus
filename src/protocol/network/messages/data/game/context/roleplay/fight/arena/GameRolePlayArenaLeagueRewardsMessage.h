#ifndef GAMEROLEPLAYARENALEAGUEREWARDSMESSAGE_H
#define GAMEROLEPLAYARENALEAGUEREWARDSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayArenaLeagueRewardsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaLeagueRewardsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaLeagueRewardsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaLeagueRewardsMessage(FuncTree tree);
  GameRolePlayArenaLeagueRewardsMessage();

  uint seasonId;
  uint leagueId;
  int ladderPosition;
  bool endSeasonReward;

private:
  void _seasonIdFunc(Reader *input);
  void _leagueIdFunc(Reader *input);
  void _ladderPositionFunc(Reader *input);
  void _endSeasonRewardFunc(Reader *input);
};

#endif // GAMEROLEPLAYARENALEAGUEREWARDSMESSAGE_H