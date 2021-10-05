#include "GuildMemberSetWarnOnConnectionMessage.h"

void GuildMemberSetWarnOnConnectionMessage::serialize(Writer *output)
{
  this->serializeAs_GuildMemberSetWarnOnConnectionMessage(output);
}

void GuildMemberSetWarnOnConnectionMessage::serializeAs_GuildMemberSetWarnOnConnectionMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void GuildMemberSetWarnOnConnectionMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildMemberSetWarnOnConnectionMessage(input);
}

void GuildMemberSetWarnOnConnectionMessage::deserializeAs_GuildMemberSetWarnOnConnectionMessage(Reader *input)
{
  this->_enableFunc(input);
}

void GuildMemberSetWarnOnConnectionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildMemberSetWarnOnConnectionMessage(tree);
}

void GuildMemberSetWarnOnConnectionMessage::deserializeAsyncAs_GuildMemberSetWarnOnConnectionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildMemberSetWarnOnConnectionMessage::_enableFunc, this, std::placeholders::_1));
}

void GuildMemberSetWarnOnConnectionMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

GuildMemberSetWarnOnConnectionMessage::GuildMemberSetWarnOnConnectionMessage()
{
  m_type = MessageEnum::GUILDMEMBERSETWARNONCONNECTIONMESSAGE;
}

