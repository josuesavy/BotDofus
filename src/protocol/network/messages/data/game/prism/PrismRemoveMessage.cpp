#include "PrismRemoveMessage.h"

void PrismRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_PrismRemoveMessage(output);
}

void PrismRemoveMessage::serializeAs_PrismRemoveMessage(Writer *output)
{
  this->prism->serializeAs_PrismGeolocalizedInformation(output);
}

void PrismRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismRemoveMessage(input);
}

void PrismRemoveMessage::deserializeAs_PrismRemoveMessage(Reader *input)
{
  this->prism = QSharedPointer<PrismGeolocalizedInformation>(new PrismGeolocalizedInformation() );
  this->prism->deserialize(input);
}

void PrismRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismRemoveMessage(tree);
}

void PrismRemoveMessage::deserializeAsyncAs_PrismRemoveMessage(FuncTree tree)
{
  this->_prismtree = tree.addChild(std::bind(&PrismRemoveMessage::_prismtreeFunc, this, std::placeholders::_1));
}

void PrismRemoveMessage::_prismtreeFunc(Reader *input)
{
  this->prism = QSharedPointer<PrismGeolocalizedInformation>(new PrismGeolocalizedInformation() );
  this->prism->deserializeAsync(this->_prismtree);
}

PrismRemoveMessage::PrismRemoveMessage()
{
  m_type = MessageEnum::PRISMREMOVEMESSAGE;
}

