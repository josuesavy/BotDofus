#include "TaxCollectorErrorMessage.h"

void TaxCollectorErrorMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorErrorMessage(output);
}

void TaxCollectorErrorMessage::serializeAs_TaxCollectorErrorMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void TaxCollectorErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorErrorMessage(input);
}

void TaxCollectorErrorMessage::deserializeAs_TaxCollectorErrorMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void TaxCollectorErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorErrorMessage(tree);
}

void TaxCollectorErrorMessage::deserializeAsyncAs_TaxCollectorErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorErrorMessage::_reasonFunc, this, std::placeholders::_1));
}

void TaxCollectorErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
}

TaxCollectorErrorMessage::TaxCollectorErrorMessage()
{
  m_type = MessageEnum::TAXCOLLECTORERRORMESSAGE;
}

