#include "StatsPreset.h"

void StatsPreset::serialize(Writer *output)
{
  this->serializeAs_StatsPreset(output);
}

void StatsPreset::serializeAs_StatsPreset(Writer *output)
{
  Preset::serializeAs_Preset(output);
  output->writeShort((short)this->stats.size());
  for(uint _i1 = 0; _i1 < this->stats.size(); _i1++)
  {
    (this->stats[_i1]).serializeAs_SimpleCharacterCharacteristicForPreset(output);
  }
}

void StatsPreset::deserialize(Reader *input)
{
  this->deserializeAs_StatsPreset(input);
}

void StatsPreset::deserializeAs_StatsPreset(Reader *input)
{
   _item1 ;
  Preset::deserialize(input);
  uint _statsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _statsLen; _i1++)
  {
    _item1 = new com.ankamagames.dofus.network.types.game.presets.SimpleCharacterCharacteristicForPreset();
    _item1.deserialize(input);
    this->stats.append(_item1);
  }
}

void StatsPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatsPreset(tree);
}

void StatsPreset::deserializeAsyncAs_StatsPreset(FuncTree tree)
{
  Preset::deserializeAsync(tree);
  this->_statstree = tree.addChild(std::bind(&StatsPreset::_statstreeFunc, this, std::placeholders::_1));
}

void StatsPreset::_statstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_statstree.addChild(std::bind(&StatsPreset::_statsFunc, this, std::placeholders::_1));
  }
}

void StatsPreset::_statsFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.presets.SimpleCharacterCharacteristicForPreset();
  _item.deserialize(input);
  this->stats.append(_item);
}

StatsPreset::StatsPreset()
{
  m_types<<ClassEnum::STATSPRESET;
}

bool StatsPreset::operator==(const StatsPreset &compared)
{
  if(stats == compared.stats)
  if(_statstree == compared._statstree)
  return true;
  
  return false;
}

