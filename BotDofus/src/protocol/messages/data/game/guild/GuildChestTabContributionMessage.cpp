#include "GuildChestTabContributionMessage.h"

void GuildChestTabContributionMessage::serialize(Writer *output)
{
  this->serializeAs_GuildChestTabContributionMessage(output);
}

void GuildChestTabContributionMessage::serializeAs_GuildChestTabContributionMessage(Writer *output)
{
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - GuildChestTabContributionMessage -"<<"Forbidden value (" << this->tabNumber << ") on element tabNumber.";
  }
  output->writeVarInt((int)this->tabNumber);
  if(this->requiredAmount < 0 || this->requiredAmount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChestTabContributionMessage -"<<"Forbidden value (" << this->requiredAmount << ") on element requiredAmount.";
  }
  output->writeVarLong((double)this->requiredAmount);
  if(this->currentAmount < 0 || this->currentAmount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChestTabContributionMessage -"<<"Forbidden value (" << this->currentAmount << ") on element currentAmount.";
  }
  output->writeVarLong((double)this->currentAmount);
  if(this->chestContributionEnrollmentDelay < 0 || this->chestContributionEnrollmentDelay > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChestTabContributionMessage -"<<"Forbidden value (" << this->chestContributionEnrollmentDelay << ") on element chestContributionEnrollmentDelay.";
  }
  output->writeDouble(this->chestContributionEnrollmentDelay);
  if(this->chestContributionDelay < 0 || this->chestContributionDelay > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChestTabContributionMessage -"<<"Forbidden value (" << this->chestContributionDelay << ") on element chestContributionDelay.";
  }
  output->writeDouble(this->chestContributionDelay);
}

void GuildChestTabContributionMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildChestTabContributionMessage(input);
}

void GuildChestTabContributionMessage::deserializeAs_GuildChestTabContributionMessage(Reader *input)
{
  this->_tabNumberFunc(input);
  this->_requiredAmountFunc(input);
  this->_currentAmountFunc(input);
  this->_chestContributionEnrollmentDelayFunc(input);
  this->_chestContributionDelayFunc(input);
}

void GuildChestTabContributionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildChestTabContributionMessage(tree);
}

void GuildChestTabContributionMessage::deserializeAsyncAs_GuildChestTabContributionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildChestTabContributionMessage::_tabNumberFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildChestTabContributionMessage::_requiredAmountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildChestTabContributionMessage::_currentAmountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildChestTabContributionMessage::_chestContributionEnrollmentDelayFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildChestTabContributionMessage::_chestContributionDelayFunc, this, std::placeholders::_1));
}

void GuildChestTabContributionMessage::_tabNumberFunc(Reader *input)
{
  this->tabNumber = input->readVarUhInt();
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - GuildChestTabContributionMessage -"<<"Forbidden value (" << this->tabNumber << ") on element of GuildChestTabContributionMessage.tabNumber.";
  }
}

void GuildChestTabContributionMessage::_requiredAmountFunc(Reader *input)
{
  this->requiredAmount = input->readVarUhLong();
  if(this->requiredAmount < 0 || this->requiredAmount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChestTabContributionMessage -"<<"Forbidden value (" << this->requiredAmount << ") on element of GuildChestTabContributionMessage.requiredAmount.";
  }
}

void GuildChestTabContributionMessage::_currentAmountFunc(Reader *input)
{
  this->currentAmount = input->readVarUhLong();
  if(this->currentAmount < 0 || this->currentAmount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChestTabContributionMessage -"<<"Forbidden value (" << this->currentAmount << ") on element of GuildChestTabContributionMessage.currentAmount.";
  }
}

void GuildChestTabContributionMessage::_chestContributionEnrollmentDelayFunc(Reader *input)
{
  this->chestContributionEnrollmentDelay = input->readDouble();
  if(this->chestContributionEnrollmentDelay < 0 || this->chestContributionEnrollmentDelay > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChestTabContributionMessage -"<<"Forbidden value (" << this->chestContributionEnrollmentDelay << ") on element of GuildChestTabContributionMessage.chestContributionEnrollmentDelay.";
  }
}

void GuildChestTabContributionMessage::_chestContributionDelayFunc(Reader *input)
{
  this->chestContributionDelay = input->readDouble();
  if(this->chestContributionDelay < 0 || this->chestContributionDelay > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChestTabContributionMessage -"<<"Forbidden value (" << this->chestContributionDelay << ") on element of GuildChestTabContributionMessage.chestContributionDelay.";
  }
}

GuildChestTabContributionMessage::GuildChestTabContributionMessage()
{
  m_type = MessageEnum::GUILDCHESTTABCONTRIBUTIONMESSAGE;
}

