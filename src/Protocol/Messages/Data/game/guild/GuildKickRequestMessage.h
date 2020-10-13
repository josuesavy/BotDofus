#ifndef GUILDKICKREQUESTMESSAGE_H
#define GUILDKICKREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildKickRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildKickRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildKickRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildKickRequestMessage(FuncTree tree);
  GuildKickRequestMessage();

  double kickedId;

private:
  void _kickedIdFunc(Reader *input);
};

#endif // GUILDKICKREQUESTMESSAGE_H