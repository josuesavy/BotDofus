#include "ExchangeObjectAddedMessage.h"

void ExchangeObjectAddedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectAddedMessage(output);
}

void ExchangeObjectAddedMessage::serializeAs_ExchangeObjectAddedMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  this->object->serializeAs_ObjectItem(output);
}

void ExchangeObjectAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectAddedMessage(input);
}

void ExchangeObjectAddedMessage::deserializeAs_ExchangeObjectAddedMessage(Reader *input)
{
  ExchangeObjectMessage::deserialize(input);
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(input);
}

void ExchangeObjectAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectAddedMessage(tree);
}

void ExchangeObjectAddedMessage::deserializeAsyncAs_ExchangeObjectAddedMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  this->_objecttree = tree.addChild(std::bind(&ExchangeObjectAddedMessage::_objecttreeFunc, this, std::placeholders::_1));
}

void ExchangeObjectAddedMessage::_objecttreeFunc(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserializeAsync(this->_objecttree);
}

ExchangeObjectAddedMessage::ExchangeObjectAddedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTADDEDMESSAGE;
}

