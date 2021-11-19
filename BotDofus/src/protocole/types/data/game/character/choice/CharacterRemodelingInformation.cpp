#include "CharacterRemodelingInformation.h"

void CharacterRemodelingInformation::serialize(Writer *output)
{
  this->serializeAs_CharacterRemodelingInformation(output);
}

void CharacterRemodelingInformation::serializeAs_CharacterRemodelingInformation(Writer *output)
{
  AbstractCharacterInformation::serializeAs_AbstractCharacterInformation(output);
  output->writeUTF(this->name);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - CharacterRemodelingInformation -"<<"Forbidden value (" << this->cosmeticId << ") on element cosmeticId.";
  }
  output->writeVarShort((int)this->cosmeticId);
  output->writeShort((short)this->colors.size());
  for(uint _i5 = 0; _i5 < this->colors.size(); _i5++)
  {
    output->writeInt((int)this->colors[_i5]);
  }
}

void CharacterRemodelingInformation::deserialize(Reader *input)
{
  this->deserializeAs_CharacterRemodelingInformation(input);
}

void CharacterRemodelingInformation::deserializeAs_CharacterRemodelingInformation(Reader *input)
{
  auto _val5 = 0;
  AbstractCharacterInformation::deserialize(input);
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

void CharacterRemodelingInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterRemodelingInformation(tree);
}

void CharacterRemodelingInformation::deserializeAsyncAs_CharacterRemodelingInformation(FuncTree tree)
{
  AbstractCharacterInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterRemodelingInformation::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterRemodelingInformation::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterRemodelingInformation::_sexFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterRemodelingInformation::_cosmeticIdFunc, this, std::placeholders::_1));
  this->_colorstree = tree.addChild(std::bind(&CharacterRemodelingInformation::_colorstreeFunc, this, std::placeholders::_1));
}

void CharacterRemodelingInformation::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void CharacterRemodelingInformation::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
}

void CharacterRemodelingInformation::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void CharacterRemodelingInformation::_cosmeticIdFunc(Reader *input)
{
  this->cosmeticId = input->readVarUhShort();
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - CharacterRemodelingInformation -"<<"Forbidden value (" << this->cosmeticId << ") on element of CharacterRemodelingInformation.cosmeticId.";
  }
}

void CharacterRemodelingInformation::_colorstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_colorstree.addChild(std::bind(&CharacterRemodelingInformation::_colorsFunc, this, std::placeholders::_1));
  }
}

void CharacterRemodelingInformation::_colorsFunc(Reader *input)
{
  int _val = input->readInt();
  this->colors.append(_val);
}

CharacterRemodelingInformation::CharacterRemodelingInformation()
{
  m_types<<ClassEnum::CHARACTERREMODELINGINFORMATION;
}

bool CharacterRemodelingInformation::operator==(const CharacterRemodelingInformation &compared)
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

