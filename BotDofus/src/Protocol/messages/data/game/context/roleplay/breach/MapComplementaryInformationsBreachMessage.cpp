#include "MapComplementaryInformationsBreachMessage.h"

void MapComplementaryInformationsBreachMessage::serialize(Writer *output)
{
  this->serializeAs_MapComplementaryInformationsBreachMessage(output);
}

void MapComplementaryInformationsBreachMessage::serializeAs_MapComplementaryInformationsBreachMessage(Writer *output)
{
  MapComplementaryInformationsDataMessage::serializeAs_MapComplementaryInformationsDataMessage(output);
  if(this->floor < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsBreachMessage -"<<"Forbidden value (" << this->floor << ") on element floor.";
  }
  output->writeVarInt((int)this->floor);
  if(this->room < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsBreachMessage -"<<"Forbidden value (" << this->room << ") on element room.";
  }
  output->writeByte(this->room);
  if(this->infinityMode < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsBreachMessage -"<<"Forbidden value (" << this->infinityMode << ") on element infinityMode.";
  }
  output->writeShort((short)this->infinityMode);
  output->writeShort((short)this->branches.size());
  for(uint _i4 = 0; _i4 < this->branches.size(); _i4++)
  {
    output->writeShort((short)qSharedPointerCast<BreachBranch>(this->branches[_i4])->getTypes().last());
    qSharedPointerCast<BreachBranch>(this->branches[_i4])->serialize(output);
  }
}

void MapComplementaryInformationsBreachMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapComplementaryInformationsBreachMessage(input);
}

void MapComplementaryInformationsBreachMessage::deserializeAs_MapComplementaryInformationsBreachMessage(Reader *input)
{
  uint _id4 = 0;
  QSharedPointer<BreachBranch> _item4 ;
  MapComplementaryInformationsDataMessage::deserialize(input);
  this->_floorFunc(input);
  this->_roomFunc(input);
  this->_infinityModeFunc(input);
  uint _branchesLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _branchesLen; _i4++)
  {
    _id4 = input->readUShort();
    _item4 = qSharedPointerCast<BreachBranch>(ClassManagerSingleton::get()->getClass(_id4));
    _item4->deserialize(input);
    this->branches.append(_item4);
  }
}

void MapComplementaryInformationsBreachMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapComplementaryInformationsBreachMessage(tree);
}

void MapComplementaryInformationsBreachMessage::deserializeAsyncAs_MapComplementaryInformationsBreachMessage(FuncTree tree)
{
  MapComplementaryInformationsDataMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&MapComplementaryInformationsBreachMessage::_floorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapComplementaryInformationsBreachMessage::_roomFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapComplementaryInformationsBreachMessage::_infinityModeFunc, this, std::placeholders::_1));
  this->_branchestree = tree.addChild(std::bind(&MapComplementaryInformationsBreachMessage::_branchestreeFunc, this, std::placeholders::_1));
}

void MapComplementaryInformationsBreachMessage::_floorFunc(Reader *input)
{
  this->floor = input->readVarUhInt();
  if(this->floor < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsBreachMessage -"<<"Forbidden value (" << this->floor << ") on element of MapComplementaryInformationsBreachMessage.floor.";
  }
}

void MapComplementaryInformationsBreachMessage::_roomFunc(Reader *input)
{
  this->room = input->readByte();
  if(this->room < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsBreachMessage -"<<"Forbidden value (" << this->room << ") on element of MapComplementaryInformationsBreachMessage.room.";
  }
}

void MapComplementaryInformationsBreachMessage::_infinityModeFunc(Reader *input)
{
  this->infinityMode = input->readShort();
  if(this->infinityMode < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsBreachMessage -"<<"Forbidden value (" << this->infinityMode << ") on element of MapComplementaryInformationsBreachMessage.infinityMode.";
  }
}

void MapComplementaryInformationsBreachMessage::_branchestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_branchestree.addChild(std::bind(&MapComplementaryInformationsBreachMessage::_branchesFunc, this, std::placeholders::_1));
  }
}

void MapComplementaryInformationsBreachMessage::_branchesFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<BreachBranch> _item = qSharedPointerCast<BreachBranch>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->branches.append(_item);
}

MapComplementaryInformationsBreachMessage::MapComplementaryInformationsBreachMessage()
{
  m_type = MessageEnum::MAPCOMPLEMENTARYINFORMATIONSBREACHMESSAGE;
}

