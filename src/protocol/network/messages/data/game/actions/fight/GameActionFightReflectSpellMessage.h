#ifndef GAMEACTIONFIGHTREFLECTSPELLMESSAGE_H
#define GAMEACTIONFIGHTREFLECTSPELLMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightReflectSpellMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightReflectSpellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightReflectSpellMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightReflectSpellMessage(FuncTree tree);
  GameActionFightReflectSpellMessage();

  double targetId;

private:
  void _targetIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTREFLECTSPELLMESSAGE_H