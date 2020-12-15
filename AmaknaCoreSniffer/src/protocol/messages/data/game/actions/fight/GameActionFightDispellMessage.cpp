#include "GameActionFightDispellMessage.h"

void GameActionFightDispellMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightDispellMessage(output);
}

void GameActionFightDispellMessage::serializeAs_GameActionFightDispellMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDispellMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  output->writeBool(this->verboseCast);
}

void GameActionFightDispellMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightDispellMessage(input);
}

void GameActionFightDispellMessage::deserializeAs_GameActionFightDispellMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_verboseCastFunc(input);
}

void GameActionFightDispellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightDispellMessage(tree);
}

void GameActionFightDispellMessage::deserializeAsyncAs_GameActionFightDispellMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightDispellMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightDispellMessage::_verboseCastFunc, this, std::placeholders::_1));
}

void GameActionFightDispellMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDispellMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightDispellMessage.targetId.";
  }
}

void GameActionFightDispellMessage::_verboseCastFunc(Reader *input)
{
  this->verboseCast = input->readBool();
}

GameActionFightDispellMessage::GameActionFightDispellMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDISPELLMESSAGE;
}

