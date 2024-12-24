#include "HaapiValidationMessage.h"

void HaapiValidationMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiValidationMessage(output);
}

void HaapiValidationMessage::serializeAs_HaapiValidationMessage(Writer *output)
{
  output->writeByte(this->action);
  output->writeByte(this->code);
}

void HaapiValidationMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiValidationMessage(input);
}

void HaapiValidationMessage::deserializeAs_HaapiValidationMessage(Reader *input)
{
  this->_actionFunc(input);
  this->_codeFunc(input);
}

void HaapiValidationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiValidationMessage(tree);
}

void HaapiValidationMessage::deserializeAsyncAs_HaapiValidationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HaapiValidationMessage::_actionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiValidationMessage::_codeFunc, this, std::placeholders::_1));
}

void HaapiValidationMessage::_actionFunc(Reader *input)
{
  this->action = input->readByte();
  if(this->action < 0)
  {
    qDebug()<<"ERREUR - HaapiValidationMessage -"<<"Forbidden value (" << this->action << ") on element of HaapiValidationMessage.action.";
  }
}

void HaapiValidationMessage::_codeFunc(Reader *input)
{
  this->code = input->readByte();
  if(this->code < 0)
  {
    qDebug()<<"ERREUR - HaapiValidationMessage -"<<"Forbidden value (" << this->code << ") on element of HaapiValidationMessage.code.";
  }
}

HaapiValidationMessage::HaapiValidationMessage()
{
  m_type = MessageEnum::HAAPIVALIDATIONMESSAGE;
}

