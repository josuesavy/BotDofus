#include "CharacterCharacteristics.h"

void CharacterCharacteristics::serialize(Writer *output)
{
  this->serializeAs_CharacterCharacteristics(output);
}

void CharacterCharacteristics::serializeAs_CharacterCharacteristics(Writer *output)
{
  output->writeShort((short)this->characteristics.size());
  for(uint _i1 = 0; _i1 < this->characteristics.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<CharacterCharacteristic>(this->characteristics[_i1])->getTypes().last());
    qSharedPointerCast<CharacterCharacteristic>(this->characteristics[_i1])->serialize(output);
  }
}

void CharacterCharacteristics::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCharacteristics(input);
}

void CharacterCharacteristics::deserializeAs_CharacterCharacteristics(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<CharacterCharacteristic> _item1 ;
  uint _characteristicsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _characteristicsLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<CharacterCharacteristic>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->characteristics.append(_item1);
  }
}

void CharacterCharacteristics::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCharacteristics(tree);
}

void CharacterCharacteristics::deserializeAsyncAs_CharacterCharacteristics(FuncTree tree)
{
  this->_characteristicstree = tree.addChild(std::bind(&CharacterCharacteristics::_characteristicstreeFunc, this, std::placeholders::_1));
}

void CharacterCharacteristics::_characteristicstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_characteristicstree.addChild(std::bind(&CharacterCharacteristics::_characteristicsFunc, this, std::placeholders::_1));
  }
}

void CharacterCharacteristics::_characteristicsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<CharacterCharacteristic> _item = qSharedPointerCast<CharacterCharacteristic>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->characteristics.append(_item);
}

CharacterCharacteristics::CharacterCharacteristics()
{
  m_types<<ClassEnum::CHARACTERCHARACTERISTICS;
}

bool CharacterCharacteristics::operator==(const CharacterCharacteristics &compared)
{
  if(characteristics == compared.characteristics)
  if(_characteristicstree == compared._characteristicstree)
  return true;
  
  return false;
}

