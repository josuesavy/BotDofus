#include "EntityInformation.h"

void EntityInformation::serialize(Writer *output)
{
  this->serializeAs_EntityInformation(output);
}

void EntityInformation::serializeAs_EntityInformation(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - EntityInformation -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarShort((int)this->id);
  if(this->experience < 0)
  {
    qDebug()<<"ERREUR - EntityInformation -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  output->writeVarInt((int)this->experience);
  output->writeBool(this->status);
}

void EntityInformation::deserialize(Reader *input)
{
  this->deserializeAs_EntityInformation(input);
}

void EntityInformation::deserializeAs_EntityInformation(Reader *input)
{
  this->_idFunc(input);
  this->_experienceFunc(input);
  this->_statusFunc(input);
}

void EntityInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EntityInformation(tree);
}

void EntityInformation::deserializeAsyncAs_EntityInformation(FuncTree tree)
{
  tree.addChild(std::bind(&EntityInformation::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&EntityInformation::_experienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&EntityInformation::_statusFunc, this, std::placeholders::_1));
}

void EntityInformation::_idFunc(Reader *input)
{
  this->id = input->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - EntityInformation -"<<"Forbidden value (" << this->id << ") on element of EntityInformation.id.";
  }
}

void EntityInformation::_experienceFunc(Reader *input)
{
  this->experience = input->readVarUhInt();
  if(this->experience < 0)
  {
    qDebug()<<"ERREUR - EntityInformation -"<<"Forbidden value (" << this->experience << ") on element of EntityInformation.experience.";
  }
}

void EntityInformation::_statusFunc(Reader *input)
{
  this->status = input->readBool();
}

EntityInformation::EntityInformation()
{
  m_types<<ClassEnum::ENTITYINFORMATION;
}

bool EntityInformation::operator==(const EntityInformation &compared)
{
  if(id == compared.id)
  if(experience == compared.experience)
  if(status == compared.status)
  return true;
  
  return false;
}

