#include "SocialFight.h"

void SocialFight::serialize(Writer *output)
{
  this->serializeAs_SocialFight(output);
}

void SocialFight::serializeAs_SocialFight(Writer *output)
{
  this->socialFightInfo.serializeAs_SocialFightInfo(output);
  output->writeShort((short)this->attackers.size());
  for(uint _i2 = 0; _i2 < this->attackers.size(); _i2++)
  {
    (this->attackers[_i2]).serializeAs_CharacterMinimalPlusLookInformations(output);
  }
  output->writeShort((short)this->defenders.size());
  for(uint _i3 = 0; _i3 < this->defenders.size(); _i3++)
  {
    (this->defenders[_i3]).serializeAs_CharacterMinimalPlusLookInformations(output);
  }
  this->phase.serializeAs_FightPhase(output);
}

void SocialFight::deserialize(Reader *input)
{
  this->deserializeAs_SocialFight(input);
}

void SocialFight::deserializeAs_SocialFight(Reader *input)
{
  CharacterMinimalPlusLookInformations _item2 ;
  CharacterMinimalPlusLookInformations _item3 ;
  this->socialFightInfo = new com.ankamagames.dofus.network.types.game.social.fight.SocialFightInfo();
  this->socialFightInfo.deserialize(input);
  uint _attackersLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _attackersLen; _i2++)
  {
    _item2 = CharacterMinimalPlusLookInformations();
    _item2.deserialize(input);
    this->attackers.append(_item2);
  }
  uint _defendersLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _defendersLen; _i3++)
  {
    _item3 = CharacterMinimalPlusLookInformations();
    _item3.deserialize(input);
    this->defenders.append(_item3);
  }
  this->phase = FightPhase();
  this->phase.deserialize(input);
}

void SocialFight::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialFight(tree);
}

void SocialFight::deserializeAsyncAs_SocialFight(FuncTree tree)
{
  this->_socialFightInfotree = tree.addChild(std::bind(&SocialFight::_socialFightInfotreeFunc, this, std::placeholders::_1));
  this->_attackerstree = tree.addChild(std::bind(&SocialFight::_attackerstreeFunc, this, std::placeholders::_1));
  this->_defenderstree = tree.addChild(std::bind(&SocialFight::_defenderstreeFunc, this, std::placeholders::_1));
  this->_phasetree = tree.addChild(std::bind(&SocialFight::_phasetreeFunc, this, std::placeholders::_1));
}

void SocialFight::_socialFightInfotreeFunc(Reader *input)
{
  this->socialFightInfo = new com.ankamagames.dofus.network.types.game.social.fight.SocialFightInfo();
  this->socialFightInfo.deserializeAsync(this->_socialFightInfotree);
}

void SocialFight::_attackerstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_attackerstree.addChild(std::bind(&SocialFight::_attackersFunc, this, std::placeholders::_1));
  }
}

void SocialFight::_attackersFunc(Reader *input)
{
  CharacterMinimalPlusLookInformations _item = CharacterMinimalPlusLookInformations();
  _item.deserialize(input);
  this->attackers.append(_item);
}

void SocialFight::_defenderstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_defenderstree.addChild(std::bind(&SocialFight::_defendersFunc, this, std::placeholders::_1));
  }
}

void SocialFight::_defendersFunc(Reader *input)
{
  CharacterMinimalPlusLookInformations _item = CharacterMinimalPlusLookInformations();
  _item.deserialize(input);
  this->defenders.append(_item);
}

void SocialFight::_phasetreeFunc(Reader *input)
{
  this->phase = FightPhase();
  this->phase.deserializeAsync(this->_phasetree);
}

SocialFight::SocialFight()
{
  m_types<<ClassEnum::SOCIALFIGHT;
}

bool SocialFight::operator==(const SocialFight &compared)
{
  if(socialFightInfo == compared.socialFightInfo)
  if(attackers == compared.attackers)
  if(defenders == compared.defenders)
  if(phase == compared.phase)
  if(_socialFightInfotree == compared._socialFightInfotree)
  if(_attackerstree == compared._attackerstree)
  if(_defenderstree == compared._defenderstree)
  if(_phasetree == compared._phasetree)
  return true;
  
  return false;
}

