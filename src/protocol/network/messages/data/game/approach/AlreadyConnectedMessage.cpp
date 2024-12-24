#include "AlreadyConnectedMessage.h"

void AlreadyConnectedMessage::serialize(Writer *output)
{
}

void AlreadyConnectedMessage::serializeAs_AlreadyConnectedMessage(Writer *output)
{
}

void AlreadyConnectedMessage::deserialize(Reader *input)
{
}

void AlreadyConnectedMessage::deserializeAs_AlreadyConnectedMessage(Reader *input)
{
}

void AlreadyConnectedMessage::deserializeAsync(FuncTree tree)
{
}

void AlreadyConnectedMessage::deserializeAsyncAs_AlreadyConnectedMessage(FuncTree tree)
{
}

AlreadyConnectedMessage::AlreadyConnectedMessage()
{
  m_type = MessageEnum::ALREADYCONNECTEDMESSAGE;
}

