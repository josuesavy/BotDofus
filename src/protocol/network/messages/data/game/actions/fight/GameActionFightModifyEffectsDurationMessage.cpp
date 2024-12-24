#include "GameActionFightModifyEffectsDurationMessage.h"

void GameActionFightModifyEffectsDurationMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightModifyEffectsDurationMessage(output);
}

void GameActionFightModifyEffectsDurationMessage::serializeAs_GameActionFightModifyEffectsDurationMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightModifyEffectsDurationMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  output->writeShort((short)this->delta);
}

void GameActionFightModifyEffectsDurationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightModifyEffectsDurationMessage(input);
}

void GameActionFightModifyEffectsDurationMessage::deserializeAs_GameActionFightModifyEffectsDurationMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_deltaFunc(input);
}

void GameActionFightModifyEffectsDurationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightModifyEffectsDurationMessage(tree);
}

void GameActionFightModifyEffectsDurationMessage::deserializeAsyncAs_GameActionFightModifyEffectsDurationMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightModifyEffectsDurationMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightModifyEffectsDurationMessage::_deltaFunc, this, std::placeholders::_1));
}

void GameActionFightModifyEffectsDurationMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightModifyEffectsDurationMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightModifyEffectsDurationMessage.targetId.";
  }
}

void GameActionFightModifyEffectsDurationMessage::_deltaFunc(Reader *input)
{
  this->delta = input->readShort();
}

GameActionFightModifyEffectsDurationMessage::GameActionFightModifyEffectsDurationMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTMODIFYEFFECTSDURATIONMESSAGE;
}

