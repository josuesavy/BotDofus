#include "ShowCellMessage.h"

void ShowCellMessage::serialize(Writer *output)
{
  this->serializeAs_ShowCellMessage(output);
}

void ShowCellMessage::serializeAs_ShowCellMessage(Writer *output)
{
  if(this->sourceId < -9007199254740992 || this->sourceId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ShowCellMessage -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
  }
  output->writeDouble(this->sourceId);
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ShowCellMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
}

void ShowCellMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShowCellMessage(input);
}

void ShowCellMessage::deserializeAs_ShowCellMessage(Reader *input)
{
  this->_sourceIdFunc(input);
  this->_cellIdFunc(input);
}

void ShowCellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShowCellMessage(tree);
}

void ShowCellMessage::deserializeAsyncAs_ShowCellMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ShowCellMessage::_sourceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ShowCellMessage::_cellIdFunc, this, std::placeholders::_1));
}

void ShowCellMessage::_sourceIdFunc(Reader *input)
{
  this->sourceId = input->readDouble();
  if(this->sourceId < -9007199254740992 || this->sourceId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ShowCellMessage -"<<"Forbidden value (" << this->sourceId << ") on element of ShowCellMessage.sourceId.";
  }
}

void ShowCellMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ShowCellMessage -"<<"Forbidden value (" << this->cellId << ") on element of ShowCellMessage.cellId.";
  }
}

ShowCellMessage::ShowCellMessage()
{
  m_type = MessageEnum::SHOWCELLMESSAGE;
}

