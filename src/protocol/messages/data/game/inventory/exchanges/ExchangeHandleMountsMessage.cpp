#include "ExchangeHandleMountsMessage.h"

void ExchangeHandleMountsMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeHandleMountsMessage(output);
}

void ExchangeHandleMountsMessage::serializeAs_ExchangeHandleMountsMessage(Writer *output)
{
  output->writeByte(this->actionType);
  output->writeShort((short)this->ridesId.size());
  for(uint _i2 = 0; _i2 < this->ridesId.size(); _i2++)
  {
    if(this->ridesId[_i2] < 0)
    {
      qDebug()<<"ERREUR - ExchangeHandleMountsMessage -"<<"Forbidden value (" << this->ridesId[_i2] << ") on element 2 (starting at 1) of ridesId.";
    }
    output->writeVarInt((int)this->ridesId[_i2]);
  }
}

void ExchangeHandleMountsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeHandleMountsMessage(input);
}

void ExchangeHandleMountsMessage::deserializeAs_ExchangeHandleMountsMessage(Reader *input)
{
  uint _val2 = 0;
  this->_actionTypeFunc(input);
  uint _ridesIdLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _ridesIdLen; _i2++)
  {
    _val2 = input->readVarUhInt();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - ExchangeHandleMountsMessage -"<<"Forbidden value (" << _val2 << ") on elements of ridesId.";
    }
    this->ridesId.append(_val2);
  }
}

void ExchangeHandleMountsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeHandleMountsMessage(tree);
}

void ExchangeHandleMountsMessage::deserializeAsyncAs_ExchangeHandleMountsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeHandleMountsMessage::_actionTypeFunc, this, std::placeholders::_1));
  this->_ridesIdtree = tree.addChild(std::bind(&ExchangeHandleMountsMessage::_ridesIdtreeFunc, this, std::placeholders::_1));
}

void ExchangeHandleMountsMessage::_actionTypeFunc(Reader *input)
{
  this->actionType = input->readByte();
}

void ExchangeHandleMountsMessage::_ridesIdtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_ridesIdtree.addChild(std::bind(&ExchangeHandleMountsMessage::_ridesIdFunc, this, std::placeholders::_1));
  }
}

void ExchangeHandleMountsMessage::_ridesIdFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeHandleMountsMessage -"<<"Forbidden value (" << _val << ") on elements of ridesId.";
  }
  this->ridesId.append(_val);
}

ExchangeHandleMountsMessage::ExchangeHandleMountsMessage()
{
  m_type = MessageEnum::EXCHANGEHANDLEMOUNTSMESSAGE;
  m_needsHash = true;
}

