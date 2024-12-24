#include "ChallengeTargetWithAttackerInformation.h"

void ChallengeTargetWithAttackerInformation::serialize(Writer *output)
{
  this->serializeAs_ChallengeTargetWithAttackerInformation(output);
}

void ChallengeTargetWithAttackerInformation::serializeAs_ChallengeTargetWithAttackerInformation(Writer *output)
{
  ChallengeTargetInformation::serializeAs_ChallengeTargetInformation(output);
  output->writeShort((short)this->attackersIds.size());
  for(uint _i1 = 0; _i1 < this->attackersIds.size(); _i1++)
  {
    if(this->attackersIds[_i1] < -9007199254740992 || this->attackersIds[_i1] > 9007199254740992)
    {
      qDebug()<<"ERREUR - ChallengeTargetWithAttackerInformation -"<<"Forbidden value (" << this->attackersIds[_i1] << ") on element 1 (starting at 1) of attackersIds.";
    }
    output->writeDouble(this->attackersIds[_i1]);
  }
}

void ChallengeTargetWithAttackerInformation::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeTargetWithAttackerInformation(input);
}

void ChallengeTargetWithAttackerInformation::deserializeAs_ChallengeTargetWithAttackerInformation(Reader *input)
{
  double _val1 = NULL;
  ChallengeTargetInformation::deserialize(input);
  uint _attackersIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _attackersIdsLen; _i1++)
  {
    _val1 = double(input->readDouble());
    if(_val1 < -9007199254740992 || _val1 > 9007199254740992)
    {
      qDebug()<<"ERREUR - ChallengeTargetWithAttackerInformation -"<<"Forbidden value (" << _val1 << ") on elements of attackersIds.";
    }
    this->attackersIds.append(_val1);
  }
}

void ChallengeTargetWithAttackerInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeTargetWithAttackerInformation(tree);
}

void ChallengeTargetWithAttackerInformation::deserializeAsyncAs_ChallengeTargetWithAttackerInformation(FuncTree tree)
{
  ChallengeTargetInformation::deserializeAsync(tree);
  this->_attackersIdstree = tree.addChild(std::bind(&ChallengeTargetWithAttackerInformation::_attackersIdstreeFunc, this, std::placeholders::_1));
}

void ChallengeTargetWithAttackerInformation::_attackersIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_attackersIdstree.addChild(std::bind(&ChallengeTargetWithAttackerInformation::_attackersIdsFunc, this, std::placeholders::_1));
  }
}

void ChallengeTargetWithAttackerInformation::_attackersIdsFunc(Reader *input)
{
  double _val = double(input->readDouble());
  if(_val < -9007199254740992 || _val > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChallengeTargetWithAttackerInformation -"<<"Forbidden value (" << _val << ") on elements of attackersIds.";
  }
  this->attackersIds.append(_val);
}

ChallengeTargetWithAttackerInformation::ChallengeTargetWithAttackerInformation()
{
  m_types<<ClassEnum::CHALLENGETARGETWITHATTACKERINFORMATION;
}

bool ChallengeTargetWithAttackerInformation::operator==(const ChallengeTargetWithAttackerInformation &compared)
{
  if(attackersIds == compared.attackersIds)
  if(_attackersIdstree == compared._attackersIdstree)
  return true;
  
  return false;
}

