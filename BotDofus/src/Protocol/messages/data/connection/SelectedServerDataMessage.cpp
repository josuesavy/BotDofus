#include "SelectedServerDataMessage.h"

void SelectedServerDataMessage::serialize(Writer *output)
{
  this->serializeAs_SelectedServerDataMessage(output);
}

void SelectedServerDataMessage::serializeAs_SelectedServerDataMessage(Writer *output)
{
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - SelectedServerDataMessage -"<<"Forbidden value (" << this->serverId << ") on element serverId.";
  }
  output->writeVarShort((int)this->serverId);
  output->writeUTF(this->address);
  output->writeShort((short)this->ports.size());
  for(uint _i3 = 0; _i3 < this->ports.size(); _i3++)
  {
    if(this->ports[_i3] < 0)
    {
      qDebug()<<"ERREUR - SelectedServerDataMessage -"<<"Forbidden value (" << this->ports[_i3] << ") on element 3 (starting at 1) of ports.";
    }
    output->writeVarShort((int)this->ports[_i3]);
  }
  output->writeBool(this->canCreateNewCharacter);
  output->writeVarInt((int)this->ticket.size());
  for(uint _i5 = 0; _i5 < this->ticket.size(); _i5++)
  {
    output->writeByte(this->ticket[_i5]);
  }
}

void SelectedServerDataMessage::deserialize(Reader *input)
{
  this->deserializeAs_SelectedServerDataMessage(input);
}

void SelectedServerDataMessage::deserializeAs_SelectedServerDataMessage(Reader *input)
{
  uint _val3 = 0;
  auto _val5 = 0;
  this->_serverIdFunc(input);
  this->_addressFunc(input);
  uint _portsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _portsLen; _i3++)
  {
    _val3 = input->readVarUhShort();
    if(_val3 < 0)
    {
      qDebug()<<"ERREUR - SelectedServerDataMessage -"<<"Forbidden value (" << _val3 << ") on elements of ports.";
    }
    this->ports.append(_val3);
  }
  this->_canCreateNewCharacterFunc(input);
  uint _ticketLen = input->readVarInt();
  for(uint _i5 = 0; _i5 < _ticketLen; _i5++)
  {
    _val5 = input->readByte();
    this->ticket.append(_val5);
  }
}

void SelectedServerDataMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SelectedServerDataMessage(tree);
}

void SelectedServerDataMessage::deserializeAsyncAs_SelectedServerDataMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SelectedServerDataMessage::_serverIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SelectedServerDataMessage::_addressFunc, this, std::placeholders::_1));
  this->_portstree = tree.addChild(std::bind(&SelectedServerDataMessage::_portstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SelectedServerDataMessage::_canCreateNewCharacterFunc, this, std::placeholders::_1));
  this->_tickettree = tree.addChild(std::bind(&SelectedServerDataMessage::_tickettreeFunc, this, std::placeholders::_1));
}

void SelectedServerDataMessage::_serverIdFunc(Reader *input)
{
  this->serverId = input->readVarUhShort();
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - SelectedServerDataMessage -"<<"Forbidden value (" << this->serverId << ") on element of SelectedServerDataMessage.serverId.";
  }
}

void SelectedServerDataMessage::_addressFunc(Reader *input)
{
  this->address = input->readUTF();
}

void SelectedServerDataMessage::_portstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_portstree.addChild(std::bind(&SelectedServerDataMessage::_portsFunc, this, std::placeholders::_1));
  }
}

void SelectedServerDataMessage::_portsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - SelectedServerDataMessage -"<<"Forbidden value (" << _val << ") on elements of ports.";
  }
  this->ports.append(_val);
}

void SelectedServerDataMessage::_canCreateNewCharacterFunc(Reader *input)
{
  this->canCreateNewCharacter = input->readBool();
}

void SelectedServerDataMessage::_tickettreeFunc(Reader *input)
{
  uint length = input->readVarInt();
  for(uint i = 0; i < length; i++)
  {
    this->_tickettree.addChild(std::bind(&SelectedServerDataMessage::_ticketFunc, this, std::placeholders::_1));
  }
}

void SelectedServerDataMessage::_ticketFunc(Reader *input)
{
  int _val = input->readByte();
  this->ticket.append(_val);
}

SelectedServerDataMessage::SelectedServerDataMessage()
{
  m_type = MessageEnum::SELECTEDSERVERDATAMESSAGE;
}

