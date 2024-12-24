#include "ExchangeMountsStableBornAddMessage.h"

void ExchangeMountsStableBornAddMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMountsStableBornAddMessage(output);
}

void ExchangeMountsStableBornAddMessage::serializeAs_ExchangeMountsStableBornAddMessage(Writer *output)
{
  ExchangeMountsStableAddMessage::serializeAs_ExchangeMountsStableAddMessage(output);
}

void ExchangeMountsStableBornAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMountsStableBornAddMessage(input);
}

void ExchangeMountsStableBornAddMessage::deserializeAs_ExchangeMountsStableBornAddMessage(Reader *input)
{
  ExchangeMountsStableAddMessage::deserialize(input);
}

void ExchangeMountsStableBornAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMountsStableBornAddMessage(tree);
}

void ExchangeMountsStableBornAddMessage::deserializeAsyncAs_ExchangeMountsStableBornAddMessage(FuncTree tree)
{
  ExchangeMountsStableAddMessage::deserializeAsync(tree);
}

ExchangeMountsStableBornAddMessage::ExchangeMountsStableBornAddMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSSTABLEBORNADDMESSAGE;
}

