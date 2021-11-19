#include "GuildMemberWarnOnConnectionStateMessage.h"

void GuildMemberWarnOnConnectionStateMessage::serialize(Writer *output)
{
  this->serializeAs_GuildMemberWarnOnConnectionStateMessage(output);
}

void GuildMemberWarnOnConnectionStateMessage::serializeAs_GuildMemberWarnOnConnectionStateMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void GuildMemberWarnOnConnectionStateMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildMemberWarnOnConnectionStateMessage(input);
}

void GuildMemberWarnOnConnectionStateMessage::deserializeAs_GuildMemberWarnOnConnectionStateMessage(Reader *input)
{
  this->_enableFunc(input);
}

void GuildMemberWarnOnConnectionStateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildMemberWarnOnConnectionStateMessage(tree);
}

void GuildMemberWarnOnConnectionStateMessage::deserializeAsyncAs_GuildMemberWarnOnConnectionStateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildMemberWarnOnConnectionStateMessage::_enableFunc, this, std::placeholders::_1));
}

void GuildMemberWarnOnConnectionStateMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

GuildMemberWarnOnConnectionStateMessage::GuildMemberWarnOnConnectionStateMessage()
{
  m_type = MessageEnum::GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE;
}

