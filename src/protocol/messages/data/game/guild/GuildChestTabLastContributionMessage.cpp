#include "GuildChestTabLastContributionMessage.h"

void GuildChestTabLastContributionMessage::serialize(Writer *output)
{
  this->serializeAs_GuildChestTabLastContributionMessage(output);
}

void GuildChestTabLastContributionMessage::serializeAs_GuildChestTabLastContributionMessage(Writer *output)
{
  if(this->lastContributionDate < 0 || this->lastContributionDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChestTabLastContributionMessage -"<<"Forbidden value (" << this->lastContributionDate << ") on element lastContributionDate.";
  }
  output->writeDouble(this->lastContributionDate);
}

void GuildChestTabLastContributionMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildChestTabLastContributionMessage(input);
}

void GuildChestTabLastContributionMessage::deserializeAs_GuildChestTabLastContributionMessage(Reader *input)
{
  this->_lastContributionDateFunc(input);
}

void GuildChestTabLastContributionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildChestTabLastContributionMessage(tree);
}

void GuildChestTabLastContributionMessage::deserializeAsyncAs_GuildChestTabLastContributionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildChestTabLastContributionMessage::_lastContributionDateFunc, this, std::placeholders::_1));
}

void GuildChestTabLastContributionMessage::_lastContributionDateFunc(Reader *input)
{
  this->lastContributionDate = input->readDouble();
  if(this->lastContributionDate < 0 || this->lastContributionDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChestTabLastContributionMessage -"<<"Forbidden value (" << this->lastContributionDate << ") on element of GuildChestTabLastContributionMessage.lastContributionDate.";
  }
}

GuildChestTabLastContributionMessage::GuildChestTabLastContributionMessage()
{
  m_type = MessageEnum::GUILDCHESTTABLASTCONTRIBUTIONMESSAGE;
}

