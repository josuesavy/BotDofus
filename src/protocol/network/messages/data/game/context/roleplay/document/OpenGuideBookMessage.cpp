#include "OpenGuideBookMessage.h"

void OpenGuideBookMessage::serialize(Writer *output)
{
  this->serializeAs_OpenGuideBookMessage(output);
}

void OpenGuideBookMessage::serializeAs_OpenGuideBookMessage(Writer *output)
{
  if(this->articleId < 0)
  {
    qDebug()<<"ERREUR - OpenGuideBookMessage -"<<"Forbidden value (" << this->articleId << ") on element articleId.";
  }
  output->writeVarShort((int)this->articleId);
}

void OpenGuideBookMessage::deserialize(Reader *input)
{
  this->deserializeAs_OpenGuideBookMessage(input);
}

void OpenGuideBookMessage::deserializeAs_OpenGuideBookMessage(Reader *input)
{
  this->_articleIdFunc(input);
}

void OpenGuideBookMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_OpenGuideBookMessage(tree);
}

void OpenGuideBookMessage::deserializeAsyncAs_OpenGuideBookMessage(FuncTree tree)
{
  tree.addChild(std::bind(&OpenGuideBookMessage::_articleIdFunc, this, std::placeholders::_1));
}

void OpenGuideBookMessage::_articleIdFunc(Reader *input)
{
  this->articleId = input->readVarUhShort();
  if(this->articleId < 0)
  {
    qDebug()<<"ERREUR - OpenGuideBookMessage -"<<"Forbidden value (" << this->articleId << ") on element of OpenGuideBookMessage.articleId.";
  }
}

OpenGuideBookMessage::OpenGuideBookMessage()
{
  m_type = MessageEnum::OPENGUIDEBOOKMESSAGE;
}

