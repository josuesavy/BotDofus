#include "GuildHouseUpdateInformationMessage.h"

void GuildHouseUpdateInformationMessage::serialize(Writer *output)
{
  this->serializeAs_GuildHouseUpdateInformationMessage(output);
}

void GuildHouseUpdateInformationMessage::serializeAs_GuildHouseUpdateInformationMessage(Writer *output)
{
  this->housesInformations->serializeAs_HouseInformationsForGuild(output);
}

void GuildHouseUpdateInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildHouseUpdateInformationMessage(input);
}

void GuildHouseUpdateInformationMessage::deserializeAs_GuildHouseUpdateInformationMessage(Reader *input)
{
  this->housesInformations = QSharedPointer<HouseInformationsForGuild>(new HouseInformationsForGuild() );
  this->housesInformations->deserialize(input);
}

void GuildHouseUpdateInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildHouseUpdateInformationMessage(tree);
}

void GuildHouseUpdateInformationMessage::deserializeAsyncAs_GuildHouseUpdateInformationMessage(FuncTree tree)
{
  this->_housesInformationstree = tree.addChild(std::bind(&GuildHouseUpdateInformationMessage::_housesInformationstreeFunc, this, std::placeholders::_1));
}

void GuildHouseUpdateInformationMessage::_housesInformationstreeFunc(Reader *input)
{
  this->housesInformations = QSharedPointer<HouseInformationsForGuild>(new HouseInformationsForGuild() );
  this->housesInformations->deserializeAsync(this->_housesInformationstree);
}

GuildHouseUpdateInformationMessage::GuildHouseUpdateInformationMessage()
{
  m_type = MessageEnum::GUILDHOUSEUPDATEINFORMATIONMESSAGE;
}

