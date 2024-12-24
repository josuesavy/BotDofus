#include "ChangeThemeRequestMessage.h"

void ChangeThemeRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ChangeThemeRequestMessage(output);
}

void ChangeThemeRequestMessage::serializeAs_ChangeThemeRequestMessage(Writer *output)
{
  output->writeByte(this->theme);
}

void ChangeThemeRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChangeThemeRequestMessage(input);
}

void ChangeThemeRequestMessage::deserializeAs_ChangeThemeRequestMessage(Reader *input)
{
  this->_themeFunc(input);
}

void ChangeThemeRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChangeThemeRequestMessage(tree);
}

void ChangeThemeRequestMessage::deserializeAsyncAs_ChangeThemeRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChangeThemeRequestMessage::_themeFunc, this, std::placeholders::_1));
}

void ChangeThemeRequestMessage::_themeFunc(Reader *input)
{
  this->theme = input->readByte();
}

ChangeThemeRequestMessage::ChangeThemeRequestMessage()
{
  m_type = MessageEnum::CHANGETHEMEREQUESTMESSAGE;
}

