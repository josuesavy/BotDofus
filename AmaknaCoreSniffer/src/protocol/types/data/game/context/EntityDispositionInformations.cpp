#include "EntityDispositionInformations.h"

void EntityDispositionInformations::serialize(Writer *output)
{
  this->serializeAs_EntityDispositionInformations(output);
}

void EntityDispositionInformations::serializeAs_EntityDispositionInformations(Writer *output)
{
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - EntityDispositionInformations -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeShort((short)this->cellId);
  output->writeByte(this->direction);
}

void EntityDispositionInformations::deserialize(Reader *input)
{
  this->deserializeAs_EntityDispositionInformations(input);
}

void EntityDispositionInformations::deserializeAs_EntityDispositionInformations(Reader *input)
{
  this->_cellIdFunc(input);
  this->_directionFunc(input);
}

void EntityDispositionInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EntityDispositionInformations(tree);
}

void EntityDispositionInformations::deserializeAsyncAs_EntityDispositionInformations(FuncTree tree)
{
  tree.addChild(std::bind(&EntityDispositionInformations::_cellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&EntityDispositionInformations::_directionFunc, this, std::placeholders::_1));
}

void EntityDispositionInformations::_cellIdFunc(Reader *input)
{
  this->cellId = input->readShort();
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - EntityDispositionInformations -"<<"Forbidden value (" << this->cellId << ") on element of EntityDispositionInformations.cellId.";
  }
}

void EntityDispositionInformations::_directionFunc(Reader *input)
{
  this->direction = input->readByte();
  if(this->direction < 0)
  {
    qDebug()<<"ERREUR - EntityDispositionInformations -"<<"Forbidden value (" << this->direction << ") on element of EntityDispositionInformations.direction.";
  }
}

EntityDispositionInformations::EntityDispositionInformations()
{
  m_types<<ClassEnum::ENTITYDISPOSITIONINFORMATIONS;
}

bool EntityDispositionInformations::operator==(const EntityDispositionInformations &compared)
{
  if(cellId == compared.cellId)
  if(direction == compared.direction)
  return true;
  
  return false;
}

