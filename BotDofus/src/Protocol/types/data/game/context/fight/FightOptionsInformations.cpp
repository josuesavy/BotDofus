#include "FightOptionsInformations.h"

void FightOptionsInformations::serialize(Writer *output)
{
  this->serializeAs_FightOptionsInformations(output);
}

void FightOptionsInformations::serializeAs_FightOptionsInformations(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->isSecret);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->isRestrictedToPartyOnly);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->isClosed);
  _box0 = BooleanByteWrapper::setFlag(_box0, 3, this->isAskingForHelp);
  output->writeByte(_box0);
}

void FightOptionsInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightOptionsInformations(input);
}

void FightOptionsInformations::deserializeAs_FightOptionsInformations(Reader *input)
{
  this->deserializeByteBoxes(input);
}

void FightOptionsInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightOptionsInformations(tree);
}

void FightOptionsInformations::deserializeAsyncAs_FightOptionsInformations(FuncTree tree)
{
  tree.addChild(std::bind(&FightOptionsInformations::deserializeByteBoxes, this, std::placeholders::_1));
}

void FightOptionsInformations::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->isSecret = BooleanByteWrapper::getFlag(_box0, 0);
  this->isRestrictedToPartyOnly = BooleanByteWrapper::getFlag(_box0, 1);
  this->isClosed = BooleanByteWrapper::getFlag(_box0, 2);
  this->isAskingForHelp = BooleanByteWrapper::getFlag(_box0, 3);
}

FightOptionsInformations::FightOptionsInformations()
{
  m_types<<ClassEnum::FIGHTOPTIONSINFORMATIONS;
}

bool FightOptionsInformations::operator==(const FightOptionsInformations &compared)
{
  if(isSecret == compared.isSecret)
  if(isRestrictedToPartyOnly == compared.isRestrictedToPartyOnly)
  if(isClosed == compared.isClosed)
  if(isAskingForHelp == compared.isAskingForHelp)
  return true;
  
  return false;
}

