#include "GameActionFightCastRequestMessage.h"

void GameActionFightCastRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightCastRequestMessage(output);
}

void GameActionFightCastRequestMessage::serializeAs_GameActionFightCastRequestMessage(Writer *output)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCastRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightCastRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeShort((short)this->cellId);
}

void GameActionFightCastRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightCastRequestMessage(input);
}

void GameActionFightCastRequestMessage::deserializeAs_GameActionFightCastRequestMessage(Reader *input)
{
  this->_spellIdFunc(input);
  this->_cellIdFunc(input);
}

void GameActionFightCastRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightCastRequestMessage(tree);
}

void GameActionFightCastRequestMessage::deserializeAsyncAs_GameActionFightCastRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameActionFightCastRequestMessage::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightCastRequestMessage::_cellIdFunc, this, std::placeholders::_1));
}

void GameActionFightCastRequestMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCastRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightCastRequestMessage.spellId.";
  }
}

void GameActionFightCastRequestMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readShort();
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightCastRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightCastRequestMessage.cellId.";
  }
}

GameActionFightCastRequestMessage::GameActionFightCastRequestMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTCASTREQUESTMESSAGE;
  m_needsHash = true;
}

