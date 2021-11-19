#ifndef ZAAPDESTINATIONSMESSAGE_H
#define ZAAPDESTINATIONSMESSAGE_H

#include "src/protocol/types/data/game/interactive/zaap/TeleportDestination.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/interactive/zaap/TeleportDestinationsMessage.h"

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