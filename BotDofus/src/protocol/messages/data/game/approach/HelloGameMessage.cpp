#include "HelloGameMessage.h"

void HelloGameMessage::serialize(Writer *output)
{
}

void HelloGameMessage::serializeAs_HelloGameMessage(Writer *output)
{
}

void HelloGameMessage::deserialize(Reader *input)
{
}

void HelloGameMessage::deserializeAs_HelloGameMessage(Reader *input)
{
}

void HelloGameMessage::deserializeAsync(FuncTree tree)
{
}

void HelloGameMessage::deserializeAsyncAs_HelloGameMessage(FuncTree tree)
{
}

HelloGameMessage::HelloGameMessage()
{
  m_type = MessageEnum::HELLOGAMEMESSAGE;
}

