#include "ExchangeObjectTransfertListToInvMessage.h"

void ExchangeObjectTransfertListToInvMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectTransfertListToInvMessage(output);
}

void ExchangeObjectTransfertListToInvMessage::serializeAs_ExchangeObjectTransfertListToInvMessage(Writer *output)
{
  output->writeShort((short)this->ids.size());
  for(uint _i1 = 0; _i1 < this->ids.size(); _i1++)
  {
    if(this->ids[_i1] < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListToInvMessage -"<<"Forbidden value (" << this->ids[_i1] << ") on element 1 (starting at 1) of ids.";
    }
    output->writeVarInt((int)this->ids[_i1]);
  }
}

void ExchangeObjectTransfertListToInvMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectTransfertListToInvMessage(input);
}

void ExchangeObjectTransfertListToInvMessage::deserializeAs_ExchangeObjectTransfertListToInvMessage(Reader *input)
{
  uint _val1 = 0;
  uint _idsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _idsLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListToInvMessage -"<<"Forbidden value (" << _val1 << ") on elements of ids.";
    }
    this->ids.append(_val1);
  }
}

void ExchangeObjectTransfertListToInvMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectTransfertListToInvMessage(tree);
}

void ExchangeObjectTransfertListToInvMessage::deserializeAsyncAs_ExchangeObjectTransfertListToInvMessage(FuncTree tree)
{
  this->_idstree = tree.addChild(std::bind(&ExchangeObjectTransfertListToInvMessage::_idstreeFunc, this, std::placeholders::_1));
}

void ExchangeObjectTransfertListToInvMessage::_idstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_idstree.addChild(std::bind(&ExchangeObjectTransfertListToInvMessage::_idsFunc, this, std::placeholders::_1));
  }
}

void ExchangeObjectTransfertListToInvMessage::_idsFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectTransfertListToInvMessage -"<<"Forbidden value (" << _val << ") on elements of ids.";
  }
  this->ids.append(_val);
}

ExchangeObjectTransfertListToInvMessage::ExchangeObjectTransfertListToInvMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTTRANSFERTLISTTOINVMESSAGE;
}

