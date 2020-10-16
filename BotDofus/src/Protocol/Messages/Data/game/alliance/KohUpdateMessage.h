#ifndef KOHUPDATEMESSAGE_H
#define KOHUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/AllianceInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class KohUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KohUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KohUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KohUpdateMessage(FuncTree tree);
  KohUpdateMessage();

  QList<QSharedPointer<AllianceInformations>> alliances;
  QList<uint> allianceNbMembers;
  QList<uint> allianceRoundWeigth;
  QList<uint> allianceMatchScore;
  QList<QSharedPointer<BasicAllianceInformations>> allianceMapWinners;
  uint allianceMapWinnerScore;
  uint allianceMapMyAllianceScore;
  double nextTickTime;

private:
  void _alliancestreeFunc(Reader *input);
  void _alliancesFunc(Reader *input);
  void _allianceNbMemberstreeFunc(Reader *input);
  void _allianceNbMembersFunc(Reader *input);
  void _allianceRoundWeigthtreeFunc(Reader *input);
  void _allianceRoundWeigthFunc(Reader *input);
  void _allianceMatchScoretreeFunc(Reader *input);
  void _allianceMatchScoreFunc(Reader *input);
  void _allianceMapWinnerstreeFunc(Reader *input);
  void _allianceMapWinnersFunc(Reader *input);
  void _allianceMapWinnerScoreFunc(Reader *input);
  void _allianceMapMyAllianceScoreFunc(Reader *input);
  void _nextTickTimeFunc(Reader *input);

  FuncTree _alliancestree;
  FuncTree _allianceNbMemberstree;
  FuncTree _allianceRoundWeigthtree;
  FuncTree _allianceMatchScoretree;
  FuncTree _allianceMapWinnerstree;
};

#endif // KOHUPDATEMESSAGE_H