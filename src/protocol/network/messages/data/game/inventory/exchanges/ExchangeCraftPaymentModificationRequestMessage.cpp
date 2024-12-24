#include "ExchangeCraftPaymentModificationRequestMessage.h"

void ExchangeCraftPaymentModificationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeCraftPaymentModificationRequestMessage(output);
}

void ExchangeCraftPaymentModificationRequestMessage::serializeAs_ExchangeCraftPaymentModificationRequestMessage(Writer *output)
{
  if(this->quantity < 0 || this->quantity > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeCraftPaymentModificationRequestMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarLong((double)this->quantity);
}

void ExchangeCraftPaymentModificationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeCraftPaymentModificationRequestMessage(input);
}

void ExchangeCraftPaymentModificationRequestMessage::deserializeAs_ExchangeCraftPaymentModificationRequestMessage(Reader *input)
{
  this->_quantityFunc(input);
}

void ExchangeCraftPaymentModificationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeCraftPaymentModificationRequestMessage(tree);
}

void ExchangeCraftPaymentModificationRequestMessage::deserializeAsyncAs_ExchangeCraftPaymentModificationRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeCraftPaymentModificationRequestMessage::_quantityFunc, this, std::placeholders::_1));
}

void ExchangeCraftPaymentModificationRequestMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhLong();
  if(this->quantity < 0 || this->quantity > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeCraftPaymentModificationRequestMessage -"<<"Forbidden value (" << this->quantity << ") on element of ExchangeCraftPaymentModificationRequestMessage.quantity.";
  }
}

ExchangeCraftPaymentModificationRequestMessage::ExchangeCraftPaymentModificationRequestMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTPAYMENTMODIFICATIONREQUESTMESSAGE;
}

