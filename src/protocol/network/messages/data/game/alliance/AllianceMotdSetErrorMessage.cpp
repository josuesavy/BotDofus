#include "AllianceMotdSetErrorMessage.h"

void AllianceMotdSetErrorMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceMotdSetErrorMessage(output);
}

void AllianceMotdSetErrorMessage::serializeAs_AllianceMotdSetErrorMessage(Writer *output)
{
  SocialNoticeSetErrorMessage::serializeAs_SocialNoticeSetErrorMessage(output);
}

void AllianceMotdSetErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceMotdSetErrorMessage(input);
}

void AllianceMotdSetErrorMessage::deserializeAs_AllianceMotdSetErrorMessage(Reader *input)
{
  SocialNoticeSetErrorMessage::deserialize(input);
}

void AllianceMotdSetErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceMotdSetErrorMessage(tree);
}

void AllianceMotdSetErrorMessage::deserializeAsyncAs_AllianceMotdSetErrorMessage(FuncTree tree)
{
  SocialNoticeSetErrorMessage::deserializeAsync(tree);
}

AllianceMotdSetErrorMessage::AllianceMotdSetErrorMessage()
{
  m_type = MessageEnum::ALLIANCEMOTDSETERRORMESSAGE;
}

