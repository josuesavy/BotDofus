#include "TitleGainedMessage.h"

void TitleGainedMessage::serialize(Writer *output)
{
  this->serializeAs_TitleGainedMessage(output);
}

void TitleGainedMessage::serializeAs_TitleGainedMessage(Writer *output)
{
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleGainedMessage -"<<"Forbidden value (" << this->titleId << ") on element titleId.";
  }
  output->writeVarShort((int)this->titleId);
}

void TitleGainedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TitleGainedMessage(input);
}

void TitleGainedMessage::deserializeAs_TitleGainedMessage(Reader *input)
{
  this->_titleIdFunc(input);
}

void TitleGainedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TitleGainedMessage(tree);
}

void TitleGainedMessage::deserializeAsyncAs_TitleGainedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TitleGainedMessage::_titleIdFunc, this, std::placeholders::_1));
}

void TitleGainedMessage::_titleIdFunc(Reader *input)
{
  this->titleId = input->readVarUhShort();
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleGainedMessage -"<<"Forbidden value (" << this->titleId << ") on element of TitleGainedMessage.titleId.";
  }
}

TitleGainedMessage::TitleGainedMessage()
{
  m_type = MessageEnum::TITLEGAINEDMESSAGE;
}

