#include "ConsoleMessage.h"

void ConsoleMessage::serialize(Writer *output)
{
  this->serializeAs_ConsoleMessage(output);
}

void ConsoleMessage::serializeAs_ConsoleMessage(Writer *output)
{
  output->writeByte(this->type);
  output->writeUTF(this->content);
}

void ConsoleMessage::deserialize(Reader *input)
{
  this->deserializeAs_ConsoleMessage(input);
}

void ConsoleMessage::deserializeAs_ConsoleMessage(Reader *input)
{
  this->_typeFunc(input);
  this->_contentFunc(input);
}

void ConsoleMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ConsoleMessage(tree);
}

void ConsoleMessage::deserializeAsyncAs_ConsoleMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ConsoleMessage::_typeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ConsoleMessage::_contentFunc, this, std::placeholders::_1));
}

void ConsoleMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - ConsoleMessage -"<<"Forbidden value (" << this->type << ") on element of ConsoleMessage.type.";
  }
}

void ConsoleMessage::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

ConsoleMessage::ConsoleMessage()
{
  m_type = MessageEnum::CONSOLEMESSAGE;
}

