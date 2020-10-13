#include "GuildModificationValidMessage.h"

void GuildModificationValidMessage::serialize(Writer *output)
{
  this->serializeAs_GuildModificationValidMessage(output);
}

void GuildModificationValidMessage::serializeAs_GuildModificationValidMessage(Writer *output)
{
  output->writeUTF(this->guildName);
  this->guildEmblem.serializeAs_GuildEmblem(output);
}

void GuildModificationValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildModificationValidMessage(input);
}

void GuildModificationValidMessage::deserializeAs_GuildModificationValidMessage(Reader *input)
{
  this->_guildNameFunc(input);
  this->guildEmblem = GuildEmblem();
  this->guildEmblem.deserialize(input);
}

void GuildModificationValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildModificationValidMessage(tree);
}

void GuildModificationValidMessage::deserializeAsyncAs_GuildModificationValidMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildModificationValidMessage::_guildNameFunc, this, std::placeholders::_1));
  this->_guildEmblemtree = tree.addChild(std::bind(&GuildModificationValidMessage::_guildEmblemtreeFunc, this, std::placeholders::_1));
}

void GuildModificationValidMessage::_guildNameFunc(Reader *input)
{
  this->guildName = input->readUTF();
}

void GuildModificationValidMessage::_guildEmblemtreeFunc(Reader *input)
{
  this->guildEmblem = GuildEmblem();
  this->guildEmblem.deserializeAsync(this->_guildEmblemtree);
}

GuildModificationValidMessage::GuildModificationValidMessage()
{
  m_type = MessageEnum::GUILDMODIFICATIONVALIDMESSAGE;
}

