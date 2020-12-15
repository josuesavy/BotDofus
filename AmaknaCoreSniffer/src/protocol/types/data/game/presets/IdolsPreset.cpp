#include "IdolsPreset.h"

void IdolsPreset::serialize(Writer *output)
{
  this->serializeAs_IdolsPreset(output);
}

void IdolsPreset::serializeAs_IdolsPreset(Writer *output)
{
  Preset::serializeAs_Preset(output);
  if(this->iconId < 0)
  {
    qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << this->iconId << ") on element iconId.";
  }
  output->writeShort((short)this->iconId);
  output->writeShort((short)this->idolIds.size());
  for(uint _i2 = 0; _i2 < this->idolIds.size(); _i2++)
  {
    if(this->idolIds[_i2] < 0)
    {
      qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << this->idolIds[_i2] << ") on element 2 (starting at 1) of idolIds.";
    }
    output->writeVarShort((int)this->idolIds[_i2]);
  }
}

void IdolsPreset::deserialize(Reader *input)
{
  this->deserializeAs_IdolsPreset(input);
}

void IdolsPreset::deserializeAs_IdolsPreset(Reader *input)
{
  uint _val2 = 0;
  Preset::deserialize(input);
  this->_iconIdFunc(input);
  uint _idolIdsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _idolIdsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << _val2 << ") on elements of idolIds.";
    }
    this->idolIds.append(_val2);
  }
}

void IdolsPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdolsPreset(tree);
}

void IdolsPreset::deserializeAsyncAs_IdolsPreset(FuncTree tree)
{
  Preset::deserializeAsync(tree);
  tree.addChild(std::bind(&IdolsPreset::_iconIdFunc, this, std::placeholders::_1));
  this->_idolIdstree = tree.addChild(std::bind(&IdolsPreset::_idolIdstreeFunc, this, std::placeholders::_1));
}

void IdolsPreset::_iconIdFunc(Reader *input)
{
  this->iconId = input->readShort();
  if(this->iconId < 0)
  {
    qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << this->iconId << ") on element of IdolsPreset.iconId.";
  }
}

void IdolsPreset::_idolIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_idolIdstree.addChild(std::bind(&IdolsPreset::_idolIdsFunc, this, std::placeholders::_1));
  }
}

void IdolsPreset::_idolIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << _val << ") on elements of idolIds.";
  }
  this->idolIds.append(_val);
}

IdolsPreset::IdolsPreset()
{
  m_types<<ClassEnum::IDOLSPRESET;
}

bool IdolsPreset::operator==(const IdolsPreset &compared)
{
  if(iconId == compared.iconId)
  if(idolIds == compared.idolIds)
  if(_idolIdstree == compared._idolIdstree)
  return true;
  
  return false;
}

