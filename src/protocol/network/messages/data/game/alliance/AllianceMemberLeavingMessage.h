#ifndef ALLIANCEMEMBERLEAVINGMESSAGE_H
#define ALLIANCEMEMBERLEAVINGMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceMemberLeavingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceMemberLeavingMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceMemberLeavingMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceMemberLeavingMessage(FuncTree tree);
  AllianceMemberLeavingMessage();

  bool kicked;
  double memberId;

private:
  void _kickedFunc(Reader *input);
  void _memberIdFunc(Reader *input);
};

#endif // ALLIANCEMEMBERLEAVINGMESSAGE_H