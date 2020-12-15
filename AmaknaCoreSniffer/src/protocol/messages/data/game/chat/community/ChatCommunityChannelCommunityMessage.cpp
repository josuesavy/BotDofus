#include "ChatCommunityChannelCommunityMessage.h"

void ChatCommunityChannelCommunityMessage::serialize(Writer *output)
{
  this->serializeAs_ChatCommunityChannelCommunityMessage(output);
}

void ChatCommunityChannelCommunityMessage::serializeAs_ChatCommunityChannelCommunityMessage(Writer *output)
{
  output->writeShort((short)this->communityId);
}

void ChatCommunityChannelCommunityMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatCommunityChannelCommunityMessage(input);
}

void ChatCommunityChannelCommunityMessage::deserializeAs_ChatCommunityChannelCommunityMessage(Reader *input)
{
  this->_communityIdFunc(input);
}

void ChatCommunityChannelCommunityMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatCommunityChannelCommunityMessage(tree);
}

void ChatCommunityChannelCommunityMessage::deserializeAsyncAs_ChatCommunityChannelCommunityMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChatCommunityChannelCommunityMessage::_communityIdFunc, this, std::placeholders::_1));
}

void ChatCommunityChannelCommunityMessage::_communityIdFunc(Reader *input)
{
  this->communityId = input->readShort();
}

ChatCommunityChannelCommunityMessage::ChatCommunityChannelCommunityMessage()
{
  m_type = MessageEnum::CHATCOMMUNITYCHANNELCOMMUNITYMESSAGE;
}

