#include "FightTeamInformations.h"

void FightTeamInformations::serialize(Writer *output)
{
  this->serializeAs_FightTeamInformations(output);
}

void FightTeamInformations::serializeAs_FightTeamInformations(Writer *output)
{
  AbstractFightTeamInformations::serializeAs_AbstractFightTeamInformations(output);
  output->writeShort((short)this->teamMembers.size());
  for(uint _i1 = 0; _i1 < this->teamMembers.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<FightTeamMemberInformations>(this->teamMembers[_i1])->getTypes().last());
    qSharedPointerCast<FightTeamMemberInformations>(this->teamMembers[_i1])->serialize(output);
  }
}

void FightTeamInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightTeamInformations(input);
}

void FightTeamInformations::deserializeAs_FightTeamInformations(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<FightTeamMemberInformations> _item1 ;
  AbstractFightTeamInformations::deserialize(input);
  uint _teamMembersLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _teamMembersLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<FightTeamMemberInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->teamMembers.append(_item1);
  }
}

void FightTeamInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTeamInformations(tree);
}

void FightTeamInformations::deserializeAsyncAs_FightTeamInformations(FuncTree tree)
{
  AbstractFightTeamInformations::deserializeAsync(tree);
  this->_teamMemberstree = tree.addChild(std::bind(&FightTeamInformations::_teamMemberstreeFunc, this, std::placeholders::_1));
}

void FightTeamInformations::_teamMemberstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_teamMemberstree.addChild(std::bind(&FightTeamInformations::_teamMembersFunc, this, std::placeholders::_1));
  }
}

void FightTeamInformations::_teamMembersFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<FightTeamMemberInformations> _item = qSharedPointerCast<FightTeamMemberInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->teamMembers.append(_item);
}

FightTeamInformations::FightTeamInformations()
{
  m_types<<ClassEnum::FIGHTTEAMINFORMATIONS;
}

bool FightTeamInformations::operator==(const FightTeamInformations &compared)
{
  if(teamMembers == compared.teamMembers)
  if(_teamMemberstree == compared._teamMemberstree)
  return true;
  
  return false;
}

