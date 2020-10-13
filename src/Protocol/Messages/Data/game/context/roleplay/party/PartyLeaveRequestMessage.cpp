#include "PartyLeaveRequestMessage.h"

void PartyLeaveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyLeaveRequestMessage(output);
}

void PartyLeaveRequestMessage::serializeAs_PartyLeaveRequestMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
}

void PartyLeaveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyLeaveRequestMessage(input);
}

void PartyLeaveRequestMessage::deserializeAs_PartyLeaveRequestMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
}

void PartyLeaveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyLeaveRequestMessage(tree);
}

void PartyLeaveRequestMessage::deserializeAsyncAs_PartyLeaveRequestMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
}

PartyLeaveRequestMessage::PartyLeaveRequestMessage()
{
  m_type = MessageEnum::PARTYLEAVEREQUESTMESSAGE;
}

