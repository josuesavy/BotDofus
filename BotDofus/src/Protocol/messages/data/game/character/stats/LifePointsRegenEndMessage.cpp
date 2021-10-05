#include "LifePointsRegenEndMessage.h"

void LifePointsRegenEndMessage::serialize(Writer *output)
{
  this->serializeAs_LifePointsRegenEndMessage(output);
}

void LifePointsRegenEndMessage::serializeAs_LifePointsRegenEndMessage(Writer *output)
{
  UpdateLifePointsMessage::serializeAs_UpdateLifePointsMessage(output);
  if(this->lifePointsGained < 0)
  {
    qDebug()<<"ERREUR - LifePointsRegenEndMessage -"<<"Forbidden value (" << this->lifePointsGained << ") on element lifePointsGained.";
  }
  output->writeVarInt((int)this->lifePointsGained);
}

void LifePointsRegenEndMessage::deserialize(Reader *input)
{
  this->deserializeAs_LifePointsRegenEndMessage(input);
}

void LifePointsRegenEndMessage::deserializeAs_LifePointsRegenEndMessage(Reader *input)
{
  UpdateLifePointsMessage::deserialize(input);
  this->_lifePointsGainedFunc(input);
}

void LifePointsRegenEndMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LifePointsRegenEndMessage(tree);
}

void LifePointsRegenEndMessage::deserializeAsyncAs_LifePointsRegenEndMessage(FuncTree tree)
{
  UpdateLifePointsMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&LifePointsRegenEndMessage::_lifePointsGainedFunc, this, std::placeholders::_1));
}

void LifePointsRegenEndMessage::_lifePointsGainedFunc(Reader *input)
{
  this->lifePointsGained = input->readVarUhInt();
  if(this->lifePointsGained < 0)
  {
    qDebug()<<"ERREUR - LifePointsRegenEndMessage -"<<"Forbidden value (" << this->lifePointsGained << ") on element of LifePointsRegenEndMessage.lifePointsGained.";
  }
}

LifePointsRegenEndMessage::LifePointsRegenEndMessage()
{
  m_type = MessageEnum::LIFEPOINTSREGENENDMESSAGE;
}

