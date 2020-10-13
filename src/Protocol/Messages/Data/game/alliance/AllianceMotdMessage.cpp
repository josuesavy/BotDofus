#include "AllianceMotdMessage.h"

void AllianceMotdMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceMotdMessage(output);
}

void AllianceMotdMessage::serializeAs_AllianceMotdMessage(Writer *output)
{
  SocialNoticeMessage::serializeAs_SocialNoticeMessage(output);
}

void AllianceMotdMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceMotdMessage(input);
}

void AllianceMotdMessage::deserializeAs_AllianceMotdMessage(Reader *input)
{
  SocialNoticeMessage::deserialize(input);
}

void AllianceMotdMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceMotdMessage(tree);
}

void AllianceMotdMessage::deserializeAsyncAs_AllianceMotdMessage(FuncTree tree)
{
  SocialNoticeMessage::deserializeAsync(tree);
}

AllianceMotdMessage::AllianceMotdMessage()
{
  m_type = MessageEnum::ALLIANCEMOTDMESSAGE;
}

