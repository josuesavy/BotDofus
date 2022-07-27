#ifndef GUILDPADDOCKTELEPORTREQUESTMESSAGE_H
#define GUILDPADDOCKTELEPORTREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildPaddockTeleportRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildPaddockTeleportRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildPaddockTeleportRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildPaddockTeleportRequestMessage(FuncTree tree);
  GuildPaddockTeleportRequestMessage();

  double paddockId;

private:
  void _paddockIdFunc(Reader *input);
};

#endif // GUILDPADDOCKTELEPORTREQUESTMESSAGE_H