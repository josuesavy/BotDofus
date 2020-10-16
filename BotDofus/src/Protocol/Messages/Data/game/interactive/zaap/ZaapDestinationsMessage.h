#ifndef ZAAPDESTINATIONSMESSAGE_H
#define ZAAPDESTINATIONSMESSAGE_H

#include "src/Protocol/Types/Data/game/interactive/zaap/TeleportDestination.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/interactive/zaap/TeleportDestinationsMessage.h"

class ZaapDestinationsMessage : public TeleportDestinationsMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ZaapDestinationsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ZaapDestinationsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ZaapDestinationsMessage(FuncTree tree);
  ZaapDestinationsMessage();

  double spawnMapId;

private:
  void _spawnMapIdFunc(Reader *input);
};

#endif // ZAAPDESTINATIONSMESSAGE_H