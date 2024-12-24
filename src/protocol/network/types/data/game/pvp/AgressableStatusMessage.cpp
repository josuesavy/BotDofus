#include "AgressableStatusMessage.h"

void AgressableStatusMessage::serialize(Writer *output)
{
  this->serializeAs_AgressableStatusMessage(output);
}

void AgressableStatusMessage::serializeAs_AgressableStatusMessage(Writer *output)
{
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AgressableStatusMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeByte(this->enable);
  output->writeInt((int)this->roleAvAId);
  output->writeInt((int)this->pictoScore);
}

void AgressableStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_AgressableStatusMessage(input);
}

void AgressableStatusMessage::deserializeAs_AgressableStatusMessage(Reader *input)
{
  this->_playerIdFunc(input);
  this->_enableFunc(input);
  this->_roleAvAIdFunc(input);
  this->_pictoScoreFunc(input);
}

void AgressableStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AgressableStatusMessage(tree);
}

void AgressableStatusMessage::deserializeAsyncAs_AgressableStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AgressableStatusMessage::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AgressableStatusMessage::_enableFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AgressableStatusMessage::_roleAvAIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AgressableStatusMessage::_pictoScoreFunc, this, std::placeholders::_1));
}

void AgressableStatusMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AgressableStatusMessage -"<<"Forbidden value (" << this->playerId << ") on element of AgressableStatusMessage.playerId.";
  }
}

void AgressableStatusMessage::_enableFunc(Reader *input)
{
  this->enable = input->readByte();
  if(this->enable < 0)
  {
    qDebug()<<"ERREUR - AgressableStatusMessage -"<<"Forbidden value (" << this->enable << ") on element of AgressableStatusMessage.enable.";
  }
}

void AgressableStatusMessage::_roleAvAIdFunc(Reader *input)
{
  this->roleAvAId = input->readInt();
}

void AgressableStatusMessage::_pictoScoreFunc(Reader *input)
{
  this->pictoScore = input->readInt();
}

AgressableStatusMessage::AgressableStatusMessage()
{
  m_types<<ClassEnum::AGRESSABLESTATUSMESSAGE;
}

bool AgressableStatusMessage::operator==(const AgressableStatusMessage &compared)
{
  if(playerId == compared.playerId)
  if(enable == compared.enable)
  if(roleAvAId == compared.roleAvAId)
  if(pictoScore == compared.pictoScore)
  return true;
  
  return false;
}

