#include "ChallengeInformation.h"

void ChallengeInformation::serialize(Writer *output)
{
  this->serializeAs_ChallengeInformation(output);
}

void ChallengeInformation::serializeAs_ChallengeInformation(Writer *output)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeInformation -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  output->writeVarInt((int)this->challengeId);
  output->writeShort((short)this->targetsList.size());
  for(uint _i2 = 0; _i2 < this->targetsList.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<ChallengeTargetInformation>(this->targetsList[_i2])->getTypes().last());
    qSharedPointerCast<ChallengeTargetInformation>(this->targetsList[_i2])->serialize(output);
  }
  if(this->dropBonus < 0)
  {
    qDebug()<<"ERREUR - ChallengeInformation -"<<"Forbidden value (" << this->dropBonus << ") on element dropBonus.";
  }
  output->writeVarInt((int)this->dropBonus);
  if(this->xpBonus < 0)
  {
    qDebug()<<"ERREUR - ChallengeInformation -"<<"Forbidden value (" << this->xpBonus << ") on element xpBonus.";
  }
  output->writeVarInt((int)this->xpBonus);
  output->writeByte(this->state);
}

void ChallengeInformation::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeInformation(input);
}

void ChallengeInformation::deserializeAs_ChallengeInformation(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<ChallengeTargetInformation> _item2 ;
  this->_challengeIdFunc(input);
  uint _targetsListLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _targetsListLen; _i2++)
  {
    _id2 = uint(input->readUShort());
    _item2 = qSharedPointerCast<ChallengeTargetInformation>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->targetsList.append(_item2);
  }
  this->_dropBonusFunc(input);
  this->_xpBonusFunc(input);
  this->_stateFunc(input);
}

void ChallengeInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeInformation(tree);
}

void ChallengeInformation::deserializeAsyncAs_ChallengeInformation(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeInformation::_challengeIdFunc, this, std::placeholders::_1));
  this->_targetsListtree = tree.addChild(std::bind(&ChallengeInformation::_targetsListtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeInformation::_dropBonusFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeInformation::_xpBonusFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeInformation::_stateFunc, this, std::placeholders::_1));
}

void ChallengeInformation::_challengeIdFunc(Reader *input)
{
  this->challengeId = input->readVarUhInt();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeInformation -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeInformation.challengeId.";
  }
}

void ChallengeInformation::_targetsListtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_targetsListtree.addChild(std::bind(&ChallengeInformation::_targetsListFunc, this, std::placeholders::_1));
  }
}

void ChallengeInformation::_targetsListFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<ChallengeTargetInformation> _item = qSharedPointerCast<ChallengeTargetInformation>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->targetsList.append(_item);
}

void ChallengeInformation::_dropBonusFunc(Reader *input)
{
  this->dropBonus = input->readVarUhInt();
  if(this->dropBonus < 0)
  {
    qDebug()<<"ERREUR - ChallengeInformation -"<<"Forbidden value (" << this->dropBonus << ") on element of ChallengeInformation.dropBonus.";
  }
}

void ChallengeInformation::_xpBonusFunc(Reader *input)
{
  this->xpBonus = input->readVarUhInt();
  if(this->xpBonus < 0)
  {
    qDebug()<<"ERREUR - ChallengeInformation -"<<"Forbidden value (" << this->xpBonus << ") on element of ChallengeInformation.xpBonus.";
  }
}

void ChallengeInformation::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - ChallengeInformation -"<<"Forbidden value (" << this->state << ") on element of ChallengeInformation.state.";
  }
}

ChallengeInformation::ChallengeInformation()
{
  m_types<<ClassEnum::CHALLENGEINFORMATION;
}

bool ChallengeInformation::operator==(const ChallengeInformation &compared)
{
  if(challengeId == compared.challengeId)
  if(targetsList == compared.targetsList)
  if(dropBonus == compared.dropBonus)
  if(xpBonus == compared.xpBonus)
  if(state == compared.state)
  if(_targetsListtree == compared._targetsListtree)
  return true;
  
  return false;
}

