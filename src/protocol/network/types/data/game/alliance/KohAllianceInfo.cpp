#include "KohAllianceInfo.h"

void KohAllianceInfo::serialize(Writer *output)
{
  this->serializeAs_KohAllianceInfo(output);
}

void KohAllianceInfo::serializeAs_KohAllianceInfo(Writer *output)
{
  this->alliance->serializeAs_AllianceInformation(output);
  if(this->memberCount < 0 || this->memberCount > 9007199254740992)
  {
    qDebug()<<"ERREUR - KohAllianceInfo -"<<"Forbidden value (" << this->memberCount << ") on element memberCount.";
  }
  output->writeVarLong((double)this->memberCount);
  output->writeShort((short)this->kohAllianceRoleMembers.size());
  for(uint _i3 = 0; _i3 < this->kohAllianceRoleMembers.size(); _i3++)
  {
    (this->kohAllianceRoleMembers[_i3] as com.ankamagames.dofus.network.types.game.alliance.KohAllianceRoleMembers).serializeAs_KohAllianceRoleMembers(output);
  }
  output->writeShort((short)this->scores.size());
  for(uint _i4 = 0; _i4 < this->scores.size(); _i4++)
  {
    (this->scores[_i4] as com.ankamagames.dofus.network.types.game.alliance.KohScore).serializeAs_KohScore(output);
  }
  if(this->matchDominationScores < 0)
  {
    qDebug()<<"ERREUR - KohAllianceInfo -"<<"Forbidden value (" << this->matchDominationScores << ") on element matchDominationScores.";
  }
  output->writeVarInt((int)this->matchDominationScores);
}

void KohAllianceInfo::deserialize(Reader *input)
{
  this->deserializeAs_KohAllianceInfo(input);
}

void KohAllianceInfo::deserializeAs_KohAllianceInfo(Reader *input)
{
  com.ankamagames.dofus.network.types.game.alliance.KohAllianceRoleMembers _item3 ;
  com.ankamagames.dofus.network.types.game.alliance.KohScore _item4 ;
  this->alliance = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->alliance->deserialize(input);
  this->_memberCountFunc(input);
  uint _kohAllianceRoleMembersLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _kohAllianceRoleMembersLen; _i3++)
  {
    _item3 = new com.ankamagames.dofus.network.types.game.alliance.KohAllianceRoleMembers();
    _item3.deserialize(input);
    this->kohAllianceRoleMembers.append(_item3);
  }
  uint _scoresLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _scoresLen; _i4++)
  {
    _item4 = new com.ankamagames.dofus.network.types.game.alliance.KohScore();
    _item4.deserialize(input);
    this->scores.append(_item4);
  }
  this->_matchDominationScoresFunc(input);
}

void KohAllianceInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_KohAllianceInfo(tree);
}

void KohAllianceInfo::deserializeAsyncAs_KohAllianceInfo(FuncTree tree)
{
  this->_alliancetree = tree.addChild(std::bind(&KohAllianceInfo::_alliancetreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&KohAllianceInfo::_memberCountFunc, this, std::placeholders::_1));
  this->_kohAllianceRoleMemberstree = tree.addChild(std::bind(&KohAllianceInfo::_kohAllianceRoleMemberstreeFunc, this, std::placeholders::_1));
  this->_scorestree = tree.addChild(std::bind(&KohAllianceInfo::_scorestreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&KohAllianceInfo::_matchDominationScoresFunc, this, std::placeholders::_1));
}

void KohAllianceInfo::_alliancetreeFunc(Reader *input)
{
  this->alliance = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->alliance->deserializeAsync(this->_alliancetree);
}

void KohAllianceInfo::_memberCountFunc(Reader *input)
{
  this->memberCount = input->readVarUhLong();
  if(this->memberCount < 0 || this->memberCount > 9007199254740992)
  {
    qDebug()<<"ERREUR - KohAllianceInfo -"<<"Forbidden value (" << this->memberCount << ") on element of KohAllianceInfo.memberCount.";
  }
}

void KohAllianceInfo::_kohAllianceRoleMemberstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_kohAllianceRoleMemberstree.addChild(std::bind(&KohAllianceInfo::_kohAllianceRoleMembersFunc, this, std::placeholders::_1));
  }
}

void KohAllianceInfo::_kohAllianceRoleMembersFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.alliance.KohAllianceRoleMembers();
  _item.deserialize(input);
  this->kohAllianceRoleMembers.append(_item);
}

void KohAllianceInfo::_scorestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_scorestree.addChild(std::bind(&KohAllianceInfo::_scoresFunc, this, std::placeholders::_1));
  }
}

void KohAllianceInfo::_scoresFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.alliance.KohScore();
  _item.deserialize(input);
  this->scores.append(_item);
}

void KohAllianceInfo::_matchDominationScoresFunc(Reader *input)
{
  this->matchDominationScores = input->readVarUhInt();
  if(this->matchDominationScores < 0)
  {
    qDebug()<<"ERREUR - KohAllianceInfo -"<<"Forbidden value (" << this->matchDominationScores << ") on element of KohAllianceInfo.matchDominationScores.";
  }
}

KohAllianceInfo::KohAllianceInfo()
{
  m_types<<ClassEnum::KOHALLIANCEINFO;
}

bool KohAllianceInfo::operator==(const KohAllianceInfo &compared)
{
  if(alliance == compared.alliance)
  if(memberCount == compared.memberCount)
  if(kohAllianceRoleMembers == compared.kohAllianceRoleMembers)
  if(scores == compared.scores)
  if(matchDominationScores == compared.matchDominationScores)
  if(_alliancetree == compared._alliancetree)
  if(_kohAllianceRoleMemberstree == compared._kohAllianceRoleMemberstree)
  if(_scorestree == compared._scorestree)
  return true;
  
  return false;
}

