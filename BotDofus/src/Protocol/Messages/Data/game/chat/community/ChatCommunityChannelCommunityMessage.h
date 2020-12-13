#ifndef CHATCOMMUNITYCHANNELCOMMUNITYMESSAGE_H
#define CHATCOMMUNITYCHANNELCOMMUNITYMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ChatCommunityChannelCommunityMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatCommunityChannelCommunityMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatCommunityChannelCommunityMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatCommunityChannelCommunityMessage(FuncTree tree);
  ChatCommunityChannelCommunityMessage();

  int communityId;

private:
  void _communityIdFunc(Reader *input);
};

#endif // CHATCOMMUNITYCHANNELCOMMUNITYMESSAGE_H