#include "ObjectItemInRolePlay.h"

void ObjectItemInRolePlay::serialize(Writer *output)
{
  this->serializeAs_ObjectItemInRolePlay(output);
}

void ObjectItemInRolePlay::serializeAs_ObjectItemInRolePlay(Writer *output)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ObjectItemInRolePlay -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemInRolePlay -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
}

void ObjectItemInRolePlay::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemInRolePlay(input);
}

void ObjectItemInRolePlay::deserializeAs_ObjectItemInRolePlay(Reader *input)
{
  this->_cellIdFunc(input);
  this->_objectGIDFunc(input);
}

void ObjectItemInRolePlay::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemInRolePlay(tree);
}

void ObjectItemInRolePlay::deserializeAsyncAs_ObjectItemInRolePlay(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectItemInRolePlay::_cellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemInRolePlay::_objectGIDFunc, this, std::placeholders::_1));
}

void ObjectItemInRolePlay::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ObjectItemInRolePlay -"<<"Forbidden value (" << this->cellId << ") on element of ObjectItemInRolePlay.cellId.";
  }
}

void ObjectItemInRolePlay::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemInRolePlay -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemInRolePlay.objectGID.";
  }
}

ObjectItemInRolePlay::ObjectItemInRolePlay()
{
  m_types<<ClassEnum::OBJECTITEMINROLEPLAY;
}

bool ObjectItemInRolePlay::operator==(const ObjectItemInRolePlay &compared)
{
  if(cellId == compared.cellId)
  if(objectGID == compared.objectGID)
  return true;
  
  return false;
}

