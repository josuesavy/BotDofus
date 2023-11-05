#include "PartyNewMemberMessage.h"

void PartyNewMemberMessage::serialize(Writer *output)
{
  this->serializeAs_PartyNewMemberMessage(output);
}

void PartyNewMemberMessage::serializeAs_PartyNewMemberMessage(Writer *output)
{
  PartyUpdateMessage::serializeAs_PartyUpdateMessage(output);
}

void PartyNewMemberMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyNewMemberMessage(input);
}

void PartyNewMemberMessage::deserializeAs_PartyNewMemberMessage(Reader *input)
{
  PartyUpdateMessage::deserialize(input);
}

void PartyNewMemberMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyNewMemberMessage(tree);
}

void PartyNewMemberMessage::deserializeAsyncAs_PartyNewMemberMessage(FuncTree tree)
{
  PartyUpdateMessage::deserializeAsync(tree);
}

PartyNewMemberMessage::PartyNewMemberMessage()
{
  m_type = MessageEnum::PARTYNEWMEMBERMESSAGE;
}

