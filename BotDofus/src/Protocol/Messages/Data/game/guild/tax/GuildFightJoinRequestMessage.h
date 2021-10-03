#ifndef GUILDFIGHTJOINREQUESTMESSAGE_H
#define GUILDFIGHTJOINREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildFightJoinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFightJoinRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFightJoinRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFightJoinRequestMessage(FuncTree tree);
  GuildFightJoinRequestMessage();

  double taxCollectorId;

private:
  void _taxCollectorIdFunc(Reader *input);
};

#endif // GUILDFIGHTJOINREQUESTMESSAGE_H