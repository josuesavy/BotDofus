#include "PurchasableDialogMessage.h"

void PurchasableDialogMessage::serialize(Writer *output)
{
  this->serializeAs_PurchasableDialogMessage(output);
}

void PurchasableDialogMessage::serializeAs_PurchasableDialogMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->buyOrSell);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->secondHand);
  output->writeByte(_box0);
  if(this->purchasableId < 0 || this->purchasableId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PurchasableDialogMessage -"<<"Forbidden value (" << this->purchasableId << ") on element purchasableId.";
  }
  output->writeDouble(this->purchasableId);
  if(this->purchasableInstanceId < 0)
  {
    qDebug()<<"ERREUR - PurchasableDialogMessage -"<<"Forbidden value (" << this->purchasableInstanceId << ") on element purchasableInstanceId.";
  }
  output->writeInt((int)this->purchasableInstanceId);
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - PurchasableDialogMessage -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarLong((double)this->price);
}

void PurchasableDialogMessage::deserialize(Reader *input)
{
  this->deserializeAs_PurchasableDialogMessage(input);
}

void PurchasableDialogMessage::deserializeAs_PurchasableDialogMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_purchasableIdFunc(input);
  this->_purchasableInstanceIdFunc(input);
  this->_priceFunc(input);
}

void PurchasableDialogMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PurchasableDialogMessage(tree);
}

void PurchasableDialogMessage::deserializeAsyncAs_PurchasableDialogMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PurchasableDialogMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&PurchasableDialogMessage::_purchasableIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PurchasableDialogMessage::_purchasableInstanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PurchasableDialogMessage::_priceFunc, this, std::placeholders::_1));
}

void PurchasableDialogMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->buyOrSell = BooleanByteWrapper::getFlag(_box0, 0);
  this->secondHand = BooleanByteWrapper::getFlag(_box0, 1);
}

void PurchasableDialogMessage::_purchasableIdFunc(Reader *input)
{
  this->purchasableId = input->readDouble();
  if(this->purchasableId < 0 || this->purchasableId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PurchasableDialogMessage -"<<"Forbidden value (" << this->purchasableId << ") on element of PurchasableDialogMessage.purchasableId.";
  }
}

void PurchasableDialogMessage::_purchasableInstanceIdFunc(Reader *input)
{
  this->purchasableInstanceId = input->readInt();
  if(this->purchasableInstanceId < 0)
  {
    qDebug()<<"ERREUR - PurchasableDialogMessage -"<<"Forbidden value (" << this->purchasableInstanceId << ") on element of PurchasableDialogMessage.purchasableInstanceId.";
  }
}

void PurchasableDialogMessage::_priceFunc(Reader *input)
{
  this->price = input->readVarUhLong();
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - PurchasableDialogMessage -"<<"Forbidden value (" << this->price << ") on element of PurchasableDialogMessage.price.";
  }
}

PurchasableDialogMessage::PurchasableDialogMessage()
{
  m_type = MessageEnum::PURCHASABLEDIALOGMESSAGE;
}

