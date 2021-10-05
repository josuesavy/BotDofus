#include "StatsUpgradeRequestMessage.h"

void StatsUpgradeRequestMessage::serialize(Writer *output)
{
  this->serializeAs_StatsUpgradeRequestMessage(output);
}

void StatsUpgradeRequestMessage::serializeAs_StatsUpgradeRequestMessage(Writer *output)
{
  output->writeBool(this->useAdditionnal);
  output->writeByte(this->statId);
  if(this->boostPoint < 0)
  {
    qDebug()<<"ERREUR - StatsUpgradeRequestMessage -"<<"Forbidden value (" << this->boostPoint << ") on element boostPoint.";
  }
  output->writeVarShort((int)this->boostPoint);
}

void StatsUpgradeRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_StatsUpgradeRequestMessage(input);
}

void StatsUpgradeRequestMessage::deserializeAs_StatsUpgradeRequestMessage(Reader *input)
{
  this->_useAdditionnalFunc(input);
  this->_statIdFunc(input);
  this->_boostPointFunc(input);
}

void StatsUpgradeRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatsUpgradeRequestMessage(tree);
}

void StatsUpgradeRequestMessage::deserializeAsyncAs_StatsUpgradeRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&StatsUpgradeRequestMessage::_useAdditionnalFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StatsUpgradeRequestMessage::_statIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StatsUpgradeRequestMessage::_boostPointFunc, this, std::placeholders::_1));
}

void StatsUpgradeRequestMessage::_useAdditionnalFunc(Reader *input)
{
  this->useAdditionnal = input->readBool();
}

void StatsUpgradeRequestMessage::_statIdFunc(Reader *input)
{
  this->statId = input->readByte();
  if(this->statId < 0)
  {
    qDebug()<<"ERREUR - StatsUpgradeRequestMessage -"<<"Forbidden value (" << this->statId << ") on element of StatsUpgradeRequestMessage.statId.";
  }
}

void StatsUpgradeRequestMessage::_boostPointFunc(Reader *input)
{
  this->boostPoint = input->readVarUhShort();
  if(this->boostPoint < 0)
  {
    qDebug()<<"ERREUR - StatsUpgradeRequestMessage -"<<"Forbidden value (" << this->boostPoint << ") on element of StatsUpgradeRequestMessage.boostPoint.";
  }
}

StatsUpgradeRequestMessage::StatsUpgradeRequestMessage()
{
  m_type = MessageEnum::STATSUPGRADEREQUESTMESSAGE;
}

