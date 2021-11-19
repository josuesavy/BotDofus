#include "ExchangeStartedWithPodsMessage.h"

void ExchangeStartedWithPodsMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartedWithPodsMessage(output);
}

void ExchangeStartedWithPodsMessage::serializeAs_ExchangeStartedWithPodsMessage(Writer *output)
{
  ExchangeStartedMessage::serializeAs_ExchangeStartedMessage(output);
  if(this->firstCharacterId < -9.007199254740992E15 || this->firstCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterId << ") on element firstCharacterId.";
  }
  output->writeDouble(this->firstCharacterId);
  if(this->firstCharacterCurrentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterCurrentWeight << ") on element firstCharacterCurrentWeight.";
  }
  output->writeVarInt((int)this->firstCharacterCurrentWeight);
  if(this->firstCharacterMaxWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterMaxWeight << ") on element firstCharacterMaxWeight.";
  }
  output->writeVarInt((int)this->firstCharacterMaxWeight);
  if(this->secondCharacterId < -9.007199254740992E15 || this->secondCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterId << ") on element secondCharacterId.";
  }
  output->writeDouble(this->secondCharacterId);
  if(this->secondCharacterCurrentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterCurrentWeight << ") on element secondCharacterCurrentWeight.";
  }
  output->writeVarInt((int)this->secondCharacterCurrentWeight);
  if(this->secondCharacterMaxWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterMaxWeight << ") on element secondCharacterMaxWeight.";
  }
  output->writeVarInt((int)this->secondCharacterMaxWeight);
}

void ExchangeStartedWithPodsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartedWithPodsMessage(input);
}

void ExchangeStartedWithPodsMessage::deserializeAs_ExchangeStartedWithPodsMessage(Reader *input)
{
  ExchangeStartedMessage::deserialize(input);
  this->_firstCharacterIdFunc(input);
  this->_firstCharacterCurrentWeightFunc(input);
  this->_firstCharacterMaxWeightFunc(input);
  this->_secondCharacterIdFunc(input);
  this->_secondCharacterCurrentWeightFunc(input);
  this->_secondCharacterMaxWeightFunc(input);
}

void ExchangeStartedWithPodsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartedWithPodsMessage(tree);
}

void ExchangeStartedWithPodsMessage::deserializeAsyncAs_ExchangeStartedWithPodsMessage(FuncTree tree)
{
  ExchangeStartedMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeStartedWithPodsMessage::_firstCharacterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartedWithPodsMessage::_firstCharacterCurrentWeightFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartedWithPodsMessage::_firstCharacterMaxWeightFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartedWithPodsMessage::_secondCharacterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartedWithPodsMessage::_secondCharacterCurrentWeightFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartedWithPodsMessage::_secondCharacterMaxWeightFunc, this, std::placeholders::_1));
}

void ExchangeStartedWithPodsMessage::_firstCharacterIdFunc(Reader *input)
{
  this->firstCharacterId = input->readDouble();
  if(this->firstCharacterId < -9.007199254740992E15 || this->firstCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterId << ") on element of ExchangeStartedWithPodsMessage.firstCharacterId.";
  }
}

void ExchangeStartedWithPodsMessage::_firstCharacterCurrentWeightFunc(Reader *input)
{
  this->firstCharacterCurrentWeight = input->readVarUhInt();
  if(this->firstCharacterCurrentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterCurrentWeight << ") on element of ExchangeStartedWithPodsMessage.firstCharacterCurrentWeight.";
  }
}

void ExchangeStartedWithPodsMessage::_firstCharacterMaxWeightFunc(Reader *input)
{
  this->firstCharacterMaxWeight = input->readVarUhInt();
  if(this->firstCharacterMaxWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterMaxWeight << ") on element of ExchangeStartedWithPodsMessage.firstCharacterMaxWeight.";
  }
}

void ExchangeStartedWithPodsMessage::_secondCharacterIdFunc(Reader *input)
{
  this->secondCharacterId = input->readDouble();
  if(this->secondCharacterId < -9.007199254740992E15 || this->secondCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterId << ") on element of ExchangeStartedWithPodsMessage.secondCharacterId.";
  }
}

void ExchangeStartedWithPodsMessage::_secondCharacterCurrentWeightFunc(Reader *input)
{
  this->secondCharacterCurrentWeight = input->readVarUhInt();
  if(this->secondCharacterCurrentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterCurrentWeight << ") on element of ExchangeStartedWithPodsMessage.secondCharacterCurrentWeight.";
  }
}

void ExchangeStartedWithPodsMessage::_secondCharacterMaxWeightFunc(Reader *input)
{
  this->secondCharacterMaxWeight = input->readVarUhInt();
  if(this->secondCharacterMaxWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterMaxWeight << ") on element of ExchangeStartedWithPodsMessage.secondCharacterMaxWeight.";
  }
}

ExchangeStartedWithPodsMessage::ExchangeStartedWithPodsMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDWITHPODSMESSAGE;
}

