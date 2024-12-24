#include "ChallengeProposalMessage.h"

void ChallengeProposalMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeProposalMessage(output);
}

void ChallengeProposalMessage::serializeAs_ChallengeProposalMessage(Writer *output)
{
  output->writeShort((short)this->challengeProposals.size());
  for(uint _i1 = 0; _i1 < this->challengeProposals.size(); _i1++)
  {
    qSharedPointerCast<ChallengeInformation>(this->challengeProposals[_i1])->serializeAs_ChallengeInformation(output);
  }
  if(this->timer < 0 || this->timer > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChallengeProposalMessage -"<<"Forbidden value (" << this->timer << ") on element timer.";
  }
  output->writeDouble(this->timer);
}

void ChallengeProposalMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeProposalMessage(input);
}

void ChallengeProposalMessage::deserializeAs_ChallengeProposalMessage(Reader *input)
{
  QSharedPointer<ChallengeInformation> _item1 ;
  uint _challengeProposalsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _challengeProposalsLen; _i1++)
  {
    _item1 = QSharedPointer<ChallengeInformation>(new ChallengeInformation() );
    _item1->deserialize(input);
    this->challengeProposals.append(_item1);
  }
  this->_timerFunc(input);
}

void ChallengeProposalMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeProposalMessage(tree);
}

void ChallengeProposalMessage::deserializeAsyncAs_ChallengeProposalMessage(FuncTree tree)
{
  this->_challengeProposalstree = tree.addChild(std::bind(&ChallengeProposalMessage::_challengeProposalstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeProposalMessage::_timerFunc, this, std::placeholders::_1));
}

void ChallengeProposalMessage::_challengeProposalstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_challengeProposalstree.addChild(std::bind(&ChallengeProposalMessage::_challengeProposalsFunc, this, std::placeholders::_1));
  }
}

void ChallengeProposalMessage::_challengeProposalsFunc(Reader *input)
{
  QSharedPointer<ChallengeInformation> _item = QSharedPointer<ChallengeInformation>(new ChallengeInformation() );
  _item->deserialize(input);
  this->challengeProposals.append(_item);
}

void ChallengeProposalMessage::_timerFunc(Reader *input)
{
  this->timer = input->readDouble();
  if(this->timer < 0 || this->timer > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChallengeProposalMessage -"<<"Forbidden value (" << this->timer << ") on element of ChallengeProposalMessage.timer.";
  }
}

ChallengeProposalMessage::ChallengeProposalMessage()
{
  m_type = MessageEnum::CHALLENGEPROPOSALMESSAGE;
}

