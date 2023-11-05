#include "FightExternalInformations.h"

void FightExternalInformations::serialize(Writer *output)
{
  this->serializeAs_FightExternalInformations(output);
}

void FightExternalInformations::serializeAs_FightExternalInformations(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - FightExternalInformations -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeByte(this->fightType);
  if(this->fightStart < 0)
  {
    qDebug()<<"ERREUR - FightExternalInformations -"<<"Forbidden value (" << this->fightStart << ") on element fightStart.";
  }
  output->writeInt((int)this->fightStart);
  output->writeBool(this->fightSpectatorLocked);
  for(uint _i5 = 0; _i5 < 2; _i5++)
  {
    this->fightTeams[_i5].serializeAs_FightTeamLightInformations(output);
  }
  for(uint _i6 = 0; _i6 < 2; _i6++)
  {
    this->fightTeamsOptions[_i6].serializeAs_FightOptionsInformations(output);
  }
}

void FightExternalInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightExternalInformations(input);
}

void FightExternalInformations::deserializeAs_FightExternalInformations(Reader *input)
{
  this->_fightIdFunc(input);
  this->_fightTypeFunc(input);
  this->_fightStartFunc(input);
  this->_fightSpectatorLockedFunc(input);
  for(uint _i5 = 0; _i5 < 2; _i5++)
  {
    this->fightTeams<<new com.ankamagames.dofus.network.types.game.context.fight.FightTeamLightInformations();
    this->fightTeams[_i5].deserialize(input);
  }
  for(uint _i6 = 0; _i6 < 2; _i6++)
  {
    this->fightTeamsOptions<<new com.ankamagames.dofus.network.types.game.context.fight.FightOptionsInformations();
    this->fightTeamsOptions[_i6].deserialize(input);
  }
}

void FightExternalInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightExternalInformations(tree);
}

void FightExternalInformations::deserializeAsyncAs_FightExternalInformations(FuncTree tree)
{
  tree.addChild(std::bind(&FightExternalInformations::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightExternalInformations::_fightTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightExternalInformations::_fightStartFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightExternalInformations::_fightSpectatorLockedFunc, this, std::placeholders::_1));
  this->_fightTeamstree = tree.addChild(std::bind(&FightExternalInformations::_fightTeamstreeFunc, this, std::placeholders::_1));
  this->_fightTeamsOptionstree = tree.addChild(std::bind(&FightExternalInformations::_fightTeamsOptionstreeFunc, this, std::placeholders::_1));
}

void FightExternalInformations::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - FightExternalInformations -"<<"Forbidden value (" << this->fightId << ") on element of FightExternalInformations.fightId.";
  }
}

void FightExternalInformations::_fightTypeFunc(Reader *input)
{
  this->fightType = input->readByte();
  if(this->fightType < 0)
  {
    qDebug()<<"ERREUR - FightExternalInformations -"<<"Forbidden value (" << this->fightType << ") on element of FightExternalInformations.fightType.";
  }
}

void FightExternalInformations::_fightStartFunc(Reader *input)
{
  this->fightStart = input->readInt();
  if(this->fightStart < 0)
  {
    qDebug()<<"ERREUR - FightExternalInformations -"<<"Forbidden value (" << this->fightStart << ") on element of FightExternalInformations.fightStart.";
  }
}

void FightExternalInformations::_fightSpectatorLockedFunc(Reader *input)
{
  this->fightSpectatorLocked = input->readBool();
}

void FightExternalInformations::_fightTeamstreeFunc(Reader *input)
{
  for(uint i = 0; i < 2; i++)
  {
    this->_fightTeamstree.addChild(std::bind(&FightExternalInformations::_fightTeamsFunc, this, std::placeholders::_1));
  }
}

void FightExternalInformations::_fightTeamsFunc(Reader *input)
{
  this->fightTeams<<new com.ankamagames.dofus.network.types.game.context.fight.FightTeamLightInformations();
  this->fightTeams[this->_fightTeamsindex].deserializeAsync(this->_fightTeamstree.getChild(this->_fightTeamsindex));
  ++this->_fightTeamsindex;
}

void FightExternalInformations::_fightTeamsOptionstreeFunc(Reader *input)
{
  for(uint i = 0; i < 2; i++)
  {
    this->_fightTeamsOptionstree.addChild(std::bind(&FightExternalInformations::_fightTeamsOptionsFunc, this, std::placeholders::_1));
  }
}

void FightExternalInformations::_fightTeamsOptionsFunc(Reader *input)
{
  this->fightTeamsOptions<<new com.ankamagames.dofus.network.types.game.context.fight.FightOptionsInformations();
  this->fightTeamsOptions[this->_fightTeamsOptionsindex].deserializeAsync(this->_fightTeamsOptionstree.getChild(this->_fightTeamsOptionsindex));
  ++this->_fightTeamsOptionsindex;
}

FightExternalInformations::FightExternalInformations()
{
  m_types<<ClassEnum::FIGHTEXTERNALINFORMATIONS;
}

bool FightExternalInformations::operator==(const FightExternalInformations &compared)
{
  if(fightId == compared.fightId)
  if(fightType == compared.fightType)
  if(fightStart == compared.fightStart)
  if(fightSpectatorLocked == compared.fightSpectatorLocked)
  if(fightTeams == compared.fightTeams)
  if(fightTeamsOptions == compared.fightTeamsOptions)
  if(_fightTeamstree == compared._fightTeamstree)
  if(_fightTeamsindex == compared._fightTeamsindex)
  if(_fightTeamsOptionstree == compared._fightTeamsOptionstree)
  if(_fightTeamsOptionsindex == compared._fightTeamsOptionsindex)
  return true;
  
  return false;
}

