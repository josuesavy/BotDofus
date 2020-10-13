#include "PresetsContainerPreset.h"

void PresetsContainerPreset::serialize(Writer *output)
{
  this->serializeAs_PresetsContainerPreset(output);
}

void PresetsContainerPreset::serializeAs_PresetsContainerPreset(Writer *output)
{
  Preset::serializeAs_Preset(output);
  output->writeShort((short)this->presets.size());
  for(uint _i1 = 0; _i1 < this->presets.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<Preset>(this->presets[_i1])->getTypes().last());
    qSharedPointerCast<Preset>(this->presets[_i1])->serialize(output);
  }
}

void PresetsContainerPreset::deserialize(Reader *input)
{
  this->deserializeAs_PresetsContainerPreset(input);
}

void PresetsContainerPreset::deserializeAs_PresetsContainerPreset(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<Preset> _item1 ;
  Preset::deserialize(input);
  uint _presetsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _presetsLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<Preset>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->presets.append(_item1);
  }
}

void PresetsContainerPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PresetsContainerPreset(tree);
}

void PresetsContainerPreset::deserializeAsyncAs_PresetsContainerPreset(FuncTree tree)
{
  Preset::deserializeAsync(tree);
  this->_presetstree = tree.addChild(std::bind(&PresetsContainerPreset::_presetstreeFunc, this, std::placeholders::_1));
}

void PresetsContainerPreset::_presetstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_presetstree.addChild(std::bind(&PresetsContainerPreset::_presetsFunc, this, std::placeholders::_1));
  }
}

void PresetsContainerPreset::_presetsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<Preset> _item = qSharedPointerCast<Preset>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->presets.append(_item);
}

PresetsContainerPreset::PresetsContainerPreset()
{
  m_types<<ClassEnum::PRESETSCONTAINERPRESET;
}

bool PresetsContainerPreset::operator==(const PresetsContainerPreset &compared)
{
  if(presets == compared.presets)
  if(_presetstree == compared._presetstree)
  return true;
  
  return false;
}

