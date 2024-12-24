#include "GuildApplicationPresenceMessage.h"

void GuildApplicationPresenceMessage::serialize(Writer *output)
{
  this->serializeAs_GuildApplicationPresenceMessage(output);
}

void GuildApplicationPresenceMessage::serializeAs_GuildApplicationPresenceMessage(Writer *output)
{
  output->writeBool(this->isApplication);
}

void GuildApplicationPresenceMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildApplicationPresenceMessage(input);
}

void GuildApplicationPresenceMessage::deserializeAs_GuildApplicationPresenceMessage(Reader *input)
{
  this->_isApplicationFunc(input);
}

void GuildApplicationPresenceMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildApplicationPresenceMessage(tree);
}

void GuildApplicationPresenceMessage::deserializeAsyncAs_GuildApplicationPresenceMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildApplicationPresenceMessage::_isApplicationFunc, this, std::placeholders::_1));
}

void GuildApplicationPresenceMessage::_isApplicationFunc(Reader *input)
{
  this->isApplication = input->readBool();
}

GuildApplicationPresenceMessage::GuildApplicationPresenceMessage()
{
  m_type = MessageEnum::GUILDAPPLICATIONPRESENCEMESSAGE;
}

