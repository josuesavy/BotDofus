#include "GuildMotdSetRequestMessage.h"

void GuildMotdSetRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildMotdSetRequestMessage(output);
}

void GuildMotdSetRequestMessage::serializeAs_GuildMotdSetRequestMessage(Writer *output)
{
  SocialNoticeSetRequestMessage::serializeAs_SocialNoticeSetRequestMessage(output);
  output->writeUTF(this->content);
}

void GuildMotdSetRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildMotdSetRequestMessage(input);
}

void GuildMotdSetRequestMessage::deserializeAs_GuildMotdSetRequestMessage(Reader *input)
{
  SocialNoticeSetRequestMessage::deserialize(input);
  this->_contentFunc(input);
}

void GuildMotdSetRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildMotdSetRequestMessage(tree);
}

void GuildMotdSetRequestMessage::deserializeAsyncAs_GuildMotdSetRequestMessage(FuncTree tree)
{
  SocialNoticeSetRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildMotdSetRequestMessage::_contentFunc, this, std::placeholders::_1));
}

void GuildMotdSetRequestMessage::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

GuildMotdSetRequestMessage::GuildMotdSetRequestMessage()
{
  m_type = MessageEnum::GUILDMOTDSETREQUESTMESSAGE;
}

