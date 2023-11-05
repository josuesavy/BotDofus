#include "ExchangeStartOkRecycleTradeMessage.h"

void ExchangeStartOkRecycleTradeMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkRecycleTradeMessage(output);
}

void ExchangeStartOkRecycleTradeMessage::serializeAs_ExchangeStartOkRecycleTradeMessage(Writer *output)
{
  if(this->percentToPrism < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPrism << ") on element percentToPrism.";
  }
  output->writeShort((short)this->percentToPrism);
  if(this->percentToPlayer < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPlayer << ") on element percentToPlayer.";
  }
  output->writeShort((short)this->percentToPlayer);
  output->writeShort((short)this->adjacentSubareaPossessed.size());
  for(uint _i3 = 0; _i3 < this->adjacentSubareaPossessed.size(); _i3++)
  {
    if(this->adjacentSubareaPossessed[_i3] < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->adjacentSubareaPossessed[_i3] << ") on element 3 (starting at 1) of adjacentSubareaPossessed.";
    }
    output->writeInt((int)this->adjacentSubareaPossessed[_i3]);
  }
  output->writeShort((short)this->adjacentSubareaUnpossessed.size());
  for(uint _i4 = 0; _i4 < this->adjacentSubareaUnpossessed.size(); _i4++)
  {
    if(this->adjacentSubareaUnpossessed[_i4] < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->adjacentSubareaUnpossessed[_i4] << ") on element 4 (starting at 1) of adjacentSubareaUnpossessed.";
    }
    output->writeInt((int)this->adjacentSubareaUnpossessed[_i4]);
  }
}

void ExchangeStartOkRecycleTradeMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkRecycleTradeMessage(input);
}

void ExchangeStartOkRecycleTradeMessage::deserializeAs_ExchangeStartOkRecycleTradeMessage(Reader *input)
{
  uint _val3 = 0;
  uint _val4 = 0;
  this->_percentToPrismFunc(input);
  this->_percentToPlayerFunc(input);
  uint _adjacentSubareaPossessedLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _adjacentSubareaPossessedLen; _i3++)
  {
    _val3 = uint(input->readInt());
    if(_val3 < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << _val3 << ") on elements of adjacentSubareaPossessed.";
    }
    this->adjacentSubareaPossessed.append(_val3);
  }
  uint _adjacentSubareaUnpossessedLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _adjacentSubareaUnpossessedLen; _i4++)
  {
    _val4 = uint(input->readInt());
    if(_val4 < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << _val4 << ") on elements of adjacentSubareaUnpossessed.";
    }
    this->adjacentSubareaUnpossessed.append(_val4);
  }
}

void ExchangeStartOkRecycleTradeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkRecycleTradeMessage(tree);
}

void ExchangeStartOkRecycleTradeMessage::deserializeAsyncAs_ExchangeStartOkRecycleTradeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeStartOkRecycleTradeMessage::_percentToPrismFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartOkRecycleTradeMessage::_percentToPlayerFunc, this, std::placeholders::_1));
  this->_adjacentSubareaPossessedtree = tree.addChild(std::bind(&ExchangeStartOkRecycleTradeMessage::_adjacentSubareaPossessedtreeFunc, this, std::placeholders::_1));
  this->_adjacentSubareaUnpossessedtree = tree.addChild(std::bind(&ExchangeStartOkRecycleTradeMessage::_adjacentSubareaUnpossessedtreeFunc, this, std::placeholders::_1));
}

void ExchangeStartOkRecycleTradeMessage::_percentToPrismFunc(Reader *input)
{
  this->percentToPrism = input->readShort();
  if(this->percentToPrism < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPrism << ") on element of ExchangeStartOkRecycleTradeMessage.percentToPrism.";
  }
}

void ExchangeStartOkRecycleTradeMessage::_percentToPlayerFunc(Reader *input)
{
  this->percentToPlayer = input->readShort();
  if(this->percentToPlayer < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPlayer << ") on element of ExchangeStartOkRecycleTradeMessage.percentToPlayer.";
  }
}

void ExchangeStartOkRecycleTradeMessage::_adjacentSubareaPossessedtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_adjacentSubareaPossessedtree.addChild(std::bind(&ExchangeStartOkRecycleTradeMessage::_adjacentSubareaPossessedFunc, this, std::placeholders::_1));
  }
}

void ExchangeStartOkRecycleTradeMessage::_adjacentSubareaPossessedFunc(Reader *input)
{
  uint _val = uint(input->readInt());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << _val << ") on elements of adjacentSubareaPossessed.";
  }
  this->adjacentSubareaPossessed.append(_val);
}

void ExchangeStartOkRecycleTradeMessage::_adjacentSubareaUnpossessedtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_adjacentSubareaUnpossessedtree.addChild(std::bind(&ExchangeStartOkRecycleTradeMessage::_adjacentSubareaUnpossessedFunc, this, std::placeholders::_1));
  }
}

void ExchangeStartOkRecycleTradeMessage::_adjacentSubareaUnpossessedFunc(Reader *input)
{
  uint _val = uint(input->readInt());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << _val << ") on elements of adjacentSubareaUnpossessed.";
  }
  this->adjacentSubareaUnpossessed.append(_val);
}

ExchangeStartOkRecycleTradeMessage::ExchangeStartOkRecycleTradeMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKRECYCLETRADEMESSAGE;
}

