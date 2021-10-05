#include "GameActionFightLifeAndShieldPointsLostMessage.h"

void GameActionFightLifeAndShieldPointsLostMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightLifeAndShieldPointsLostMessage(output);
}

void GameActionFightLifeAndShieldPointsLostMessage::serializeAs_GameActionFightLifeAndShieldPointsLostMessage(Writer *output)
{
  GameActionFightLifePointsLostMessage::serializeAs_GameActionFightLifePointsLostMessage(output);
  if(this->shieldLoss < 0)
  {
    qDebug()<<"ERREUR - GameActionFightLifeAndShieldPointsLostMessage -"<<"Forbidden value (" << this->shieldLoss << ") on element shieldLoss.";
  }
  output->writeVarShort((int)this->shieldLoss);
}

void GameActionFightLifeAndShieldPointsLostMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightLifeAndShieldPointsLostMessage(input);
}

void GameActionFightLifeAndShieldPointsLostMessage::deserializeAs_GameActionFightLifeAndShieldPointsLostMessage(Reader *input)
{
  GameActionFightLifePointsLostMessage::deserialize(input);
  this->_shieldLossFunc(input);
}

void GameActionFightLifeAndShieldPointsLostMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightLifeAndShieldPointsLostMessage(tree);
}

void GameActionFightLifeAndShieldPointsLostMessage::deserializeAsyncAs_GameActionFightLifeAndShieldPointsLostMessage(FuncTree tree)
{
  GameActionFightLifePointsLostMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightLifeAndShieldPointsLostMessage::_shieldLossFunc, this, std::placeholders::_1));
}

void GameActionFightLifeAndShieldPointsLostMessage::_shieldLossFunc(Reader *input)
{
  this->shieldLoss = input->readVarUhShort();
  if(this->shieldLoss < 0)
  {
    qDebug()<<"ERREUR - GameActionFightLifeAndShieldPointsLostMessage -"<<"Forbidden value (" << this->shieldLoss << ") on element of GameActionFightLifeAndShieldPointsLostMessage.shieldLoss.";
  }
}

GameActionFightLifeAndShieldPointsLostMessage::GameActionFightLifeAndShieldPointsLostMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE;
}

