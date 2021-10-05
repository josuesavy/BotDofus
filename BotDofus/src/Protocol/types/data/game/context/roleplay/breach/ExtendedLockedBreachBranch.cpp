#include "ExtendedLockedBreachBranch.h"

void ExtendedLockedBreachBranch::serialize(Writer *output)
{
  this->serializeAs_ExtendedLockedBreachBranch(output);
}

void ExtendedLockedBreachBranch::serializeAs_ExtendedLockedBreachBranch(Writer *output)
{
  ExtendedBreachBranch::serializeAs_ExtendedBreachBranch(output);
  if(this->unlockPrice < 0)
  {
    qDebug()<<"ERREUR - ExtendedLockedBreachBranch -"<<"Forbidden value (" << this->unlockPrice << ") on element unlockPrice.";
  }
  output->writeVarInt((int)this->unlockPrice);
}

void ExtendedLockedBreachBranch::deserialize(Reader *input)
{
  this->deserializeAs_ExtendedLockedBreachBranch(input);
}

void ExtendedLockedBreachBranch::deserializeAs_ExtendedLockedBreachBranch(Reader *input)
{
  ExtendedBreachBranch::deserialize(input);
  this->_unlockPriceFunc(input);
}

void ExtendedLockedBreachBranch::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExtendedLockedBreachBranch(tree);
}

void ExtendedLockedBreachBranch::deserializeAsyncAs_ExtendedLockedBreachBranch(FuncTree tree)
{
  ExtendedBreachBranch::deserializeAsync(tree);
  tree.addChild(std::bind(&ExtendedLockedBreachBranch::_unlockPriceFunc, this, std::placeholders::_1));
}

void ExtendedLockedBreachBranch::_unlockPriceFunc(Reader *input)
{
  this->unlockPrice = input->readVarUhInt();
  if(this->unlockPrice < 0)
  {
    qDebug()<<"ERREUR - ExtendedLockedBreachBranch -"<<"Forbidden value (" << this->unlockPrice << ") on element of ExtendedLockedBreachBranch.unlockPrice.";
  }
}

ExtendedLockedBreachBranch::ExtendedLockedBreachBranch()
{
  m_types<<ClassEnum::EXTENDEDLOCKEDBREACHBRANCH;
}

bool ExtendedLockedBreachBranch::operator==(const ExtendedLockedBreachBranch &compared)
{
  if(unlockPrice == compared.unlockPrice)
  return true;
  
  return false;
}

