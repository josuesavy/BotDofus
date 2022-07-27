#include "ExchangeTypesItemsExchangerDescriptionForUserMessage.h"

void ExchangeTypesItemsExchangerDescriptionForUserMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(output);
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::serializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(Writer *output)
{
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeTypesItemsExchangerDescriptionForUserMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - ExchangeTypesItemsExchangerDescriptionForUserMessage -"<<"Forbidden value (" << this->objectType << ") on element objectType.";
  }
  output->writeInt((int)this->objectType);
  output->writeShort((short)this->itemTypeDescriptions.size());
  for(uint _i3 = 0; _i3 < this->itemTypeDescriptions.size(); _i3++)
  {
    qSharedPointerCast<BidExchangerObjectInfo>(this->itemTypeDescriptions[_i3])->serializeAs_BidExchangerObjectInfo(output);
  }
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(input);
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::deserializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(Reader *input)
{
  QSharedPointer<BidExchangerObjectInfo> _item3 ;
  this->_objectGIDFunc(input);
  this->_objectTypeFunc(input);
  uint _itemTypeDescriptionsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _itemTypeDescriptionsLen; _i3++)
  {
    _item3 = QSharedPointer<BidExchangerObjectInfo>(new BidExchangerObjectInfo() );
    _item3->deserialize(input);
    this->itemTypeDescriptions.append(_item3);
  }
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(tree);
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::deserializeAsyncAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeTypesItemsExchangerDescriptionForUserMessage::_objectGIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeTypesItemsExchangerDescriptionForUserMessage::_objectTypeFunc, this, std::placeholders::_1));
  this->_itemTypeDescriptionstree = tree.addChild(std::bind(&ExchangeTypesItemsExchangerDescriptionForUserMessage::_itemTypeDescriptionstreeFunc, this, std::placeholders::_1));
}

void ExchangeTypesItemsExchangerDescriptionForUserMessage::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeTypesItemsExchangerDescriptionForUserMessage -"<<"Forbidden value (" << this->objectGID << ") on element of ExchangeTypesItemsExchangerDescriptionForUserMessage.objectGID.";
  }
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

