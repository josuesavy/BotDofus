#include "PrismAddOrUpdateMessage.h"

void PrismAddOrUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_PrismAddOrUpdateMessage(output);
}

void PrismAddOrUpdateMessage::serializeAs_PrismAddOrUpdateMessage(Writer *output)
{
  this->prism->serializeAs_PrismGeolocalizedInformation(output);
}

void PrismAddOrUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismAddOrUpdateMessage(input);
}

void PrismAddOrUpdateMessage::deserializeAs_PrismAddOrUpdateMessage(Reader *input)
{
  this->prism = QSharedPointer<PrismGeolocalizedInformation>(new PrismGeolocalizedInformation() );
  this->prism->deserialize(input);
}

void PrismAddOrUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismAddOrUpdateMessage(tree);
}

void PrismAddOrUpdateMessage::deserializeAsyncAs_PrismAddOrUpdateMessage(FuncTree tree)
{
  this->_prismtree = tree.addChild(std::bind(&PrismAddOrUpdateMessage::_prismtreeFunc, this, std::placeholders::_1));
}

void PrismAddOrUpdateMessage::_prismtreeFunc(Reader *input)
{
  this->prism = QSharedPointer<PrismGeolocalizedInformation>(new PrismGeolocalizedInformation() );
  this->prism->deserializeAsync(this->_prismtree);
}

PrismAddOrUpdateMessage::PrismAddOrUpdateMessage()
{
  m_type = MessageEnum::PRISMADDORUPDATEMESSAGE;
}

