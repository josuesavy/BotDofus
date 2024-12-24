#ifndef GAMEROLEPLAYFIGHTREQUESTCANCELEDMESSAGE_H
#define GAMEROLEPLAYFIGHTREQUESTCANCELEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayFightRequestCanceledMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayFightRequestCanceledMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayFightRequestCanceledMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayFightRequestCanceledMessage(FuncTree tree);
  GameRolePlayFightRequestCanceledMessage();

  uint fightId;
  double sourceId;
  double targetId;

private:
  void _fightIdFunc(Reader *input);
  void _sourceIdFunc(Reader *input);
  void _targetIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYFIGHTREQUESTCANCELEDMESSAGE_H