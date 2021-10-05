#include "FinishMoveInformations.h"

void FinishMoveInformations::serialize(Writer *output)
{
  this->serializeAs_FinishMoveInformations(output);
}

void FinishMoveInformations::serializeAs_FinishMoveInformations(Writer *output)
{
  if(this->finishMoveId < 0)
  {
    qDebug()<<"ERREUR - FinishMoveInformations -"<<"Forbidden value (" << this->finishMoveId << ") on element finishMoveId.";
  }
  output->writeInt((int)this->finishMoveId);
  output->writeBool(this->finishMoveState);
}

void FinishMoveInformations::deserialize(Reader *input)
{
  this->deserializeAs_FinishMoveInformations(input);
}

void FinishMoveInformations::deserializeAs_FinishMoveInformations(Reader *input)
{
  this->_finishMoveIdFunc(input);
  this->_finishMoveStateFunc(input);
}

void FinishMoveInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FinishMoveInformations(tree);
}

void FinishMoveInformations::deserializeAsyncAs_FinishMoveInformations(FuncTree tree)
{
  tree.addChild(std::bind(&FinishMoveInformations::_finishMoveIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FinishMoveInformations::_finishMoveStateFunc, this, std::placeholders::_1));
}

void FinishMoveInformations::_finishMoveIdFunc(Reader *input)
{
  this->finishMoveId = input->readInt();
  if(this->finishMoveId < 0)
  {
    qDebug()<<"ERREUR - FinishMoveInformations -"<<"Forbidden value (" << this->finishMoveId << ") on element of FinishMoveInformations.finishMoveId.";
  }
}

void FinishMoveInformations::_finishMoveStateFunc(Reader *input)
{
  this->finishMoveState = input->readBool();
}

FinishMoveInformations::FinishMoveInformations()
{
  m_types<<ClassEnum::FINISHMOVEINFORMATIONS;
}

bool FinishMoveInformations::operator==(const FinishMoveInformations &compared)
{
  if(finishMoveId == compared.finishMoveId)
  if(finishMoveState == compared.finishMoveState)
  return true;
  
  return false;
}

