#include "ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage.h"

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(output);
}

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::serializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(Writer *output)
{
  output->writeBool(this->allow);
}

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(input);
}

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::deserializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(Reader *input)
{
  this->_allowFunc(input);
}

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(tree);
}

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::deserializeAsyncAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::_allowFunc, this, std::placeholders::_1));
}

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::_allowFunc(Reader *input)
{
  this->allow = input->readBool();
}

ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage()
{
  m_type = MessageEnum::EXCHANGEMULTICRAFTSETCRAFTERCANUSEHISRESSOURCESMESSAGE;
}

