#include "MoodSmileyUpdateMessage.h"

void MoodSmileyUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_MoodSmileyUpdateMessage(output);
}

void MoodSmileyUpdateMessage::serializeAs_MoodSmileyUpdateMessage(Writer *output)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
  }
  output->writeVarShort((int)this->smileyId);
}

void MoodSmileyUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_MoodSmileyUpdateMessage(input);
}

void MoodSmileyUpdateMessage::deserializeAs_MoodSmileyUpdateMessage(Reader *input)
{
  this->_accountIdFunc(input);
  this->_playerIdFunc(input);
  this->_smileyIdFunc(input);
}

void MoodSmileyUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MoodSmileyUpdateMessage(tree);
}

void MoodSmileyUpdateMessage::deserializeAsyncAs_MoodSmileyUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MoodSmileyUpdateMessage::_accountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MoodSmileyUpdateMessage::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MoodSmileyUpdateMessage::_smileyIdFunc, this, std::placeholders::_1));
}

void MoodSmileyUpdateMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->accountId << ") on element of MoodSmileyUpdateMessage.accountId.";
  }
}

void MoodSmileyUpdateMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element of MoodSmileyUpdateMessage.playerId.";
  }
}

void MoodSmileyUpdateMessage::_smileyIdFunc(Reader *input)
{
  this->smileyId = input->readVarUhShort();
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->smileyId << ") on element of MoodSmileyUpdateMessage.smileyId.";
  }
}

MoodSmileyUpdateMessage::MoodSmileyUpdateMessage()
{
  m_type = MessageEnum::MOODSMILEYUPDATEMESSAGE;
}

