#include "GuildApplicationDeletedMessage.h"

void GuildApplicationDeletedMessage::serialize(Writer *output)
{
  this->serializeAs_GuildApplicationDeletedMessage(output);
}

void GuildApplicationDeletedMessage::serializeAs_GuildApplicationDeletedMessage(Writer *output)
{
  output->writeBool(this->deleted);
}

void GuildApplicationDeletedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildApplicationDeletedMessage(input);
}

void GuildApplicationDeletedMessage::deserializeAs_GuildApplicationDeletedMessage(Reader *input)
{
  this->_deletedFunc(input);
}

void GuildApplicationDeletedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildApplicationDeletedMessage(tree);
}

void GuildApplicationDeletedMessage::deserializeAsyncAs_GuildApplicationDeletedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildApplicationDeletedMessage::_deletedFunc, this, std::placeholders::_1));
}

void GuildApplicationDeletedMessage::_deletedFunc(Reader *input)
{
  this->deleted = input->readBool();
}

GuildApplicationDeletedMessage::GuildApplicationDeletedMessage()
{
  m_type = MessageEnum::GUILDAPPLICATIONDELETEDMESSAGE;
}

