#ifndef FORGETTABLESPELLLISTUPDATEMESSAGE_H
#define FORGETTABLESPELLLISTUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ForgettableSpellItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ForgettableSpellListUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ForgettableSpellListUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ForgettableSpellListUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ForgettableSpellListUpdateMessage(FuncTree tree);
  ForgettableSpellListUpdateMessage();

  uint action;
  QList<ForgettableSpellItem> spells;

private:
  void _actionFunc(Reader *input);
  void _spellstreeFunc(Reader *input);
  void _spellsFunc(Reader *input);

  FuncTree _spellstree;
};

#endif // FORGETTABLESPELLLISTUPDATEMESSAGE_H