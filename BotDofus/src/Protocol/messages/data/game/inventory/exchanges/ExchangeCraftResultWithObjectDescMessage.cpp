#include "ExchangeCraftResultWithObjectDescMessage.h"

void ExchangeCraftResultWithObjectDescMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeCraftResultWithObjectDescMessage(output);
}

void ExchangeCraftResultWithObjectDescMessage::serializeAs_ExchangeCraftResultWithObjectDescMessage(Writer *output)
{
  ExchangeCraftResultMessage::serializeAs_ExchangeCraftResultMessage(output);
  this->objectInfo->serializeAs_ObjectItemNotInContainer(output);
}

void ExchangeCraftResultWithObjectDescMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeCraftResultWithObjectDescMessage(input);
}

void ExchangeCraftResultWithObjectDescMessage::deserializeAs_ExchangeCraftResultWithObjectDescMessage(Reader *input)
{
  ExchangeCraftResultMessage::deserialize(input);
  this->objectInfo = QSharedPointer<ObjectItemNotInContainer>(new ObjectItemNotInContainer() );
  this->objectInfo->deserialize(input);
}

void ExchangeCraftResultWithObjectDescMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeCraftResultWithObjectDescMessage(tree);
}

void ExchangeCraftResultWithObjectDescMessage::deserializeAsyncAs_ExchangeCraftResultWithObjectDescMessage(FuncTree tree)
{
  ExchangeCraftResultMessage::deserializeAsync(tree);
  this->_objectInfotree = tree.addChild(std::bind(&ExchangeCraftResultWithObjectDescMessage::_objectInfotreeFunc, this, std::placeholders::_1));
}

void ExchangeCraftResultWithObjectDescMessage::_objectInfotreeFunc(Reader *input)
{
  this->objectInfo = QSharedPointer<ObjectItemNotInContainer>(new ObjectItemNotInContainer() );
  this->objectInfo->deserializeAsync(this->_objectInfotree);
}

ExchangeCraftResultWithObjectDescMessage::ExchangeCraftResultWithObjectDescMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTRESULTWITHOBJECTDESCMESSAGE;
}

