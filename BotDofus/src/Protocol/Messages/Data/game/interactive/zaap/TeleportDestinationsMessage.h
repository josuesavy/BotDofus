#ifndef TELEPORTDESTINATIONSMESSAGE_H
#define TELEPORTDESTINATIONSMESSAGE_H

#include "src/Protocol/Types/Data/game/interactive/zaap/TeleportDestination.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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