#include "GuildApplicationIsAnsweredMessage.h"

void GuildApplicationIsAnsweredMessage::serialize(Writer *output)
{
  this->serializeAs_GuildApplicationIsAnsweredMessage(output);
}

void GuildApplicationIsAnsweredMessage::serializeAs_GuildApplicationIsAnsweredMessage(Writer *output)
{
  output->writeBool(this->accepted);
  this->guildInformation->serializeAs_GuildInformations(output);
}

void GuildApplicationIsAnsweredMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildApplicationIsAnsweredMessage(input);
}

void GuildApplicationIsAnsweredMessage::deserializeAs_GuildApplicationIsAnsweredMessage(Reader *input)
{
  this->_acceptedFunc(input);
  this->guildInformation = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInformation->deserialize(input);
}

void GuildApplicationIsAnsweredMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildApplicationIsAnsweredMessage(tree);
}

void GuildApplicationIsAnsweredMessage::deserializeAsyncAs_GuildApplicationIsAnsweredMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildApplicationIsAnsweredMessage::_acceptedFunc, this, std::placeholders::_1));
  this->_guildInformationtree = tree.addChild(std::bind(&GuildApplicationIsAnsweredMessage::_guildInformationtreeFunc, this, std::placeholders::_1));
}

void GuildApplicationIsAnsweredMessage::_acceptedFunc(Reader *input)
{
  this->accepted = input->readBool();
}

void GuildApplicationIsAnsweredMessage::_guildInformationtreeFunc(Reader *input)
{
  this->guildInformation = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInformation->deserializeAsync(this->_guildInformationtree);
}

GuildApplicationIsAnsweredMessage::GuildApplicationIsAnsweredMessage()
{
  m_type = MessageEnum::GUILDAPPLICATIONISANSWEREDMESSAGE;
}

