#ifndef GAMEACTIONFIGHTVANISHMESSAGE_H
#define GAMEACTIONFIGHTVANISHMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightVanishMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightVanishMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightVanishMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightVanishMessage(FuncTree tree);
  GameActionFightVanishMessage();

  double targetId;

private:
  void _targetIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTVANISHMESSAGE_H