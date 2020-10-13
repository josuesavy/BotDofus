#include "CheckFileRequestMessage.h"

void CheckFileRequestMessage::serialize(Writer *output)
{
  this->serializeAs_CheckFileRequestMessage(output);
}

void CheckFileRequestMessage::serializeAs_CheckFileRequestMessage(Writer *output)
{
  output->writeUTF(this->filename);
  output->writeByte(this->type);
}

void CheckFileRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_CheckFileRequestMessage(input);
}

void CheckFileRequestMessage::deserializeAs_CheckFileRequestMessage(Reader *input)
{
  this->_filenameFunc(input);
  this->_typeFunc(input);
}

void CheckFileRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CheckFileRequestMessage(tree);
}

void CheckFileRequestMessage::deserializeAsyncAs_CheckFileRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CheckFileRequestMessage::_filenameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CheckFileRequestMessage::_typeFunc, this, std::placeholders::_1));
}

void CheckFileRequestMessage::_filenameFunc(Reader *input)
{
  this->filename = input->readUTF();
}

void CheckFileRequestMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - CheckFileRequestMessage -"<<"Forbidden value (" << this->type << ") on element of CheckFileRequestMessage.type.";
  }
}

CheckFileRequestMessage::CheckFileRequestMessage()
{
  m_type = MessageEnum::CHECKFILEREQUESTMESSAGE;
}

