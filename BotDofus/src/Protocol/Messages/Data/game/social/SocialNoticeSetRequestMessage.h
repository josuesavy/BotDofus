#ifndef SOCIALNOTICESETREQUESTMESSAGE_H
#define SOCIALNOTICESETREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class SocialNoticeSetRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialNoticeSetRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialNoticeSetRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialNoticeSetRequestMessage(FuncTree tree);
  SocialNoticeSetRequestMessage();
};

#endif // SOCIALNOTICESETREQUESTMESSAGE_H