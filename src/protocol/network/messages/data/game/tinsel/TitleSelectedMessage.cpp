#include "TitleSelectedMessage.h"

void TitleSelectedMessage::serialize(Writer *output)
{
  this->serializeAs_TitleSelectedMessage(output);
}

void TitleSelectedMessage::serializeAs_TitleSelectedMessage(Writer *output)
{
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleSelectedMessage -"<<"Forbidden value (" << this->titleId << ") on element titleId.";
  }
  output->writeVarShort((int)this->titleId);
}

void TitleSelectedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TitleSelectedMessage(input);
}

void TitleSelectedMessage::deserializeAs_TitleSelectedMessage(Reader *input)
{
  this->_titleIdFunc(input);
}

void TitleSelectedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TitleSelectedMessage(tree);
}

void TitleSelectedMessage::deserializeAsyncAs_TitleSelectedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TitleSelectedMessage::_titleIdFunc, this, std::placeholders::_1));
}

void TitleSelectedMessage::_titleIdFunc(Reader *input)
{
  this->titleId = input->readVarUhShort();
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleSelectedMessage -"<<"Forbidden value (" << this->titleId << ") on element of TitleSelectedMessage.titleId.";
  }
}

TitleSelectedMessage::TitleSelectedMessage()
{
  m_type = MessageEnum::TITLESELECTEDMESSAGE;
}

