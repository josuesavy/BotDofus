#include "ChatAdminServerMessage.h"

void ChatAdminServerMessage::serialize(Writer *output)
{
  this->serializeAs_ChatAdminServerMessage(output);
}

void ChatAdminServerMessage::serializeAs_ChatAdminServerMessage(Writer *output)
{
  ChatServerMessage::serializeAs_ChatServerMessage(output);
}

void ChatAdminServerMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatAdminServerMessage(input);
}

void ChatAdminServerMessage::deserializeAs_ChatAdminServerMessage(Reader *input)
{
  ChatServerMessage::deserialize(input);
}

void ChatAdminServerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatAdminServerMessage(tree);
}

void ChatAdminServerMessage::deserializeAsyncAs_ChatAdminServerMessage(FuncTree tree)
{
  ChatServerMessage::deserializeAsync(tree);
}

ChatAdminServerMessage::ChatAdminServerMessage()
{
  m_type = MessageEnum::CHATADMINSERVERMESSAGE;
}

