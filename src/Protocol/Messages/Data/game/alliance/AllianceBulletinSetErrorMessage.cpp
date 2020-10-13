#include "AllianceBulletinSetErrorMessage.h"

void AllianceBulletinSetErrorMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceBulletinSetErrorMessage(output);
}

void AllianceBulletinSetErrorMessage::serializeAs_AllianceBulletinSetErrorMessage(Writer *output)
{
  SocialNoticeSetErrorMessage::serializeAs_SocialNoticeSetErrorMessage(output);
}

void AllianceBulletinSetErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceBulletinSetErrorMessage(input);
}

void AllianceBulletinSetErrorMessage::deserializeAs_AllianceBulletinSetErrorMessage(Reader *input)
{
  SocialNoticeSetErrorMessage::deserialize(input);
}

void AllianceBulletinSetErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceBulletinSetErrorMessage(tree);
}

void AllianceBulletinSetErrorMessage::deserializeAsyncAs_AllianceBulletinSetErrorMessage(FuncTree tree)
{
  SocialNoticeSetErrorMessage::deserializeAsync(tree);
}

AllianceBulletinSetErrorMessage::AllianceBulletinSetErrorMessage()
{
  m_type = MessageEnum::ALLIANCEBULLETINSETERRORMESSAGE;
}

