#include "GuildPlayerApplicationInformationMessage.h"

void GuildPlayerApplicationInformationMessage::serialize(Writer *output)
{
  this->serializeAs_GuildPlayerApplicationInformationMessage(output);
}

void GuildPlayerApplicationInformationMessage::serializeAs_GuildPlayerApplicationInformationMessage(Writer *output)
{
  GuildPlayerApplicationAbstractMessage::serializeAs_GuildPlayerApplicationAbstractMessage(output);
  this->guildInformation->serializeAs_GuildInformations(output);
  this->apply->serializeAs_GuildApplicationInformation(output);
}

void GuildPlayerApplicationInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildPlayerApplicationInformationMessage(input);
}

void GuildPlayerApplicationInformationMessage::deserializeAs_GuildPlayerApplicationInformationMessage(Reader *input)
{
  GuildPlayerApplicationAbstractMessage::deserialize(input);
  this->guildInformation = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInformation->deserialize(input);
  this->apply = QSharedPointer<GuildApplicationInformation>(new GuildApplicationInformation() );
  this->apply->deserialize(input);
}

void GuildPlayerApplicationInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildPlayerApplicationInformationMessage(tree);
}

void GuildPlayerApplicationInformationMessage::deserializeAsyncAs_GuildPlayerApplicationInformationMessage(FuncTree tree)
{
  GuildPlayerApplicationAbstractMessage::deserializeAsync(tree);
  this->_guildInformationtree = tree.addChild(std::bind(&GuildPlayerApplicationInformationMessage::_guildInformationtreeFunc, this, std::placeholders::_1));
  this->_applytree = tree.addChild(std::bind(&GuildPlayerApplicationInformationMessage::_applytreeFunc, this, std::placeholders::_1));
}

void GuildPlayerApplicationInformationMessage::_guildInformationtreeFunc(Reader *input)
{
  this->guildInformation = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInformation->deserializeAsync(this->_guildInformationtree);
}

void GuildPlayerApplicationInformationMessage::_applytreeFunc(Reader *input)
{
  this->apply = QSharedPointer<GuildApplicationInformation>(new GuildApplicationInformation() );
  this->apply->deserializeAsync(this->_applytree);
}

GuildPlayerApplicationInformationMessage::GuildPlayerApplicationInformationMessage()
{
  m_type = MessageEnum::GUILDPLAYERAPPLICATIONINFORMATIONMESSAGE;
}

