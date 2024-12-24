#ifndef GAMEACTIONFIGHTSPELLIMMUNITYMESSAGE_H
#define GAMEACTIONFIGHTSPELLIMMUNITYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightSpellImmunityMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightSpellImmunityMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightSpellImmunityMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightSpellImmunityMessage(FuncTree tree);
  GameActionFightSpellImmunityMessage();

  double targetId;
  uint spellId;

private:
  void _targetIdFunc(Reader *input);
  void _spellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTSPELLIMMUNITYMESSAGE_H