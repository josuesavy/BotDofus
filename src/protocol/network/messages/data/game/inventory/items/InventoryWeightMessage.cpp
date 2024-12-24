#include "InventoryWeightMessage.h"

void InventoryWeightMessage::serialize(Writer *output)
{
  this->serializeAs_InventoryWeightMessage(output);
}

void InventoryWeightMessage::serializeAs_InventoryWeightMessage(Writer *output)
{
  if(this->inventoryWeight < 0)
  {
    qDebug()<<"ERREUR - InventoryWeightMessage -"<<"Forbidden value (" << this->inventoryWeight << ") on element inventoryWeight.";
  }
  output->writeVarInt((int)this->inventoryWeight);
  if(this->weightMax < 0)
  {
    qDebug()<<"ERREUR - InventoryWeightMessage -"<<"Forbidden value (" << this->weightMax << ") on element weightMax.";
  }
  output->writeVarInt((int)this->weightMax);
}

void InventoryWeightMessage::deserialize(Reader *input)
{
  this->deserializeAs_InventoryWeightMessage(input);
}

void InventoryWeightMessage::deserializeAs_InventoryWeightMessage(Reader *input)
{
  this->_inventoryWeightFunc(input);
  this->_weightMaxFunc(input);
}

void InventoryWeightMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InventoryWeightMessage(tree);
}

void InventoryWeightMessage::deserializeAsyncAs_InventoryWeightMessage(FuncTree tree)
{
  tree.addChild(std::bind(&InventoryWeightMessage::_inventoryWeightFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InventoryWeightMessage::_weightMaxFunc, this, std::placeholders::_1));
}

void InventoryWeightMessage::_inventoryWeightFunc(Reader *input)
{
  this->inventoryWeight = input->readVarUhInt();
  if(this->inventoryWeight < 0)
  {
    qDebug()<<"ERREUR - InventoryWeightMessage -"<<"Forbidden value (" << this->inventoryWeight << ") on element of InventoryWeightMessage.inventoryWeight.";
  }
}

void InventoryWeightMessage::_weightMaxFunc(Reader *input)
{
  this->weightMax = input->readVarUhInt();
  if(this->weightMax < 0)
  {
    qDebug()<<"ERREUR - InventoryWeightMessage -"<<"Forbidden value (" << this->weightMax << ") on element of InventoryWeightMessage.weightMax.";
  }
}

InventoryWeightMessage::InventoryWeightMessage()
{
  m_type = MessageEnum::INVENTORYWEIGHTMESSAGE;
}

