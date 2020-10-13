#ifndef CHATCOMMUNITYCHANNELSETCOMMUNITYREQUESTMESSAGE_H
#define CHATCOMMUNITYCHANNELSETCOMMUNITYREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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