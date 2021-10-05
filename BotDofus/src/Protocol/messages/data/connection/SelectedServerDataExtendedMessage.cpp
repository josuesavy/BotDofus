#include "SelectedServerDataExtendedMessage.h"

void SelectedServerDataExtendedMessage::serialize(Writer *output)
{
  this->serializeAs_SelectedServerDataExtendedMessage(output);
}

void SelectedServerDataExtendedMessage::serializeAs_SelectedServerDataExtendedMessage(Writer *output)
{
  SelectedServerDataMessage::serializeAs_SelectedServerDataMessage(output);
  output->writeShort((short)this->servers.size());
  for(uint _i1 = 0; _i1 < this->servers.size(); _i1++)
  {
    (this->servers[_i1]).serializeAs_GameServerInformations(output);
  }
}

void SelectedServerDataExtendedMessage::deserialize(Reader *input)
{
  this->deserializeAs_SelectedServerDataExtendedMessage(input);
}

void SelectedServerDataExtendedMessage::deserializeAs_SelectedServerDataExtendedMessage(Reader *input)
{
  GameServerInformations _item1 ;
  SelectedServerDataMessage::deserialize(input);
  uint _serversLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _serversLen; _i1++)
  {
    _item1 = GameServerInformations();
    _item1.deserialize(input);
    this->servers.append(_item1);
  }
}

void SelectedServerDataExtendedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SelectedServerDataExtendedMessage(tree);
}

void SelectedServerDataExtendedMessage::deserializeAsyncAs_SelectedServerDataExtendedMessage(FuncTree tree)
{
  SelectedServerDataMessage::deserializeAsync(tree);
  this->_serverstree = tree.addChild(std::bind(&SelectedServerDataExtendedMessage::_serverstreeFunc, this, std::placeholders::_1));
}

void SelectedServerDataExtendedMessage::_serverstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_serverstree.addChild(std::bind(&SelectedServerDataExtendedMessage::_serversFunc, this, std::placeholders::_1));
  }
}

void SelectedServerDataExtendedMessage::_serversFunc(Reader *input)
{
  GameServerInformations _item = GameServerInformations();
  _item.deserialize(input);
  this->servers.append(_item);
}

SelectedServerDataExtendedMessage::SelectedServerDataExtendedMessage()
{
  m_type = MessageEnum::SELECTEDSERVERDATAEXTENDEDMESSAGE;
}

