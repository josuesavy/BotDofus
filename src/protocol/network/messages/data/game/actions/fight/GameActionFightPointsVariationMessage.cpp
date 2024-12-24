#include "GameActionFightPointsVariationMessage.h"

void GameActionFightPointsVariationMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightPointsVariationMessage(output);
}

void GameActionFightPointsVariationMessage::serializeAs_GameActionFightPointsVariationMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightPointsVariationMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  output->writeShort((short)this->delta);
}

void GameActionFightPointsVariationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightPointsVariationMessage(input);
}

void GameActionFightPointsVariationMessage::deserializeAs_GameActionFightPointsVariationMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_deltaFunc(input);
}

void GameActionFightPointsVariationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightPointsVariationMessage(tree);
}

void GameActionFightPointsVariationMessage::deserializeAsyncAs_GameActionFightPointsVariationMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightPointsVariationMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightPointsVariationMessage::_deltaFunc, this, std::placeholders::_1));
}

void GameActionFightPointsVariationMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightPointsVariationMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightPointsVariationMessage.targetId.";
  }
}

void GameActionFightPointsVariationMessage::_deltaFunc(Reader *input)
{
  this->delta = input->readShort();
}

GameActionFightPointsVariationMessage::GameActionFightPointsVariationMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE;
}

