#ifndef TELEPORTDESTINATIONSMESSAGE_H
#define TELEPORTDESTINATIONSMESSAGE_H

#include "src/protocol/network/types/data/game/interactive/zaap/TeleportDestination.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TeleportDestinationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportDestinationsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportDestinationsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportDestinationsMessage(FuncTree tree);
  TeleportDestinationsMessage();

  uint type;
  QList<TeleportDestination> destinations;

private:
  void _typeFunc(Reader *input);
  void _destinationstreeFunc(Reader *input);
  void _destinationsFunc(Reader *input);

  FuncTree _destinationstree;
};

#endif // TELEPORTDESTINATIONSMESSAGE_H