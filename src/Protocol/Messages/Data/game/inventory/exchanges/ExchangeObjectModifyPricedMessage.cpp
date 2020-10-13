#include "ExchangeObjectModifyPricedMessage.h"

void ExchangeObjectModifyPricedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectModifyPricedMessage(output);
}

void ExchangeObjectModifyPricedMessage::serializeAs_ExchangeObjectModifyPricedMessage(Writer *output)
{
  ExchangeObjectMovePricedMessage::serializeAs_ExchangeObjectMovePricedMessage(output);
}

void ExchangeObjectModifyPricedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectModifyPricedMessage(input);
}

void ExchangeObjectModifyPricedMessage::deserializeAs_ExchangeObjectModifyPricedMessage(Reader *input)
{
  ExchangeObjectMovePricedMessage::deserialize(input);
}

void ExchangeObjectModifyPricedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectModifyPricedMessage(tree);
}

void ExchangeObjectModifyPricedMessage::deserializeAsyncAs_ExchangeObjectModifyPricedMessage(FuncTree tree)
{
  ExchangeObjectMovePricedMessage::deserializeAsync(tree);
}

ExchangeObjectModifyPricedMessage::ExchangeObjectModifyPricedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMODIFYPRICEDMESSAGE;
  m_needsHash = true;
}

