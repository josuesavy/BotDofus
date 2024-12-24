#include "HousePropertiesMessage.h"

void HousePropertiesMessage::serialize(Writer *output)
{
  this->serializeAs_HousePropertiesMessage(output);
}

void HousePropertiesMessage::serializeAs_HousePropertiesMessage(Writer *output)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HousePropertiesMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  output->writeShort((short)this->doorsOnMap.size());
  for(uint _i2 = 0; _i2 < this->doorsOnMap.size(); _i2++)
  {
    if(this->doorsOnMap[_i2] < 0)
    {
      qDebug()<<"ERREUR - HousePropertiesMessage -"<<"Forbidden value (" << this->doorsOnMap[_i2] << ") on element 2 (starting at 1) of doorsOnMap.";
    }
    output->writeInt((int)this->doorsOnMap[_i2]);
  }
  output->writeShort((short)this->properties->getTypes().last());
  this->properties->serialize(output);
}

void HousePropertiesMessage::deserialize(Reader *input)
{
  this->deserializeAs_HousePropertiesMessage(input);
}

void HousePropertiesMessage::deserializeAs_HousePropertiesMessage(Reader *input)
{
  uint _val2 = 0;
  this->_houseIdFunc(input);
  uint _doorsOnMapLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _doorsOnMapLen; _i2++)
  {
    _val2 = uint(input->readInt());
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - HousePropertiesMessage -"<<"Forbidden value (" << _val2 << ") on elements of doorsOnMap.";
    }
    this->doorsOnMap.append(_val2);
  }
  uint _id3 = uint(input->readUShort());
  this->properties = qSharedPointerCast<HouseInstanceInformations>(ClassManagerSingleton::get()->getClass(_id3));
  this->properties->deserialize(input);
}

void HousePropertiesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HousePropertiesMessage(tree);
}

void HousePropertiesMessage::deserializeAsyncAs_HousePropertiesMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HousePropertiesMessage::_houseIdFunc, this, std::placeholders::_1));
  this->_doorsOnMaptree = tree.addChild(std::bind(&HousePropertiesMessage::_doorsOnMaptreeFunc, this, std::placeholders::_1));
  this->_propertiestree = tree.addChild(std::bind(&HousePropertiesMessage::_propertiestreeFunc, this, std::placeholders::_1));
}

void HousePropertiesMessage::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HousePropertiesMessage -"<<"Forbidden value (" << this->houseId << ") on element of HousePropertiesMessage.houseId.";
  }
}

void HousePropertiesMessage::_doorsOnMaptreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_doorsOnMaptree.addChild(std::bind(&HousePropertiesMessage::_doorsOnMapFunc, this, std::placeholders::_1));
  }
}

void HousePropertiesMessage::_doorsOnMapFunc(Reader *input)
{
  uint _val = uint(input->readInt());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - HousePropertiesMessage -"<<"Forbidden value (" << _val << ") on elements of doorsOnMap.";
  }
  this->doorsOnMap.append(_val);
}

void HousePropertiesMessage::_propertiestreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->properties = qSharedPointerCast<HouseInstanceInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->properties->deserializeAsync(this->_propertiestree);
}

HousePropertiesMessage::HousePropertiesMessage()
{
  m_type = MessageEnum::HOUSEPROPERTIESMESSAGE;
}

