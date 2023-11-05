#include "FightCommonInformations.h"

void FightCommonInformations::serialize(Writer *output)
{
  this->serializeAs_FightCommonInformations(output);
}

void FightCommonInformations::serializeAs_FightCommonInformations(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - FightCommonInformations -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeByte(this->fightType);
  output->writeShort((short)this->fightTeams.size());
  for(uint _i3 = 0; _i3 < this->fightTeams.size(); _i3++)
  {
    output->writeShort((short)(this->fightTeams[_i3]ascom.ankamagames.dofus.network.types.game.context.fight.FightTeamInformations).getTypeId());
    (this->fightTeams[_i3] as com.ankamagames.dofus.network.types.game.context.fight.FightTeamInformations).serialize(output);
  }
  output->writeShort((short)this->fightTeamsPositions.size());
  for(uint _i4 = 0; _i4 < this->fightTeamsPositions.size(); _i4++)
  {
    if(this->fightTeamsPositions[_i4] < 0 || this->fightTeamsPositions[_i4] > 559)
    {
      qDebug()<<"ERREUR - FightCommonInformations -"<<"Forbidden value (" << this->fightTeamsPositions[_i4] << ") on element 4 (starting at 1) of fightTeamsPositions.";
    }
    output->writeVarShort((int)this->fightTeamsPositions[_i4]);
  }
  output->writeShort((short)this->fightTeamsOptions.size());
  for(uint _i5 = 0; _i5 < this->fightTeamsOptions.size(); _i5++)
  {
    (this->fightTeamsOptions[_i5]).serializeAs_FightOptionsInformations(output);
  }
}

void FightCommonInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightCommonInformations(input);
}

void FightCommonInformations::deserializeAs_FightCommonInformations(Reader *input)
{
  uint _id3 = 0;
  com.ankamagames.dofus.network.types.game.context.fight.FightTeamInformations _item3 ;
  uint _val4 = 0;
   _item5 ;
  this->_fightIdFunc(input);
  this->_fightTypeFunc(input);
  uint _fightTeamsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _fightTeamsLen; _i3++)
  {
    _id3 = uint(input->readUShort());
    _item3 = qSharedPointerCast<>(ClassManagerSingleton::get()->getClass(_id3));
    _item3.deserialize(input);
    this->fightTeams.append(_item3);
  }
  uint _fightTeamsPositionsLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _fightTeamsPositionsLen; _i4++)
  {
    _val4 = input->readVarUhShort();
    if(_val4 < 0 || _val4 > 559)
    {
      qDebug()<<"ERREUR - FightCommonInformations -"<<"Forbidden value (" << _val4 << ") on elements of fightTeamsPositions.";
    }
    this->fightTeamsPositions.append(_val4);
  }
  uint _fightTeamsOptionsLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _fightTeamsOptionsLen; _i5++)
  {
    _item5 = new com.ankamagames.dofus.network.types.game.context.fight.FightOptionsInformations();
    _item5.deserialize(input);
    this->fightTeamsOptions.append(_item5);
  }
}

void FightCommonInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightCommonInformations(tree);
}

void FightCommonInformations::deserializeAsyncAs_FightCommonInformations(FuncTree tree)
{
  tree.addChild(std::bind(&FightCommonInformations::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightCommonInformations::_fightTypeFunc, this, std::placeholders::_1));
  this->_fightTeamstree = tree.addChild(std::bind(&FightCommonInformations::_fightTeamstreeFunc, this, std::placeholders::_1));
  this->_fightTeamsPositionstree = tree.addChild(std::bind(&FightCommonInformations::_fightTeamsPositionstreeFunc, this, std::placeholders::_1));
  this->_fightTeamsOptionstree = tree.addChild(std::bind(&FightCommonInformations::_fightTeamsOptionstreeFunc, this, std::placeholders::_1));
}

void FightCommonInformations::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - FightCommonInformations -"<<"Forbidden value (" << this->fightId << ") on element of FightCommonInformations.fightId.";
  }
}

void FightCommonInformations::_fightTypeFunc(Reader *input)
{
  this->fightType = input->readByte();
  if(this->fightType < 0)
  {
    qDebug()<<"ERREUR - FightCommonInformations -"<<"Forbidden value (" << this->fightType << ") on element of FightCommonInformations.fightType.";
  }
}

void FightCommonInformations::_fightTeamstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_fightTeamstree.addChild(std::bind(&FightCommonInformations::_fightTeamsFunc, this, std::placeholders::_1));
  }
}

void FightCommonInformations::_fightTeamsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
   _item = qSharedPointerCast<>(ClassManagerSingleton::get()->getClass(_id));
  _item.deserialize(input);
  this->fightTeams.append(_item);
}

void FightCommonInformations::_fightTeamsPositionstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_fightTeamsPositionstree.addChild(std::bind(&FightCommonInformations::_fightTeamsPositionsFunc, this, std::placeholders::_1));
  }
}

void FightCommonInformations::_fightTeamsPositionsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0 || _val > 559)
  {
    qDebug()<<"ERREUR - FightCommonInformations -"<<"Forbidden value (" << _val << ") on elements of fightTeamsPositions.";
  }
  this->fightTeamsPositions.append(_val);
}

void FightCommonInformations::_fightTeamsOptionstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_fightTeamsOptionstree.addChild(std::bind(&FightCommonInformations::_fightTeamsOptionsFunc, this, std::placeholders::_1));
  }
}

void FightCommonInformations::_fightTeamsOptionsFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.context.fight.FightOptionsInformations();
  _item.deserialize(input);
  this->fightTeamsOptions.append(_item);
}

FightCommonInformations::FightCommonInformations()
{
  m_types<<ClassEnum::FIGHTCOMMONINFORMATIONS;
}

bool FightCommonInformations::operator==(const FightCommonInformations &compared)
{
  if(fightId == compared.fightId)
  if(fightType == compared.fightType)
  if(fightTeams == compared.fightTeams)
  if(fightTeamsPositions == compared.fightTeamsPositions)
  if(fightTeamsOptions == compared.fightTeamsOptions)
  if(_fightTeamstree == compared._fightTeamstree)
  if(_fightTeamsPositionstree == compared._fightTeamsPositionstree)
  if(_fightTeamsOptionstree == compared._fightTeamsOptionstree)
  return true;
  
  return false;
}

