#include "GameActionFightReflectSpellMessage.h"

void GameActionFightReflectSpellMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightReflectSpellMessage(output);
}

void GameActionFightReflectSpellMessage::serializeAs_GameActionFightReflectSpellMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightReflectSpellMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
}

void GameActionFightReflectSpellMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightReflectSpellMessage(input);
}

void GameActionFightReflectSpellMessage::deserializeAs_GameActionFightReflectSpellMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
}

void GameActionFightReflectSpellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightReflectSpellMessage(tree);
}

void GameActionFightReflectSpellMessage::deserializeAsyncAs_GameActionFightReflectSpellMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightReflectSpellMessage::_targetIdFunc, this, std::placeholders::_1));
}

void GameActionFightReflectSpellMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightReflectSpellMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightReflectSpellMessage.targetId.";
  }
}

GameActionFightReflectSpellMessage::GameActionFightReflectSpellMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTREFLECTSPELLMESSAGE;
}

