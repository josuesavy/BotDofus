#include "TaxCollectorInformations.h"

void TaxCollectorInformations::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorInformations(output);
}

void TaxCollectorInformations::serializeAs_TaxCollectorInformations(Writer *output)
{
  if(this->uniqueId < 0 || this->uniqueId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->uniqueId << ") on element uniqueId.";
  }
  output->writeDouble(this->uniqueId);
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  output->writeVarShort((int)this->firstNameId);
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
  }
  output->writeVarShort((int)this->lastNameId);
  this->allianceIdentity->serializeAs_AllianceInformation(output);
  this->additionalInfos.serializeAs_AdditionalTaxCollectorInformation(output);
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
  for(uint _i11 = 0; _i11 < this->complements.size(); _i11++)
  {
    output->writeShort((short)qSharedPointerCast<TaxCollectorComplementaryInformations>(this->complements[_i11])->getTypes().last());
    qSharedPointerCast<TaxCollectorComplementaryInformations>(this->complements[_i11])->serialize(output);
  }
  this->characteristics->serializeAs_CharacterCharacteristics(output);
  output->writeShort((short)this->equipments.size());
  for(uint _i13 = 0; _i13 < this->equipments.size(); _i13++)
  {
    qSharedPointerCast<ObjectItem>(this->equipments[_i13])->serializeAs_ObjectItem(output);
  }
  output->writeShort((short)this->spells.size());
  for(uint _i14 = 0; _i14 < this->spells.size(); _i14++)
  {
    (this->spells[_i14]).serializeAs_TaxCollectorOrderedSpell(output);
  }
}

void TaxCollectorInformations::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorInformations(input);
}

void TaxCollectorInformations::deserializeAs_TaxCollectorInformations(Reader *input)
{
  uint _id11 = 0;
  QSharedPointer<TaxCollectorComplementaryInformations> _item11 ;
  QSharedPointer<ObjectItem> _item13 ;
  TaxCollectorOrderedSpell _item14 ;
  this->_uniqueIdFunc(input);
  this->_firstNameIdFunc(input);
  this->_lastNameIdFunc(input);
  this->allianceIdentity = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceIdentity->deserialize(input);
  this->additionalInfos = AdditionalTaxCollectorInformation();
  this->additionalInfos.deserialize(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_subAreaIdFunc(input);
  this->_stateFunc(input);
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(input);
  uint _complementsLen = uint(input->readUShort());
  for(uint _i11 = 0; _i11 < _complementsLen; _i11++)
  {
    _id11 = uint(input->readUShort());
    _item11 = qSharedPointerCast<TaxCollectorComplementaryInformations>(ClassManagerSingleton::get()->getClass(_id11));
    _item11->deserialize(input);
    this->complements.append(_item11);
  }
  this->characteristics = QSharedPointer<CharacterCharacteristics>(new CharacterCharacteristics() );
  this->characteristics->deserialize(input);
  uint _equipmentsLen = uint(input->readUShort());
  for(uint _i13 = 0; _i13 < _equipmentsLen; _i13++)
  {
    _item13 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item13->deserialize(input);
    this->equipments.append(_item13);
  }
  uint _spellsLen = uint(input->readUShort());
  for(uint _i14 = 0; _i14 < _spellsLen; _i14++)
  {
    _item14 = TaxCollectorOrderedSpell();
    _item14.deserialize(input);
    this->spells.append(_item14);
  }
}

void TaxCollectorInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorInformations(tree);
}

void TaxCollectorInformations::deserializeAsyncAs_TaxCollectorInformations(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorInformations::_uniqueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_firstNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_lastNameIdFunc, this, std::placeholders::_1));
  this->_allianceIdentitytree = tree.addChild(std::bind(&TaxCollectorInformations::_allianceIdentitytreeFunc, this, std::placeholders::_1));
  this->_additionalInfostree = tree.addChild(std::bind(&TaxCollectorInformations::_additionalInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorInformations::_stateFunc, this, std::placeholders::_1));
  this->_looktree = tree.addChild(std::bind(&TaxCollectorInformations::_looktreeFunc, this, std::placeholders::_1));
  this->_complementstree = tree.addChild(std::bind(&TaxCollectorInformations::_complementstreeFunc, this, std::placeholders::_1));
  this->_characteristicstree = tree.addChild(std::bind(&TaxCollectorInformations::_characteristicstreeFunc, this, std::placeholders::_1));
  this->_equipmentstree = tree.addChild(std::bind(&TaxCollectorInformations::_equipmentstreeFunc, this, std::placeholders::_1));
  this->_spellstree = tree.addChild(std::bind(&TaxCollectorInformations::_spellstreeFunc, this, std::placeholders::_1));
}

void TaxCollectorInformations::_uniqueIdFunc(Reader *input)
{
  this->uniqueId = input->readDouble();
  if(this->uniqueId < 0 || this->uniqueId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->uniqueId << ") on element of TaxCollectorInformations.uniqueId.";
  }
}

void TaxCollectorInformations::_firstNameIdFunc(Reader *input)
{
  this->firstNameId = input->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of TaxCollectorInformations.firstNameId.";
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

void TaxCollectorInformations::_allianceIdentitytreeFunc(Reader *input)
{
  this->allianceIdentity = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceIdentity->deserializeAsync(this->_allianceIdentitytree);
}

void TaxCollectorInformations::_additionalInfostreeFunc(Reader *input)
{
  this->additionalInfos = AdditionalTaxCollectorInformation();
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
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_complementstree.addChild(std::bind(&TaxCollectorInformations::_complementsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorInformations::_complementsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<TaxCollectorComplementaryInformations> _item = qSharedPointerCast<TaxCollectorComplementaryInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->complements.append(_item);
}

void TaxCollectorInformations::_characteristicstreeFunc(Reader *input)
{
  this->characteristics = QSharedPointer<CharacterCharacteristics>(new CharacterCharacteristics() );
  this->characteristics->deserializeAsync(this->_characteristicstree);
}

void TaxCollectorInformations::_equipmentstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_equipmentstree.addChild(std::bind(&TaxCollectorInformations::_equipmentsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorInformations::_equipmentsFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->equipments.append(_item);
}

void TaxCollectorInformations::_spellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_spellstree.addChild(std::bind(&TaxCollectorInformations::_spellsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorInformations::_spellsFunc(Reader *input)
{
  TaxCollectorOrderedSpell _item = TaxCollectorOrderedSpell();
  _item.deserialize(input);
  this->spells.append(_item);
}

TaxCollectorInformations::TaxCollectorInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORINFORMATIONS;
}

bool TaxCollectorInformations::operator==(const TaxCollectorInformations &compared)
{
  if(uniqueId == compared.uniqueId)
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  if(allianceIdentity == compared.allianceIdentity)
  if(additionalInfos == compared.additionalInfos)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(subAreaId == compared.subAreaId)
  if(state == compared.state)
  if(look == compared.look)
  if(complements == compared.complements)
  if(characteristics == compared.characteristics)
  if(equipments == compared.equipments)
  if(spells == compared.spells)
  if(_allianceIdentitytree == compared._allianceIdentitytree)
  if(_additionalInfostree == compared._additionalInfostree)
  if(_looktree == compared._looktree)
  if(_complementstree == compared._complementstree)
  if(_characteristicstree == compared._characteristicstree)
  if(_equipmentstree == compared._equipmentstree)
  if(_spellstree == compared._spellstree)
  return true;
  
  return false;
}

