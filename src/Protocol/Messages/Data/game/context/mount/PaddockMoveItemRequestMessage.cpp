#include "PaddockMoveItemRequestMessage.h"

void PaddockMoveItemRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PaddockMoveItemRequestMessage(output);
}

void PaddockMoveItemRequestMessage::serializeAs_PaddockMoveItemRequestMessage(Writer *output)
{
  if(this->oldCellId < 0 || this->oldCellId > 559)
  {
    qDebug()<<"ERREUR - PaddockMoveItemRequestMessage -"<<"Forbidden value (" << this->oldCellId << ") on element oldCellId.";
  }
  output->writeVarShort((int)this->oldCellId);
  if(this->newCellId < 0 || this->newCellId > 559)
  {
    qDebug()<<"ERREUR - PaddockMoveItemRequestMessage -"<<"Forbidden value (" << this->newCellId << ") on element newCellId.";
  }
  output->writeVarShort((int)this->newCellId);
}

void PaddockMoveItemRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaddockMoveItemRequestMessage(input);
}

void PaddockMoveItemRequestMessage::deserializeAs_PaddockMoveItemRequestMessage(Reader *input)
{
  this->_oldCellIdFunc(input);
  this->_newCellIdFunc(input);
}

void PaddockMoveItemRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockMoveItemRequestMessage(tree);
}

void PaddockMoveItemRequestMessage::deserializeAsyncAs_PaddockMoveItemRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockMoveItemRequestMessage::_oldCellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockMoveItemRequestMessage::_newCellIdFunc, this, std::placeholders::_1));
}

void PaddockMoveItemRequestMessage::_oldCellIdFunc(Reader *input)
{
  this->oldCellId = input->readVarUhShort();
  if(this->oldCellId < 0 || this->oldCellId > 559)
  {
    qDebug()<<"ERREUR - PaddockMoveItemRequestMessage -"<<"Forbidden value (" << this->oldCellId << ") on element of PaddockMoveItemRequestMessage.oldCellId.";
  }
}

void PaddockMoveItemRequestMessage::_newCellIdFunc(Reader *input)
{
  this->newCellId = input->readVarUhShort();
  if(this->newCellId < 0 || this->newCellId > 559)
  {
    qDebug()<<"ERREUR - PaddockMoveItemRequestMessage -"<<"Forbidden value (" << this->newCellId << ") on element of PaddockMoveItemRequestMessage.newCellId.";
  }
}

PaddockMoveItemRequestMessage::PaddockMoveItemRequestMessage()
{
  m_type = MessageEnum::PADDOCKMOVEITEMREQUESTMESSAGE;
}

