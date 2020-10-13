#include "LockableStateUpdateHouseDoorMessage.h"

void LockableStateUpdateHouseDoorMessage::serialize(Writer *output)
{
  this->serializeAs_LockableStateUpdateHouseDoorMessage(output);
}

void LockableStateUpdateHouseDoorMessage::serializeAs_LockableStateUpdateHouseDoorMessage(Writer *output)
{
  LockableStateUpdateAbstractMessage::serializeAs_LockableStateUpdateAbstractMessage(output);
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - LockableStateUpdateHouseDoorMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - LockableStateUpdateHouseDoorMessage -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  output->writeBool(this->secondHand);
}

void LockableStateUpdateHouseDoorMessage::deserialize(Reader *input)
{
  this->deserializeAs_LockableStateUpdateHouseDoorMessage(input);
}

void LockableStateUpdateHouseDoorMessage::deserializeAs_LockableStateUpdateHouseDoorMessage(Reader *input)
{
  LockableStateUpdateAbstractMessage::deserialize(input);
  this->_houseIdFunc(input);
  this->_instanceIdFunc(input);
  this->_secondHandFunc(input);
}

void LockableStateUpdateHouseDoorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LockableStateUpdateHouseDoorMessage(tree);
}

void LockableStateUpdateHouseDoorMessage::deserializeAsyncAs_LockableStateUpdateHouseDoorMessage(FuncTree tree)
{
  LockableStateUpdateAbstractMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&LockableStateUpdateHouseDoorMessage::_houseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LockableStateUpdateHouseDoorMessage::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LockableStateUpdateHouseDoorMessage::_secondHandFunc, this, std::placeholders::_1));
}

void LockableStateUpdateHouseDoorMessage::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - LockableStateUpdateHouseDoorMessage -"<<"Forbidden value (" << this->houseId << ") on element of LockableStateUpdateHouseDoorMessage.houseId.";
  }
}

void LockableStateUpdateHouseDoorMessage::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - LockableStateUpdateHouseDoorMessage -"<<"Forbidden value (" << this->instanceId << ") on element of LockableStateUpdateHouseDoorMessage.instanceId.";
  }
}

void LockableStateUpdateHouseDoorMessage::_secondHandFunc(Reader *input)
{
  this->secondHand = input->readBool();
}

LockableStateUpdateHouseDoorMessage::LockableStateUpdateHouseDoorMessage()
{
  m_type = MessageEnum::LOCKABLESTATEUPDATEHOUSEDOORMESSAGE;
}

