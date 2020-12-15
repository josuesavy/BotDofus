#include "ExchangeObjectTransfertListWithQuantityToInvMessage.h"

void ExchangeObjectTransfertListWithQuantityToInvMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(output);
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::serializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(Writer *output)
{
  output->writeShort((short)this->ids.size());
  for(uint _i1 = 0; _i1 < this->ids.size(); _i1++)
  {
    if(this->ids[_i1] < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListWithQuantityToInvMessage -"<<"Forbidden value (" << this->ids[_i1] << ") on element 1 (starting at 1) of ids.";
    }
    output->writeVarInt((int)this->ids[_i1]);
  }
  output->writeShort((short)this->qtys.size());
  for(uint _i2 = 0; _i2 < this->qtys.size(); _i2++)
  {
    if(this->qtys[_i2] < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListWithQuantityToInvMessage -"<<"Forbidden value (" << this->qtys[_i2] << ") on element 2 (starting at 1) of qtys.";
    }
    output->writeVarInt((int)this->qtys[_i2]);
  }
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(input);
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::deserializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _idsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _idsLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListWithQuantityToInvMessage -"<<"Forbidden value (" << _val1 << ") on elements of ids.";
    }
    this->ids.append(_val1);
  }
  uint _qtysLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _qtysLen; _i2++)
  {
    _val2 = input->readVarUhInt();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectTransfertListWithQuantityToInvMessage -"<<"Forbidden value (" << _val2 << ") on elements of qtys.";
    }
    this->qtys.append(_val2);
  }
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectTransfertListWithQuantityToInvMessage(tree);
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::deserializeAsyncAs_ExchangeObjectTransfertListWithQuantityToInvMessage(FuncTree tree)
{
  this->_idstree = tree.addChild(std::bind(&ExchangeObjectTransfertListWithQuantityToInvMessage::_idstreeFunc, this, std::placeholders::_1));
  this->_qtystree = tree.addChild(std::bind(&ExchangeObjectTransfertListWithQuantityToInvMessage::_qtystreeFunc, this, std::placeholders::_1));
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::_idstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_idstree.addChild(std::bind(&ExchangeObjectTransfertListWithQuantityToInvMessage::_idsFunc, this, std::placeholders::_1));
  }
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::_idsFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectTransfertListWithQuantityToInvMessage -"<<"Forbidden value (" << _val << ") on elements of ids.";
  }
  this->ids.append(_val);
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::_qtystreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_qtystree.addChild(std::bind(&ExchangeObjectTransfertListWithQuantityToInvMessage::_qtysFunc, this, std::placeholders::_1));
  }
}

void ExchangeObjectTransfertListWithQuantityToInvMessage::_qtysFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectTransfertListWithQuantityToInvMessage -"<<"Forbidden value (" << _val << ") on elements of qtys.";
  }
  this->qtys.append(_val);
}

ExchangeObjectTransfertListWithQuantityToInvMessage::ExchangeObjectTransfertListWithQuantityToInvMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTTRANSFERTLISTWITHQUANTITYTOINVMESSAGE;
}

