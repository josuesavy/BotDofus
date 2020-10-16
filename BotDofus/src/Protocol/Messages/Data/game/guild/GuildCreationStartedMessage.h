#ifndef GUILDCREATIONSTARTEDMESSAGE_H
#define GUILDCREATIONSTARTEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildCreationStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildCreationStartedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildCreationStartedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildCreationStartedMessage(FuncTree tree);
  GuildCreationStartedMessage();
};

#endif // GUILDCREATIONSTARTEDMESSAGE_H