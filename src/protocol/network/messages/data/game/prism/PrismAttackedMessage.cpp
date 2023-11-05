#include "PrismAttackedMessage.h"

void PrismAttackedMessage::serialize(Writer *output)
{
  this->serializeAs_PrismAttackedMessage(output);
}

void PrismAttackedMessage::serializeAs_PrismAttackedMessage(Writer *output)
{
  this->prism->serializeAs_PrismGeolocalizedInformation(output);
}

void PrismAttackedMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismAttackedMessage(input);
}

void PrismAttackedMessage::deserializeAs_PrismAttackedMessage(Reader *input)
{
  this->prism = QSharedPointer<PrismGeolocalizedInformation>(new PrismGeolocalizedInformation() );
  this->prism->deserialize(input);
}

void PrismAttackedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismAttackedMessage(tree);
}

void PrismAttackedMessage::deserializeAsyncAs_PrismAttackedMessage(FuncTree tree)
{
  this->_prismtree = tree.addChild(std::bind(&PrismAttackedMessage::_prismtreeFunc, this, std::placeholders::_1));
}

void PrismAttackedMessage::_prismtreeFunc(Reader *input)
{
  this->prism = QSharedPointer<PrismGeolocalizedInformation>(new PrismGeolocalizedInformation() );
  this->prism->deserializeAsync(this->_prismtree);
}

PrismAttackedMessage::PrismAttackedMessage()
{
  m_type = MessageEnum::PRISMATTACKEDMESSAGE;
}

