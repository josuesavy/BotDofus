#include "HaapiSessionMessage.h"

void HaapiSessionMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiSessionMessage(output);
}

void HaapiSessionMessage::serializeAs_HaapiSessionMessage(Writer *output)
{
  output->writeUTF(this->key);
  output->writeByte(this->type);
}

void HaapiSessionMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiSessionMessage(input);
}

void HaapiSessionMessage::deserializeAs_HaapiSessionMessage(Reader *input)
{
  this->_keyFunc(input);
  this->_typeFunc(input);
}

void HaapiSessionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiSessionMessage(tree);
}

void HaapiSessionMessage::deserializeAsyncAs_HaapiSessionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HaapiSessionMessage::_keyFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiSessionMessage::_typeFunc, this, std::placeholders::_1));
}

void HaapiSessionMessage::_keyFunc(Reader *input)
{
  this->key = input->readUTF();
}

void HaapiSessionMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - HaapiSessionMessage -"<<"Forbidden value (" << this->type << ") on element of HaapiSessionMessage.type.";
  }
}

HaapiSessionMessage::HaapiSessionMessage()
{
  m_type = MessageEnum::HAAPISESSIONMESSAGE;
}

