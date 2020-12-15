#include "GuildModificationEmblemValidMessage.h"

void GuildModificationEmblemValidMessage::serialize(Writer *output)
{
  this->serializeAs_GuildModificationEmblemValidMessage(output);
}

void GuildModificationEmblemValidMessage::serializeAs_GuildModificationEmblemValidMessage(Writer *output)
{
  this->guildEmblem.serializeAs_GuildEmblem(output);
}

void GuildModificationEmblemValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildModificationEmblemValidMessage(input);
}

void GuildModificationEmblemValidMessage::deserializeAs_GuildModificationEmblemValidMessage(Reader *input)
{
  this->guildEmblem = GuildEmblem();
  this->guildEmblem.deserialize(input);
}

void GuildModificationEmblemValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildModificationEmblemValidMessage(tree);
}

void GuildModificationEmblemValidMessage::deserializeAsyncAs_GuildModificationEmblemValidMessage(FuncTree tree)
{
  this->_guildEmblemtree = tree.addChild(std::bind(&GuildModificationEmblemValidMessage::_guildEmblemtreeFunc, this, std::placeholders::_1));
}

void GuildModificationEmblemValidMessage::_guildEmblemtreeFunc(Reader *input)
{
  this->guildEmblem = GuildEmblem();
  this->guildEmblem.deserializeAsync(this->_guildEmblemtree);
}

GuildModificationEmblemValidMessage::GuildModificationEmblemValidMessage()
{
  m_type = MessageEnum::GUILDMODIFICATIONEMBLEMVALIDMESSAGE;
}

