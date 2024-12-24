#ifndef SLAVESWITCHCONTEXTMESSAGE_H
#define SLAVESWITCHCONTEXTMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristicsInformations.h"
#include "src/protocol/network/types/data/game/data/items/SpellItem.h"
#include "src/protocol/network/types/data/game/shortcut/Shortcut.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
  uint slaveTurn;
  QList<SpellItem> slaveSpells;
  QSharedPointer<CharacterCharacteristicsInformations> slaveStats;
  QList<QSharedPointer<Shortcut>> shortcuts;

private:
  void _masterIdFunc(Reader *input);
  void _slaveIdFunc(Reader *input);
  void _slaveTurnFunc(Reader *input);
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