#ifndef GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWERMESSAGE_H
#define GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWERMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/fight/arena/LeagueFriendInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayArenaInvitationCandidatesAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaInvitationCandidatesAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaInvitationCandidatesAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaInvitationCandidatesAnswerMessage(FuncTree tree);
  GameRolePlayArenaInvitationCandidatesAnswerMessage();

  QList<LeagueFriendInformations> candidates;

private:
  void _candidatestreeFunc(Reader *input);
  void _candidatesFunc(Reader *input);

  FuncTree _candidatestree;
};

#endif // GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWERMESSAGE_H