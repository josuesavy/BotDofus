#include "TitleSelectErrorMessage.h"

void TitleSelectErrorMessage::serialize(Writer *output)
{
  this->serializeAs_TitleSelectErrorMessage(output);
}

void TitleSelectErrorMessage::serializeAs_TitleSelectErrorMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void TitleSelectErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_TitleSelectErrorMessage(input);
}

void TitleSelectErrorMessage::deserializeAs_TitleSelectErrorMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void TitleSelectErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TitleSelectErrorMessage(tree);
}

void TitleSelectErrorMessage::deserializeAsyncAs_TitleSelectErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TitleSelectErrorMessage::_reasonFunc, this, std::placeholders::_1));
}

void TitleSelectErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - TitleSelectErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of TitleSelectErrorMessage.reason.";
  }
}

TitleSelectErrorMessage::TitleSelectErrorMessage()
{
  m_type = MessageEnum::TITLESELECTERRORMESSAGE;
}

