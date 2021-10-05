#include "ExchangeBidHouseInListUpdatedMessage.h"

void ExchangeBidHouseInListUpdatedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseInListUpdatedMessage(output);
}

void ExchangeBidHouseInListUpdatedMessage::serializeAs_ExchangeBidHouseInListUpdatedMessage(Writer *output)
{
  ExchangeBidHouseInListAddedMessage::serializeAs_ExchangeBidHouseInListAddedMessage(output);
}

void ExchangeBidHouseInListUpdatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseInListUpdatedMessage(input);
}

void ExchangeBidHouseInListUpdatedMessage::deserializeAs_ExchangeBidHouseInListUpdatedMessage(Reader *input)
{
  ExchangeBidHouseInListAddedMessage::deserialize(input);
}

void ExchangeBidHouseInListUpdatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseInListUpdatedMessage(tree);
}

void ExchangeBidHouseInListUpdatedMessage::deserializeAsyncAs_ExchangeBidHouseInListUpdatedMessage(FuncTree tree)
{
  ExchangeBidHouseInListAddedMessage::deserializeAsync(tree);
}

ExchangeBidHouseInListUpdatedMessage::ExchangeBidHouseInListUpdatedMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE;
}

