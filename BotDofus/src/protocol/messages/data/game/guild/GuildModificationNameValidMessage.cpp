#include "GuildModificationNameValidMessage.h"

void GuildModificationNameValidMessage::serialize(Writer *output)
{
  this->serializeAs_GuildModificationNameValidMessage(output);
}

void GuildModificationNameValidMessage::serializeAs_GuildModificationNameValidMessage(Writer *output)
{
  output->writeUTF(this->guildName);
}

void GuildModificationNameValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildModificationNameValidMessage(input);
}

void GuildModificationNameValidMessage::deserializeAs_GuildModificationNameValidMessage(Reader *input)
{
  this->_guildNameFunc(input);
}

void GuildModificationNameValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildModificationNameValidMessage(tree);
}

void GuildModificationNameValidMessage::deserializeAsyncAs_GuildModificationNameValidMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildModificationNameValidMessage::_guildNameFunc, this, std::placeholders::_1));
}

void GuildModificationNameValidMessage::_guildNameFunc(Reader *input)
{
  this->guildName = input->readUTF();
}

GuildModificationNameValidMessage::GuildModificationNameValidMessage()
{
  m_type = MessageEnum::GUILDMODIFICATIONNAMEVALIDMESSAGE;
}

