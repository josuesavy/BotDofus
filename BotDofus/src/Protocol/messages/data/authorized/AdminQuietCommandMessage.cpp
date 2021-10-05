#include "AdminQuietCommandMessage.h"

void AdminQuietCommandMessage::serialize(Writer *output)
{
  this->serializeAs_AdminQuietCommandMessage(output);
}

void AdminQuietCommandMessage::serializeAs_AdminQuietCommandMessage(Writer *output)
{
  AdminCommandMessage::serializeAs_AdminCommandMessage(output);
}

void AdminQuietCommandMessage::deserialize(Reader *input)
{
  this->deserializeAs_AdminQuietCommandMessage(input);
}

void AdminQuietCommandMessage::deserializeAs_AdminQuietCommandMessage(Reader *input)
{
  AdminCommandMessage::deserialize(input);
}

void AdminQuietCommandMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AdminQuietCommandMessage(tree);
}

void AdminQuietCommandMessage::deserializeAsyncAs_AdminQuietCommandMessage(FuncTree tree)
{
  AdminCommandMessage::deserializeAsync(tree);
}

AdminQuietCommandMessage::AdminQuietCommandMessage()
{
  m_type = MessageEnum::ADMINQUIETCOMMANDMESSAGE;
}

