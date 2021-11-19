#include "ExchangeObjectModifiedInBagMessage.h"

void ExchangeObjectModifiedInBagMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectModifiedInBagMessage(output);
}

void ExchangeObjectModifiedInBagMessage::serializeAs_ExchangeObjectModifiedInBagMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  this->object->serializeAs_ObjectItem(output);
}

void ExchangeObjectModifiedInBagMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectModifiedInBagMessage(input);
}

void ExchangeObjectModifiedInBagMessage::deserializeAs_ExchangeObjectModifiedInBagMessage(Reader *input)
{
  ExchangeObjectMessage::deserialize(input);
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(input);
}

void ExchangeObjectModifiedInBagMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectModifiedInBagMessage(tree);
}

void ExchangeObjectModifiedInBagMessage::deserializeAsyncAs_ExchangeObjectModifiedInBagMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  this->_objecttree = tree.addChild(std::bind(&ExchangeObjectModifiedInBagMessage::_objecttreeFunc, this, std::placeholders::_1));
}

void ExchangeObjectModifiedInBagMessage::_objecttreeFunc(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserializeAsync(this->_objecttree);
}

ExchangeObjectModifiedInBagMessage::ExchangeObjectModifiedInBagMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMODIFIEDINBAGMESSAGE;
}

