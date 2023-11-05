#include "IndexedEntityLook.h"

void IndexedEntityLook::serialize(Writer *output)
{
  this->serializeAs_IndexedEntityLook(output);
}

void IndexedEntityLook::serializeAs_IndexedEntityLook(Writer *output)
{
  this->look.serializeAs_EntityLook(output);
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - IndexedEntityLook -"<<"Forbidden value (" << this->index << ") on element index.";
  }
  output->writeByte(this->index);
}

void IndexedEntityLook::deserialize(Reader *input)
{
  this->deserializeAs_IndexedEntityLook(input);
}

void IndexedEntityLook::deserializeAs_IndexedEntityLook(Reader *input)
{
  this->look = new com.ankamagames.dofus.network.types.game.look.EntityLook();
  this->look.deserialize(input);
  this->_indexFunc(input);
}

void IndexedEntityLook::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IndexedEntityLook(tree);
}

void IndexedEntityLook::deserializeAsyncAs_IndexedEntityLook(FuncTree tree)
{
  this->_looktree = tree.addChild(std::bind(&IndexedEntityLook::_looktreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IndexedEntityLook::_indexFunc, this, std::placeholders::_1));
}

void IndexedEntityLook::_looktreeFunc(Reader *input)
{
  this->look = new com.ankamagames.dofus.network.types.game.look.EntityLook();
  this->look.deserializeAsync(this->_looktree);
}

void IndexedEntityLook::_indexFunc(Reader *input)
{
  this->index = input->readByte();
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - IndexedEntityLook -"<<"Forbidden value (" << this->index << ") on element of IndexedEntityLook.index.";
  }
}

IndexedEntityLook::IndexedEntityLook()
{
  m_types<<ClassEnum::INDEXEDENTITYLOOK;
}

bool IndexedEntityLook::operator==(const IndexedEntityLook &compared)
{
  if(look == compared.look)
  if(index == compared.index)
  if(_looktree == compared._looktree)
  return true;
  
  return false;
}

