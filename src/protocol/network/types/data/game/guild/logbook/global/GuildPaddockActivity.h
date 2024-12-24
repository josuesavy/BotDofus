#ifndef GUILDPADDOCKACTIVITY_H
#define GUILDPADDOCKACTIVITY_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/MapCoordinatesExtended.h"
#include "src/protocol/network/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/utils/io/type/FuncTree.h"

class GuildPaddockActivity : public GuildLogbookEntryBasicInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildPaddockActivity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildPaddockActivity(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildPaddockActivity(FuncTree tree);
  GuildPaddockActivity();
  bool operator==(const GuildPaddockActivity &compared);

  double playerId;
  QString playerName;
  QSharedPointer<MapCoordinatesExtended> paddockCoordinates;
  double farmId;
  uint paddockEventType;

private:
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _paddockCoordinatestreeFunc(Reader *input);
  void _farmIdFunc(Reader *input);
  void _paddockEventTypeFunc(Reader *input);

  FuncTree _paddockCoordinatestree;
};

#endif // GUILDPADDOCKACTIVITY_H