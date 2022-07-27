#include "ExchangeObjectPutInBagMessage.h"

void ExchangeObjectPutInBagMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectPutInBagMessage(output);
}

void ExchangeObjectPutInBagMessage::serializeAs_ExchangeObjectPutInBagMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  this->object->serializeAs_ObjectItem(output);
}

void ExchangeObjectPutInBagMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectPutInBagMessage(input);
}

void ExchangeObjectPutInBagMessage::deserializeAs_ExchangeObjectPutInBagMessage(Reader *input)
{
  ExchangeObjectMessage::deserialize(input);
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(input);
}

void ExchangeObjectPutInBagMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectPutInBagMessage(tree);
}

void ExchangeObjectPutInBagMessage::deserializeAsyncAs_ExchangeObjectPutInBagMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  this->_objecttree = tree.addChild(std::bind(&ExchangeObjectPutInBagMessage::_objecttreeFunc, this, std::placeholders::_1));
}

void ExchangeObjectPutInBagMessage::_objecttreeFunc(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserializeAsync(this->_objecttree);
}

ExchangeObjectPutInBagMessage::ExchangeObjectPutInBagMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTPUTINBAGMESSAGE;
}

