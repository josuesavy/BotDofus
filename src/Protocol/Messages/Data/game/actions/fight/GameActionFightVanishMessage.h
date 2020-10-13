#ifndef GAMEACTIONFIGHTVANISHMESSAGE_H
#define GAMEACTIONFIGHTVANISHMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

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