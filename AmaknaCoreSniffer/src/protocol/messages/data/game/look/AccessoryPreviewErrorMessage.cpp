#include "AccessoryPreviewErrorMessage.h"

void AccessoryPreviewErrorMessage::serialize(Writer *output)
{
  this->serializeAs_AccessoryPreviewErrorMessage(output);
}

void AccessoryPreviewErrorMessage::serializeAs_AccessoryPreviewErrorMessage(Writer *output)
{
  output->writeByte(this->error);
}

void AccessoryPreviewErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_AccessoryPreviewErrorMessage(input);
}

void AccessoryPreviewErrorMessage::deserializeAs_AccessoryPreviewErrorMessage(Reader *input)
{
  this->_errorFunc(input);
}

void AccessoryPreviewErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AccessoryPreviewErrorMessage(tree);
}

void AccessoryPreviewErrorMessage::deserializeAsyncAs_AccessoryPreviewErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AccessoryPreviewErrorMessage::_errorFunc, this, std::placeholders::_1));
}

void AccessoryPreviewErrorMessage::_errorFunc(Reader *input)
{
  this->error = input->readByte();
  if(this->error < 0)
  {
    qDebug()<<"ERREUR - AccessoryPreviewErrorMessage -"<<"Forbidden value (" << this->error << ") on element of AccessoryPreviewErrorMessage.error.";
  }
}

AccessoryPreviewErrorMessage::AccessoryPreviewErrorMessage()
{
  m_type = MessageEnum::ACCESSORYPREVIEWERRORMESSAGE;
}

