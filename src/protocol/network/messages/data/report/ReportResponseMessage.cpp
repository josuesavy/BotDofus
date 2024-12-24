#include "ReportResponseMessage.h"

void ReportResponseMessage::serialize(Writer *output)
{
  this->serializeAs_ReportResponseMessage(output);
}

void ReportResponseMessage::serializeAs_ReportResponseMessage(Writer *output)
{
  output->writeBool(this->success);
}

void ReportResponseMessage::deserialize(Reader *input)
{
  this->deserializeAs_ReportResponseMessage(input);
}

void ReportResponseMessage::deserializeAs_ReportResponseMessage(Reader *input)
{
  this->_successFunc(input);
}

void ReportResponseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ReportResponseMessage(tree);
}

void ReportResponseMessage::deserializeAsyncAs_ReportResponseMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ReportResponseMessage::_successFunc, this, std::placeholders::_1));
}

void ReportResponseMessage::_successFunc(Reader *input)
{
  this->success = input->readBool();
}

ReportResponseMessage::ReportResponseMessage()
{
  m_type = MessageEnum::REPORTRESPONSEMESSAGE;
}

