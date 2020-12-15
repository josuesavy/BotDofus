#include "ShortcutBarSwapErrorMessage.h"

void ShortcutBarSwapErrorMessage::serialize(Writer *output)
{
  this->serializeAs_ShortcutBarSwapErrorMessage(output);
}

void ShortcutBarSwapErrorMessage::serializeAs_ShortcutBarSwapErrorMessage(Writer *output)
{
  output->writeByte(this->error);
}

void ShortcutBarSwapErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShortcutBarSwapErrorMessage(input);
}

void ShortcutBarSwapErrorMessage::deserializeAs_ShortcutBarSwapErrorMessage(Reader *input)
{
  this->_errorFunc(input);
}

void ShortcutBarSwapErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShortcutBarSwapErrorMessage(tree);
}

void ShortcutBarSwapErrorMessage::deserializeAsyncAs_ShortcutBarSwapErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShortcutBarSwapErrorMessage::_errorFunc, this, std::placeholders::_1));
}

void ShortcutBarSwapErrorMessage::_errorFunc(Reader *input)
{
  this->error = input->readByte();
  if(this->error < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarSwapErrorMessage -"<<"Forbidden value (" << this->error << ") on element of ShortcutBarSwapErrorMessage.error.";
  }
}

ShortcutBarSwapErrorMessage::ShortcutBarSwapErrorMessage()
{
  m_type = MessageEnum::SHORTCUTBARSWAPERRORMESSAGE;
}

