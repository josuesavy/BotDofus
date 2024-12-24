#include "ChallengeListMessage.h"

void ChallengeListMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeListMessage(output);
}

void ChallengeListMessage::serializeAs_ChallengeListMessage(Writer *output)
{
  output->writeShort((short)this->challengesInformation.size());
  for(uint _i1 = 0; _i1 < this->challengesInformation.size(); _i1++)
  {
    qSharedPointerCast<ChallengeInformation>(this->challengesInformation[_i1])->serializeAs_ChallengeInformation(output);
  }
}

void ChallengeListMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeListMessage(input);
}

void ChallengeListMessage::deserializeAs_ChallengeListMessage(Reader *input)
{
  QSharedPointer<ChallengeInformation> _item1 ;
  uint _challengesInformationLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _challengesInformationLen; _i1++)
  {
    _item1 = QSharedPointer<ChallengeInformation>(new ChallengeInformation() );
    _item1->deserialize(input);
    this->challengesInformation.append(_item1);
  }
}

void ChallengeListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeListMessage(tree);
}

void ChallengeListMessage::deserializeAsyncAs_ChallengeListMessage(FuncTree tree)
{
  this->_challengesInformationtree = tree.addChild(std::bind(&ChallengeListMessage::_challengesInformationtreeFunc, this, std::placeholders::_1));
}

void ChallengeListMessage::_challengesInformationtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_challengesInformationtree.addChild(std::bind(&ChallengeListMessage::_challengesInformationFunc, this, std::placeholders::_1));
  }
}

void ChallengeListMessage::_challengesInformationFunc(Reader *input)
{
  QSharedPointer<ChallengeInformation> _item = QSharedPointer<ChallengeInformation>(new ChallengeInformation() );
  _item->deserialize(input);
  this->challengesInformation.append(_item);
}

ChallengeListMessage::ChallengeListMessage()
{
  m_type = MessageEnum::CHALLENGELISTMESSAGE;
}

