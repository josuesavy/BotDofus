#include "PartyLeaveMessage.h"

void PartyLeaveMessage::serialize(Writer *output)
{
  this->serializeAs_PartyLeaveMessage(output);
}

void PartyLeaveMessage::serializeAs_PartyLeaveMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
}

void PartyLeaveMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyLeaveMessage(input);
}

void PartyLeaveMessage::deserializeAs_PartyLeaveMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
}

void PartyLeaveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyLeaveMessage(tree);
}

void PartyLeaveMessage::deserializeAsyncAs_PartyLeaveMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
}

PartyLeaveMessage::PartyLeaveMessage()
{
  m_type = MessageEnum::PARTYLEAVEMESSAGE;
}

