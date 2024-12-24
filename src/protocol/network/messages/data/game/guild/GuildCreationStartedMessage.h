#ifndef GUILDCREATIONSTARTEDMESSAGE_H
#define GUILDCREATIONSTARTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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