#ifndef GUILDFACTSREQUESTMESSAGE_H
#define GUILDFACTSREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildFactsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFactsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFactsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFactsRequestMessage(FuncTree tree);
  GuildFactsRequestMessage();

  uint guildId;

private:
  void _guildIdFunc(Reader *input);
};

#endif // GUILDFACTSREQUESTMESSAGE_H