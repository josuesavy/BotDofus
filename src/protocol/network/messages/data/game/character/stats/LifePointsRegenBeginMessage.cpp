#include "LifePointsRegenBeginMessage.h"

void LifePointsRegenBeginMessage::serialize(Writer *output)
{
  this->serializeAs_LifePointsRegenBeginMessage(output);
}

void LifePointsRegenBeginMessage::serializeAs_LifePointsRegenBeginMessage(Writer *output)
{
  if(this->regenRate < 0 || this->regenRate > 255)
  {
    qDebug()<<"ERREUR - LifePointsRegenBeginMessage -"<<"Forbidden value (" << this->regenRate << ") on element regenRate.";
  }
  output->writeByte(this->regenRate);
}

void LifePointsRegenBeginMessage::deserialize(Reader *input)
{
  this->deserializeAs_LifePointsRegenBeginMessage(input);
}

void LifePointsRegenBeginMessage::deserializeAs_LifePointsRegenBeginMessage(Reader *input)
{
  this->_regenRateFunc(input);
}

void LifePointsRegenBeginMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LifePointsRegenBeginMessage(tree);
}

void LifePointsRegenBeginMessage::deserializeAsyncAs_LifePointsRegenBeginMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LifePointsRegenBeginMessage::_regenRateFunc, this, std::placeholders::_1));
}

void LifePointsRegenBeginMessage::_regenRateFunc(Reader *input)
{
  this->regenRate = input->readUByte();
  if(this->regenRate < 0 || this->regenRate > 255)
  {
    qDebug()<<"ERREUR - LifePointsRegenBeginMessage -"<<"Forbidden value (" << this->regenRate << ") on element of LifePointsRegenBeginMessage.regenRate.";
  }
}

LifePointsRegenBeginMessage::LifePointsRegenBeginMessage()
{
  m_type = MessageEnum::LIFEPOINTSREGENBEGINMESSAGE;
}

