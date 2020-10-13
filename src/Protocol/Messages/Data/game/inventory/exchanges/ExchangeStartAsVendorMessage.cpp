#include "ExchangeStartAsVendorMessage.h"

void ExchangeStartAsVendorMessage::serialize(Writer *output)
{
}

void ExchangeStartAsVendorMessage::serializeAs_ExchangeStartAsVendorMessage(Writer *output)
{
}

void ExchangeStartAsVendorMessage::deserialize(Reader *input)
{
}

void ExchangeStartAsVendorMessage::deserializeAs_ExchangeStartAsVendorMessage(Reader *input)
{
}

void ExchangeStartAsVendorMessage::deserializeAsync(FuncTree tree)
{
}

void ExchangeStartAsVendorMessage::deserializeAsyncAs_ExchangeStartAsVendorMessage(FuncTree tree)
{
}

ExchangeStartAsVendorMessage::ExchangeStartAsVendorMessage()
{
  m_type = MessageEnum::EXCHANGESTARTASVENDORMESSAGE;
  m_needsHash = true;
}

