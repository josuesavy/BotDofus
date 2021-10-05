#include "ShowCellRequestMessage.h"

void ShowCellRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ShowCellRequestMessage(output);
}

void ShowCellRequestMessage::serializeAs_ShowCellRequestMessage(Writer *output)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ShowCellRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
}

void ShowCellRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShowCellRequestMessage(input);
}

void ShowCellRequestMessage::deserializeAs_ShowCellRequestMessage(Reader *input)
{
  this->_cellIdFunc(input);
}

void ShowCellRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShowCellRequestMessage(tree);
}

void ShowCellRequestMessage::deserializeAsyncAs_ShowCellRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShowCellRequestMessage::_cellIdFunc, this, std::placeholders::_1));
}

void ShowCellRequestMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ShowCellRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element of ShowCellRequestMessage.cellId.";
  }
}

ShowCellRequestMessage::ShowCellRequestMessage()
{
  m_type = MessageEnum::SHOWCELLREQUESTMESSAGE;
}

