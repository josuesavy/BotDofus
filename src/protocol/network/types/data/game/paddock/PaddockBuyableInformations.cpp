#include "PaddockBuyableInformations.h"

void PaddockBuyableInformations::serialize(Writer *output)
{
  this->serializeAs_PaddockBuyableInformations(output);
}

void PaddockBuyableInformations::serializeAs_PaddockBuyableInformations(Writer *output)
{
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockBuyableInformations -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarLong((double)this->price);
  output->writeBool(this->locked);
}

void PaddockBuyableInformations::deserialize(Reader *input)
{
  this->deserializeAs_PaddockBuyableInformations(input);
}

void PaddockBuyableInformations::deserializeAs_PaddockBuyableInformations(Reader *input)
{
  this->_priceFunc(input);
  this->_lockedFunc(input);
}

void PaddockBuyableInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockBuyableInformations(tree);
}

void PaddockBuyableInformations::deserializeAsyncAs_PaddockBuyableInformations(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockBuyableInformations::_priceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockBuyableInformations::_lockedFunc, this, std::placeholders::_1));
}

void PaddockBuyableInformations::_priceFunc(Reader *input)
{
  this->price = input->readVarUhLong();
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockBuyableInformations -"<<"Forbidden value (" << this->price << ") on element of PaddockBuyableInformations.price.";
  }
}

void PaddockBuyableInformations::_lockedFunc(Reader *input)
{
  this->locked = input->readBool();
}

PaddockBuyableInformations::PaddockBuyableInformations()
{
  m_types<<ClassEnum::PADDOCKBUYABLEINFORMATIONS;
}

bool PaddockBuyableInformations::operator==(const PaddockBuyableInformations &compared)
{
  if(price == compared.price)
  if(locked == compared.locked)
  return true;
  
  return false;
}

