#include "PartyEntityMemberInformation.h"

void PartyEntityMemberInformation::serialize(Writer *output)
{
  this->serializeAs_PartyEntityMemberInformation(output);
}

void PartyEntityMemberInformation::serializeAs_PartyEntityMemberInformation(Writer *output)
{
  PartyEntityBaseInformation::serializeAs_PartyEntityBaseInformation(output);
  if(this->initiative < 0)
  {
    qDebug()<<"ERREUR - PartyEntityMemberInformation -"<<"Forbidden value (" << this->initiative << ") on element initiative.";
  }
  output->writeVarShort((int)this->initiative);
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyEntityMemberInformation -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
  }
  output->writeVarInt((int)this->lifePoints);
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyEntityMemberInformation -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
  }
  output->writeVarInt((int)this->maxLifePoints);
  if(this->prospecting < 0)
  {
    qDebug()<<"ERREUR - PartyEntityMemberInformation -"<<"Forbidden value (" << this->prospecting << ") on element prospecting.";
  }
  output->writeVarShort((int)this->prospecting);
  if(this->regenRate < 0 || this->regenRate > 255)
  {
    qDebug()<<"ERREUR - PartyEntityMemberInformation -"<<"Forbidden value (" << this->regenRate << ") on element regenRate.";
  }
  output->writeByte(this->regenRate);
}

void PartyEntityMemberInformation::deserialize(Reader *input)
{
  this->deserializeAs_PartyEntityMemberInformation(input);
}

void PartyEntityMemberInformation::deserializeAs_PartyEntityMemberInformation(Reader *input)
{
  PartyEntityBaseInformation::deserialize(input);
  this->_initiativeFunc(input);
  this->_lifePointsFunc(input);
  this->_maxLifePointsFunc(input);
  this->_prospectingFunc(input);
  this->_regenRateFunc(input);
}

void PartyEntityMemberInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyEntityMemberInformation(tree);
}

void PartyEntityMemberInformation::deserializeAsyncAs_PartyEntityMemberInformation(FuncTree tree)
{
  PartyEntityBaseInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyEntityMemberInformation::_initiativeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyEntityMemberInformation::_lifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyEntityMemberInformation::_maxLifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyEntityMemberInformation::_prospectingFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyEntityMemberInformation::_regenRateFunc, this, std::placeholders::_1));
}

void PartyEntityMemberInformation::_initiativeFunc(Reader *input)
{
  this->initiative = input->readVarUhShort();
  if(this->initiative < 0)
  {
    qDebug()<<"ERREUR - PartyEntityMemberInformation -"<<"Forbidden value (" << this->initiative << ") on element of PartyEntityMemberInformation.initiative.";
  }
}

void PartyEntityMemberInformation::_lifePointsFunc(Reader *input)
{
  this->lifePoints = input->readVarUhInt();
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyEntityMemberInformation -"<<"Forbidden value (" << this->lifePoints << ") on element of PartyEntityMemberInformation.lifePoints.";
  }
}

void PartyEntityMemberInformation::_maxLifePointsFunc(Reader *input)
{
  this->maxLifePoints = input->readVarUhInt();
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyEntityMemberInformation -"<<"Forbidden value (" << this->maxLifePoints << ") on element of PartyEntityMemberInformation.maxLifePoints.";
  }
}

void PartyEntityMemberInformation::_prospectingFunc(Reader *input)
{
  this->prospecting = input->readVarUhShort();
  if(this->prospecting < 0)
  {
    qDebug()<<"ERREUR - PartyEntityMemberInformation -"<<"Forbidden value (" << this->prospecting << ") on element of PartyEntityMemberInformation.prospecting.";
  }
}

void PartyEntityMemberInformation::_regenRateFunc(Reader *input)
{
  this->regenRate = input->readUByte();
  if(this->regenRate < 0 || this->regenRate > 255)
  {
    qDebug()<<"ERREUR - PartyEntityMemberInformation -"<<"Forbidden value (" << this->regenRate << ") on element of PartyEntityMemberInformation.regenRate.";
  }
}

PartyEntityMemberInformation::PartyEntityMemberInformation()
{
  m_types<<ClassEnum::PARTYENTITYMEMBERINFORMATION;
}

bool PartyEntityMemberInformation::operator==(const PartyEntityMemberInformation &compared)
{
  if(initiative == compared.initiative)
  if(lifePoints == compared.lifePoints)
  if(maxLifePoints == compared.maxLifePoints)
  if(prospecting == compared.prospecting)
  if(regenRate == compared.regenRate)
  return true;
  
  return false;
}

