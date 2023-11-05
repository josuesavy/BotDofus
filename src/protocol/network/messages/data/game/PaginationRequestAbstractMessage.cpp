#include "PaginationRequestAbstractMessage.h"

void PaginationRequestAbstractMessage::serialize(Writer *output)
{
  this->serializeAs_PaginationRequestAbstractMessage(output);
}

void PaginationRequestAbstractMessage::serializeAs_PaginationRequestAbstractMessage(Writer *output)
{
  if(this->offset < 0 || this->offset > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaginationRequestAbstractMessage -"<<"Forbidden value (" << this->offset << ") on element offset.";
  }
  output->writeDouble(this->offset);
  if(this->count < 0 || this->count > 4294967295)
  {
    qDebug()<<"ERREUR - PaginationRequestAbstractMessage -"<<"Forbidden value (" << this->count << ") on element count.";
  }
  output->writeUInt((uint)this->count);
}

void PaginationRequestAbstractMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaginationRequestAbstractMessage(input);
}

void PaginationRequestAbstractMessage::deserializeAs_PaginationRequestAbstractMessage(Reader *input)
{
  this->_offsetFunc(input);
  this->_countFunc(input);
}

void PaginationRequestAbstractMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaginationRequestAbstractMessage(tree);
}

void PaginationRequestAbstractMessage::deserializeAsyncAs_PaginationRequestAbstractMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaginationRequestAbstractMessage::_offsetFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaginationRequestAbstractMessage::_countFunc, this, std::placeholders::_1));
}

void PaginationRequestAbstractMessage::_offsetFunc(Reader *input)
{
  this->offset = input->readDouble();
  if(this->offset < 0 || this->offset > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaginationRequestAbstractMessage -"<<"Forbidden value (" << this->offset << ") on element of PaginationRequestAbstractMessage.offset.";
  }
}

void PaginationRequestAbstractMessage::_countFunc(Reader *input)
{
  this->count = input->readUInt();
  if(this->count < 0 || this->count > 4294967295)
  {
    qDebug()<<"ERREUR - PaginationRequestAbstractMessage -"<<"Forbidden value (" << this->count << ") on element of PaginationRequestAbstractMessage.count.";
  }
}

PaginationRequestAbstractMessage::PaginationRequestAbstractMessage()
{
  m_type = MessageEnum::PAGINATIONREQUESTABSTRACTMESSAGE;
}

