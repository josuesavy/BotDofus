#include "SpellForPreset.h"

void SpellForPreset::serialize(Writer *output)
{
  this->serializeAs_SpellForPreset(output);
}

void SpellForPreset::serializeAs_SpellForPreset(Writer *output)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellForPreset -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
  output->writeShort((short)this->shortcuts.size());
  for(uint _i2 = 0; _i2 < this->shortcuts.size(); _i2++)
  {
    output->writeShort((short)this->shortcuts[_i2]);
  }
}

void SpellForPreset::deserialize(Reader *input)
{
  this->deserializeAs_SpellForPreset(input);
}

void SpellForPreset::deserializeAs_SpellForPreset(Reader *input)
{
  auto _val2 = 0;
  this->_spellIdFunc(input);
  uint _shortcutsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _shortcutsLen; _i2++)
  {
    _val2 = input->readShort();
    this->shortcuts.append(_val2);
  }
}

void SpellForPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpellForPreset(tree);
}

void SpellForPreset::deserializeAsyncAs_SpellForPreset(FuncTree tree)
{
  tree.addChild(std::bind(&SpellForPreset::_spellIdFunc, this, std::placeholders::_1));
  this->_shortcutstree = tree.addChild(std::bind(&SpellForPreset::_shortcutstreeFunc, this, std::placeholders::_1));
}

void SpellForPreset::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellForPreset -"<<"Forbidden value (" << this->spellId << ") on element of SpellForPreset.spellId.";
  }
}

void SpellForPreset::_shortcutstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_shortcutstree.addChild(std::bind(&SpellForPreset::_shortcutsFunc, this, std::placeholders::_1));
  }
}

void SpellForPreset::_shortcutsFunc(Reader *input)
{
  int _val = input->readShort();
  this->shortcuts.append(_val);
}

SpellForPreset::SpellForPreset()
{
  m_types<<ClassEnum::SPELLFORPRESET;
}

bool SpellForPreset::operator==(const SpellForPreset &compared)
{
  if(spellId == compared.spellId)
  if(shortcuts == compared.shortcuts)
  if(_shortcutstree == compared._shortcutstree)
  return true;
  
  return false;
}

