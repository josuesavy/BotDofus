#include "IconNamedPreset.h"

void IconNamedPreset::serialize(Writer *output)
{
  this->serializeAs_IconNamedPreset(output);
}

void IconNamedPreset::serializeAs_IconNamedPreset(Writer *output)
{
  PresetsContainerPreset::serializeAs_PresetsContainerPreset(output);
  if(this->iconId < 0)
  {
    qDebug()<<"ERREUR - IconNamedPreset -"<<"Forbidden value (" << this->iconId << ") on element iconId.";
  }
  output->writeShort((short)this->iconId);
  output->writeUTF(this->name);
}

void IconNamedPreset::deserialize(Reader *input)
{
  this->deserializeAs_IconNamedPreset(input);
}

void IconNamedPreset::deserializeAs_IconNamedPreset(Reader *input)
{
  PresetsContainerPreset::deserialize(input);
  this->_iconIdFunc(input);
  this->_nameFunc(input);
}

void IconNamedPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IconNamedPreset(tree);
}

void IconNamedPreset::deserializeAsyncAs_IconNamedPreset(FuncTree tree)
{
  PresetsContainerPreset::deserializeAsync(tree);
  tree.addChild(std::bind(&IconNamedPreset::_iconIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IconNamedPreset::_nameFunc, this, std::placeholders::_1));
}

void IconNamedPreset::_iconIdFunc(Reader *input)
{
  this->iconId = input->readShort();
  if(this->iconId < 0)
  {
    qDebug()<<"ERREUR - IconNamedPreset -"<<"Forbidden value (" << this->iconId << ") on element of IconNamedPreset.iconId.";
  }
}

void IconNamedPreset::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

IconNamedPreset::IconNamedPreset()
{
  m_types<<ClassEnum::ICONNAMEDPRESET;
}

bool IconNamedPreset::operator==(const IconNamedPreset &compared)
{
  if(iconId == compared.iconId)
  if(name == compared.name)
  return true;
  
  return false;
}

