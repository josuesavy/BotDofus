#ifndef GAMEFIGHTREMOVETEAMMEMBERMESSAGE_H
#define GAMEFIGHTREMOVETEAMMEMBERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightRemoveTeamMemberMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightRemoveTeamMemberMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightRemoveTeamMemberMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightRemoveTeamMemberMessage(FuncTree tree);
  GameFightRemoveTeamMemberMessage();

  uint fightId;
  uint teamId;
  double charId;

private:
  void _fightIdFunc(Reader *input);
  void _teamIdFunc(Reader *input);
  void _charIdFunc(Reader *input);
};

#endif // GAMEFIGHTREMOVETEAMMEMBERMESSAGE_H