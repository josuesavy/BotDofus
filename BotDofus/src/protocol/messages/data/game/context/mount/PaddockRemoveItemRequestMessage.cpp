#include "PaddockRemoveItemRequestMessage.h"

void PaddockRemoveItemRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PaddockRemoveItemRequestMessage(output);
}

void PaddockRemoveItemRequestMessage::serializeAs_PaddockRemoveItemRequestMessage(Writer *output)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - PaddockRemoveItemRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
}

void PaddockRemoveItemRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaddockRemoveItemRequestMessage(input);
}

void PaddockRemoveItemRequestMessage::deserializeAs_PaddockRemoveItemRequestMessage(Reader *input)
{
  this->_cellIdFunc(input);
}

void PaddockRemoveItemRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockRemoveItemRequestMessage(tree);
}

void PaddockRemoveItemRequestMessage::deserializeAsyncAs_PaddockRemoveItemRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockRemoveItemRequestMessage::_cellIdFunc, this, std::placeholders::_1));
}

void PaddockRemoveItemRequestMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - PaddockRemoveItemRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element of PaddockRemoveItemRequestMessage.cellId.";
  }
}

PaddockRemoveItemRequestMessage::PaddockRemoveItemRequestMessage()
{
  m_type = MessageEnum::PADDOCKREMOVEITEMREQUESTMESSAGE;
}

