#include "TaxCollectorFightersInformation.h"

void TaxCollectorFightersInformation::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorFightersInformation(output);
}

void TaxCollectorFightersInformation::serializeAs_TaxCollectorFightersInformation(Writer *output)
{
  if(this->collectorId < 0 || this->collectorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorFightersInformation -"<<"Forbidden value (" << this->collectorId << ") on element collectorId.";
  }
  output->writeDouble(this->collectorId);
  output->writeShort((short)this->allyCharactersInformations.size());
  for(uint _i2 = 0; _i2 < this->allyCharactersInformations.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->allyCharactersInformations[_i2])->getTypes().last());
    qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->allyCharactersInformations[_i2])->serialize(output);
  }
  output->writeShort((short)this->enemyCharactersInformations.size());
  for(uint _i3 = 0; _i3 < this->enemyCharactersInformations.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->enemyCharactersInformations[_i3])->getTypes().last());
    qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->enemyCharactersInformations[_i3])->serialize(output);
  }
}

void TaxCollectorFightersInformation::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorFightersInformation(input);
}

void TaxCollectorFightersInformation::deserializeAs_TaxCollectorFightersInformation(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<CharacterMinimalPlusLookInformations> _item2 ;
  uint _id3 = 0;
  QSharedPointer<CharacterMinimalPlusLookInformations> _item3 ;
  this->_collectorIdFunc(input);
  uint _allyCharactersInformationsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _allyCharactersInformationsLen; _i2++)
  {
    _id2 = input->readUShort();
    _item2 = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->allyCharactersInformations.append(_item2);
  }
  uint _enemyCharactersInformationsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _enemyCharactersInformationsLen; _i3++)
  {
    _id3 = input->readUShort();
    _item3 = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->enemyCharactersInformations.append(_item3);
  }
}

void TaxCollectorFightersInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorFightersInformation(tree);
}

void TaxCollectorFightersInformation::deserializeAsyncAs_TaxCollectorFightersInformation(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorFightersInformation::_collectorIdFunc, this, std::placeholders::_1));
  this->_allyCharactersInformationstree = tree.addChild(std::bind(&TaxCollectorFightersInformation::_allyCharactersInformationstreeFunc, this, std::placeholders::_1));
  this->_enemyCharactersInformationstree = tree.addChild(std::bind(&TaxCollectorFightersInformation::_enemyCharactersInformationstreeFunc, this, std::placeholders::_1));
}

void TaxCollectorFightersInformation::_collectorIdFunc(Reader *input)
{
  this->collectorId = input->readDouble();
  if(this->collectorId < 0 || this->collectorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorFightersInformation -"<<"Forbidden value (" << this->collectorId << ") on element of TaxCollectorFightersInformation.collectorId.";
  }
}

void TaxCollectorFightersInformation::_allyCharactersInformationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_allyCharactersInformationstree.addChild(std::bind(&TaxCollectorFightersInformation::_allyCharactersInformationsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorFightersInformation::_allyCharactersInformationsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<CharacterMinimalPlusLookInformations> _item = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->allyCharactersInformations.append(_item);
}

void TaxCollectorFightersInformation::_enemyCharactersInformationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_enemyCharactersInformationstree.addChild(std::bind(&TaxCollectorFightersInformation::_enemyCharactersInformationsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorFightersInformation::_enemyCharactersInformationsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<CharacterMinimalPlusLookInformations> _item = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->enemyCharactersInformations.append(_item);
}

TaxCollectorFightersInformation::TaxCollectorFightersInformation()
{
  m_types<<ClassEnum::TAXCOLLECTORFIGHTERSINFORMATION;
}

bool TaxCollectorFightersInformation::operator==(const TaxCollectorFightersInformation &compared)
{
  if(collectorId == compared.collectorId)
  if(allyCharactersInformations == compared.allyCharactersInformations)
  if(enemyCharactersInformations == compared.enemyCharactersInformations)
  if(_allyCharactersInformationstree == compared._allyCharactersInformationstree)
  if(_enemyCharactersInformationstree == compared._enemyCharactersInformationstree)
  return true;
  
  return false;
}

