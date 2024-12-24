#include "PartyUpdateLightMessage.h"

void PartyUpdateLightMessage::serialize(Writer *output)
{
  this->serializeAs_PartyUpdateLightMessage(output);
}

void PartyUpdateLightMessage::serializeAs_PartyUpdateLightMessage(Writer *output)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(output);
  if(this->id < 0 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarLong((double)this->id);
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
  }
  output->writeVarInt((int)this->lifePoints);
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
  }
  output->writeVarInt((int)this->maxLifePoints);
  if(this->prospecting < 0)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->prospecting << ") on element prospecting.";
  }
  output->writeVarInt((int)this->prospecting);
  if(this->regenRate < 0 || this->regenRate > 255)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->regenRate << ") on element regenRate.";
  }
  output->writeByte(this->regenRate);
}

void PartyUpdateLightMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyUpdateLightMessage(input);
}

void PartyUpdateLightMessage::deserializeAs_PartyUpdateLightMessage(Reader *input)
{
  AbstractPartyEventMessage::deserialize(input);
  this->_idFunc(input);
  this->_lifePointsFunc(input);
  this->_maxLifePointsFunc(input);
  this->_prospectingFunc(input);
  this->_regenRateFunc(input);
}

void PartyUpdateLightMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyUpdateLightMessage(tree);
}

void PartyUpdateLightMessage::deserializeAsyncAs_PartyUpdateLightMessage(FuncTree tree)
{
  AbstractPartyEventMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyUpdateLightMessage::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyUpdateLightMessage::_lifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyUpdateLightMessage::_maxLifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyUpdateLightMessage::_prospectingFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyUpdateLightMessage::_regenRateFunc, this, std::placeholders::_1));
}

void PartyUpdateLightMessage::_idFunc(Reader *input)
{
  this->id = input->readVarUhLong();
  if(this->id < 0 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->id << ") on element of PartyUpdateLightMessage.id.";
  }
}

void PartyUpdateLightMessage::_lifePointsFunc(Reader *input)
{
  this->lifePoints = input->readVarUhInt();
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->lifePoints << ") on element of PartyUpdateLightMessage.lifePoints.";
  }
}

void PartyUpdateLightMessage::_maxLifePointsFunc(Reader *input)
{
  this->maxLifePoints = input->readVarUhInt();
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->maxLifePoints << ") on element of PartyUpdateLightMessage.maxLifePoints.";
  }
}

void PartyUpdateLightMessage::_prospectingFunc(Reader *input)
{
  this->prospecting = input->readVarUhInt();
  if(this->prospecting < 0)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->prospecting << ") on element of PartyUpdateLightMessage.prospecting.";
  }
}

void PartyUpdateLightMessage::_regenRateFunc(Reader *input)
{
  this->regenRate = input->readUByte();
  if(this->regenRate < 0 || this->regenRate > 255)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->regenRate << ") on element of PartyUpdateLightMessage.regenRate.";
  }
}

PartyUpdateLightMessage::PartyUpdateLightMessage()
{
  m_type = MessageEnum::PARTYUPDATELIGHTMESSAGE;
}

