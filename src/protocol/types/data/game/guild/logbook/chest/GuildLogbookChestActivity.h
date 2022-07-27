#ifndef GUILDLOGBOOKCHESTACTIVITY_H
#define GUILDLOGBOOKCHESTACTIVITY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/ObjectItemNotInContainer.h"
#include "src/protocol/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildLogbookChestActivity : public GuildLogbookEntryBasicInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildLogbookChestActivity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildLogbookChestActivity(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildLogbookChestActivity(FuncTree tree);
  GuildLogbookChestActivity();
  bool operator==(const GuildLogbookChestActivity &compared);

  double playerId;
  QString playerName;
  uint eventType;
  uint quantity;
  QSharedPointer<ObjectItemNotInContainer> object;
  uint sourceTabId;
  uint destinationTabId;

private:
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _eventTypeFunc(Reader *input);
  void _quantityFunc(Reader *input);
  void _objecttreeFunc(Reader *input);
  void _sourceTabIdFunc(Reader *input);
  void _destinationTabIdFunc(Reader *input);

  FuncTree _objecttree;
};

#endif // GUILDLOGBOOKCHESTACTIVITY_H