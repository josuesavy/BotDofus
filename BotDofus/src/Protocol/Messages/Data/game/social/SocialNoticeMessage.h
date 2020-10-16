#ifndef SOCIALNOTICEMESSAGE_H
#define SOCIALNOTICEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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