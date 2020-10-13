#include "CheckFileMessage.h"

void CheckFileMessage::serialize(Writer *output)
{
  this->serializeAs_CheckFileMessage(output);
}

void CheckFileMessage::serializeAs_CheckFileMessage(Writer *output)
{
  output->writeUTF(this->filenameHash);
  output->writeByte(this->type);
  output->writeUTF(this->value);
}

void CheckFileMessage::deserialize(Reader *input)
{
  this->deserializeAs_CheckFileMessage(input);
}

void CheckFileMessage::deserializeAs_CheckFileMessage(Reader *input)
{
  this->_filenameHashFunc(input);
  this->_typeFunc(input);
  this->_valueFunc(input);
}

void CheckFileMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CheckFileMessage(tree);
}

void CheckFileMessage::deserializeAsyncAs_CheckFileMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CheckFileMessage::_filenameHashFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CheckFileMessage::_typeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CheckFileMessage::_valueFunc, this, std::placeholders::_1));
}

void CheckFileMessage::_filenameHashFunc(Reader *input)
{
  this->filenameHash = input->readUTF();
}

void CheckFileMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - CheckFileMessage -"<<"Forbidden value (" << this->type << ") on element of CheckFileMessage.type.";
  }
}

void CheckFileMessage::_valueFunc(Reader *input)
{
  this->value = input->readUTF();
}

CheckFileMessage::CheckFileMessage()
{
  m_type = MessageEnum::CHECKFILEMESSAGE;
}

