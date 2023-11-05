#include "ChallengeInfoMessage.h"

void ChallengeInfoMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeInfoMessage(output);
}

void ChallengeInfoMessage::serializeAs_ChallengeInfoMessage(Writer *output)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  output->writeVarShort((int)this->challengeId);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->xpBonus < 0)
  {
    qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->xpBonus << ") on element xpBonus.";
  }
  output->writeVarInt((int)this->xpBonus);
  if(this->dropBonus < 0)
  {
    qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->dropBonus << ") on element dropBonus.";
  }
  output->writeVarInt((int)this->dropBonus);
}

void ChallengeInfoMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeInfoMessage(input);
}

void ChallengeInfoMessage::deserializeAs_ChallengeInfoMessage(Reader *input)
{
  this->_challengeIdFunc(input);
  this->_targetIdFunc(input);
  this->_xpBonusFunc(input);
  this->_dropBonusFunc(input);
}

void ChallengeInfoMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeInfoMessage(tree);
}

void ChallengeInfoMessage::deserializeAsyncAs_ChallengeInfoMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeInfoMessage::_challengeIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeInfoMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeInfoMessage::_xpBonusFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeInfoMessage::_dropBonusFunc, this, std::placeholders::_1));
}

void ChallengeInfoMessage::_challengeIdFunc(Reader *input)
{
  this->challengeId = input->readVarUhShort();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeInfoMessage.challengeId.";
  }
}

void ChallengeInfoMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->targetId << ") on element of ChallengeInfoMessage.targetId.";
  }
}

void ChallengeInfoMessage::_xpBonusFunc(Reader *input)
{
  this->xpBonus = input->readVarUhInt();
  if(this->xpBonus < 0)
  {
    qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->xpBonus << ") on element of ChallengeInfoMessage.xpBonus.";
  }
}

void ChallengeInfoMessage::_dropBonusFunc(Reader *input)
{
  this->dropBonus = input->readVarUhInt();
  if(this->dropBonus < 0)
  {
    qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->dropBonus << ") on element of ChallengeInfoMessage.dropBonus.";
  }
}

ChallengeInfoMessage::ChallengeInfoMessage()
{
  m_type = MessageEnum::CHALLENGEINFOMESSAGE;
}

