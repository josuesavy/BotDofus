#include "CharacterCharacteristicsInformations.h"

void CharacterCharacteristicsInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterCharacteristicsInformations(output);
}

void CharacterCharacteristicsInformations::serializeAs_CharacterCharacteristicsInformations(Writer *output)
{
  if(this->experience < 0 || this->experience > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  output->writeVarLong((double)this->experience);
  if(this->experienceLevelFloor < 0 || this->experienceLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceLevelFloor << ") on element experienceLevelFloor.";
  }
  output->writeVarLong((double)this->experienceLevelFloor);
  if(this->experienceNextLevelFloor < 0 || this->experienceNextLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceNextLevelFloor << ") on element experienceNextLevelFloor.";
  }
  output->writeVarLong((double)this->experienceNextLevelFloor);
  if(this->experienceBonusLimit < 0 || this->experienceBonusLimit > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceBonusLimit << ") on element experienceBonusLimit.";
  }
  output->writeVarLong((double)this->experienceBonusLimit);
  if(this->kamas < 0 || this->kamas > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  output->writeVarLong((double)this->kamas);
  this->alignmentInfos.serializeAs_ActorExtendedAlignmentInformations(output);
  if(this->criticalHitWeapon < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->criticalHitWeapon << ") on element criticalHitWeapon.";
  }
  output->writeVarShort((int)this->criticalHitWeapon);
  output->writeShort((short)this->characteristics.size());
  for(uint _i8 = 0; _i8 < this->characteristics.size(); _i8++)
  {
    output->writeShort((short)qSharedPointerCast<CharacterCharacteristic>(this->characteristics[_i8])->getTypes().last());
    qSharedPointerCast<CharacterCharacteristic>(this->characteristics[_i8])->serialize(output);
  }
  output->writeShort((short)this->spellModifiers.size());
  for(uint _i9 = 0; _i9 < this->spellModifiers.size(); _i9++)
  {
    (this->spellModifiers[_i9]).serializeAs_SpellModifierMessage(output);
  }
  if(this->probationTime < 0 || this->probationTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->probationTime << ") on element probationTime.";
  }
  output->writeDouble(this->probationTime);
}

void CharacterCharacteristicsInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCharacteristicsInformations(input);
}

void CharacterCharacteristicsInformations::deserializeAs_CharacterCharacteristicsInformations(Reader *input)
{
  uint _id8 = 0;
  QSharedPointer<CharacterCharacteristic> _item8 ;
  SpellModifierMessage _item9 ;
  this->_experienceFunc(input);
  this->_experienceLevelFloorFunc(input);
  this->_experienceNextLevelFloorFunc(input);
  this->_experienceBonusLimitFunc(input);
  this->_kamasFunc(input);
  this->alignmentInfos = ActorExtendedAlignmentInformations();
  this->alignmentInfos.deserialize(input);
  this->_criticalHitWeaponFunc(input);
  uint _characteristicsLen = uint(input->readUShort());
  for(uint _i8 = 0; _i8 < _characteristicsLen; _i8++)
  {
    _id8 = uint(input->readUShort());
    _item8 = qSharedPointerCast<CharacterCharacteristic>(ClassManagerSingleton::get()->getClass(_id8));
    _item8->deserialize(input);
    this->characteristics.append(_item8);
  }
  uint _spellModifiersLen = uint(input->readUShort());
  for(uint _i9 = 0; _i9 < _spellModifiersLen; _i9++)
  {
    _item9 = SpellModifierMessage();
    _item9.deserialize(input);
    this->spellModifiers.append(_item9);
  }
  this->_probationTimeFunc(input);
}

void CharacterCharacteristicsInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCharacteristicsInformations(tree);
}

void CharacterCharacteristicsInformations::deserializeAsyncAs_CharacterCharacteristicsInformations(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_experienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_experienceLevelFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_experienceNextLevelFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_experienceBonusLimitFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_kamasFunc, this, std::placeholders::_1));
  this->_alignmentInfostree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_alignmentInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_criticalHitWeaponFunc, this, std::placeholders::_1));
  this->_characteristicstree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_characteristicstreeFunc, this, std::placeholders::_1));
  this->_spellModifierstree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_spellModifierstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_probationTimeFunc, this, std::placeholders::_1));
}

void CharacterCharacteristicsInformations::_experienceFunc(Reader *input)
{
  this->experience = input->readVarUhLong();
  if(this->experience < 0 || this->experience > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experience << ") on element of CharacterCharacteristicsInformations.experience.";
  }
}

void CharacterCharacteristicsInformations::_experienceLevelFloorFunc(Reader *input)
{
  this->experienceLevelFloor = input->readVarUhLong();
  if(this->experienceLevelFloor < 0 || this->experienceLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceLevelFloor << ") on element of CharacterCharacteristicsInformations.experienceLevelFloor.";
  }
}

void CharacterCharacteristicsInformations::_experienceNextLevelFloorFunc(Reader *input)
{
  this->experienceNextLevelFloor = input->readVarUhLong();
  if(this->experienceNextLevelFloor < 0 || this->experienceNextLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceNextLevelFloor << ") on element of CharacterCharacteristicsInformations.experienceNextLevelFloor.";
  }
}

void CharacterCharacteristicsInformations::_experienceBonusLimitFunc(Reader *input)
{
  this->experienceBonusLimit = input->readVarUhLong();
  if(this->experienceBonusLimit < 0 || this->experienceBonusLimit > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceBonusLimit << ") on element of CharacterCharacteristicsInformations.experienceBonusLimit.";
  }
}

void CharacterCharacteristicsInformations::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->kamas << ") on element of CharacterCharacteristicsInformations.kamas.";
  }
}

void CharacterCharacteristicsInformations::_alignmentInfostreeFunc(Reader *input)
{
  this->alignmentInfos = ActorExtendedAlignmentInformations();
  this->alignmentInfos.deserializeAsync(this->_alignmentInfostree);
}

void CharacterCharacteristicsInformations::_criticalHitWeaponFunc(Reader *input)
{
  this->criticalHitWeapon = input->readVarUhShort();
  if(this->criticalHitWeapon < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->criticalHitWeapon << ") on element of CharacterCharacteristicsInformations.criticalHitWeapon.";
  }
}

void CharacterCharacteristicsInformations::_characteristicstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_characteristicstree.addChild(std::bind(&CharacterCharacteristicsInformations::_characteristicsFunc, this, std::placeholders::_1));
  }
}

void CharacterCharacteristicsInformations::_characteristicsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<CharacterCharacteristic> _item = qSharedPointerCast<CharacterCharacteristic>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->characteristics.append(_item);
}

void CharacterCharacteristicsInformations::_spellModifierstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_spellModifierstree.addChild(std::bind(&CharacterCharacteristicsInformations::_spellModifiersFunc, this, std::placeholders::_1));
  }
}

void CharacterCharacteristicsInformations::_spellModifiersFunc(Reader *input)
{
  SpellModifierMessage _item = SpellModifierMessage();
  _item.deserialize(input);
  this->spellModifiers.append(_item);
}

void CharacterCharacteristicsInformations::_probationTimeFunc(Reader *input)
{
  this->probationTime = input->readDouble();
  if(this->probationTime < 0 || this->probationTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->probationTime << ") on element of CharacterCharacteristicsInformations.probationTime.";
  }
}

CharacterCharacteristicsInformations::CharacterCharacteristicsInformations()
{
  m_types<<ClassEnum::CHARACTERCHARACTERISTICSINFORMATIONS;
}

bool CharacterCharacteristicsInformations::operator==(const CharacterCharacteristicsInformations &compared)
{
  if(experience == compared.experience)
  if(experienceLevelFloor == compared.experienceLevelFloor)
  if(experienceNextLevelFloor == compared.experienceNextLevelFloor)
  if(experienceBonusLimit == compared.experienceBonusLimit)
  if(kamas == compared.kamas)
  if(alignmentInfos == compared.alignmentInfos)
  if(criticalHitWeapon == compared.criticalHitWeapon)
  if(characteristics == compared.characteristics)
  if(spellModifiers == compared.spellModifiers)
  if(probationTime == compared.probationTime)
  if(_alignmentInfostree == compared._alignmentInfostree)
  if(_characteristicstree == compared._characteristicstree)
  if(_spellModifierstree == compared._spellModifierstree)
  return true;
  
  return false;
}

