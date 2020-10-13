#include "AbstractPartyEventMessage.h"

void AbstractPartyEventMessage::serialize(Writer *output)
{
  this->serializeAs_AbstractPartyEventMessage(output);
}

void AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
}

void AbstractPartyEventMessage::deserialize(Reader *input)
{
  this->deserializeAs_AbstractPartyEventMessage(input);
}

void AbstractPartyEventMessage::deserializeAs_AbstractPartyEventMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
}

void AbstractPartyEventMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractPartyEventMessage(tree);
}

void AbstractPartyEventMessage::deserializeAsyncAs_AbstractPartyEventMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
}

AbstractPartyEventMessage::AbstractPartyEventMessage()
{
  m_type = MessageEnum::ABSTRACTPARTYEVENTMESSAGE;
}

