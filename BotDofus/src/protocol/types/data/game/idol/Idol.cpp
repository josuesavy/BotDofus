#include "Idol.h"

void Idol::serialize(Writer *output)
{
  this->serializeAs_Idol(output);
}

void Idol::serializeAs_Idol(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarShort((int)this->id);
  if(this->xpBonusPercent < 0)
  {
    qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->xpBonusPercent << ") on element xpBonusPercent.";
  }
  output->writeVarShort((int)this->xpBonusPercent);
  if(this->dropBonusPercent < 0)
  {
    qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->dropBonusPercent << ") on element dropBonusPercent.";
  }
  output->writeVarShort((int)this->dropBonusPercent);
}

void Idol::deserialize(Reader *input)
{
  this->deserializeAs_Idol(input);
}

void Idol::deserializeAs_Idol(Reader *input)
{
  this->_idFunc(input);
  this->_xpBonusPercentFunc(input);
  this->_dropBonusPercentFunc(input);
}

void Idol::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_Idol(tree);
}

void Idol::deserializeAsyncAs_Idol(FuncTree tree)
{
  tree.addChild(std::bind(&Idol::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&Idol::_xpBonusPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&Idol::_dropBonusPercentFunc, this, std::placeholders::_1));
}

void Idol::_idFunc(Reader *input)
{
  this->id = input->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->id << ") on element of Idol.id.";
  }
}

void Idol::_xpBonusPercentFunc(Reader *input)
{
  this->xpBonusPercent = input->readVarUhShort();
  if(this->xpBonusPercent < 0)
  {
    qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->xpBonusPercent << ") on element of Idol.xpBonusPercent.";
  }
}

void Idol::_dropBonusPercentFunc(Reader *input)
{
  this->dropBonusPercent = input->readVarUhShort();
  if(this->dropBonusPercent < 0)
  {
    qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->dropBonusPercent << ") on element of Idol.dropBonusPercent.";
  }
}

Idol::Idol()
{
  m_types<<ClassEnum::IDOL;
}

bool Idol::operator==(const Idol &compared)
{
  if(id == compared.id)
  if(xpBonusPercent == compared.xpBonusPercent)
  if(dropBonusPercent == compared.dropBonusPercent)
  return true;
  
  return false;
}

