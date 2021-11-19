#include "PopupWarningMessage.h"

void PopupWarningMessage::serialize(Writer *output)
{
  this->serializeAs_PopupWarningMessage(output);
}

void PopupWarningMessage::serializeAs_PopupWarningMessage(Writer *output)
{
  if(this->lockDuration < 0 || this->lockDuration > 255)
  {
    qDebug()<<"ERREUR - PopupWarningMessage -"<<"Forbidden value (" << this->lockDuration << ") on element lockDuration.";
  }
  output->writeByte(this->lockDuration);
  output->writeUTF(this->author);
  output->writeUTF(this->content);
}

void PopupWarningMessage::deserialize(Reader *input)
{
  this->deserializeAs_PopupWarningMessage(input);
}

void PopupWarningMessage::deserializeAs_PopupWarningMessage(Reader *input)
{
  this->_lockDurationFunc(input);
  this->_authorFunc(input);
  this->_contentFunc(input);
}

void PopupWarningMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PopupWarningMessage(tree);
}

void PopupWarningMessage::deserializeAsyncAs_PopupWarningMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PopupWarningMessage::_lockDurationFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PopupWarningMessage::_authorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PopupWarningMessage::_contentFunc, this, std::placeholders::_1));
}

void PopupWarningMessage::_lockDurationFunc(Reader *input)
{
  this->lockDuration = input->readUByte();
  if(this->lockDuration < 0 || this->lockDuration > 255)
  {
    qDebug()<<"ERREUR - PopupWarningMessage -"<<"Forbidden value (" << this->lockDuration << ") on element of PopupWarningMessage.lockDuration.";
  }
}

void PopupWarningMessage::_authorFunc(Reader *input)
{
  this->author = input->readUTF();
}

void PopupWarningMessage::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

PopupWarningMessage::PopupWarningMessage()
{
  m_type = MessageEnum::POPUPWARNINGMESSAGE;
}

