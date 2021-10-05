#include "ObjectGroundRemovedMessage.h"

void ObjectGroundRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectGroundRemovedMessage(output);
}

void ObjectGroundRemovedMessage::serializeAs_ObjectGroundRemovedMessage(Writer *output)
{
  if(this->cell < 0 || this->cell > 559)
  {
    qDebug()<<"ERREUR - ObjectGroundRemovedMessage -"<<"Forbidden value (" << this->cell << ") on element cell.";
  }
  output->writeVarShort((int)this->cell);
}

void ObjectGroundRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectGroundRemovedMessage(input);
}

void ObjectGroundRemovedMessage::deserializeAs_ObjectGroundRemovedMessage(Reader *input)
{
  this->_cellFunc(input);
}

void ObjectGroundRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectGroundRemovedMessage(tree);
}

void ObjectGroundRemovedMessage::deserializeAsyncAs_ObjectGroundRemovedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectGroundRemovedMessage::_cellFunc, this, std::placeholders::_1));
}

void ObjectGroundRemovedMessage::_cellFunc(Reader *input)
{
  this->cell = input->readVarUhShort();
  if(this->cell < 0 || this->cell > 559)
  {
    qDebug()<<"ERREUR - ObjectGroundRemovedMessage -"<<"Forbidden value (" << this->cell << ") on element of ObjectGroundRemovedMessage.cell.";
  }
}

ObjectGroundRemovedMessage::ObjectGroundRemovedMessage()
{
  m_type = MessageEnum::OBJECTGROUNDREMOVEDMESSAGE;
}

