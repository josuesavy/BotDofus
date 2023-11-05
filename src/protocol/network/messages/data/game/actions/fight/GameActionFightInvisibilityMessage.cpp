#include "GameActionFightInvisibilityMessage.h"

void GameActionFightInvisibilityMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightInvisibilityMessage(output);
}

void GameActionFightInvisibilityMessage::serializeAs_GameActionFightInvisibilityMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibilityMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  output->writeByte(this->state);
}

void GameActionFightInvisibilityMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightInvisibilityMessage(input);
}

void GameActionFightInvisibilityMessage::deserializeAs_GameActionFightInvisibilityMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_stateFunc(input);
}

void GameActionFightInvisibilityMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightInvisibilityMessage(tree);
}

void GameActionFightInvisibilityMessage::deserializeAsyncAs_GameActionFightInvisibilityMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightInvisibilityMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightInvisibilityMessage::_stateFunc, this, std::placeholders::_1));
}

void GameActionFightInvisibilityMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibilityMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightInvisibilityMessage.targetId.";
  }
}

void GameActionFightInvisibilityMessage::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibilityMessage -"<<"Forbidden value (" << this->state << ") on element of GameActionFightInvisibilityMessage.state.";
  }
}

GameActionFightInvisibilityMessage::GameActionFightInvisibilityMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTINVISIBILITYMESSAGE;
}

