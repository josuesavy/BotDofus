#ifndef SPELLLISTMESSAGE_H
#define SPELLLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/SpellItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class SpellListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpellListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpellListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpellListMessage(FuncTree tree);
  SpellListMessage();

  bool spellPrevisualization;
  QList<SpellItem> spells;

private:
  void _spellPrevisualizationFunc(Reader *input);
  void _spellstreeFunc(Reader *input);
  void _spellsFunc(Reader *input);

  FuncTree _spellstree;
};

#endif // SPELLLISTMESSAGE_H