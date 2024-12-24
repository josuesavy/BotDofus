#ifndef ALLIANCEMEMBERONLINESTATUSMESSAGE_H
#define ALLIANCEMEMBERONLINESTATUSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceMemberOnlineStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceMemberOnlineStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceMemberOnlineStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceMemberOnlineStatusMessage(FuncTree tree);
  AllianceMemberOnlineStatusMessage();

  double memberId;
  bool online;

private:
  void _memberIdFunc(Reader *input);
  void _onlineFunc(Reader *input);
};

#endif // ALLIANCEMEMBERONLINESTATUSMESSAGE_H