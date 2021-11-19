#include "HaapiBuyValidationMessage.h"

void HaapiBuyValidationMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiBuyValidationMessage(output);
}

void HaapiBuyValidationMessage::serializeAs_HaapiBuyValidationMessage(Writer *output)
{
  HaapiValidationMessage::serializeAs_HaapiValidationMessage(output);
  if(this->amount < 0 || this->amount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HaapiBuyValidationMessage -"<<"Forbidden value (" << this->amount << ") on element amount.";
  }
  output->writeVarLong((double)this->amount);
  output->writeUTF(this->email);
}

void HaapiBuyValidationMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiBuyValidationMessage(input);
}

void HaapiBuyValidationMessage::deserializeAs_HaapiBuyValidationMessage(Reader *input)
{
  HaapiValidationMessage::deserialize(input);
  this->_amountFunc(input);
  this->_emailFunc(input);
}

void HaapiBuyValidationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiBuyValidationMessage(tree);
}

void HaapiBuyValidationMessage::deserializeAsyncAs_HaapiBuyValidationMessage(FuncTree tree)
{
  HaapiValidationMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&HaapiBuyValidationMessage::_amountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiBuyValidationMessage::_emailFunc, this, std::placeholders::_1));
}

void HaapiBuyValidationMessage::_amountFunc(Reader *input)
{
  this->amount = input->readVarUhLong();
  if(this->amount < 0 || this->amount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HaapiBuyValidationMessage -"<<"Forbidden value (" << this->amount << ") on element of HaapiBuyValidationMessage.amount.";
  }
}

void HaapiBuyValidationMessage::_emailFunc(Reader *input)
{
  this->email = input->readUTF();
}

HaapiBuyValidationMessage::HaapiBuyValidationMessage()
{
  m_type = MessageEnum::HAAPIBUYVALIDATIONMESSAGE;
}

