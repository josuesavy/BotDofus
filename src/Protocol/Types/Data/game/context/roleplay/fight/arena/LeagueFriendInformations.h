#ifndef LEAGUEFRIENDINFORMATIONS_H
#define LEAGUEFRIENDINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/friend/AbstractContactInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Enums/Data/PlayableBreedEnum.h"

class LeagueFriendInformations : public AbstractContactInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LeagueFriendInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LeagueFriendInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LeagueFriendInformations(FuncTree tree);
  LeagueFriendInformations();
  bool operator==(const LeagueFriendInformations &compared);

  double playerId;
  QString playerName;
  int breed;
  bool sex;
  uint level;
  int leagueId;
  int totalLeaguePoints;
  int ladderPosition;

private:
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _leagueIdFunc(Reader *input);
  void _totalLeaguePointsFunc(Reader *input);
  void _ladderPositionFunc(Reader *input);
};

#endif // LEAGUEFRIENDINFORMATIONS_H