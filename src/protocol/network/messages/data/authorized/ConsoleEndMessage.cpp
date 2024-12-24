#include "ConsoleEndMessage.h"

void ConsoleEndMessage::serialize(Writer *output)
{
  this->serializeAs_ConsoleEndMessage(output);
}

void ConsoleEndMessage::serializeAs_ConsoleEndMessage(Writer *output)
{
  this->consoleUuid.serializeAs_Uuid(output);
  output->writeBool(this->isSuccess);
}

void ConsoleEndMessage::deserialize(Reader *input)
{
  this->deserializeAs_ConsoleEndMessage(input);
}

void ConsoleEndMessage::deserializeAs_ConsoleEndMessage(Reader *input)
{
  this->consoleUuid = Uuid();
  this->consoleUuid.deserialize(input);
  this->_isSuccessFunc(input);
}

void ConsoleEndMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ConsoleEndMessage(tree);
}

void ConsoleEndMessage::deserializeAsyncAs_ConsoleEndMessage(FuncTree tree)
{
  this->_consoleUuidtree = tree.addChild(std::bind(&ConsoleEndMessage::_consoleUuidtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ConsoleEndMessage::_isSuccessFunc, this, std::placeholders::_1));
}

void ConsoleEndMessage::_consoleUuidtreeFunc(Reader *input)
{
  this->consoleUuid = Uuid();
  this->consoleUuid.deserializeAsync(this->_consoleUuidtree);
}

void ConsoleEndMessage::_isSuccessFunc(Reader *input)
{
  this->isSuccess = input->readBool();
}

ConsoleEndMessage::ConsoleEndMessage()
{
  m_type = MessageEnum::CONSOLEENDMESSAGE;
}

