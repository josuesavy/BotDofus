#ifndef GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE_H
#define GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayArenaFightPropositionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaFightPropositionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaFightPropositionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaFightPropositionMessage(FuncTree tree);
  GameRolePlayArenaFightPropositionMessage();

  uint fightId;
  QList<double> alliesId;
  uint duration;

private:
  void _fightIdFunc(Reader *input);
  void _alliesIdtreeFunc(Reader *input);
  void _alliesIdFunc(Reader *input);
  void _durationFunc(Reader *input);

  FuncTree _alliesIdtree;
};

#endif // GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE_H