#include "Preset.h"

void Preset::serialize(Writer *output)
{
  this->serializeAs_Preset(output);
}

void Preset::serializeAs_Preset(Writer *output)
{
  output->writeShort((short)this->id);
}

void Preset::deserialize(Reader *input)
{
  this->deserializeAs_Preset(input);
}

void Preset::deserializeAs_Preset(Reader *input)
{
  this->_idFunc(input);
}

void Preset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_Preset(tree);
}

void Preset::deserializeAsyncAs_Preset(FuncTree tree)
{
  tree.addChild(std::bind(&Preset::_idFunc, this, std::placeholders::_1));
}

void Preset::_idFunc(Reader *input)
{
  this->id = input->readShort();
}

Preset::Preset()
{
  m_types<<ClassEnum::PRESET;
}

bool Preset::operator==(const Preset &compared)
{
  if(id == compared.id)
  return true;
  
  return false;
}

