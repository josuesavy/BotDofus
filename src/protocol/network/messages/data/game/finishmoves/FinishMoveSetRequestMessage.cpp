#include "FinishMoveSetRequestMessage.h"

void FinishMoveSetRequestMessage::serialize(Writer *output)
{
  this->serializeAs_FinishMoveSetRequestMessage(output);
}

void FinishMoveSetRequestMessage::serializeAs_FinishMoveSetRequestMessage(Writer *output)
{
  if(this->finishMoveId < 0)
  {
    qDebug()<<"ERREUR - FinishMoveSetRequestMessage -"<<"Forbidden value (" << this->finishMoveId << ") on element finishMoveId.";
  }
  output->writeInt((int)this->finishMoveId);
  output->writeBool(this->finishMoveState);
}

void FinishMoveSetRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_FinishMoveSetRequestMessage(input);
}

void FinishMoveSetRequestMessage::deserializeAs_FinishMoveSetRequestMessage(Reader *input)
{
  this->_finishMoveIdFunc(input);
  this->_finishMoveStateFunc(input);
}

void FinishMoveSetRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FinishMoveSetRequestMessage(tree);
}

void FinishMoveSetRequestMessage::deserializeAsyncAs_FinishMoveSetRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FinishMoveSetRequestMessage::_finishMoveIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FinishMoveSetRequestMessage::_finishMoveStateFunc, this, std::placeholders::_1));
}

void FinishMoveSetRequestMessage::_finishMoveIdFunc(Reader *input)
{
  this->finishMoveId = input->readInt();
  if(this->finishMoveId < 0)
  {
    qDebug()<<"ERREUR - FinishMoveSetRequestMessage -"<<"Forbidden value (" << this->finishMoveId << ") on element of FinishMoveSetRequestMessage.finishMoveId.";
  }
}

void FinishMoveSetRequestMessage::_finishMoveStateFunc(Reader *input)
{
  this->finishMoveState = input->readBool();
}

FinishMoveSetRequestMessage::FinishMoveSetRequestMessage()
{
  m_type = MessageEnum::FINISHMOVESETREQUESTMESSAGE;
}

