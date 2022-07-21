#ifndef GUILDLOGBOOKINFORMATIONREQUESTMESSAGE_H
#define GUILDLOGBOOKINFORMATIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildLogbookInformationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildLogbookInformationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildLogbookInformationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildLogbookInformationRequestMessage(FuncTree tree);
  GuildLogbookInformationRequestMessage();
};

#endif // GUILDLOGBOOKINFORMATIONREQUESTMESSAGE_H