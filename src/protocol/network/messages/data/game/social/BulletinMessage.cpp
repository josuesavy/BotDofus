#include "BulletinMessage.h"

void BulletinMessage::serialize(Writer *output)
{
  this->serializeAs_BulletinMessage(output);
}

void BulletinMessage::serializeAs_BulletinMessage(Writer *output)
{
  SocialNoticeMessage::serializeAs_SocialNoticeMessage(output);
}

void BulletinMessage::deserialize(Reader *input)
{
  this->deserializeAs_BulletinMessage(input);
}

void BulletinMessage::deserializeAs_BulletinMessage(Reader *input)
{
  SocialNoticeMessage::deserialize(input);
}

void BulletinMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BulletinMessage(tree);
}

void BulletinMessage::deserializeAsyncAs_BulletinMessage(FuncTree tree)
{
  SocialNoticeMessage::deserializeAsync(tree);
}

BulletinMessage::BulletinMessage()
{
  m_type = MessageEnum::BULLETINMESSAGE;
}

