#include "SocialNoticeSetErrorMessage.h"

void SocialNoticeSetErrorMessage::serialize(Writer *output)
{
  this->serializeAs_SocialNoticeSetErrorMessage(output);
}

void SocialNoticeSetErrorMessage::serializeAs_SocialNoticeSetErrorMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void SocialNoticeSetErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_SocialNoticeSetErrorMessage(input);
}

void SocialNoticeSetErrorMessage::deserializeAs_SocialNoticeSetErrorMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void SocialNoticeSetErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialNoticeSetErrorMessage(tree);
}

void SocialNoticeSetErrorMessage::deserializeAsyncAs_SocialNoticeSetErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SocialNoticeSetErrorMessage::_reasonFunc, this, std::placeholders::_1));
}

void SocialNoticeSetErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - SocialNoticeSetErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of SocialNoticeSetErrorMessage.reason.";
  }
}

SocialNoticeSetErrorMessage::SocialNoticeSetErrorMessage()
{
  m_type = MessageEnum::SOCIALNOTICESETERRORMESSAGE;
}

