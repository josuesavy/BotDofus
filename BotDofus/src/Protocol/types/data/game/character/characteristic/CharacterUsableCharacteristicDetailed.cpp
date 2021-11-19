#include "CharacterUsableCharacteristicDetailed.h"

void CharacterUsableCharacteristicDetailed::serialize(Writer *output)
{
  this->serializeAs_CharacterUsableCharacteristicDetailed(output);
}

void CharacterUsableCharacteristicDetailed::serializeAs_CharacterUsableCharacteristicDetailed(Writer *output)
{
  CharacterCharacteristicDetailed::serializeAs_CharacterCharacteristicDetailed(output);
  if(this->used < 0)
  {
    qDebug()<<"ERREUR - CharacterUsableCharacteristicDetailed -"<<"Forbidden value (" << this->used << ") on element used.";
  }
  output->writeVarShort((int)this->used);
}

void CharacterUsableCharacteristicDetailed::deserialize(Reader *input)
{
  this->deserializeAs_CharacterUsableCharacteristicDetailed(input);
}

void CharacterUsableCharacteristicDetailed::deserializeAs_CharacterUsableCharacteristicDetailed(Reader *input)
{
  CharacterCharacteristicDetailed::deserialize(input);
  this->_usedFunc(input);
}

void CharacterUsableCharacteristicDetailed::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterUsableCharacteristicDetailed(tree);
}

void CharacterUsableCharacteristicDetailed::deserializeAsyncAs_CharacterUsableCharacteristicDetailed(FuncTree tree)
{
  CharacterCharacteristicDetailed::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterUsableCharacteristicDetailed::_usedFunc, this, std::placeholders::_1));
}

void CharacterUsableCharacteristicDetailed::_usedFunc(Reader *input)
{
  this->used = input->readVarUhShort();
  if(this->used < 0)
  {
    qDebug()<<"ERREUR - CharacterUsableCharacteristicDetailed -"<<"Forbidden value (" << this->used << ") on element of CharacterUsableCharacteristicDetailed.used.";
  }
}

CharacterUsableCharacteristicDetailed::CharacterUsableCharacteristicDetailed()
{
  m_types<<ClassEnum::CHARACTERUSABLECHARACTERISTICDETAILED;
}

bool CharacterUsableCharacteristicDetailed::operator==(const CharacterUsableCharacteristicDetailed &compared)
{
  if(used == compared.used)
  return true;
  
  return false;
}

