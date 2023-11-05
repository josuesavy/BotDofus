#ifndef GAMEACTIONFIGHTINVISIBILITYMESSAGE_H
#define GAMEACTIONFIGHTINVISIBILITYMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightInvisibilityMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightInvisibilityMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightInvisibilityMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightInvisibilityMessage(FuncTree tree);
  GameActionFightInvisibilityMessage();

  double targetId;
  uint state;

private:
  void _targetIdFunc(Reader *input);
  void _stateFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTINVISIBILITYMESSAGE_H