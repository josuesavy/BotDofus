#include "CompassUpdateMessage.h"

void CompassUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_CompassUpdateMessage(output);
}

void CompassUpdateMessage::serializeAs_CompassUpdateMessage(Writer *output)
{
  output->writeByte(this->type);
  output->writeShort((short)this->coords->getTypes().last());
  this->coords->serialize(output);
}

void CompassUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_CompassUpdateMessage(input);
}

void CompassUpdateMessage::deserializeAs_CompassUpdateMessage(Reader *input)
{
  this->_typeFunc(input);
  uint _id2 = uint(input->readUShort());
  this->coords = qSharedPointerCast<MapCoordinates>(ClassManagerSingleton::get()->getClass(_id2));
  this->coords->deserialize(input);
}

void CompassUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CompassUpdateMessage(tree);
}

void CompassUpdateMessage::deserializeAsyncAs_CompassUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CompassUpdateMessage::_typeFunc, this, std::placeholders::_1));
  this->_coordstree = tree.addChild(std::bind(&CompassUpdateMessage::_coordstreeFunc, this, std::placeholders::_1));
}

void CompassUpdateMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - CompassUpdateMessage -"<<"Forbidden value (" << this->type << ") on element of CompassUpdateMessage.type.";
  }
}

void CompassUpdateMessage::_coordstreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->coords = qSharedPointerCast<MapCoordinates>(ClassManagerSingleton::get()->getClass(_id));
  this->coords->deserializeAsync(this->_coordstree);
}

CompassUpdateMessage::CompassUpdateMessage()
{
  m_type = MessageEnum::COMPASSUPDATEMESSAGE;
}

