#ifndef GUILDISTHEREANYAPPLICATIONMESSAGE_H
#define GUILDISTHEREANYAPPLICATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildIsThereAnyApplicationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildIsThereAnyApplicationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildIsThereAnyApplicationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildIsThereAnyApplicationMessage(FuncTree tree);
  GuildIsThereAnyApplicationMessage();
};

#endif // GUILDISTHEREANYAPPLICATIONMESSAGE_H