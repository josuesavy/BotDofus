#include "ShortcutBarAddErrorMessage.h"

void ShortcutBarAddErrorMessage::serialize(Writer *output)
{
  this->serializeAs_ShortcutBarAddErrorMessage(output);
}

void ShortcutBarAddErrorMessage::serializeAs_ShortcutBarAddErrorMessage(Writer *output)
{
  output->writeByte(this->error);
}

void ShortcutBarAddErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutBarAddErrorMessage(input);
}

void ShortcutBarAddErrorMessage::deserializeAs_ShortcutBarAddErrorMessage(Reader *input)
{
  this->_errorFunc(input);
}

void ShortcutBarAddErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutBarAddErrorMessage(tree);
}

void ShortcutBarAddErrorMessage::deserializeAsyncAs_ShortcutBarAddErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShortcutBarAddErrorMessage::_errorFunc, this, std::placeholders::_1));
}

void ShortcutBarAddErrorMessage::_errorFunc(Reader *input)
{
  this->error = input->readByte();
  if(this->error < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarAddErrorMessage -"<<"Forbidden value (" << this->error << ") on element of ShortcutBarAddErrorMessage.error.";
  }
}

ShortcutBarAddErrorMessage::ShortcutBarAddErrorMessage()
{
  m_type = MessageEnum::SHORTCUTBARADDERRORMESSAGE;
}

