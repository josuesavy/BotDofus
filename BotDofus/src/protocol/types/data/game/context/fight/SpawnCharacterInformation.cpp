#include "SpawnCharacterInformation.h"

void SpawnCharacterInformation::serialize(Writer *output)
{
  this->serializeAs_SpawnCharacterInformation(output);
}

void SpawnCharacterInformation::serializeAs_SpawnCharacterInformation(Writer *output)
{
  SpawnInformation::serializeAs_SpawnInformation(output);
  output->writeUTF(this->name);
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - SpawnCharacterInformation -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
}

void SpawnCharacterInformation::deserialize(Reader *input)
{
  this->deserializeAs_SpawnCharacterInformation(input);
}

void SpawnCharacterInformation::deserializeAs_SpawnCharacterInformation(Reader *input)
{
  SpawnInformation::deserialize(input);
  this->_nameFunc(input);
  this->_levelFunc(input);
}

void SpawnCharacterInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpawnCharacterInformation(tree);
}

void SpawnCharacterInformation::deserializeAsyncAs_SpawnCharacterInformation(FuncTree tree)
{
  SpawnInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&SpawnCharacterInformation::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SpawnCharacterInformation::_levelFunc, this, std::placeholders::_1));
}

void SpawnCharacterInformation::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void SpawnCharacterInformation::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - SpawnCharacterInformation -"<<"Forbidden value (" << this->level << ") on element of SpawnCharacterInformation.level.";
  }
}

SpawnCharacterInformation::SpawnCharacterInformation()
{
  m_types<<ClassEnum::SPAWNCHARACTERINFORMATION;
}

bool SpawnCharacterInformation::operator==(const SpawnCharacterInformation &compared)
{
  if(name == compared.name)
  if(level == compared.level)
  return true;
  
  return false;
}

