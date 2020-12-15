#include "PrismInfoJoinLeaveRequestMessage.h"

void PrismInfoJoinLeaveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PrismInfoJoinLeaveRequestMessage(output);
}

void PrismInfoJoinLeaveRequestMessage::serializeAs_PrismInfoJoinLeaveRequestMessage(Writer *output)
{
  output->writeBool(this->join);
}

void PrismInfoJoinLeaveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismInfoJoinLeaveRequestMessage(input);
}

void PrismInfoJoinLeaveRequestMessage::deserializeAs_PrismInfoJoinLeaveRequestMessage(Reader *input)
{
  this->_joinFunc(input);
}

void PrismInfoJoinLeaveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismInfoJoinLeaveRequestMessage(tree);
}

void PrismInfoJoinLeaveRequestMessage::deserializeAsyncAs_PrismInfoJoinLeaveRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismInfoJoinLeaveRequestMessage::_joinFunc, this, std::placeholders::_1));
}

void PrismInfoJoinLeaveRequestMessage::_joinFunc(Reader *input)
{
  this->join = input->readBool();
}

PrismInfoJoinLeaveRequestMessage::PrismInfoJoinLeaveRequestMessage()
{
  m_type = MessageEnum::PRISMINFOJOINLEAVEREQUESTMESSAGE;
}

