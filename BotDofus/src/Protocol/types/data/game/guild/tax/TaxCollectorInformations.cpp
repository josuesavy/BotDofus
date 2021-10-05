#include "TaxCollectorInformations.h"

void TaxCollectorInformations::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorInformations(output);
}

void TaxCollectorInformations::serializeAs_TaxCollectorInformations(Writer *output)
{
  if(this->uniqueId < 0 || this->uniqueId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->uniqueId << ") on element uniqueId.";
  }
  output->writeDouble(this->uniqueId);
  if(this->firtNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->firtNameId << ") on element firtNameId.";
  }
  output->writeVarShort((int)this->firtNameId);
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
  }
  output->writeVarShort((int)this->lastNameId);
  this->additionalInfos.serializeAs_AdditionalTaxCollectorInformations(output);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeByte(this->state);
  this->look->serializeAs_EntityLook(output);
  output->writeShort((short)this->complements.size());
  for(uint _i10 = 0; _i10 < this->complements.size(); _i10++)
  {
    output->writeShort((short)qSharedPointerCast<TaxCollectorComplementaryInformations>(this->complements[_i10])->getTypes().last());
    qSharedPointerCast<TaxCollectorComplementaryInformations>(this->complements[_i10])->serialize(output);
  }
}

void TaxCollectorInformations::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorInformations(input);
}

void TaxCollectorInformations::deserializeAs_TaxCollectorInformations(Reader *input)
{
  uint _id10 = 0;
  QSharedPointer<TaxCollectorComplementaryInformations> _item10 ;
  this->_uniqueIdFunc(input);
  this->_firtNameIdFunc(input);
  this->_lastNameIdFunc(input);
  this->additionalInfos = AdditionalTaxCollectorInformations();
  this->additionalInfos.deserialize(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_subAreaIdFunc(input);
  this->_stateFunc(input);
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(input);
  uint _complementsLen = input->readUShort();
  for(uint _i10 = 0; _i10 < _complementsLen; _i10++)
  {
    _id10 = input->readUShort();
    _item10 = qSharedPointerCast<TaxCollectorComplementaryInformations>(ClassManagerSingleton::get()->getClass(_id10));
    _item10->deserialize(input);
    this->complements.append(_item10);
  }
}

void TaxCollectorInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorInformations(tree);
}

void TaxCollectorInformations::deserializeAsyncAs_TaxCollectorInformations(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorInformations::_uniqueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_firtNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_lastNameIdFunc, this, std::placeholders::_1));
  this->_additionalInfostree = tree.addChild(std::bind(&TaxCollectorInformations::_additionalInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_stateFunc, this, std::placeholders::_1));
  this->_looktree = tree.addChild(std::bind(&TaxCollectorInformations::_looktreeFunc, this, std::placeholders::_1));
  this->_complementstree = tree.addChild(std::bind(&TaxCollectorInformations::_complementstreeFunc, this, std::placeholders::_1));
}

void TaxCollectorInformations::_uniqueIdFunc(Reader *input)
{
  this->uniqueId = input->readDouble();
  if(this->uniqueId < 0 || this->uniqueId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->uniqueId << ") on element of TaxCollectorInformations.uniqueId.";
  }
}

void TaxCollectorInformations::_firtNameIdFunc(Reader *input)
{
  this->firtNameId = input->readVarUhShort();
  if(this->firtNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->firtNameId << ") on element of TaxCollectorInformations.firtNameId.";
  }
}

void TaxCollectorInformations::_lastNameIdFunc(Reader *input)
{
  this->lastNameId = input->readVarUhShort();
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of TaxCollectorInformations.lastNameId.";
  }
}

void TaxCollectorInformations::_additionalInfostreeFunc(Reader *input)
{
  this->additionalInfos = AdditionalTaxCollectorInformations();
  this->additionalInfos.deserializeAsync(this->_additionalInfostree);
}

void TaxCollectorInformations::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->worldX << ") on element of TaxCollectorInformations.worldX.";
  }
}

void TaxCollectorInformations::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->worldY << ") on element of TaxCollectorInformations.worldY.";
  }
}

void TaxCollectorInformations::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of TaxCollectorInformations.subAreaId.";
  }
}

void TaxCollectorInformations::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->state << ") on element of TaxCollectorInformations.state.";
  }
}

void TaxCollectorInformations::_looktreeFunc(Reader *input)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserializeAsync(this->_looktree);
}

void TaxCollectorInformations::_complementstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_complementstree.addChild(std::bind(&TaxCollectorInformations::_complementsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorInformations::_complementsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<TaxCollectorComplementaryInformations> _item = qSharedPointerCast<TaxCollectorComplementaryInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->complements.append(_item);
}

TaxCollectorInformations::TaxCollectorInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORINFORMATIONS;
}

bool TaxCollectorInformations::operator==(const TaxCollectorInformations &compared)
{
  if(uniqueId == compared.uniqueId)
  if(firtNameId == compared.firtNameId)
  if(lastNameId == compared.lastNameId)
  if(additionalInfos == compared.additionalInfos)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(subAreaId == compared.subAreaId)
  if(state == compared.state)
  if(look == compared.look)
  if(complements == compared.complements)
  if(_additionalInfostree == compared._additionalInfostree)
  if(_looktree == compared._looktree)
  if(_complementstree == compared._complementstree)
  return true;
  
  return false;
}

