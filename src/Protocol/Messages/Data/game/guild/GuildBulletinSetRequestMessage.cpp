#include "GuildBulletinSetRequestMessage.h"

void GuildBulletinSetRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildBulletinSetRequestMessage(output);
}

void GuildBulletinSetRequestMessage::serializeAs_GuildBulletinSetRequestMessage(Writer *output)
{
  SocialNoticeSetRequestMessage::serializeAs_SocialNoticeSetRequestMessage(output);
  output->writeUTF(this->content);
  output->writeBool(this->notifyMembers);
}

void GuildBulletinSetRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildBulletinSetRequestMessage(input);
}

void GuildBulletinSetRequestMessage::deserializeAs_GuildBulletinSetRequestMessage(Reader *input)
{
  SocialNoticeSetRequestMessage::deserialize(input);
  this->_contentFunc(input);
  this->_notifyMembersFunc(input);
}

void GuildBulletinSetRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildBulletinSetRequestMessage(tree);
}

void GuildBulletinSetRequestMessage::deserializeAsyncAs_GuildBulletinSetRequestMessage(FuncTree tree)
{
  SocialNoticeSetRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildBulletinSetRequestMessage::_contentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildBulletinSetRequestMessage::_notifyMembersFunc, this, std::placeholders::_1));
}

void GuildBulletinSetRequestMessage::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

void GuildBulletinSetRequestMessage::_notifyMembersFunc(Reader *input)
{
  this->notifyMembers = input->readBool();
}

GuildBulletinSetRequestMessage::GuildBulletinSetRequestMessage()
{
  m_type = MessageEnum::GUILDBULLETINSETREQUESTMESSAGE;
}

