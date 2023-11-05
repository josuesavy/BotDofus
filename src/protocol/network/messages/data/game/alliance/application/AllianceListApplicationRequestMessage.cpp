#include "AllianceListApplicationRequestMessage.h"

void AllianceListApplicationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceListApplicationRequestMessage(output);
}

void AllianceListApplicationRequestMessage::serializeAs_AllianceListApplicationRequestMessage(Writer *output)
{
  PaginationRequestAbstractMessage::serializeAs_PaginationRequestAbstractMessage(output);
}

void AllianceListApplicationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceListApplicationRequestMessage(input);
}

void AllianceListApplicationRequestMessage::deserializeAs_AllianceListApplicationRequestMessage(Reader *input)
{
  PaginationRequestAbstractMessage::deserialize(input);
}

void AllianceListApplicationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceListApplicationRequestMessage(tree);
}

void AllianceListApplicationRequestMessage::deserializeAsyncAs_AllianceListApplicationRequestMessage(FuncTree tree)
{
  PaginationRequestAbstractMessage::deserializeAsync(tree);
}

AllianceListApplicationRequestMessage::AllianceListApplicationRequestMessage()
{
  m_type = MessageEnum::ALLIANCELISTAPPLICATIONREQUESTMESSAGE;
}

