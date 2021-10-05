#include "HumanOptionTitle.h"

void HumanOptionTitle::serialize(Writer *output)
{
  this->serializeAs_HumanOptionTitle(output);
}

void HumanOptionTitle::serializeAs_HumanOptionTitle(Writer *output)
{
  HumanOption::serializeAs_HumanOption(output);
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionTitle -"<<"Forbidden value (" << this->titleId << ") on element titleId.";
  }
  output->writeVarShort((int)this->titleId);
  output->writeUTF(this->titleParam);
}

void HumanOptionTitle::deserialize(Reader *input)
{
  this->deserializeAs_HumanOptionTitle(input);
}

void HumanOptionTitle::deserializeAs_HumanOptionTitle(Reader *input)
{
  HumanOption::deserialize(input);
  this->_titleIdFunc(input);
  this->_titleParamFunc(input);
}

void HumanOptionTitle::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanOptionTitle(tree);
}

void HumanOptionTitle::deserializeAsyncAs_HumanOptionTitle(FuncTree tree)
{
  HumanOption::deserializeAsync(tree);
  tree.addChild(std::bind(&HumanOptionTitle::_titleIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionTitle::_titleParamFunc, this, std::placeholders::_1));
}

void HumanOptionTitle::_titleIdFunc(Reader *input)
{
  this->titleId = input->readVarUhShort();
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionTitle -"<<"Forbidden value (" << this->titleId << ") on element of HumanOptionTitle.titleId.";
  }
}

void HumanOptionTitle::_titleParamFunc(Reader *input)
{
  this->titleParam = input->readUTF();
}

HumanOptionTitle::HumanOptionTitle()
{
  m_types<<ClassEnum::HUMANOPTIONTITLE;
}

bool HumanOptionTitle::operator==(const HumanOptionTitle &compared)
{
  if(titleId == compared.titleId)
  if(titleParam == compared.titleParam)
  return true;
  
  return false;
}

