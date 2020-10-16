#ifndef GAMEACTIONFIGHTREFLECTSPELLMESSAGE_H
#define GAMEACTIONFIGHTREFLECTSPELLMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

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