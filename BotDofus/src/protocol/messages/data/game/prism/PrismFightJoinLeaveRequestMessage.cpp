#include "PrismFightJoinLeaveRequestMessage.h"

void PrismFightJoinLeaveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PrismFightJoinLeaveRequestMessage(output);
}

void PrismFightJoinLeaveRequestMessage::serializeAs_PrismFightJoinLeaveRequestMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightJoinLeaveRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeBool(this->join);
}

void PrismFightJoinLeaveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismFightJoinLeaveRequestMessage(input);
}

void PrismFightJoinLeaveRequestMessage::deserializeAs_PrismFightJoinLeaveRequestMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_joinFunc(input);
}

void PrismFightJoinLeaveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismFightJoinLeaveRequestMessage(tree);
}

void PrismFightJoinLeaveRequestMessage::deserializeAsyncAs_PrismFightJoinLeaveRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismFightJoinLeaveRequestMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismFightJoinLeaveRequestMessage::_joinFunc, this, std::placeholders::_1));
}

void PrismFightJoinLeaveRequestMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightJoinLeaveRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightJoinLeaveRequestMessage.subAreaId.";
  }
}

void PrismFightJoinLeaveRequestMessage::_joinFunc(Reader *input)
{
  this->join = input->readBool();
}

PrismFightJoinLeaveRequestMessage::PrismFightJoinLeaveRequestMessage()
{
  m_type = MessageEnum::PRISMFIGHTJOINLEAVEREQUESTMESSAGE;
}

