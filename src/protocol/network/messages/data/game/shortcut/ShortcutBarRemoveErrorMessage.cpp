#include "ShortcutBarRemoveErrorMessage.h"

void ShortcutBarRemoveErrorMessage::serialize(Writer *output)
{
  this->serializeAs_ShortcutBarRemoveErrorMessage(output);
}

void ShortcutBarRemoveErrorMessage::serializeAs_ShortcutBarRemoveErrorMessage(Writer *output)
{
  output->writeByte(this->error);
}

void ShortcutBarRemoveErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutBarRemoveErrorMessage(input);
}

void ShortcutBarRemoveErrorMessage::deserializeAs_ShortcutBarRemoveErrorMessage(Reader *input)
{
  this->_errorFunc(input);
}

void ShortcutBarRemoveErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutBarRemoveErrorMessage(tree);
}

void ShortcutBarRemoveErrorMessage::deserializeAsyncAs_ShortcutBarRemoveErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShortcutBarRemoveErrorMessage::_errorFunc, this, std::placeholders::_1));
}

void ShortcutBarRemoveErrorMessage::_errorFunc(Reader *input)
{
  this->error = input->readByte();
  if(this->error < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarRemoveErrorMessage -"<<"Forbidden value (" << this->error << ") on element of ShortcutBarRemoveErrorMessage.error.";
  }
}

ShortcutBarRemoveErrorMessage::ShortcutBarRemoveErrorMessage()
{
  m_type = MessageEnum::SHORTCUTBARREMOVEERRORMESSAGE;
}

