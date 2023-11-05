#include "UpdateMountCharacteristicsMessage.h"

void UpdateMountCharacteristicsMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateMountCharacteristicsMessage(output);
}

void UpdateMountCharacteristicsMessage::serializeAs_UpdateMountCharacteristicsMessage(Writer *output)
{
  output->writeVarInt((int)this->rideId);
  output->writeShort((short)this->boostToUpdateList.size());
  for(uint _i2 = 0; _i2 < this->boostToUpdateList.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<UpdateMountCharacteristic>(this->boostToUpdateList[_i2])->getTypes().last());
    qSharedPointerCast<UpdateMountCharacteristic>(this->boostToUpdateList[_i2])->serialize(output);
  }
}

void UpdateMountCharacteristicsMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateMountCharacteristicsMessage(input);
}

void UpdateMountCharacteristicsMessage::deserializeAs_UpdateMountCharacteristicsMessage(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<UpdateMountCharacteristic> _item2 ;
  this->_rideIdFunc(input);
  uint _boostToUpdateListLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _boostToUpdateListLen; _i2++)
  {
    _id2 = uint(input->readUShort());
    _item2 = qSharedPointerCast<UpdateMountCharacteristic>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->boostToUpdateList.append(_item2);
  }
}

void UpdateMountCharacteristicsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateMountCharacteristicsMessage(tree);
}

void UpdateMountCharacteristicsMessage::deserializeAsyncAs_UpdateMountCharacteristicsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&UpdateMountCharacteristicsMessage::_rideIdFunc, this, std::placeholders::_1));
  this->_boostToUpdateListtree = tree.addChild(std::bind(&UpdateMountCharacteristicsMessage::_boostToUpdateListtreeFunc, this, std::placeholders::_1));
}

void UpdateMountCharacteristicsMessage::_rideIdFunc(Reader *input)
{
  this->rideId = input->readVarInt();
}

void UpdateMountCharacteristicsMessage::_boostToUpdateListtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_boostToUpdateListtree.addChild(std::bind(&UpdateMountCharacteristicsMessage::_boostToUpdateListFunc, this, std::placeholders::_1));
  }
}

void UpdateMountCharacteristicsMessage::_boostToUpdateListFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<UpdateMountCharacteristic> _item = qSharedPointerCast<UpdateMountCharacteristic>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->boostToUpdateList.append(_item);
}

UpdateMountCharacteristicsMessage::UpdateMountCharacteristicsMessage()
{
  m_type = MessageEnum::UPDATEMOUNTCHARACTERISTICSMESSAGE;
}

