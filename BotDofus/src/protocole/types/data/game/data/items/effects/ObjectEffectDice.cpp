#include "ObjectEffectDice.h"

void ObjectEffectDice::serialize(Writer *output)
{
  this->serializeAs_ObjectEffectDice(output);
}

void ObjectEffectDice::serializeAs_ObjectEffectDice(Writer *output)
{
  ObjectEffect::serializeAs_ObjectEffect(output);
  if(this->diceNum < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceNum << ") on element diceNum.";
  }
  output->writeVarInt((int)this->diceNum);
  if(this->diceSide < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceSide << ") on element diceSide.";
  }
  output->writeVarInt((int)this->diceSide);
  if(this->diceConst < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceConst << ") on element diceConst.";
  }
  output->writeVarInt((int)this->diceConst);
}

void ObjectEffectDice::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffectDice(input);
}

void ObjectEffectDice::deserializeAs_ObjectEffectDice(Reader *input)
{
  ObjectEffect::deserialize(input);
  this->_diceNumFunc(input);
  this->_diceSideFunc(input);
  this->_diceConstFunc(input);
}

void ObjectEffectDice::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffectDice(tree);
}

void ObjectEffectDice::deserializeAsyncAs_ObjectEffectDice(FuncTree tree)
{
  ObjectEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectEffectDice::_diceNumFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectDice::_diceSideFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectDice::_diceConstFunc, this, std::placeholders::_1));
}

void ObjectEffectDice::_diceNumFunc(Reader *input)
{
  this->diceNum = input->readVarUhInt();
  if(this->diceNum < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceNum << ") on element of ObjectEffectDice.diceNum.";
  }
}

void ObjectEffectDice::_diceSideFunc(Reader *input)
{
  this->diceSide = input->readVarUhInt();
  if(this->diceSide < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceSide << ") on element of ObjectEffectDice.diceSide.";
  }
}

void ObjectEffectDice::_diceConstFunc(Reader *input)
{
  this->diceConst = input->readVarUhInt();
  if(this->diceConst < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceConst << ") on element of ObjectEffectDice.diceConst.";
  }
}

ObjectEffectDice::ObjectEffectDice()
{
  m_types<<ClassEnum::OBJECTEFFECTDICE;
}

bool ObjectEffectDice::operator==(const ObjectEffectDice &compared)
{
  if(diceNum == compared.diceNum)
  if(diceSide == compared.diceSide)
  if(diceConst == compared.diceConst)
  return true;
  
  return false;
}

