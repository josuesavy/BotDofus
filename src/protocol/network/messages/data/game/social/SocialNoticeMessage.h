#ifndef SOCIALNOTICEMESSAGE_H
#define SOCIALNOTICEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SocialNoticeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialNoticeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialNoticeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialNoticeMessage(FuncTree tree);
  SocialNoticeMessage();

  QString content;
  uint timestamp;
  double memberId;
  QString memberName;

private:
  void _contentFunc(Reader *input);
  void _timestampFunc(Reader *input);
  void _memberIdFunc(Reader *input);
  void _memberNameFunc(Reader *input);
};

#endif // SOCIALNOTICEMESSAGE_H