#include "ExchangeStartedTaxCollectorShopMessage.h"

void ExchangeStartedTaxCollectorShopMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartedTaxCollectorShopMessage(output);
}

void ExchangeStartedTaxCollectorShopMessage::serializeAs_ExchangeStartedTaxCollectorShopMessage(Writer *output)
{
  output->writeShort((short)this->objects.size());
  for(uint _i1 = 0; _i1 < this->objects.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->objects[_i1])->serializeAs_ObjectItem(output);
  }
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartedTaxCollectorShopMessage -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  output->writeVarLong((double)this->kamas);
}

void ExchangeStartedTaxCollectorShopMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartedTaxCollectorShopMessage(input);
}

void ExchangeStartedTaxCollectorShopMessage::deserializeAs_ExchangeStartedTaxCollectorShopMessage(Reader *input)
{
  QSharedPointer<ObjectItem> _item1 ;
  uint _objectsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectsLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item1->deserialize(input);
    this->objects.append(_item1);
  }
  this->_kamasFunc(input);
}

void ExchangeStartedTaxCollectorShopMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartedTaxCollectorShopMessage(tree);
}

void ExchangeStartedTaxCollectorShopMessage::deserializeAsyncAs_ExchangeStartedTaxCollectorShopMessage(FuncTree tree)
{
  this->_objectstree = tree.addChild(std::bind(&ExchangeStartedTaxCollectorShopMessage::_objectstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartedTaxCollectorShopMessage::_kamasFunc, this, std::placeholders::_1));
}

void ExchangeStartedTaxCollectorShopMessage::_objectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectstree.addChild(std::bind(&ExchangeStartedTaxCollectorShopMessage::_objectsFunc, this, std::placeholders::_1));
  }
}

void ExchangeStartedTaxCollectorShopMessage::_objectsFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->objects.append(_item);
}

void ExchangeStartedTaxCollectorShopMessage::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartedTaxCollectorShopMessage -"<<"Forbidden value (" << this->kamas << ") on element of ExchangeStartedTaxCollectorShopMessage.kamas.";
  }
}

ExchangeStartedTaxCollectorShopMessage::ExchangeStartedTaxCollectorShopMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE;
}

