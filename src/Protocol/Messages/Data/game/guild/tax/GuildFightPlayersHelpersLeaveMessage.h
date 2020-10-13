#ifndef GUILDFIGHTPLAYERSHELPERSLEAVEMESSAGE_H
#define GUILDFIGHTPLAYERSHELPERSLEAVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildFightPlayersHelpersLeaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFightPlayersHelpersLeaveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFightPlayersHelpersLeaveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFightPlayersHelpersLeaveMessage(FuncTree tree);
  GuildFightPlayersHelpersLeaveMessage();

  double fightId;
  double playerId;

private:
  void _fightIdFunc(Reader *input);
  void _playerIdFunc(Reader *input);
};

#endif // GUILDFIGHTPLAYERSHELPERSLEAVEMESSAGE_H