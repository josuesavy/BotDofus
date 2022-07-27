#include "BasicNoOperationMessage.h"

void BasicNoOperationMessage::serialize(Writer *output)
{
}

void BasicNoOperationMessage::serializeAs_BasicNoOperationMessage(Writer *output)
{
}

void BasicNoOperationMessage::deserialize(Reader *input)
{
}

void BasicNoOperationMessage::deserializeAs_BasicNoOperationMessage(Reader *input)
{
}

void BasicNoOperationMessage::deserializeAsync(FuncTree tree)
{
}

void BasicNoOperationMessage::deserializeAsyncAs_BasicNoOperationMessage(FuncTree tree)
{
}

BasicNoOperationMessage::BasicNoOperationMessage()
{
  m_type = MessageEnum::BASICNOOPERATIONMESSAGE;
}

