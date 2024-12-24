#include "ChatCommunityChannelSetCommunityRequestMessage.h"

void ChatCommunityChannelSetCommunityRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ChatCommunityChannelSetCommunityRequestMessage(output);
}

void ChatCommunityChannelSetCommunityRequestMessage::serializeAs_ChatCommunityChannelSetCommunityRequestMessage(Writer *output)
{
  output->writeShort((short)this->communityId);
}

void ChatCommunityChannelSetCommunityRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatCommunityChannelSetCommunityRequestMessage(input);
}

void ChatCommunityChannelSetCommunityRequestMessage::deserializeAs_ChatCommunityChannelSetCommunityRequestMessage(Reader *input)
{
  this->_communityIdFunc(input);
}

void ChatCommunityChannelSetCommunityRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatCommunityChannelSetCommunityRequestMessage(tree);
}

void ChatCommunityChannelSetCommunityRequestMessage::deserializeAsyncAs_ChatCommunityChannelSetCommunityRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChatCommunityChannelSetCommunityRequestMessage::_communityIdFunc, this, std::placeholders::_1));
}

void ChatCommunityChannelSetCommunityRequestMessage::_communityIdFunc(Reader *input)
{
  this->communityId = input->readShort();
}

ChatCommunityChannelSetCommunityRequestMessage::ChatCommunityChannelSetCommunityRequestMessage()
{
  m_type = MessageEnum::CHATCOMMUNITYCHANNELSETCOMMUNITYREQUESTMESSAGE;
}

