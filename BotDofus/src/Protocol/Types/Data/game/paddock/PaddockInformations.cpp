#include "PaddockInformations.h"

void PaddockInformations::serialize(Writer *output)
{
  this->serializeAs_PaddockInformations(output);
}

void PaddockInformations::serializeAs_PaddockInformations(Writer *output)
{
  if(this->maxOutdoorMount < 0)
  {
    qDebug()<<"ERREUR - PaddockInformations -"<<"Forbidden value (" << this->maxOutdoorMount << ") on element maxOutdoorMount.";
  }
  output->writeVarShort((int)this->maxOutdoorMount);
  if(this->maxItems < 0)
  {
    qDebug()<<"ERREUR - PaddockInformations -"<<"Forbidden value (" << this->maxItems << ") on element maxItems.";
  }
  output->writeVarShort((int)this->maxItems);
}

void PaddockInformations::deserialize(Reader *input)
{
  this->deserializeAs_PaddockInformations(input);
}

void PaddockInformations::deserializeAs_PaddockInformations(Reader *input)
{
  this->_maxOutdoorMountFunc(input);
  this->_maxItemsFunc(input);
}

void PaddockInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockInformations(tree);
}

void PaddockInformations::deserializeAsyncAs_PaddockInformations(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockInformations::_maxOutdoorMountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockInformations::_maxItemsFunc, this, std::placeholders::_1));
}

void PaddockInformations::_maxOutdoorMountFunc(Reader *input)
{
  this->maxOutdoorMount = input->readVarUhShort();
  if(this->maxOutdoorMount < 0)
  {
    qDebug()<<"ERREUR - PaddockInformations -"<<"Forbidden value (" << this->maxOutdoorMount << ") on element of PaddockInformations.maxOutdoorMount.";
  }
}

void PaddockInformations::_maxItemsFunc(Reader *input)
{
  this->maxItems = input->readVarUhShort();
  if(this->maxItems < 0)
  {
    qDebug()<<"ERREUR - PaddockInformations -"<<"Forbidden value (" << this->maxItems << ") on element of PaddockInformations.maxItems.";
  }
}

PaddockInformations::PaddockInformations()
{
  m_types<<ClassEnum::PADDOCKINFORMATIONS;
}

bool PaddockInformations::operator==(const PaddockInformations &compared)
{
  if(maxOutdoorMount == compared.maxOutdoorMount)
  if(maxItems == compared.maxItems)
  return true;
  
  return false;
}

