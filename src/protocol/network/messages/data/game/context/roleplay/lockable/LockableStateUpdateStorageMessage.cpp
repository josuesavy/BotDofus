#include "LockableStateUpdateStorageMessage.h"

void LockableStateUpdateStorageMessage::serialize(Writer *output)
{
  this->serializeAs_LockableStateUpdateStorageMessage(output);
}

void LockableStateUpdateStorageMessage::serializeAs_LockableStateUpdateStorageMessage(Writer *output)
{
  LockableStateUpdateAbstractMessage::serializeAs_LockableStateUpdateAbstractMessage(output);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - LockableStateUpdateStorageMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - LockableStateUpdateStorageMessage -"<<"Forbidden value (" << this->elementId << ") on element elementId.";
  }
  output->writeVarInt((int)this->elementId);
}

void LockableStateUpdateStorageMessage::deserialize(Reader *input)
{
  this->deserializeAs_LockableStateUpdateStorageMessage(input);
}

void LockableStateUpdateStorageMessage::deserializeAs_LockableStateUpdateStorageMessage(Reader *input)
{
  LockableStateUpdateAbstractMessage::deserialize(input);
  this->_mapIdFunc(input);
  this->_elementIdFunc(input);
}

void LockableStateUpdateStorageMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LockableStateUpdateStorageMessage(tree);
}

void LockableStateUpdateStorageMessage::deserializeAsyncAs_LockableStateUpdateStorageMessage(FuncTree tree)
{
  LockableStateUpdateAbstractMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&LockableStateUpdateStorageMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LockableStateUpdateStorageMessage::_elementIdFunc, this, std::placeholders::_1));
}

void LockableStateUpdateStorageMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - LockableStateUpdateStorageMessage -"<<"Forbidden value (" << this->mapId << ") on element of LockableStateUpdateStorageMessage.mapId.";
  }
}

void LockableStateUpdateStorageMessage::_elementIdFunc(Reader *input)
{
  this->elementId = input->readVarUhInt();
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - LockableStateUpdateStorageMessage -"<<"Forbidden value (" << this->elementId << ") on element of LockableStateUpdateStorageMessage.elementId.";
  }
}

LockableStateUpdateStorageMessage::LockableStateUpdateStorageMessage()
{
  m_type = MessageEnum::LOCKABLESTATEUPDATESTORAGEMESSAGE;
}

