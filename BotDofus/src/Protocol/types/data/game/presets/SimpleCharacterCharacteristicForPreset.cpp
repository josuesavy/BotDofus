#include "SimpleCharacterCharacteristicForPreset.h"

void SimpleCharacterCharacteristicForPreset::serialize(Writer *output)
{
  this->serializeAs_SimpleCharacterCharacteristicForPreset(output);
}

void SimpleCharacterCharacteristicForPreset::serializeAs_SimpleCharacterCharacteristicForPreset(Writer *output)
{
  output->writeUTF(this->keyword);
  output->writeVarShort((int)this->base);
  output->writeVarShort((int)this->additionnal);
}

void SimpleCharacterCharacteristicForPreset::deserialize(Reader *input)
{
  this->deserializeAs_SimpleCharacterCharacteristicForPreset(input);
}

void SimpleCharacterCharacteristicForPreset::deserializeAs_SimpleCharacterCharacteristicForPreset(Reader *input)
{
  this->_keywordFunc(input);
  this->_baseFunc(input);
  this->_additionnalFunc(input);
}

void SimpleCharacterCharacteristicForPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SimpleCharacterCharacteristicForPreset(tree);
}

void SimpleCharacterCharacteristicForPreset::deserializeAsyncAs_SimpleCharacterCharacteristicForPreset(FuncTree tree)
{
  tree.addChild(std::bind(&SimpleCharacterCharacteristicForPreset::_keywordFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SimpleCharacterCharacteristicForPreset::_baseFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SimpleCharacterCharacteristicForPreset::_additionnalFunc, this, std::placeholders::_1));
}

void SimpleCharacterCharacteristicForPreset::_keywordFunc(Reader *input)
{
  this->keyword = input->readUTF();
}

void SimpleCharacterCharacteristicForPreset::_baseFunc(Reader *input)
{
  this->base = input->readVarShort();
}

void SimpleCharacterCharacteristicForPreset::_additionnalFunc(Reader *input)
{
  this->additionnal = input->readVarShort();
}

SimpleCharacterCharacteristicForPreset::SimpleCharacterCharacteristicForPreset()
{
  m_types<<ClassEnum::SIMPLECHARACTERCHARACTERISTICFORPRESET;
}

bool SimpleCharacterCharacteristicForPreset::operator==(const SimpleCharacterCharacteristicForPreset &compared)
{
  if(keyword == compared.keyword)
  if(base == compared.base)
  if(additionnal == compared.additionnal)
  return true;
  
  return false;
}

