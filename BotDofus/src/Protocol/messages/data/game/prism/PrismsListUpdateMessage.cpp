#include "PrismsListUpdateMessage.h"

void PrismsListUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_PrismsListUpdateMessage(output);
}

void PrismsListUpdateMessage::serializeAs_PrismsListUpdateMessage(Writer *output)
{
  PrismsListMessage::serializeAs_PrismsListMessage(output);
}

void PrismsListUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismsListUpdateMessage(input);
}

void PrismsListUpdateMessage::deserializeAs_PrismsListUpdateMessage(Reader *input)
{
  PrismsListMessage::deserialize(input);
}

void PrismsListUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismsListUpdateMessage(tree);
}

void PrismsListUpdateMessage::deserializeAsyncAs_PrismsListUpdateMessage(FuncTree tree)
{
  PrismsListMessage::deserializeAsync(tree);
}

PrismsListUpdateMessage::PrismsListUpdateMessage()
{
  m_type = MessageEnum::PRISMSLISTUPDATEMESSAGE;
}

