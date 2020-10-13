#ifndef GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWER_H
#define GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWER_H

#include "src/Protocol/Types/Data/game/context/roleplay/fight/arena/LeagueFriendInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameRolePlayArenaInvitationCandidatesAnswer : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaInvitationCandidatesAnswer(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaInvitationCandidatesAnswer(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaInvitationCandidatesAnswer(FuncTree tree);
  GameRolePlayArenaInvitationCandidatesAnswer();

  QList<LeagueFriendInformations> candidates;

private:
  void _candidatestreeFunc(Reader *input);
  void _candidatesFunc(Reader *input);

  FuncTree _candidatestree;
};

#endif // GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWER_H