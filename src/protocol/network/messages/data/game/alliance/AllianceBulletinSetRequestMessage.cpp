#include "AllianceBulletinSetRequestMessage.h"

void AllianceBulletinSetRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceBulletinSetRequestMessage(output);
}

void AllianceBulletinSetRequestMessage::serializeAs_AllianceBulletinSetRequestMessage(Writer *output)
{
  SocialNoticeSetRequestMessage::serializeAs_SocialNoticeSetRequestMessage(output);
  output->writeUTF(this->content);
}

void AllianceBulletinSetRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceBulletinSetRequestMessage(input);
}

void AllianceBulletinSetRequestMessage::deserializeAs_AllianceBulletinSetRequestMessage(Reader *input)
{
  SocialNoticeSetRequestMessage::deserialize(input);
  this->_contentFunc(input);
}

void AllianceBulletinSetRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceBulletinSetRequestMessage(tree);
}

void AllianceBulletinSetRequestMessage::deserializeAsyncAs_AllianceBulletinSetRequestMessage(FuncTree tree)
{
  SocialNoticeSetRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&AllianceBulletinSetRequestMessage::_contentFunc, this, std::placeholders::_1));
}

void AllianceBulletinSetRequestMessage::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

AllianceBulletinSetRequestMessage::AllianceBulletinSetRequestMessage()
{
  m_type = MessageEnum::ALLIANCEBULLETINSETREQUESTMESSAGE;
}

