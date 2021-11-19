#include "ExchangeLeaveMessage.h"

void ExchangeLeaveMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeLeaveMessage(output);
}

void ExchangeLeaveMessage::serializeAs_ExchangeLeaveMessage(Writer *output)
{
  LeaveDialogMessage::serializeAs_LeaveDialogMessage(output);
  output->writeBool(this->success);
}

void ExchangeLeaveMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeLeaveMessage(input);
}

void ExchangeLeaveMessage::deserializeAs_ExchangeLeaveMessage(Reader *input)
{
  LeaveDialogMessage::deserialize(input);
  this->_successFunc(input);
}

void ExchangeLeaveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeLeaveMessage(tree);
}

void ExchangeLeaveMessage::deserializeAsyncAs_ExchangeLeaveMessage(FuncTree tree)
{
  LeaveDialogMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeLeaveMessage::_successFunc, this, std::placeholders::_1));
}

void ExchangeLeaveMessage::_successFunc(Reader *input)
{
  this->success = input->readBool();
}

ExchangeLeaveMessage::ExchangeLeaveMessage()
{
  m_type = MessageEnum::EXCHANGELEAVEMESSAGE;
}

