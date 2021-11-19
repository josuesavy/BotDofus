#include "AcquaintanceServerListMessage.h"

void AcquaintanceServerListMessage::serialize(Writer *output)
{
  this->serializeAs_AcquaintanceServerListMessage(output);
}

void AcquaintanceServerListMessage::serializeAs_AcquaintanceServerListMessage(Writer *output)
{
  output->writeShort((short)this->servers.size());
  for(uint _i1 = 0; _i1 < this->servers.size(); _i1++)
  {
    if(this->servers[_i1] < 0)
    {
      qDebug()<<"ERREUR - AcquaintanceServerListMessage -"<<"Forbidden value (" << this->servers[_i1] << ") on element 1 (starting at 1) of servers.";
    }
    output->writeVarShort((int)this->servers[_i1]);
  }
}

void AcquaintanceServerListMessage::deserialize(Reader *input)
{
  this->deserializeAs_AcquaintanceServerListMessage(input);
}

void AcquaintanceServerListMessage::deserializeAs_AcquaintanceServerListMessage(Reader *input)
{
  uint _val1 = 0;
  uint _serversLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _serversLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - AcquaintanceServerListMessage -"<<"Forbidden value (" << _val1 << ") on elements of servers.";
    }
    this->servers.append(_val1);
  }
}

void AcquaintanceServerListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AcquaintanceServerListMessage(tree);
}

void AcquaintanceServerListMessage::deserializeAsyncAs_AcquaintanceServerListMessage(FuncTree tree)
{
  this->_serverstree = tree.addChild(std::bind(&AcquaintanceServerListMessage::_serverstreeFunc, this, std::placeholders::_1));
}

void AcquaintanceServerListMessage::_serverstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_serverstree.addChild(std::bind(&AcquaintanceServerListMessage::_serversFunc, this, std::placeholders::_1));
  }
}

void AcquaintanceServerListMessage::_serversFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - AcquaintanceServerListMessage -"<<"Forbidden value (" << _val << ") on elements of servers.";
  }
  this->servers.append(_val);
}

AcquaintanceServerListMessage::AcquaintanceServerListMessage()
{
  m_type = MessageEnum::ACQUAINTANCESERVERLISTMESSAGE;
}

