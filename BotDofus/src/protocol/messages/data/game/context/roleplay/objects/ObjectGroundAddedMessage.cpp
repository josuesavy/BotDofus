#include "ObjectGroundAddedMessage.h"

void ObjectGroundAddedMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectGroundAddedMessage(output);
}

void ObjectGroundAddedMessage::serializeAs_ObjectGroundAddedMessage(Writer *output)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ObjectGroundAddedMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectGroundAddedMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
}

void ObjectGroundAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectGroundAddedMessage(input);
}

void ObjectGroundAddedMessage::deserializeAs_ObjectGroundAddedMessage(Reader *input)
{
  this->_cellIdFunc(input);
  this->_objectGIDFunc(input);
}

void ObjectGroundAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectGroundAddedMessage(tree);
}

void ObjectGroundAddedMessage::deserializeAsyncAs_ObjectGroundAddedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectGroundAddedMessage::_cellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectGroundAddedMessage::_objectGIDFunc, this, std::placeholders::_1));
}

void ObjectGroundAddedMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ObjectGroundAddedMessage -"<<"Forbidden value (" << this->cellId << ") on element of ObjectGroundAddedMessage.cellId.";
  }
}

void ObjectGroundAddedMessage::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectGroundAddedMessage -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectGroundAddedMessage.objectGID.";
  }
}

ObjectGroundAddedMessage::ObjectGroundAddedMessage()
{
  m_type = MessageEnum::OBJECTGROUNDADDEDMESSAGE;
}

