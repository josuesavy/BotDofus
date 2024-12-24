#ifndef GAMEACTIONFIGHTDISPELLSPELLMESSAGE_H
#define GAMEACTIONFIGHTDISPELLSPELLMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/fight/GameActionFightDispellMessage.h"

class GameActionFightDispellSpellMessage : public GameActionFightDispellMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightDispellSpellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightDispellSpellMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightDispellSpellMessage(FuncTree tree);
  GameActionFightDispellSpellMessage();

  uint spellId;

private:
  void _spellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTDISPELLSPELLMESSAGE_H