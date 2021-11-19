#include "HouseKickIndoorMerchantRequestMessage.h"

void HouseKickIndoorMerchantRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HouseKickIndoorMerchantRequestMessage(output);
}

void HouseKickIndoorMerchantRequestMessage::serializeAs_HouseKickIndoorMerchantRequestMessage(Writer *output)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - HouseKickIndoorMerchantRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
}

void HouseKickIndoorMerchantRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseKickIndoorMerchantRequestMessage(input);
}

void HouseKickIndoorMerchantRequestMessage::deserializeAs_HouseKickIndoorMerchantRequestMessage(Reader *input)
{
  this->_cellIdFunc(input);
}

void HouseKickIndoorMerchantRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseKickIndoorMerchantRequestMessage(tree);
}

void HouseKickIndoorMerchantRequestMessage::deserializeAsyncAs_HouseKickIndoorMerchantRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseKickIndoorMerchantRequestMessage::_cellIdFunc, this, std::placeholders::_1));
}

void HouseKickIndoorMerchantRequestMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - HouseKickIndoorMerchantRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element of HouseKickIndoorMerchantRequestMessage.cellId.";
  }
}

HouseKickIndoorMerchantRequestMessage::HouseKickIndoorMerchantRequestMessage()
{
  m_type = MessageEnum::HOUSEKICKINDOORMERCHANTREQUESTMESSAGE;
}

