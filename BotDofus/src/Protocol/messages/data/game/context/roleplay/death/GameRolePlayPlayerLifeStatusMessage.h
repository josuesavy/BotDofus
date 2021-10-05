#ifndef GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE_H
#define GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayPlayerLifeStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayPlayerLifeStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayPlayerLifeStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayPlayerLifeStatusMessage(FuncTree tree);
  GameRolePlayPlayerLifeStatusMessage();

  uint state;
  double phenixMapId;

private:
  void _stateFunc(Reader *input);
  void _phenixMapIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE_H