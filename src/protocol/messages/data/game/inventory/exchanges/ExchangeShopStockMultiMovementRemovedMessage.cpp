#include "ExchangeShopStockMultiMovementRemovedMessage.h"

void ExchangeShopStockMultiMovementRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeShopStockMultiMovementRemovedMessage(output);
}

void ExchangeShopStockMultiMovementRemovedMessage::serializeAs_ExchangeShopStockMultiMovementRemovedMessage(Writer *output)
{
  output->writeShort((short)this->objectIdList.size());
  for(uint _i1 = 0; _i1 < this->objectIdList.size(); _i1++)
  {
    if(this->objectIdList[_i1] < 0)
    {
      qDebug()<<"ERREUR - ExchangeShopStockMultiMovementRemovedMessage -"<<"Forbidden value (" << this->objectIdList[_i1] << ") on element 1 (starting at 1) of objectIdList.";
    }
    output->writeVarInt((int)this->objectIdList[_i1]);
  }
}

void ExchangeShopStockMultiMovementRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeShopStockMultiMovementRemovedMessage(input);
}

void ExchangeShopStockMultiMovementRemovedMessage::deserializeAs_ExchangeShopStockMultiMovementRemovedMessage(Reader *input)
{
  uint _val1 = 0;
  uint _objectIdListLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectIdListLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ExchangeShopStockMultiMovementRemovedMessage -"<<"Forbidden value (" << _val1 << ") on elements of objectIdList.";
    }
    this->objectIdList.append(_val1);
  }
}

void ExchangeShopStockMultiMovementRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeShopStockMultiMovementRemovedMessage(tree);
}

void ExchangeShopStockMultiMovementRemovedMessage::deserializeAsyncAs_ExchangeShopStockMultiMovementRemovedMessage(FuncTree tree)
{
  this->_objectIdListtree = tree.addChild(std::bind(&ExchangeShopStockMultiMovementRemovedMessage::_objectIdListtreeFunc, this, std::placeholders::_1));
}

void ExchangeShopStockMultiMovementRemovedMessage::_objectIdListtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectIdListtree.addChild(std::bind(&ExchangeShopStockMultiMovementRemovedMessage::_objectIdListFunc, this, std::placeholders::_1));
  }
}

void ExchangeShopStockMultiMovementRemovedMessage::_objectIdListFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeShopStockMultiMovementRemovedMessage -"<<"Forbidden value (" << _val << ") on elements of objectIdList.";
  }
  this->objectIdList.append(_val);
}

ExchangeShopStockMultiMovementRemovedMessage::ExchangeShopStockMultiMovementRemovedMessage()
{
  m_type = MessageEnum::EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE;
}

