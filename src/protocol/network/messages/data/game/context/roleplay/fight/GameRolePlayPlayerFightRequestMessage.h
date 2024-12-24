#ifndef GAMEROLEPLAYPLAYERFIGHTREQUESTMESSAGE_H
#define GAMEROLEPLAYPLAYERFIGHTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayPlayerFightRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayPlayerFightRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayPlayerFightRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayPlayerFightRequestMessage(FuncTree tree);
  GameRolePlayPlayerFightRequestMessage();

  double targetId;
  int targetCellId;
  bool friendly;

private:
  void _targetIdFunc(Reader *input);
  void _targetCellIdFunc(Reader *input);
  void _friendlyFunc(Reader *input);
};

#endif // GAMEROLEPLAYPLAYERFIGHTREQUESTMESSAGE_H