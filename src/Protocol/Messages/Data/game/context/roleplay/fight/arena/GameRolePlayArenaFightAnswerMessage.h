#ifndef GAMEROLEPLAYARENAFIGHTANSWERMESSAGE_H
#define GAMEROLEPLAYARENAFIGHTANSWERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameRolePlayArenaFightAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaFightAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaFightAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaFightAnswerMessage(FuncTree tree);
  GameRolePlayArenaFightAnswerMessage();

  uint fightId;
  bool accept;

private:
  void _fightIdFunc(Reader *input);
  void _acceptFunc(Reader *input);
};

#endif // GAMEROLEPLAYARENAFIGHTANSWERMESSAGE_H