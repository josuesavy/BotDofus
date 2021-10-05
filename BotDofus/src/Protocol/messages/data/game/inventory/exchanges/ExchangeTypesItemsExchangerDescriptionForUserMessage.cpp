#include "ExchangeTypesItemsExchangerDescriptionForUserMessage.h"

void ExchangeTypesItemsExchangerDescriptionForUserMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(output);
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::serializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(Writer *output)
{
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - ExchangeTypesItemsExchangerDescriptionForUserMessage -"<<"Forbidden value (" << this->objectType << ") on element objectType.";
  }
  output->writeInt((int)this->objectType);
  output->writeShort((short)this->itemTypeDescriptions.size());
  for(uint _i2 = 0; _i2 < this->itemTypeDescriptions.size(); _i2++)
  {
    qSharedPointerCast<BidExchangerObjectInfo>(this->itemTypeDescriptions[_i2])->serializeAs_BidExchangerObjectInfo(output);
  }
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(input);
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::deserializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(Reader *input)
{
  QSharedPointer<BidExchangerObjectInfo> _item2 ;
  this->_objectTypeFunc(input);
  uint _itemTypeDescriptionsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _itemTypeDescriptionsLen; _i2++)
  {
    _item2 = QSharedPointer<BidExchangerObjectInfo>(new BidExchangerObjectInfo() );
    _item2->deserialize(input);
    this->itemTypeDescriptions.append(_item2);
  }
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(tree);
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::deserializeAsyncAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeTypesItemsExchangerDescriptionForUserMessage::_objectTypeFunc, this, std::placeholders::_1));
  this->_itemTypeDescriptionstree = tree.addChild(std::bind(&ExchangeTypesItemsExchangerDescriptionForUserMessage::_itemTypeDescriptionstreeFunc, this, std::placeholders::_1));
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::_objectTypeFunc(Reader *input)
{
  this->objectType = input->readInt();
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - ExchangeTypesItemsExchangerDescriptionForUserMessage -"<<"Forbidden value (" << this->objectType << ") on element of ExchangeTypesItemsExchangerDescriptionForUserMessage.objectType.";
  }
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::_itemTypeDescriptionstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_itemTypeDescriptionstree.addChild(std::bind(&ExchangeTypesItemsExchangerDescriptionForUserMessage::_itemTypeDescriptionsFunc, this, std::placeholders::_1));
  }
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::_itemTypeDescriptionsFunc(Reader *input)
{
  QSharedPointer<BidExchangerObjectInfo> _item = QSharedPointer<BidExchangerObjectInfo>(new BidExchangerObjectInfo() );
  _item->deserialize(input);
  this->itemTypeDescriptions.append(_item);
}

ExchangeTypesItemsExchangerDescriptionForUserMessage::ExchangeTypesItemsExchangerDescriptionForUserMessage()
{
  m_type = MessageEnum::EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE;
}

