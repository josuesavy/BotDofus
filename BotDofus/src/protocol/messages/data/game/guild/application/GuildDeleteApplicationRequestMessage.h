#ifndef GUILDDELETEAPPLICATIONREQUESTMESSAGE_H
#define GUILDDELETEAPPLICATIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildDeleteApplicationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildDeleteApplicationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildDeleteApplicationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildDeleteApplicationRequestMessage(FuncTree tree);
  GuildDeleteApplicationRequestMessage();
};

#endif // GUILDDELETEAPPLICATIONREQUESTMESSAGE_H