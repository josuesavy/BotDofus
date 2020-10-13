#include "URLOpenMessage.h"

void URLOpenMessage::serialize(Writer *output)
{
  this->serializeAs_URLOpenMessage(output);
}

void URLOpenMessage::serializeAs_URLOpenMessage(Writer *output)
{
  if(this->urlId < 0)
  {
    qDebug()<<"ERREUR - URLOpenMessage -"<<"Forbidden value (" << this->urlId << ") on element urlId.";
  }
  output->writeByte(this->urlId);
}

void URLOpenMessage::deserialize(Reader *input)
{
  this->deserializeAs_URLOpenMessage(input);
}

void URLOpenMessage::deserializeAs_URLOpenMessage(Reader *input)
{
  this->_urlIdFunc(input);
}

void URLOpenMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_URLOpenMessage(tree);
}

void URLOpenMessage::deserializeAsyncAs_URLOpenMessage(FuncTree tree)
{
  tree.addChild(std::bind(&URLOpenMessage::_urlIdFunc, this, std::placeholders::_1));
}

void URLOpenMessage::_urlIdFunc(Reader *input)
{
  this->urlId = input->readByte();
  if(this->urlId < 0)
  {
    qDebug()<<"ERREUR - URLOpenMessage -"<<"Forbidden value (" << this->urlId << ") on element of URLOpenMessage.urlId.";
  }
}

URLOpenMessage::URLOpenMessage()
{
  m_type = MessageEnum::URLOPENMESSAGE;
}

