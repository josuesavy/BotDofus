#include "GuildInAllianceFactsMessage.h"

void GuildInAllianceFactsMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInAllianceFactsMessage(output);
}

void GuildInAllianceFactsMessage::serializeAs_GuildInAllianceFactsMessage(Writer *output)
{
  GuildFactsMessage::serializeAs_GuildFactsMessage(output);
  this->allianceInfos->serializeAs_BasicNamedAllianceInformations(output);
}

void GuildInAllianceFactsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInAllianceFactsMessage(input);
}

void GuildInAllianceFactsMessage::deserializeAs_GuildInAllianceFactsMessage(Reader *input)
{
  GuildFactsMessage::deserialize(input);
  this->allianceInfos = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->allianceInfos->deserialize(input);
}

void GuildInAllianceFactsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInAllianceFactsMessage(tree);
}

void GuildInAllianceFactsMessage::deserializeAsyncAs_GuildInAllianceFactsMessage(FuncTree tree)
{
  GuildFactsMessage::deserializeAsync(tree);
  this->_allianceInfostree = tree.addChild(std::bind(&GuildInAllianceFactsMessage::_allianceInfostreeFunc, this, std::placeholders::_1));
}

void GuildInAllianceFactsMessage::_allianceInfostreeFunc(Reader *input)
{
  this->allianceInfos = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->allianceInfos->deserializeAsync(this->_allianceInfostree);
}

GuildInAllianceFactsMessage::GuildInAllianceFactsMessage()
{
  m_type = MessageEnum::GUILDINALLIANCEFACTSMESSAGE;
}

