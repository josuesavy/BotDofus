#include "ObjectUseOnCellMessage.h"

void ObjectUseOnCellMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectUseOnCellMessage(output);
}

void ObjectUseOnCellMessage::serializeAs_ObjectUseOnCellMessage(Writer *output)
{
  ObjectUseMessage::serializeAs_ObjectUseMessage(output);
  if(this->cells < 0 || this->cells > 559)
  {
    qDebug()<<"ERREUR - ObjectUseOnCellMessage -"<<"Forbidden value (" << this->cells << ") on element cells.";
  }
  output->writeVarShort((int)this->cells);
}

void ObjectUseOnCellMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectUseOnCellMessage(input);
}

void ObjectUseOnCellMessage::deserializeAs_ObjectUseOnCellMessage(Reader *input)
{
  ObjectUseMessage::deserialize(input);
  this->_cellsFunc(input);
}

void ObjectUseOnCellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectUseOnCellMessage(tree);
}

void ObjectUseOnCellMessage::deserializeAsyncAs_ObjectUseOnCellMessage(FuncTree tree)
{
  ObjectUseMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectUseOnCellMessage::_cellsFunc, this, std::placeholders::_1));
}

void ObjectUseOnCellMessage::_cellsFunc(Reader *input)
{
  this->cells = input->readVarUhShort();
  if(this->cells < 0 || this->cells > 559)
  {
    qDebug()<<"ERREUR - ObjectUseOnCellMessage -"<<"Forbidden value (" << this->cells << ") on element of ObjectUseOnCellMessage.cells.";
  }
}

ObjectUseOnCellMessage::ObjectUseOnCellMessage()
{
  m_type = MessageEnum::OBJECTUSEONCELLMESSAGE;
}

