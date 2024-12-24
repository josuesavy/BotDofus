#ifndef GAMEACTIONFIGHTNOSPELLCASTMESSAGE_H
#define GAMEACTIONFIGHTNOSPELLCASTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameActionFightNoSpellCastMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightNoSpellCastMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightNoSpellCastMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightNoSpellCastMessage(FuncTree tree);
  GameActionFightNoSpellCastMessage();

  uint spellLevelId;

private:
  void _spellLevelIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTNOSPELLCASTMESSAGE_H