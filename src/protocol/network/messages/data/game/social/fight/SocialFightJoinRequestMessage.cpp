#include "SocialFightJoinRequestMessage.h"

void SocialFightJoinRequestMessage::serialize(Writer *output)
{
  this->serializeAs_SocialFightJoinRequestMessage(output);
}

void SocialFightJoinRequestMessage::serializeAs_SocialFightJoinRequestMessage(Writer *output)
{
  this->socialFightInfo.serializeAs_SocialFightInfo(output);
}

void SocialFightJoinRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_SocialFightJoinRequestMessage(input);
}

void SocialFightJoinRequestMessage::deserializeAs_SocialFightJoinRequestMessage(Reader *input)
{
  this->socialFightInfo = SocialFightInfo();
  this->socialFightInfo.deserialize(input);
}

void SocialFightJoinRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialFightJoinRequestMessage(tree);
}

void SocialFightJoinRequestMessage::deserializeAsyncAs_SocialFightJoinRequestMessage(FuncTree tree)
{
  this->_socialFightInfotree = tree.addChild(std::bind(&SocialFightJoinRequestMessage::_socialFightInfotreeFunc, this, std::placeholders::_1));
}

void SocialFightJoinRequestMessage::_socialFightInfotreeFunc(Reader *input)
{
  this->socialFightInfo = SocialFightInfo();
  this->socialFightInfo.deserializeAsync(this->_socialFightInfotree);
}

SocialFightJoinRequestMessage::SocialFightJoinRequestMessage()
{
  m_type = MessageEnum::SOCIALFIGHTJOINREQUESTMESSAGE;
}

