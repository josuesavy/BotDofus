#ifndef GAMEACTIONFIGHTCASTONTARGETREQUESTMESSAGE_H
#define GAMEACTIONFIGHTCASTONTARGETREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameActionFightCastOnTargetRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightCastOnTargetRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightCastOnTargetRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightCastOnTargetRequestMessage(FuncTree tree);
  GameActionFightCastOnTargetRequestMessage();

  uint spellId;
  double targetId;

private:
  void _spellIdFunc(Reader *input);
  void _targetIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTCASTONTARGETREQUESTMESSAGE_H