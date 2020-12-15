#include "StatsUpgradeResultMessage.h"

void StatsUpgradeResultMessage::serialize(Writer *output)
{
  this->serializeAs_StatsUpgradeResultMessage(output);
}

void StatsUpgradeResultMessage::serializeAs_StatsUpgradeResultMessage(Writer *output)
{
  output->writeByte(this->result);
  if(this->nbCharacBoost < 0)
  {
    qDebug()<<"ERREUR - StatsUpgradeResultMessage -"<<"Forbidden value (" << this->nbCharacBoost << ") on element nbCharacBoost.";
  }
  output->writeVarShort((int)this->nbCharacBoost);
}

void StatsUpgradeResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_StatsUpgradeResultMessage(input);
}

void StatsUpgradeResultMessage::deserializeAs_StatsUpgradeResultMessage(Reader *input)
{
  this->_resultFunc(input);
  this->_nbCharacBoostFunc(input);
}

void StatsUpgradeResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatsUpgradeResultMessage(tree);
}

void StatsUpgradeResultMessage::deserializeAsyncAs_StatsUpgradeResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&StatsUpgradeResultMessage::_resultFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StatsUpgradeResultMessage::_nbCharacBoostFunc, this, std::placeholders::_1));
}

void StatsUpgradeResultMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
}

void StatsUpgradeResultMessage::_nbCharacBoostFunc(Reader *input)
{
  this->nbCharacBoost = input->readVarUhShort();
  if(this->nbCharacBoost < 0)
  {
    qDebug()<<"ERREUR - StatsUpgradeResultMessage -"<<"Forbidden value (" << this->nbCharacBoost << ") on element of StatsUpgradeResultMessage.nbCharacBoost.";
  }
}

StatsUpgradeResultMessage::StatsUpgradeResultMessage()
{
  m_type = MessageEnum::STATSUPGRADERESULTMESSAGE;
}

