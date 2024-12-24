#ifndef CHATCOMMUNITYCHANNELSETCOMMUNITYREQUESTMESSAGE_H
#define CHATCOMMUNITYCHANNELSETCOMMUNITYREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChatCommunityChannelSetCommunityRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatCommunityChannelSetCommunityRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatCommunityChannelSetCommunityRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatCommunityChannelSetCommunityRequestMessage(FuncTree tree);
  ChatCommunityChannelSetCommunityRequestMessage();

  int communityId;

private:
  void _communityIdFunc(Reader *input);
};

#endif // CHATCOMMUNITYCHANNELSETCOMMUNITYREQUESTMESSAGE_H