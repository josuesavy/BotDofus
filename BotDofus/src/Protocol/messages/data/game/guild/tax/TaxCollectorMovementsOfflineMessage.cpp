#include "TaxCollectorMovementsOfflineMessage.h"

void TaxCollectorMovementsOfflineMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorMovementsOfflineMessage(output);
}

void TaxCollectorMovementsOfflineMessage::serializeAs_TaxCollectorMovementsOfflineMessage(Writer *output)
{
  output->writeShort((short)this->movements.size());
  for(uint _i1 = 0; _i1 < this->movements.size(); _i1++)
  {
    (this->movements[_i1]).serializeAs_TaxCollectorMovement(output);
  }
}

void TaxCollectorMovementsOfflineMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorMovementsOfflineMessage(input);
}

void TaxCollectorMovementsOfflineMessage::deserializeAs_TaxCollectorMovementsOfflineMessage(Reader *input)
{
  TaxCollectorMovement _item1 ;
  uint _movementsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _movementsLen; _i1++)
  {
    _item1 = TaxCollectorMovement();
    _item1.deserialize(input);
    this->movements.append(_item1);
  }
}

void TaxCollectorMovementsOfflineMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorMovementsOfflineMessage(tree);
}

void TaxCollectorMovementsOfflineMessage::deserializeAsyncAs_TaxCollectorMovementsOfflineMessage(FuncTree tree)
{
  this->_movementstree = tree.addChild(std::bind(&TaxCollectorMovementsOfflineMessage::_movementstreeFunc, this, std::placeholders::_1));
}

void TaxCollectorMovementsOfflineMessage::_movementstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_movementstree.addChild(std::bind(&TaxCollectorMovementsOfflineMessage::_movementsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorMovementsOfflineMessage::_movementsFunc(Reader *input)
{
  TaxCollectorMovement _item = TaxCollectorMovement();
  _item.deserialize(input);
  this->movements.append(_item);
}

TaxCollectorMovementsOfflineMessage::TaxCollectorMovementsOfflineMessage()
{
  m_type = MessageEnum::TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE;
}

