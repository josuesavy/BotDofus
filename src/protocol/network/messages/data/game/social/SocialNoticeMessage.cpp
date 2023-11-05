#include "SocialNoticeMessage.h"

void SocialNoticeMessage::serialize(Writer *output)
{
  this->serializeAs_SocialNoticeMessage(output);
}

void SocialNoticeMessage::serializeAs_SocialNoticeMessage(Writer *output)
{
  output->writeUTF(this->content);
  if(this->timestamp < 0)
  {
    qDebug()<<"ERREUR - SocialNoticeMessage -"<<"Forbidden value (" << this->timestamp << ") on element timestamp.";
  }
  output->writeInt((int)this->timestamp);
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialNoticeMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
  output->writeUTF(this->memberName);
}

void SocialNoticeMessage::deserialize(Reader *input)
{
  this->deserializeAs_SocialNoticeMessage(input);
}

void SocialNoticeMessage::deserializeAs_SocialNoticeMessage(Reader *input)
{
  this->_contentFunc(input);
  this->_timestampFunc(input);
  this->_memberIdFunc(input);
  this->_memberNameFunc(input);
}

void SocialNoticeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialNoticeMessage(tree);
}

void SocialNoticeMessage::deserializeAsyncAs_SocialNoticeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SocialNoticeMessage::_contentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialNoticeMessage::_timestampFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialNoticeMessage::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialNoticeMessage::_memberNameFunc, this, std::placeholders::_1));
}

void SocialNoticeMessage::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

void SocialNoticeMessage::_timestampFunc(Reader *input)
{
  this->timestamp = input->readInt();
  if(this->timestamp < 0)
  {
    qDebug()<<"ERREUR - SocialNoticeMessage -"<<"Forbidden value (" << this->timestamp << ") on element of SocialNoticeMessage.timestamp.";
  }
}

void SocialNoticeMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialNoticeMessage -"<<"Forbidden value (" << this->memberId << ") on element of SocialNoticeMessage.memberId.";
  }
}

void SocialNoticeMessage::_memberNameFunc(Reader *input)
{
  this->memberName = input->readUTF();
}

SocialNoticeMessage::SocialNoticeMessage()
{
  m_type = MessageEnum::SOCIALNOTICEMESSAGE;
}

