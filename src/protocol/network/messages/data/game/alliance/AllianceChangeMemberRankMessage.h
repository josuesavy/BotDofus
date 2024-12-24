#ifndef ALLIANCECHANGEMEMBERRANKMESSAGE_H
#define ALLIANCECHANGEMEMBERRANKMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceChangeMemberRankMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceChangeMemberRankMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceChangeMemberRankMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceChangeMemberRankMessage(FuncTree tree);
  AllianceChangeMemberRankMessage();

  double memberId;
  uint rankId;

private:
  void _memberIdFunc(Reader *input);
  void _rankIdFunc(Reader *input);
};

#endif // ALLIANCECHANGEMEMBERRANKMESSAGE_H