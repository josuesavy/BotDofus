#ifndef GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWER_H
#define GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWER_H

#include "src/protocol/types/data/game/context/roleplay/fight/arena/LeagueFriendInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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