#include "HaapiAuthErrorMessage.h"

void HaapiAuthErrorMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiAuthErrorMessage(output);
}

void HaapiAuthErrorMessage::serializeAs_HaapiAuthErrorMessage(Writer *output)
{
  output->writeByte(this->type);
}

void HaapiAuthErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiAuthErrorMessage(input);
}

void HaapiAuthErrorMessage::deserializeAs_HaapiAuthErrorMessage(Reader *input)
{
  this->_typeFunc(input);
}

void HaapiAuthErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiAuthErrorMessage(tree);
}

void HaapiAuthErrorMessage::deserializeAsyncAs_HaapiAuthErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HaapiAuthErrorMessage::_typeFunc, this, std::placeholders::_1));
}

void HaapiAuthErrorMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - HaapiAuthErrorMessage -"<<"Forbidden value (" << this->type << ") on element of HaapiAuthErrorMessage.type.";
  }
}

HaapiAuthErrorMessage::HaapiAuthErrorMessage()
{
  m_type = MessageEnum::HAAPIAUTHERRORMESSAGE;
}

