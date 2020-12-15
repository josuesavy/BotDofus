#include "BufferInformation.h"

void BufferInformation::serialize(Writer *output)
{
  this->serializeAs_BufferInformation(output);
}

void BufferInformation::serializeAs_BufferInformation(Writer *output)
{
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BufferInformation -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarLong((double)this->id);
  if(this->amount < 0 || this->amount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BufferInformation -"<<"Forbidden value (" << this->amount << ") on element amount.";
  }
  output->writeVarLong((double)this->amount);
}

void BufferInformation::deserialize(Reader *input)
{
  this->deserializeAs_BufferInformation(input);
}

void BufferInformation::deserializeAs_BufferInformation(Reader *input)
{
  this->_idFunc(input);
  this->_amountFunc(input);
}

void BufferInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BufferInformation(tree);
}

void BufferInformation::deserializeAsyncAs_BufferInformation(FuncTree tree)
{
  tree.addChild(std::bind(&BufferInformation::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BufferInformation::_amountFunc, this, std::placeholders::_1));
}

void BufferInformation::_idFunc(Reader *input)
{
  this->id = input->readVarUhLong();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BufferInformation -"<<"Forbidden value (" << this->id << ") on element of BufferInformation.id.";
  }
}

void BufferInformation::_amountFunc(Reader *input)
{
  this->amount = input->readVarUhLong();
  if(this->amount < 0 || this->amount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BufferInformation -"<<"Forbidden value (" << this->amount << ") on element of BufferInformation.amount.";
  }
}

BufferInformation::BufferInformation()
{
  m_types<<ClassEnum::BUFFERINFORMATION;
}

bool BufferInformation::operator==(const BufferInformation &compared)
{
  if(id == compared.id)
  if(amount == compared.amount)
  return true;
  
  return false;
}

