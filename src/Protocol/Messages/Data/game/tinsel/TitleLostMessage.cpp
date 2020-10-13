#include "TitleLostMessage.h"

void TitleLostMessage::serialize(Writer *output)
{
  this->serializeAs_TitleLostMessage(output);
}

void TitleLostMessage::serializeAs_TitleLostMessage(Writer *output)
{
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleLostMessage -"<<"Forbidden value (" << this->titleId << ") on element titleId.";
  }
  output->writeVarShort((int)this->titleId);
}

void TitleLostMessage::deserialize(Reader *input)
{
  this->deserializeAs_TitleLostMessage(input);
}

void TitleLostMessage::deserializeAs_TitleLostMessage(Reader *input)
{
  this->_titleIdFunc(input);
}

void TitleLostMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TitleLostMessage(tree);
}

void TitleLostMessage::deserializeAsyncAs_TitleLostMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TitleLostMessage::_titleIdFunc, this, std::placeholders::_1));
}

void TitleLostMessage::_titleIdFunc(Reader *input)
{
  this->titleId = input->readVarUhShort();
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleLostMessage -"<<"Forbidden value (" << this->titleId << ") on element of TitleLostMessage.titleId.";
  }
}

TitleLostMessage::TitleLostMessage()
{
  m_type = MessageEnum::TITLELOSTMESSAGE;
}

