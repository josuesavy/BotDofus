#include "ServersListMessage.h"

void ServersListMessage::serialize(Writer *output)
{
  this->serializeAs_ServersListMessage(output);
}

void ServersListMessage::serializeAs_ServersListMessage(Writer *output)
{
  output->writeShort((short)this->servers.size());
  for(uint _i1 = 0; _i1 < this->servers.size(); _i1++)
  {
    (this->servers[_i1]).serializeAs_GameServerInformations(output);
  }
  if(this->alreadyConnectedToServerId < 0)
  {
    qDebug()<<"ERREUR - ServersListMessage -"<<"Forbidden value (" << this->alreadyConnectedToServerId << ") on element alreadyConnectedToServerId.";
  }
  output->writeVarShort((int)this->alreadyConnectedToServerId);
  output->writeBool(this->canCreateNewCharacter);
}

void ServersListMessage::deserialize(Reader *input)
{
  this->deserializeAs_ServersListMessage(input);
}

void ServersListMessage::deserializeAs_ServersListMessage(Reader *input)
{
  GameServerInformations _item1 ;
  uint _serversLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _serversLen; _i1++)
  {
    _item1 = GameServerInformations();
    _item1.deserialize(input);
    this->servers.append(_item1);
  }
  this->_alreadyConnectedToServerIdFunc(input);
  this->_canCreateNewCharacterFunc(input);
}

void ServersListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServersListMessage(tree);
}

void ServersListMessage::deserializeAsyncAs_ServersListMessage(FuncTree tree)
{
  this->_serverstree = tree.addChild(std::bind(&ServersListMessage::_serverstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ServersListMessage::_alreadyConnectedToServerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ServersListMessage::_canCreateNewCharacterFunc, this, std::placeholders::_1));
}

void ServersListMessage::_serverstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_serverstree.addChild(std::bind(&ServersListMessage::_serversFunc, this, std::placeholders::_1));
  }
}

void ServersListMessage::_serversFunc(Reader *input)
{
  GameServerInformations _item = GameServerInformations();
  _item.deserialize(input);
  this->servers.append(_item);
}

void ServersListMessage::_alreadyConnectedToServerIdFunc(Reader *input)
{
  this->alreadyConnectedToServerId = input->readVarUhShort();
  if(this->alreadyConnectedToServerId < 0)
  {
    qDebug()<<"ERREUR - ServersListMessage -"<<"Forbidden value (" << this->alreadyConnectedToServerId << ") on element of ServersListMessage.alreadyConnectedToServerId.";
  }
}

void ServersListMessage::_canCreateNewCharacterFunc(Reader *input)
{
  this->canCreateNewCharacter = input->readBool();
}

ServersListMessage::ServersListMessage()
{
  m_type = MessageEnum::SERVERSLISTMESSAGE;
}

