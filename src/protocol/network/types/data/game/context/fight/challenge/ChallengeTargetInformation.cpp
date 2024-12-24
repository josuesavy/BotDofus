#include "ChallengeTargetInformation.h"

void ChallengeTargetInformation::serialize(Writer *output)
{
  this->serializeAs_ChallengeTargetInformation(output);
}

void ChallengeTargetInformation::serializeAs_ChallengeTargetInformation(Writer *output)
{
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChallengeTargetInformation -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->targetCell < -1 || this->targetCell > 559)
  {
    qDebug()<<"ERREUR - ChallengeTargetInformation -"<<"Forbidden value (" << this->targetCell << ") on element targetCell.";
  }
  output->writeShort((short)this->targetCell);
}

void ChallengeTargetInformation::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeTargetInformation(input);
}

void ChallengeTargetInformation::deserializeAs_ChallengeTargetInformation(Reader *input)
{
  this->_targetIdFunc(input);
  this->_targetCellFunc(input);
}

void ChallengeTargetInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeTargetInformation(tree);
}

void ChallengeTargetInformation::deserializeAsyncAs_ChallengeTargetInformation(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeTargetInformation::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeTargetInformation::_targetCellFunc, this, std::placeholders::_1));
}

void ChallengeTargetInformation::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChallengeTargetInformation -"<<"Forbidden value (" << this->targetId << ") on element of ChallengeTargetInformation.targetId.";
  }
}

void ChallengeTargetInformation::_targetCellFunc(Reader *input)
{
  this->targetCell = input->readShort();
  if(this->targetCell < -1 || this->targetCell > 559)
  {
    qDebug()<<"ERREUR - ChallengeTargetInformation -"<<"Forbidden value (" << this->targetCell << ") on element of ChallengeTargetInformation.targetCell.";
  }
}

ChallengeTargetInformation::ChallengeTargetInformation()
{
  m_types<<ClassEnum::CHALLENGETARGETINFORMATION;
}

bool ChallengeTargetInformation::operator==(const ChallengeTargetInformation &compared)
{
  if(targetId == compared.targetId)
  if(targetCell == compared.targetCell)
  return true;
  
  return false;
}

