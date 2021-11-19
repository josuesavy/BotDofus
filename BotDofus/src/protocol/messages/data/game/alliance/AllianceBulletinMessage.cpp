#include "AllianceBulletinMessage.h"

void AllianceBulletinMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceBulletinMessage(output);
}

void AllianceBulletinMessage::serializeAs_AllianceBulletinMessage(Writer *output)
{
  BulletinMessage::serializeAs_BulletinMessage(output);
}

void AllianceBulletinMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceBulletinMessage(input);
}

void AllianceBulletinMessage::deserializeAs_AllianceBulletinMessage(Reader *input)
{
  BulletinMessage::deserialize(input);
}

void AllianceBulletinMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceBulletinMessage(tree);
}

void AllianceBulletinMessage::deserializeAsyncAs_AllianceBulletinMessage(FuncTree tree)
{
  BulletinMessage::deserializeAsync(tree);
}

AllianceBulletinMessage::AllianceBulletinMessage()
{
  m_type = MessageEnum::ALLIANCEBULLETINMESSAGE;
}

