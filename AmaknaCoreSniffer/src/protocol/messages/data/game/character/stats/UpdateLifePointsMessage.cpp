#include "UpdateLifePointsMessage.h"

void UpdateLifePointsMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateLifePointsMessage(output);
}

void UpdateLifePointsMessage::serializeAs_UpdateLifePointsMessage(Writer *output)
{
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - UpdateLifePointsMessage -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
  }
  output->writeVarInt((int)this->lifePoints);
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - UpdateLifePointsMessage -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
  }
  output->writeVarInt((int)this->maxLifePoints);
}

void UpdateLifePointsMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateLifePointsMessage(input);
}

void UpdateLifePointsMessage::deserializeAs_UpdateLifePointsMessage(Reader *input)
{
  this->_lifePointsFunc(input);
  this->_maxLifePointsFunc(input);
}

void UpdateLifePointsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateLifePointsMessage(tree);
}

void UpdateLifePointsMessage::deserializeAsyncAs_UpdateLifePointsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&UpdateLifePointsMessage::_lifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&UpdateLifePointsMessage::_maxLifePointsFunc, this, std::placeholders::_1));
}

void UpdateLifePointsMessage::_lifePointsFunc(Reader *input)
{
  this->lifePoints = input->readVarUhInt();
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - UpdateLifePointsMessage -"<<"Forbidden value (" << this->lifePoints << ") on element of UpdateLifePointsMessage.lifePoints.";
  }
}

void UpdateLifePointsMessage::_maxLifePointsFunc(Reader *input)
{
  this->maxLifePoints = input->readVarUhInt();
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - UpdateLifePointsMessage -"<<"Forbidden value (" << this->maxLifePoints << ") on element of UpdateLifePointsMessage.maxLifePoints.";
  }
}

UpdateLifePointsMessage::UpdateLifePointsMessage()
{
  m_type = MessageEnum::UPDATELIFEPOINTSMESSAGE;
}

