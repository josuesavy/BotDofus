#include "GameActionFightLifePointsLostMessage.h"

void GameActionFightLifePointsLostMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightLifePointsLostMessage(output);
}

void GameActionFightLifePointsLostMessage::serializeAs_GameActionFightLifePointsLostMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->loss < 0)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->loss << ") on element loss.";
  }
  output->writeVarInt((int)this->loss);
  if(this->permanentDamages < 0)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->permanentDamages << ") on element permanentDamages.";
  }
  output->writeVarInt((int)this->permanentDamages);
  output->writeVarInt((int)this->elementId);
}

void GameActionFightLifePointsLostMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightLifePointsLostMessage(input);
}

void GameActionFightLifePointsLostMessage::deserializeAs_GameActionFightLifePointsLostMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_lossFunc(input);
  this->_permanentDamagesFunc(input);
  this->_elementIdFunc(input);
}

void GameActionFightLifePointsLostMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightLifePointsLostMessage(tree);
}

void GameActionFightLifePointsLostMessage::deserializeAsyncAs_GameActionFightLifePointsLostMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightLifePointsLostMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightLifePointsLostMessage::_lossFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightLifePointsLostMessage::_permanentDamagesFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightLifePointsLostMessage::_elementIdFunc, this, std::placeholders::_1));
}

void GameActionFightLifePointsLostMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightLifePointsLostMessage.targetId.";
  }
}

void GameActionFightLifePointsLostMessage::_lossFunc(Reader *input)
{
  this->loss = input->readVarUhInt();
  if(this->loss < 0)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->loss << ") on element of GameActionFightLifePointsLostMessage.loss.";
  }
}

void GameActionFightLifePointsLostMessage::_permanentDamagesFunc(Reader *input)
{
  this->permanentDamages = input->readVarUhInt();
  if(this->permanentDamages < 0)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsLostMessage -"<<"Forbidden value (" << this->permanentDamages << ") on element of GameActionFightLifePointsLostMessage.permanentDamages.";
  }
}

void GameActionFightLifePointsLostMessage::_elementIdFunc(Reader *input)
{
  this->elementId = input->readVarInt();
}

GameActionFightLifePointsLostMessage::GameActionFightLifePointsLostMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE;
}

