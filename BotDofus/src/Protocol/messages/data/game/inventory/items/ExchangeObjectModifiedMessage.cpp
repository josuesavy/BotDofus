#include "ExchangeObjectModifiedMessage.h"

void ExchangeObjectModifiedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectModifiedMessage(output);
}

void ExchangeObjectModifiedMessage::serializeAs_ExchangeObjectModifiedMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  this->object->serializeAs_ObjectItem(output);
}

void ExchangeObjectModifiedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectModifiedMessage(input);
}

void ExchangeObjectModifiedMessage::deserializeAs_ExchangeObjectModifiedMessage(Reader *input)
{
  ExchangeObjectMessage::deserialize(input);
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(input);
}

void ExchangeObjectModifiedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectModifiedMessage(tree);
}

void ExchangeObjectModifiedMessage::deserializeAsyncAs_ExchangeObjectModifiedMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  this->_objecttree = tree.addChild(std::bind(&ExchangeObjectModifiedMessage::_objecttreeFunc, this, std::placeholders::_1));
}

void ExchangeObjectModifiedMessage::_objecttreeFunc(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserializeAsync(this->_objecttree);
}

ExchangeObjectModifiedMessage::ExchangeObjectModifiedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMODIFIEDMESSAGE;
}

