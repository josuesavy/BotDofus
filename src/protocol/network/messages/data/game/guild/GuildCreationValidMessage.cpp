#include "GuildCreationValidMessage.h"

void GuildCreationValidMessage::serialize(Writer *output)
{
  this->serializeAs_GuildCreationValidMessage(output);
}

void GuildCreationValidMessage::serializeAs_GuildCreationValidMessage(Writer *output)
{
  output->writeUTF(this->guildName);
  this->guildEmblem.serializeAs_SocialEmblem(output);
}

void GuildCreationValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildCreationValidMessage(input);
}

void GuildCreationValidMessage::deserializeAs_GuildCreationValidMessage(Reader *input)
{
  this->_guildNameFunc(input);
  this->guildEmblem = SocialEmblem();
  this->guildEmblem.deserialize(input);
}

void GuildCreationValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildCreationValidMessage(tree);
}

void GuildCreationValidMessage::deserializeAsyncAs_GuildCreationValidMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildCreationValidMessage::_guildNameFunc, this, std::placeholders::_1));
  this->_guildEmblemtree = tree.addChild(std::bind(&GuildCreationValidMessage::_guildEmblemtreeFunc, this, std::placeholders::_1));
}

void GuildCreationValidMessage::_guildNameFunc(Reader *input)
{
  this->guildName = input->readUTF();
}

void GuildCreationValidMessage::_guildEmblemtreeFunc(Reader *input)
{
  this->guildEmblem = SocialEmblem();
  this->guildEmblem.deserializeAsync(this->_guildEmblemtree);
}

GuildCreationValidMessage::GuildCreationValidMessage()
{
  m_type = MessageEnum::GUILDCREATIONVALIDMESSAGE;
}

