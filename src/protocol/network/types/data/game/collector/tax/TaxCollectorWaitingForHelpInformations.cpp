#include "TaxCollectorWaitingForHelpInformations.h"

void TaxCollectorWaitingForHelpInformations::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorWaitingForHelpInformations(output);
}

void TaxCollectorWaitingForHelpInformations::serializeAs_TaxCollectorWaitingForHelpInformations(Writer *output)
{
  TaxCollectorComplementaryInformations::serializeAs_TaxCollectorComplementaryInformations(output);
  this->waitingForHelpInfo.serializeAs_ProtectedEntityWaitingForHelpInfo(output);
}

void TaxCollectorWaitingForHelpInformations::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorWaitingForHelpInformations(input);
}

void TaxCollectorWaitingForHelpInformations::deserializeAs_TaxCollectorWaitingForHelpInformations(Reader *input)
{
  TaxCollectorComplementaryInformations::deserialize(input);
  this->waitingForHelpInfo = ProtectedEntityWaitingForHelpInfo();
  this->waitingForHelpInfo.deserialize(input);
}

void TaxCollectorWaitingForHelpInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorWaitingForHelpInformations(tree);
}

void TaxCollectorWaitingForHelpInformations::deserializeAsyncAs_TaxCollectorWaitingForHelpInformations(FuncTree tree)
{
  TaxCollectorComplementaryInformations::deserializeAsync(tree);
  this->_waitingForHelpInfotree = tree.addChild(std::bind(&TaxCollectorWaitingForHelpInformations::_waitingForHelpInfotreeFunc, this, std::placeholders::_1));
}

void TaxCollectorWaitingForHelpInformations::_waitingForHelpInfotreeFunc(Reader *input)
{
  this->waitingForHelpInfo = ProtectedEntityWaitingForHelpInfo();
  this->waitingForHelpInfo.deserializeAsync(this->_waitingForHelpInfotree);
}

TaxCollectorWaitingForHelpInformations::TaxCollectorWaitingForHelpInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORWAITINGFORHELPINFORMATIONS;
}

bool TaxCollectorWaitingForHelpInformations::operator==(const TaxCollectorWaitingForHelpInformations &compared)
{
  if(waitingForHelpInfo == compared.waitingForHelpInfo)
  if(_waitingForHelpInfotree == compared._waitingForHelpInfotree)
  return true;
  
  return false;
}

