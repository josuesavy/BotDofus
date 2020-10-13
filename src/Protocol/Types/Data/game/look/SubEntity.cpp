#include "SubEntity.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"

void SubEntity::serialize(Writer *output)
{
  this->serializeAs_SubEntity(output);
}

void SubEntity::serializeAs_SubEntity(Writer *output)
{
  output->writeByte(this->bindingPointCategory);
  if(this->bindingPointIndex < 0)
  {
    qDebug()<<"ERREUR - SubEntity -"<<"Forbidden value (" << this->bindingPointIndex << ") on element bindingPointIndex.";
  }
  output->writeByte(this->bindingPointIndex);
  this->subEntityLook->serializeAs_EntityLook(output);
}

void SubEntity::deserialize(Reader *input)
{
  this->deserializeAs_SubEntity(input);
}

void SubEntity::deserializeAs_SubEntity(Reader *input)
{
  this->_bindingPointCategoryFunc(input);
  this->_bindingPointIndexFunc(input);
  this->subEntityLook = QSharedPointer<EntityLook>(new EntityLook() );
  this->subEntityLook->deserialize(input);
}

void SubEntity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SubEntity(tree);
}

void SubEntity::deserializeAsyncAs_SubEntity(FuncTree tree)
{
  tree.addChild(std::bind(&SubEntity::_bindingPointCategoryFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SubEntity::_bindingPointIndexFunc, this, std::placeholders::_1));
  this->_subEntityLooktree = tree.addChild(std::bind(&SubEntity::_subEntityLooktreeFunc, this, std::placeholders::_1));
}

void SubEntity::_bindingPointCategoryFunc(Reader *input)
{
  this->bindingPointCategory = input->readByte();
  if(this->bindingPointCategory < 0)
  {
    qDebug()<<"ERREUR - SubEntity -"<<"Forbidden value (" << this->bindingPointCategory << ") on element of SubEntity.bindingPointCategory.";
  }
}

void SubEntity::_bindingPointIndexFunc(Reader *input)
{
  this->bindingPointIndex = input->readByte();
  if(this->bindingPointIndex < 0)
  {
    qDebug()<<"ERREUR - SubEntity -"<<"Forbidden value (" << this->bindingPointIndex << ") on element of SubEntity.bindingPointIndex.";
  }
}

void SubEntity::_subEntityLooktreeFunc(Reader *input)
{
  this->subEntityLook = QSharedPointer<EntityLook>(new EntityLook() );
  this->subEntityLook->deserializeAsync(this->_subEntityLooktree);
}

SubEntity::SubEntity()
{
  m_types<<ClassEnum::SUBENTITY;
}

bool SubEntity::operator==(const SubEntity &compared)
{
  if(bindingPointCategory == compared.bindingPointCategory)
  if(bindingPointIndex == compared.bindingPointIndex)
  if(subEntityLook == compared.subEntityLook)
  if(_subEntityLooktree == compared._subEntityLooktree)
  return true;
  
  return false;
}

