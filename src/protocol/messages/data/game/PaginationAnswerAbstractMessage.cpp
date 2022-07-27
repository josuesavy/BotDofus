#include "PaginationAnswerAbstractMessage.h"

void PaginationAnswerAbstractMessage::serialize(Writer *output)
{
  this->serializeAs_PaginationAnswerAbstractMessage(output);
}

void PaginationAnswerAbstractMessage::serializeAs_PaginationAnswerAbstractMessage(Writer *output)
{
  if(this->offset < 0 || this->offset > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PaginationAnswerAbstractMessage -"<<"Forbidden value (" << this->offset << ") on element offset.";
  }
  output->writeDouble(this->offset);
  if(this->count < 0 || this->count > 4.294967295E9)
  {
    qDebug()<<"ERREUR - PaginationAnswerAbstractMessage -"<<"Forbidden value (" << this->count << ") on element count.";
  }
  output->writeUInt((uint)this->count);
  if(this->total < 0 || this->total > 4.294967295E9)
  {
    qDebug()<<"ERREUR - PaginationAnswerAbstractMessage -"<<"Forbidden value (" << this->total << ") on element total.";
  }
  output->writeUInt((uint)this->total);
}

void PaginationAnswerAbstractMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaginationAnswerAbstractMessage(input);
}

void PaginationAnswerAbstractMessage::deserializeAs_PaginationAnswerAbstractMessage(Reader *input)
{
  this->_offsetFunc(input);
  this->_countFunc(input);
  this->_totalFunc(input);
}

void PaginationAnswerAbstractMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaginationAnswerAbstractMessage(tree);
}

void PaginationAnswerAbstractMessage::deserializeAsyncAs_PaginationAnswerAbstractMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaginationAnswerAbstractMessage::_offsetFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaginationAnswerAbstractMessage::_countFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaginationAnswerAbstractMessage::_totalFunc, this, std::placeholders::_1));
}

void PaginationAnswerAbstractMessage::_offsetFunc(Reader *input)
{
  this->offset = input->readDouble();
  if(this->offset < 0 || this->offset > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PaginationAnswerAbstractMessage -"<<"Forbidden value (" << this->offset << ") on element of PaginationAnswerAbstractMessage.offset.";
  }
}

void PaginationAnswerAbstractMessage::_countFunc(Reader *input)
{
  this->count = input->readUInt();
  if(this->count < 0 || this->count > 4.294967295E9)
  {
    qDebug()<<"ERREUR - PaginationAnswerAbstractMessage -"<<"Forbidden value (" << this->count << ") on element of PaginationAnswerAbstractMessage.count.";
  }
}

void PaginationAnswerAbstractMessage::_totalFunc(Reader *input)
{
  this->total = input->readUInt();
  if(this->total < 0 || this->total > 4.294967295E9)
  {
    qDebug()<<"ERREUR - PaginationAnswerAbstractMessage -"<<"Forbidden value (" << this->total << ") on element of PaginationAnswerAbstractMessage.total.";
  }
}

PaginationAnswerAbstractMessage::PaginationAnswerAbstractMessage()
{
  m_type = MessageEnum::PAGINATIONANSWERABSTRACTMESSAGE;
}

