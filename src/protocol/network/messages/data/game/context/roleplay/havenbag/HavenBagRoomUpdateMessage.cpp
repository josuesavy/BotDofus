#include "HavenBagRoomUpdateMessage.h"

void HavenBagRoomUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_HavenBagRoomUpdateMessage(output);
}

void HavenBagRoomUpdateMessage::serializeAs_HavenBagRoomUpdateMessage(Writer *output)
{
  output->writeByte(this->action);
  output->writeShort((short)this->roomsPreview.size());
  for(uint _i2 = 0; _i2 < this->roomsPreview.size(); _i2++)
  {
    (this->roomsPreview[_i2]).serializeAs_HavenBagRoomPreviewInformation(output);
  }
}

void HavenBagRoomUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_HavenBagRoomUpdateMessage(input);
}

void HavenBagRoomUpdateMessage::deserializeAs_HavenBagRoomUpdateMessage(Reader *input)
{
  HavenBagRoomPreviewInformation _item2 ;
  this->_actionFunc(input);
  uint _roomsPreviewLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _roomsPreviewLen; _i2++)
  {
    _item2 = HavenBagRoomPreviewInformation();
    _item2.deserialize(input);
    this->roomsPreview.append(_item2);
  }
}

void HavenBagRoomUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HavenBagRoomUpdateMessage(tree);
}

void HavenBagRoomUpdateMessage::deserializeAsyncAs_HavenBagRoomUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HavenBagRoomUpdateMessage::_actionFunc, this, std::placeholders::_1));
  this->_roomsPreviewtree = tree.addChild(std::bind(&HavenBagRoomUpdateMessage::_roomsPreviewtreeFunc, this, std::placeholders::_1));
}

void HavenBagRoomUpdateMessage::_actionFunc(Reader *input)
{
  this->action = input->readByte();
  if(this->action < 0)
  {
    qDebug()<<"ERREUR - HavenBagRoomUpdateMessage -"<<"Forbidden value (" << this->action << ") on element of HavenBagRoomUpdateMessage.action.";
  }
}

void HavenBagRoomUpdateMessage::_roomsPreviewtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_roomsPreviewtree.addChild(std::bind(&HavenBagRoomUpdateMessage::_roomsPreviewFunc, this, std::placeholders::_1));
  }
}

void HavenBagRoomUpdateMessage::_roomsPreviewFunc(Reader *input)
{
  HavenBagRoomPreviewInformation _item = HavenBagRoomPreviewInformation();
  _item.deserialize(input);
  this->roomsPreview.append(_item);
}

HavenBagRoomUpdateMessage::HavenBagRoomUpdateMessage()
{
  m_type = MessageEnum::HAVENBAGROOMUPDATEMESSAGE;
}

