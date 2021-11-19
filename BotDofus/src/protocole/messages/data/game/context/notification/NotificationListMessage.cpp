#include "NotificationListMessage.h"

void NotificationListMessage::serialize(Writer *output)
{
  this->serializeAs_NotificationListMessage(output);
}

void NotificationListMessage::serializeAs_NotificationListMessage(Writer *output)
{
  output->writeShort((short)this->flags.size());
  for(uint _i1 = 0; _i1 < this->flags.size(); _i1++)
  {
    output->writeVarInt((int)this->flags[_i1]);
  }
}

void NotificationListMessage::deserialize(Reader *input)
{
  this->deserializeAs_NotificationListMessage(input);
}

void NotificationListMessage::deserializeAs_NotificationListMessage(Reader *input)
{
  auto _val1 = 0;
  uint _flagsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _flagsLen; _i1++)
  {
    _val1 = input->readVarInt();
    this->flags.append(_val1);
  }
}

void NotificationListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NotificationListMessage(tree);
}

void NotificationListMessage::deserializeAsyncAs_NotificationListMessage(FuncTree tree)
{
  this->_flagstree = tree.addChild(std::bind(&NotificationListMessage::_flagstreeFunc, this, std::placeholders::_1));
}

void NotificationListMessage::_flagstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_flagstree.addChild(std::bind(&NotificationListMessage::_flagsFunc, this, std::placeholders::_1));
  }
}

void NotificationListMessage::_flagsFunc(Reader *input)
{
  int _val = input->readVarInt();
  this->flags.append(_val);
}

NotificationListMessage::NotificationListMessage()
{
  m_type = MessageEnum::NOTIFICATIONLISTMESSAGE;
}

