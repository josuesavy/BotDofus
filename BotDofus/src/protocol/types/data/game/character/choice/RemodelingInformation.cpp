#include "RemodelingInformation.h"

void RemodelingInformation::serialize(Writer *output)
{
  this->serializeAs_RemodelingInformation(output);
}

void RemodelingInformation::serializeAs_RemodelingInformation(Writer *output)
{
  output->writeUTF(this->name);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - RemodelingInformation -"<<"Forbidden value (" << this->cosmeticId << ") on element cosmeticId.";
  }
  output->writeVarShort((int)this->cosmeticId);
  output->writeShort((short)this->colors.size());
  for(uint _i5 = 0; _i5 < this->colors.size(); _i5++)
  {
    output->writeInt((int)this->colors[_i5]);
  }
}

void RemodelingInformation::deserialize(Reader *input)
{
  this->deserializeAs_RemodelingInformation(input);
}

void RemodelingInformation::deserializeAs_RemodelingInformation(Reader *input)
{
  auto _val5 = 0;
  this->_nameFunc(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
  this->_cosmeticIdFunc(input);
  uint _colorsLen = input->readUShort();
  for(uint _i5 = 0; _i5 < _colorsLen; _i5++)
  {
    _val5 = input->readInt();
    this->colors.append(_val5);
  }
}

void RemodelingInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RemodelingInformation(tree);
}

void RemodelingInformation::deserializeAsyncAs_RemodelingInformation(FuncTree tree)
{
  tree.addChild(std::bind(&RemodelingInformation::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RemodelingInformation::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RemodelingInformation::_sexFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RemodelingInformation::_cosmeticIdFunc, this, std::placeholders::_1));
  this->_colorstree = tree.addChild(std::bind(&RemodelingInformation::_colorstreeFunc, this, std::placeholders::_1));
}

void RemodelingInformation::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void RemodelingInformation::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
}

void RemodelingInformation::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void RemodelingInformation::_cosmeticIdFunc(Reader *input)
{
  this->cosmeticId = input->readVarUhShort();
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - RemodelingInformation -"<<"Forbidden value (" << this->cosmeticId << ") on element of RemodelingInformation.cosmeticId.";
  }
}

void RemodelingInformation::_colorstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_colorstree.addChild(std::bind(&RemodelingInformation::_colorsFunc, this, std::placeholders::_1));
  }
}

void RemodelingInformation::_colorsFunc(Reader *input)
{
  int _val = input->readInt();
  this->colors.append(_val);
}

RemodelingInformation::RemodelingInformation()
{
  m_types<<ClassEnum::REMODELINGINFORMATION;
}

bool RemodelingInformation::operator==(const RemodelingInformation &compared)
{
  if(name == compared.name)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(cosmeticId == compared.cosmeticId)
  if(colors == compared.colors)
  if(_colorstree == compared._colorstree)
  return true;
  
  return false;
}

