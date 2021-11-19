#include "ExchangeSetCraftRecipeMessage.h"

void ExchangeSetCraftRecipeMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeSetCraftRecipeMessage(output);
}

void ExchangeSetCraftRecipeMessage::serializeAs_ExchangeSetCraftRecipeMessage(Writer *output)
{
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeSetCraftRecipeMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarShort((int)this->objectGID);
}

void ExchangeSetCraftRecipeMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeSetCraftRecipeMessage(input);
}

void ExchangeSetCraftRecipeMessage::deserializeAs_ExchangeSetCraftRecipeMessage(Reader *input)
{
  this->_objectGIDFunc(input);
}

void ExchangeSetCraftRecipeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeSetCraftRecipeMessage(tree);
}

void ExchangeSetCraftRecipeMessage::deserializeAsyncAs_ExchangeSetCraftRecipeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeSetCraftRecipeMessage::_objectGIDFunc, this, std::placeholders::_1));
}

void ExchangeSetCraftRecipeMessage::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhShort();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeSetCraftRecipeMessage -"<<"Forbidden value (" << this->objectGID << ") on element of ExchangeSetCraftRecipeMessage.objectGID.";
  }
}

ExchangeSetCraftRecipeMessage::ExchangeSetCraftRecipeMessage()
{
  m_type = MessageEnum::EXCHANGESETCRAFTRECIPEMESSAGE;
}

