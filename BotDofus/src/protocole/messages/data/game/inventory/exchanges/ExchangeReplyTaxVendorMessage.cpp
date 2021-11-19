#include "ExchangeReplyTaxVendorMessage.h"

void ExchangeReplyTaxVendorMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeReplyTaxVendorMessage(output);
}

void ExchangeReplyTaxVendorMessage::serializeAs_ExchangeReplyTaxVendorMessage(Writer *output)
{
  if(this->objectValue < 0 || this->objectValue > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeReplyTaxVendorMessage -"<<"Forbidden value (" << this->objectValue << ") on element objectValue.";
  }
  output->writeVarLong((double)this->objectValue);
  if(this->totalTaxValue < 0 || this->totalTaxValue > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeReplyTaxVendorMessage -"<<"Forbidden value (" << this->totalTaxValue << ") on element totalTaxValue.";
  }
  output->writeVarLong((double)this->totalTaxValue);
}

void ExchangeReplyTaxVendorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeReplyTaxVendorMessage(input);
}

void ExchangeReplyTaxVendorMessage::deserializeAs_ExchangeReplyTaxVendorMessage(Reader *input)
{
  this->_objectValueFunc(input);
  this->_totalTaxValueFunc(input);
}

void ExchangeReplyTaxVendorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeReplyTaxVendorMessage(tree);
}

void ExchangeReplyTaxVendorMessage::deserializeAsyncAs_ExchangeReplyTaxVendorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeReplyTaxVendorMessage::_objectValueFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeReplyTaxVendorMessage::_totalTaxValueFunc, this, std::placeholders::_1));
}

void ExchangeReplyTaxVendorMessage::_objectValueFunc(Reader *input)
{
  this->objectValue = input->readVarUhLong();
  if(this->objectValue < 0 || this->objectValue > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeReplyTaxVendorMessage -"<<"Forbidden value (" << this->objectValue << ") on element of ExchangeReplyTaxVendorMessage.objectValue.";
  }
}

void ExchangeReplyTaxVendorMessage::_totalTaxValueFunc(Reader *input)
{
  this->totalTaxValue = input->readVarUhLong();
  if(this->totalTaxValue < 0 || this->totalTaxValue > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeReplyTaxVendorMessage -"<<"Forbidden value (" << this->totalTaxValue << ") on element of ExchangeReplyTaxVendorMessage.totalTaxValue.";
  }
}

ExchangeReplyTaxVendorMessage::ExchangeReplyTaxVendorMessage()
{
  m_type = MessageEnum::EXCHANGEREPLYTAXVENDORMESSAGE;
}

