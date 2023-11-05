#include "TitleSelectRequestMessage.h"

void TitleSelectRequestMessage::serialize(Writer *output)
{
  this->serializeAs_TitleSelectRequestMessage(output);
}

void TitleSelectRequestMessage::serializeAs_TitleSelectRequestMessage(Writer *output)
{
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleSelectRequestMessage -"<<"Forbidden value (" << this->titleId << ") on element titleId.";
  }
  output->writeVarShort((int)this->titleId);
}

void TitleSelectRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_TitleSelectRequestMessage(input);
}

void TitleSelectRequestMessage::deserializeAs_TitleSelectRequestMessage(Reader *input)
{
  this->_titleIdFunc(input);
}

void TitleSelectRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TitleSelectRequestMessage(tree);
}

void TitleSelectRequestMessage::deserializeAsyncAs_TitleSelectRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TitleSelectRequestMessage::_titleIdFunc, this, std::placeholders::_1));
}

void TitleSelectRequestMessage::_titleIdFunc(Reader *input)
{
  this->titleId = input->readVarUhShort();
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleSelectRequestMessage -"<<"Forbidden value (" << this->titleId << ") on element of TitleSelectRequestMessage.titleId.";
  }
}

TitleSelectRequestMessage::TitleSelectRequestMessage()
{
  m_type = MessageEnum::TITLESELECTREQUESTMESSAGE;
}

