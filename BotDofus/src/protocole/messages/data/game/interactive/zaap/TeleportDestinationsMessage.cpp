#include "TeleportDestinationsMessage.h"

void TeleportDestinationsMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportDestinationsMessage(output);
}

void TeleportDestinationsMessage::serializeAs_TeleportDestinationsMessage(Writer *output)
{
  output->writeByte(this->type);
  output->writeShort((short)this->destinations.size());
  for(uint _i2 = 0; _i2 < this->destinations.size(); _i2++)
  {
    (this->destinations[_i2]).serializeAs_TeleportDestination(output);
  }
}

void TeleportDestinationsMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportDestinationsMessage(input);
}

void TeleportDestinationsMessage::deserializeAs_TeleportDestinationsMessage(Reader *input)
{
  TeleportDestination _item2 ;
  this->_typeFunc(input);
  uint _destinationsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _destinationsLen; _i2++)
  {
    _item2 = TeleportDestination();
    _item2.deserialize(input);
    this->destinations.append(_item2);
  }
}

void TeleportDestinationsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportDestinationsMessage(tree);
}

void TeleportDestinationsMessage::deserializeAsyncAs_TeleportDestinationsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportDestinationsMessage::_typeFunc, this, std::placeholders::_1));
  this->_destinationstree = tree.addChild(std::bind(&TeleportDestinationsMessage::_destinationstreeFunc, this, std::placeholders::_1));
}

void TeleportDestinationsMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - TeleportDestinationsMessage -"<<"Forbidden value (" << this->type << ") on element of TeleportDestinationsMessage.type.";
  }
}

void TeleportDestinationsMessage::_destinationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_destinationstree.addChild(std::bind(&TeleportDestinationsMessage::_destinationsFunc, this, std::placeholders::_1));
  }
}

void TeleportDestinationsMessage::_destinationsFunc(Reader *input)
{
  TeleportDestination _item = TeleportDestination();
  _item.deserialize(input);
  this->destinations.append(_item);
}

TeleportDestinationsMessage::TeleportDestinationsMessage()
{
  m_type = MessageEnum::TELEPORTDESTINATIONSMESSAGE;
}

