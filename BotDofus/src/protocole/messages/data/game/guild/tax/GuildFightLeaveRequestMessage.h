#ifndef GUILDFIGHTLEAVEREQUESTMESSAGE_H
#define GUILDFIGHTLEAVEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildFightLeaveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFightLeaveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFightLeaveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFightLeaveRequestMessage(FuncTree tree);
  GuildFightLeaveRequestMessage();

  double taxCollectorId;
  double characterId;

private:
  void _taxCollectorIdFunc(Reader *input);
  void _characterIdFunc(Reader *input);
};

#endif // GUILDFIGHTLEAVEREQUESTMESSAGE_H