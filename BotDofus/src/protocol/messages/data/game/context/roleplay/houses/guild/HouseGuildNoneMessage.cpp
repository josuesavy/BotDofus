#include "HouseGuildNoneMessage.h"

void HouseGuildNoneMessage::serialize(Writer *output)
{
  this->serializeAs_HouseGuildNoneMessage(output);
}

void HouseGuildNoneMessage::serializeAs_HouseGuildNoneMessage(Writer *output)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildNoneMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildNoneMessage -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  output->writeBool(this->secondHand);
}

void HouseGuildNoneMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseGuildNoneMessage(input);
}

void HouseGuildNoneMessage::deserializeAs_HouseGuildNoneMessage(Reader *input)
{
  this->_houseIdFunc(input);
  this->_instanceIdFunc(input);
  this->_secondHandFunc(input);
}

void HouseGuildNoneMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseGuildNoneMessage(tree);
}

void HouseGuildNoneMessage::deserializeAsyncAs_HouseGuildNoneMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseGuildNoneMessage::_houseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseGuildNoneMessage::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseGuildNoneMessage::_secondHandFunc, this, std::placeholders::_1));
}

void HouseGuildNoneMessage::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildNoneMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseGuildNoneMessage.houseId.";
  }
}

void HouseGuildNoneMessage::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildNoneMessage -"<<"Forbidden value (" << this->instanceId << ") on element of HouseGuildNoneMessage.instanceId.";
  }
}

void HouseGuildNoneMessage::_secondHandFunc(Reader *input)
{
  this->secondHand = input->readBool();
}

HouseGuildNoneMessage::HouseGuildNoneMessage()
{
  m_type = MessageEnum::HOUSEGUILDNONEMESSAGE;
}

