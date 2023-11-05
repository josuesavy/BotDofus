#include "SocialFightLeaveRequestMessage.h"

void SocialFightLeaveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_SocialFightLeaveRequestMessage(output);
}

void SocialFightLeaveRequestMessage::serializeAs_SocialFightLeaveRequestMessage(Writer *output)
{
  this->socialFightInfo.serializeAs_SocialFightInfo(output);
}

void SocialFightLeaveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_SocialFightLeaveRequestMessage(input);
}

void SocialFightLeaveRequestMessage::deserializeAs_SocialFightLeaveRequestMessage(Reader *input)
{
  this->socialFightInfo = SocialFightInfo();
  this->socialFightInfo.deserialize(input);
}

void SocialFightLeaveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialFightLeaveRequestMessage(tree);
}

void SocialFightLeaveRequestMessage::deserializeAsyncAs_SocialFightLeaveRequestMessage(FuncTree tree)
{
  this->_socialFightInfotree = tree.addChild(std::bind(&SocialFightLeaveRequestMessage::_socialFightInfotreeFunc, this, std::placeholders::_1));
}

void SocialFightLeaveRequestMessage::_socialFightInfotreeFunc(Reader *input)
{
  this->socialFightInfo = SocialFightInfo();
  this->socialFightInfo.deserializeAsync(this->_socialFightInfotree);
}

SocialFightLeaveRequestMessage::SocialFightLeaveRequestMessage()
{
  m_type = MessageEnum::SOCIALFIGHTLEAVEREQUESTMESSAGE;
}

