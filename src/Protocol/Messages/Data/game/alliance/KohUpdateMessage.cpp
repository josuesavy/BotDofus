#include "KohUpdateMessage.h"

void KohUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_KohUpdateMessage(output);
}

void KohUpdateMessage::serializeAs_KohUpdateMessage(Writer *output)
{
  output->writeShort((short)this->alliances.size());
  for(uint _i1 = 0; _i1 < this->alliances.size(); _i1++)
  {
    qSharedPointerCast<AllianceInformations>(this->alliances[_i1])->serializeAs_AllianceInformations(output);
  }
  output->writeShort((short)this->allianceNbMembers.size());
  for(uint _i2 = 0; _i2 < this->allianceNbMembers.size(); _i2++)
  {
    if(this->allianceNbMembers[_i2] < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceNbMembers[_i2] << ") on element 2 (starting at 1) of allianceNbMembers.";
    }
    output->writeVarShort((int)this->allianceNbMembers[_i2]);
  }
  output->writeShort((short)this->allianceRoundWeigth.size());
  for(uint _i3 = 0; _i3 < this->allianceRoundWeigth.size(); _i3++)
  {
    if(this->allianceRoundWeigth[_i3] < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceRoundWeigth[_i3] << ") on element 3 (starting at 1) of allianceRoundWeigth.";
    }
    output->writeVarInt((int)this->allianceRoundWeigth[_i3]);
  }
  output->writeShort((short)this->allianceMatchScore.size());
  for(uint _i4 = 0; _i4 < this->allianceMatchScore.size(); _i4++)
  {
    if(this->allianceMatchScore[_i4] < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceMatchScore[_i4] << ") on element 4 (starting at 1) of allianceMatchScore.";
    }
    output->writeByte(this->allianceMatchScore[_i4]);
  }
  output->writeShort((short)this->allianceMapWinners.size());
  for(uint _i5 = 0; _i5 < this->allianceMapWinners.size(); _i5++)
  {
    qSharedPointerCast<BasicAllianceInformations>(this->allianceMapWinners[_i5])->serializeAs_BasicAllianceInformations(output);
  }
  if(this->allianceMapWinnerScore < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceMapWinnerScore << ") on element allianceMapWinnerScore.";
  }
  output->writeVarInt((int)this->allianceMapWinnerScore);
  if(this->allianceMapMyAllianceScore < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceMapMyAllianceScore << ") on element allianceMapMyAllianceScore.";
  }
  output->writeVarInt((int)this->allianceMapMyAllianceScore);
  if(this->nextTickTime < 0 || this->nextTickTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->nextTickTime << ") on element nextTickTime.";
  }
  output->writeDouble(this->nextTickTime);
}

void KohUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_KohUpdateMessage(input);
}

void KohUpdateMessage::deserializeAs_KohUpdateMessage(Reader *input)
{
  QSharedPointer<AllianceInformations> _item1 ;
  uint _val2 = 0;
  uint _val3 = 0;
  uint _val4 = 0;
  QSharedPointer<BasicAllianceInformations> _item5 ;
  uint _alliancesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _alliancesLen; _i1++)
  {
    _item1 = QSharedPointer<AllianceInformations>(new AllianceInformations() );
    _item1->deserialize(input);
    this->alliances.append(_item1);
  }
  uint _allianceNbMembersLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _allianceNbMembersLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << _val2 << ") on elements of allianceNbMembers.";
    }
    this->allianceNbMembers.append(_val2);
  }
  uint _allianceRoundWeigthLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _allianceRoundWeigthLen; _i3++)
  {
    _val3 = input->readVarUhInt();
    if(_val3 < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << _val3 << ") on elements of allianceRoundWeigth.";
    }
    this->allianceRoundWeigth.append(_val3);
  }
  uint _allianceMatchScoreLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _allianceMatchScoreLen; _i4++)
  {
    _val4 = input->readByte();
    if(_val4 < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << _val4 << ") on elements of allianceMatchScore.";
    }
    this->allianceMatchScore.append(_val4);
  }
  uint _allianceMapWinnersLen = input->readUShort();
  for(uint _i5 = 0; _i5 < _allianceMapWinnersLen; _i5++)
  {
    _item5 = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
    _item5->deserialize(input);
    this->allianceMapWinners.append(_item5);
  }
  this->_allianceMapWinnerScoreFunc(input);
  this->_allianceMapMyAllianceScoreFunc(input);
  this->_nextTickTimeFunc(input);
}

void KohUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_KohUpdateMessage(tree);
}

void KohUpdateMessage::deserializeAsyncAs_KohUpdateMessage(FuncTree tree)
{
  this->_alliancestree = tree.addChild(std::bind(&KohUpdateMessage::_alliancestreeFunc, this, std::placeholders::_1));
  this->_allianceNbMemberstree = tree.addChild(std::bind(&KohUpdateMessage::_allianceNbMemberstreeFunc, this, std::placeholders::_1));
  this->_allianceRoundWeigthtree = tree.addChild(std::bind(&KohUpdateMessage::_allianceRoundWeigthtreeFunc, this, std::placeholders::_1));
  this->_allianceMatchScoretree = tree.addChild(std::bind(&KohUpdateMessage::_allianceMatchScoretreeFunc, this, std::placeholders::_1));
  this->_allianceMapWinnerstree = tree.addChild(std::bind(&KohUpdateMessage::_allianceMapWinnerstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&KohUpdateMessage::_allianceMapWinnerScoreFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&KohUpdateMessage::_allianceMapMyAllianceScoreFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&KohUpdateMessage::_nextTickTimeFunc, this, std::placeholders::_1));
}

void KohUpdateMessage::_alliancestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_alliancestree.addChild(std::bind(&KohUpdateMessage::_alliancesFunc, this, std::placeholders::_1));
  }
}

void KohUpdateMessage::_alliancesFunc(Reader *input)
{
  QSharedPointer<AllianceInformations> _item = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  _item->deserialize(input);
  this->alliances.append(_item);
}

void KohUpdateMessage::_allianceNbMemberstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_allianceNbMemberstree.addChild(std::bind(&KohUpdateMessage::_allianceNbMembersFunc, this, std::placeholders::_1));
  }
}

void KohUpdateMessage::_allianceNbMembersFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << _val << ") on elements of allianceNbMembers.";
  }
  this->allianceNbMembers.append(_val);
}

void KohUpdateMessage::_allianceRoundWeigthtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_allianceRoundWeigthtree.addChild(std::bind(&KohUpdateMessage::_allianceRoundWeigthFunc, this, std::placeholders::_1));
  }
}

void KohUpdateMessage::_allianceRoundWeigthFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << _val << ") on elements of allianceRoundWeigth.";
  }
  this->allianceRoundWeigth.append(_val);
}

void KohUpdateMessage::_allianceMatchScoretreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_allianceMatchScoretree.addChild(std::bind(&KohUpdateMessage::_allianceMatchScoreFunc, this, std::placeholders::_1));
  }
}

void KohUpdateMessage::_allianceMatchScoreFunc(Reader *input)
{
  uint _val = input->readByte();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << _val << ") on elements of allianceMatchScore.";
  }
  this->allianceMatchScore.append(_val);
}

void KohUpdateMessage::_allianceMapWinnerstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_allianceMapWinnerstree.addChild(std::bind(&KohUpdateMessage::_allianceMapWinnersFunc, this, std::placeholders::_1));
  }
}

void KohUpdateMessage::_allianceMapWinnersFunc(Reader *input)
{
  QSharedPointer<BasicAllianceInformations> _item = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  _item->deserialize(input);
  this->allianceMapWinners.append(_item);
}

void KohUpdateMessage::_allianceMapWinnerScoreFunc(Reader *input)
{
  this->allianceMapWinnerScore = input->readVarUhInt();
  if(this->allianceMapWinnerScore < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceMapWinnerScore << ") on element of KohUpdateMessage.allianceMapWinnerScore.";
  }
}

void KohUpdateMessage::_allianceMapMyAllianceScoreFunc(Reader *input)
{
  this->allianceMapMyAllianceScore = input->readVarUhInt();
  if(this->allianceMapMyAllianceScore < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceMapMyAllianceScore << ") on element of KohUpdateMessage.allianceMapMyAllianceScore.";
  }
}

void KohUpdateMessage::_nextTickTimeFunc(Reader *input)
{
  this->nextTickTime = input->readDouble();
  if(this->nextTickTime < 0 || this->nextTickTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->nextTickTime << ") on element of KohUpdateMessage.nextTickTime.";
  }
}

KohUpdateMessage::KohUpdateMessage()
{
  m_type = MessageEnum::KOHUPDATEMESSAGE;
}

