#ifndef SLAVESWITCHCONTEXTMESSAGE_H
#define SLAVESWITCHCONTEXTMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/SpellItem.h"
#include "src/Protocol/Types/Data/game/character/characteristic/CharacterCharacteristicsInformations.h"
#include "src/Protocol/Types/Data/game/shortcut/Shortcut.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class SlaveSwitchContextMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SlaveSwitchContextMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SlaveSwitchContextMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SlaveSwitchContextMessage(FuncTree tree);
  SlaveSwitchContextMessage();

  double masterId;
  double slaveId;
  QList<SpellItem> slaveSpells;
  CharacterCharacteristicsInformations slaveStats;
  QList<QSharedPointer<Shortcut>> shortcuts;

private:
  void _masterIdFunc(Reader *input);
  void _slaveIdFunc(Reader *input);
  void _slaveSpellstreeFunc(Reader *input);
  void _slaveSpellsFunc(Reader *input);
  void _slaveStatstreeFunc(Reader *input);
  void _shortcutstreeFunc(Reader *input);
  void _shortcutsFunc(Reader *input);

  FuncTree _slaveSpellstree;
  FuncTree _slaveStatstree;
  FuncTree _shortcutstree;
};

#endif // SLAVESWITCHCONTEXTMESSAGE_H