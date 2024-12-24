#include "AlliancePartialListMessage.h"

void AlliancePartialListMessage::serialize(Writer *output)
{
  this->serializeAs_AlliancePartialListMessage(output);
}

void AlliancePartialListMessage::serializeAs_AlliancePartialListMessage(Writer *output)
{
  AllianceListMessage::serializeAs_AllianceListMessage(output);
}

void AlliancePartialListMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlliancePartialListMessage(input);
}

void AlliancePartialListMessage::deserializeAs_AlliancePartialListMessage(Reader *input)
{
  AllianceListMessage::deserialize(input);
}

void AlliancePartialListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlliancePartialListMessage(tree);
}

void AlliancePartialListMessage::deserializeAsyncAs_AlliancePartialListMessage(FuncTree tree)
{
  AllianceListMessage::deserializeAsync(tree);
}

AlliancePartialListMessage::AlliancePartialListMessage()
{
  m_type = MessageEnum::ALLIANCEPARTIALLISTMESSAGE;
}

