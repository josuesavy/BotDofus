#include "HouseBuyResultMessage.h"

void HouseBuyResultMessage::serialize(Writer *output)
{
  this->serializeAs_HouseBuyResultMessage(output);
}

void HouseBuyResultMessage::serializeAs_HouseBuyResultMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->secondHand);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->bought);
  output->writeByte(_box0);
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseBuyResultMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseBuyResultMessage -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  if(this->realPrice < 0 || this->realPrice > 9007199254740992)
  {
    qDebug()<<"ERREUR - HouseBuyResultMessage -"<<"Forbidden value (" << this->realPrice << ") on element realPrice.";
  }
  output->writeVarLong((double)this->realPrice);
}

void HouseBuyResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseBuyResultMessage(input);
}

void HouseBuyResultMessage::deserializeAs_HouseBuyResultMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_houseIdFunc(input);
  this->_instanceIdFunc(input);
  this->_realPriceFunc(input);
}

void HouseBuyResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseBuyResultMessage(tree);
}

void HouseBuyResultMessage::deserializeAsyncAs_HouseBuyResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseBuyResultMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseBuyResultMessage::_houseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseBuyResultMessage::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseBuyResultMessage::_realPriceFunc, this, std::placeholders::_1));
}

void HouseBuyResultMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->secondHand = BooleanByteWrapper::getFlag(_box0, 0);
  this->bought = BooleanByteWrapper::getFlag(_box0, 1);
}

void HouseBuyResultMessage::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseBuyResultMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseBuyResultMessage.houseId.";
  }
}

void HouseBuyResultMessage::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseBuyResultMessage -"<<"Forbidden value (" << this->instanceId << ") on element of HouseBuyResultMessage.instanceId.";
  }
}

void HouseBuyResultMessage::_realPriceFunc(Reader *input)
{
  this->realPrice = input->readVarUhLong();
  if(this->realPrice < 0 || this->realPrice > 9007199254740992)
  {
    qDebug()<<"ERREUR - HouseBuyResultMessage -"<<"Forbidden value (" << this->realPrice << ") on element of HouseBuyResultMessage.realPrice.";
  }
}

HouseBuyResultMessage::HouseBuyResultMessage()
{
  m_type = MessageEnum::HOUSEBUYRESULTMESSAGE;
}

