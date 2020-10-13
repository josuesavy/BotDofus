#include "ExchangeObjectTransfertListFromInvMessage.h"

void ExchangeObjectTransfertListFromInvMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectTransfertListFromInvMessage(output);
}

void ExchangeObjectTransfertListFromInvMessage::serializeAs_ExchangeObjectTransfertListFromInvMessage(Writer *output)
{
  output->writeShort((short)this->ids.size());
  for(uint _i1 = 0; _i1 < this->ids.size(); _i1++)
  {
    if(this->ids[_i1] < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListFromInvMessage -"<<"Forbidden value (" << this->ids[_i1] << ") on element 1 (starting at 1) of ids.";
    }
    output->writeVarInt((int)this->ids[_i1]);
  }
}

void ExchangeObjectTransfertListFromInvMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectTransfertListFromInvMessage(input);
}

void ExchangeObjectTransfertListFromInvMessage::deserializeAs_ExchangeObjectTransfertListFromInvMessage(Reader *input)
{
  uint _val1 = 0;
  uint _idsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _idsLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListFromInvMessage -"<<"Forbidden value (" << _val1 << ") on elements of ids.";
    }
    this->ids.append(_val1);
  }
}

void ExchangeObjectTransfertListFromInvMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectTransfertListFromInvMessage(tree);
}

void ExchangeObjectTransfertListFromInvMessage::deserializeAsyncAs_ExchangeObjectTransfertListFromInvMessage(FuncTree tree)
{
  this->_idstree = tree.addChild(std::bind(&ExchangeObjectTransfertListFromInvMessage::_idstreeFunc, this, std::placeholders::_1));
}

void ExchangeObjectTransfertListFromInvMessage::_idstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_idstree.addChild(std::bind(&ExchangeObjectTransfertListFromInvMessage::_idsFunc, this, std::placeholders::_1));
  }
}

void ExchangeObjectTransfertListFromInvMessage::_idsFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectTransfertListFromInvMessage -"<<"Forbidden value (" << _val << ") on elements of ids.";
  }
  this->ids.append(_val);
}

ExchangeObjectTransfertListFromInvMessage::ExchangeObjectTransfertListFromInvMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTTRANSFERTLISTFROMINVMESSAGE;
}

