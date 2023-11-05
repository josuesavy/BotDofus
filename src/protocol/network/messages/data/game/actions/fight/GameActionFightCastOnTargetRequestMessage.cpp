#include "GameActionFightCastOnTargetRequestMessage.h"

void GameActionFightCastOnTargetRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightCastOnTargetRequestMessage(output);
}

void GameActionFightCastOnTargetRequestMessage::serializeAs_GameActionFightCastOnTargetRequestMessage(Writer *output)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCastOnTargetRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightCastOnTargetRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
}

void GameActionFightCastOnTargetRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightCastOnTargetRequestMessage(input);
}

void GameActionFightCastOnTargetRequestMessage::deserializeAs_GameActionFightCastOnTargetRequestMessage(Reader *input)
{
  this->_spellIdFunc(input);
  this->_targetIdFunc(input);
}

void GameActionFightCastOnTargetRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightCastOnTargetRequestMessage(tree);
}

void GameActionFightCastOnTargetRequestMessage::deserializeAsyncAs_GameActionFightCastOnTargetRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameActionFightCastOnTargetRequestMessage::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightCastOnTargetRequestMessage::_targetIdFunc, this, std::placeholders::_1));
}

void GameActionFightCastOnTargetRequestMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCastOnTargetRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightCastOnTargetRequestMessage.spellId.";
  }
}

void GameActionFightCastOnTargetRequestMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightCastOnTargetRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightCastOnTargetRequestMessage.targetId.";
  }
}

GameActionFightCastOnTargetRequestMessage::GameActionFightCastOnTargetRequestMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTCASTONTARGETREQUESTMESSAGE;
}

