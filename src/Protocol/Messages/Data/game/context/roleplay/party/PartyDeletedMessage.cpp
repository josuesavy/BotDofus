#include "PartyDeletedMessage.h"

void PartyDeletedMessage::serialize(Writer *output)
{
  this->serializeAs_PartyDeletedMessage(output);
}

void PartyDeletedMessage::serializeAs_PartyDeletedMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
}

void PartyDeletedMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyDeletedMessage(input);
}

void PartyDeletedMessage::deserializeAs_PartyDeletedMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
}

void PartyDeletedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyDeletedMessage(tree);
}

void PartyDeletedMessage::deserializeAsyncAs_PartyDeletedMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
}

PartyDeletedMessage::PartyDeletedMessage()
{
  m_type = MessageEnum::PARTYDELETEDMESSAGE;
}

