#include "HumanOptionOrnament.h"

void HumanOptionOrnament::serialize(Writer *output)
{
  this->serializeAs_HumanOptionOrnament(output);
}

void HumanOptionOrnament::serializeAs_HumanOptionOrnament(Writer *output)
{
  HumanOption::serializeAs_HumanOption(output);
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionOrnament -"<<"Forbidden value (" << this->ornamentId << ") on element ornamentId.";
  }
  output->writeVarShort((int)this->ornamentId);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - HumanOptionOrnament -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  output->writeVarShort((int)this->leagueId);
  output->writeInt((int)this->ladderPosition);
}

void HumanOptionOrnament::deserialize(Reader *input)
{
  this->deserializeAs_HumanOptionOrnament(input);
}

void HumanOptionOrnament::deserializeAs_HumanOptionOrnament(Reader *input)
{
  HumanOption::deserialize(input);
  this->_ornamentIdFunc(input);
  this->_levelFunc(input);
  this->_leagueIdFunc(input);
  this->_ladderPositionFunc(input);
}

void HumanOptionOrnament::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanOptionOrnament(tree);
}

void HumanOptionOrnament::deserializeAsyncAs_HumanOptionOrnament(FuncTree tree)
{
  HumanOption::deserializeAsync(tree);
  tree.addChild(std::bind(&HumanOptionOrnament::_ornamentIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionOrnament::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionOrnament::_leagueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionOrnament::_ladderPositionFunc, this, std::placeholders::_1));
}

void HumanOptionOrnament::_ornamentIdFunc(Reader *input)
{
  this->ornamentId = input->readVarUhShort();
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionOrnament -"<<"Forbidden value (" << this->ornamentId << ") on element of HumanOptionOrnament.ornamentId.";
  }
}

void HumanOptionOrnament::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - HumanOptionOrnament -"<<"Forbidden value (" << this->level << ") on element of HumanOptionOrnament.level.";
  }
}

void HumanOptionOrnament::_leagueIdFunc(Reader *input)
{
  this->leagueId = input->readVarShort();
}

void HumanOptionOrnament::_ladderPositionFunc(Reader *input)
{
  this->ladderPosition = input->readInt();
}

HumanOptionOrnament::HumanOptionOrnament()
{
  m_types<<ClassEnum::HUMANOPTIONORNAMENT;
}

bool HumanOptionOrnament::operator==(const HumanOptionOrnament &compared)
{
  if(ornamentId == compared.ornamentId)
  if(level == compared.level)
  if(leagueId == compared.leagueId)
  if(ladderPosition == compared.ladderPosition)
  return true;
  
  return false;
}

