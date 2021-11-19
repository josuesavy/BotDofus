#include "AllianceMembershipMessage.h"

void AllianceMembershipMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceMembershipMessage(output);
}

void AllianceMembershipMessage::serializeAs_AllianceMembershipMessage(Writer *output)
{
  AllianceJoinedMessage::serializeAs_AllianceJoinedMessage(output);
}

void AllianceMembershipMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceMembershipMessage(input);
}

void AllianceMembershipMessage::deserializeAs_AllianceMembershipMessage(Reader *input)
{
  AllianceJoinedMessage::deserialize(input);
}

void AllianceMembershipMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceMembershipMessage(tree);
}

void AllianceMembershipMessage::deserializeAsyncAs_AllianceMembershipMessage(FuncTree tree)
{
  AllianceJoinedMessage::deserializeAsync(tree);
}

AllianceMembershipMessage::AllianceMembershipMessage()
{
  m_type = MessageEnum::ALLIANCEMEMBERSHIPMESSAGE;
}

