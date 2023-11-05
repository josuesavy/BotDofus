#include "PrismAttackResultMessage.h"

void PrismAttackResultMessage::serialize(Writer *output)
{
  this->serializeAs_PrismAttackResultMessage(output);
}

void PrismAttackResultMessage::serializeAs_PrismAttackResultMessage(Writer *output)
{
  this->prism->serializeAs_PrismGeolocalizedInformation(output);
  output->writeByte(this->result);
}

void PrismAttackResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismAttackResultMessage(input);
}

void PrismAttackResultMessage::deserializeAs_PrismAttackResultMessage(Reader *input)
{
  this->prism = QSharedPointer<PrismGeolocalizedInformation>(new PrismGeolocalizedInformation() );
  this->prism->deserialize(input);
  this->_resultFunc(input);
}

void PrismAttackResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismAttackResultMessage(tree);
}

void PrismAttackResultMessage::deserializeAsyncAs_PrismAttackResultMessage(FuncTree tree)
{
  this->_prismtree = tree.addChild(std::bind(&PrismAttackResultMessage::_prismtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismAttackResultMessage::_resultFunc, this, std::placeholders::_1));
}

void PrismAttackResultMessage::_prismtreeFunc(Reader *input)
{
  this->prism = QSharedPointer<PrismGeolocalizedInformation>(new PrismGeolocalizedInformation() );
  this->prism->deserializeAsync(this->_prismtree);
}

void PrismAttackResultMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - PrismAttackResultMessage -"<<"Forbidden value (" << this->result << ") on element of PrismAttackResultMessage.result.";
  }
}

PrismAttackResultMessage::PrismAttackResultMessage()
{
  m_type = MessageEnum::PRISMATTACKRESULTMESSAGE;
}

