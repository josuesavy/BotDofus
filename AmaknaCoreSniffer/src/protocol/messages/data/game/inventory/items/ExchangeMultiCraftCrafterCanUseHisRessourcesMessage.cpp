#include "ExchangeMultiCraftCrafterCanUseHisRessourcesMessage.h"

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(output);
}

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::serializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(Writer *output)
{
  output->writeBool(this->allowed);
}

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(input);
}

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::deserializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(Reader *input)
{
  this->_allowedFunc(input);
}

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(tree);
}

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::deserializeAsyncAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::_allowedFunc, this, std::placeholders::_1));
}

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::_allowedFunc(Reader *input)
{
  this->allowed = input->readBool();
}

ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::ExchangeMultiCraftCrafterCanUseHisRessourcesMessage()
{
  m_type = MessageEnum::EXCHANGEMULTICRAFTCRAFTERCANUSEHISRESSOURCESMESSAGE;
}

