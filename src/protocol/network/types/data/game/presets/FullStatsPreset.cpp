#include "FullStatsPreset.h"

void FullStatsPreset::serialize(Writer *output)
{
  this->serializeAs_FullStatsPreset(output);
}

void FullStatsPreset::serializeAs_FullStatsPreset(Writer *output)
{
  Preset::serializeAs_Preset(output);
  output->writeShort((short)this->stats.size());
  for(uint _i1 = 0; _i1 < this->stats.size(); _i1++)
  {
    (this->stats[_i1]).serializeAs_CharacterCharacteristicForPreset(output);
  }
}

void FullStatsPreset::deserialize(Reader *input)
{
  this->deserializeAs_FullStatsPreset(input);
}

void FullStatsPreset::deserializeAs_FullStatsPreset(Reader *input)
{
  CharacterCharacteristicForPreset _item1 ;
  Preset::deserialize(input);
  uint _statsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _statsLen; _i1++)
  {
    _item1 = CharacterCharacteristicForPreset();
    _item1.deserialize(input);
    this->stats.append(_item1);
  }
}

void FullStatsPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FullStatsPreset(tree);
}

void FullStatsPreset::deserializeAsyncAs_FullStatsPreset(FuncTree tree)
{
  Preset::deserializeAsync(tree);
  this->_statstree = tree.addChild(std::bind(&FullStatsPreset::_statstreeFunc, this, std::placeholders::_1));
}

void FullStatsPreset::_statstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_statstree.addChild(std::bind(&FullStatsPreset::_statsFunc, this, std::placeholders::_1));
  }
}

void FullStatsPreset::_statsFunc(Reader *input)
{
  CharacterCharacteristicForPreset _item = CharacterCharacteristicForPreset();
  _item.deserialize(input);
  this->stats.append(_item);
}

FullStatsPreset::FullStatsPreset()
{
  m_types<<ClassEnum::FULLSTATSPRESET;
}

bool FullStatsPreset::operator==(const FullStatsPreset &compared)
{
  if(stats == compared.stats)
  if(_statstree == compared._statstree)
  return true;
  
  return false;
}

