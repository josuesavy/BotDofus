#ifndef GAMEACTIONFIGHTDROPCHARACTERMESSAGE_H
#define GAMEACTIONFIGHTDROPCHARACTERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightDropCharacterMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightDropCharacterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightDropCharacterMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightDropCharacterMessage(FuncTree tree);
  GameActionFightDropCharacterMessage();

  double targetId;
  int cellId;

private:
  void _targetIdFunc(Reader *input);
  void _cellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTDROPCHARACTERMESSAGE_H