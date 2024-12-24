#include "PartyEntityBaseInformation.h"

void PartyEntityBaseInformation::serialize(Writer *output)
{
  this->serializeAs_PartyEntityBaseInformation(output);
}

void PartyEntityBaseInformation::serializeAs_PartyEntityBaseInformation(Writer *output)
{
  if(this->indexId < 0)
  {
    qDebug()<<"ERREUR - PartyEntityBaseInformation -"<<"Forbidden value (" << this->indexId << ") on element indexId.";
  }
  output->writeByte(this->indexId);
  if(this->entityModelId < 0)
  {
    qDebug()<<"ERREUR - PartyEntityBaseInformation -"<<"Forbidden value (" << this->entityModelId << ") on element entityModelId.";
  }
  output->writeByte(this->entityModelId);
  this->entityLook->serializeAs_EntityLook(output);
}

void PartyEntityBaseInformation::deserialize(Reader *input)
{
  this->deserializeAs_PartyEntityBaseInformation(input);
}

void PartyEntityBaseInformation::deserializeAs_PartyEntityBaseInformation(Reader *input)
{
  this->_indexIdFunc(input);
  this->_entityModelIdFunc(input);
  this->entityLook = QSharedPointer<EntityLook>(new EntityLook() );
  this->entityLook->deserialize(input);
}

void PartyEntityBaseInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyEntityBaseInformation(tree);
}

void PartyEntityBaseInformation::deserializeAsyncAs_PartyEntityBaseInformation(FuncTree tree)
{
  tree.addChild(std::bind(&PartyEntityBaseInformation::_indexIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyEntityBaseInformation::_entityModelIdFunc, this, std::placeholders::_1));
  this->_entityLooktree = tree.addChild(std::bind(&PartyEntityBaseInformation::_entityLooktreeFunc, this, std::placeholders::_1));
}

void PartyEntityBaseInformation::_indexIdFunc(Reader *input)
{
  this->indexId = input->readByte();
  if(this->indexId < 0)
  {
    qDebug()<<"ERREUR - PartyEntityBaseInformation -"<<"Forbidden value (" << this->indexId << ") on element of PartyEntityBaseInformation.indexId.";
  }
}

void PartyEntityBaseInformation::_entityModelIdFunc(Reader *input)
{
  this->entityModelId = input->readByte();
  if(this->entityModelId < 0)
  {
    qDebug()<<"ERREUR - PartyEntityBaseInformation -"<<"Forbidden value (" << this->entityModelId << ") on element of PartyEntityBaseInformation.entityModelId.";
  }
}

void PartyEntityBaseInformation::_entityLooktreeFunc(Reader *input)
{
  this->entityLook = QSharedPointer<EntityLook>(new EntityLook() );
  this->entityLook->deserializeAsync(this->_entityLooktree);
}

PartyEntityBaseInformation::PartyEntityBaseInformation()
{
  m_types<<ClassEnum::PARTYENTITYBASEINFORMATION;
}

bool PartyEntityBaseInformation::operator==(const PartyEntityBaseInformation &compared)
{
  if(indexId == compared.indexId)
  if(entityModelId == compared.entityModelId)
  if(entityLook == compared.entityLook)
  if(_entityLooktree == compared._entityLooktree)
  return true;
  
  return false;
}

