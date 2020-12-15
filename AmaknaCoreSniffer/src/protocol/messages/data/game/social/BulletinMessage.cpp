#include "BulletinMessage.h"

void BulletinMessage::serialize(Writer *output)
{
  this->serializeAs_BulletinMessage(output);
}

void BulletinMessage::serializeAs_BulletinMessage(Writer *output)
{
  SocialNoticeMessage::serializeAs_SocialNoticeMessage(output);
  if(this->lastNotifiedTimestamp < 0)
  {
    qDebug()<<"ERREUR - BulletinMessage -"<<"Forbidden value (" << this->lastNotifiedTimestamp << ") on element lastNotifiedTimestamp.";
  }
  output->writeInt((int)this->lastNotifiedTimestamp);
}

void BulletinMessage::deserialize(Reader *input)
{
  this->deserializeAs_BulletinMessage(input);
}

void BulletinMessage::deserializeAs_BulletinMessage(Reader *input)
{
  SocialNoticeMessage::deserialize(input);
  this->_lastNotifiedTimestampFunc(input);
}

void BulletinMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BulletinMessage(tree);
}

void BulletinMessage::deserializeAsyncAs_BulletinMessage(FuncTree tree)
{
  SocialNoticeMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&BulletinMessage::_lastNotifiedTimestampFunc, this, std::placeholders::_1));
}

void BulletinMessage::_lastNotifiedTimestampFunc(Reader *input)
{
  this->lastNotifiedTimestamp = input->readInt();
  if(this->lastNotifiedTimestamp < 0)
  {
    qDebug()<<"ERREUR - BulletinMessage -"<<"Forbidden value (" << this->lastNotifiedTimestamp << ") on element of BulletinMessage.lastNotifiedTimestamp.";
  }
}

BulletinMessage::BulletinMessage()
{
  m_type = MessageEnum::BULLETINMESSAGE;
}

