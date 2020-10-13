#include "PauseDialogMessage.h"

void PauseDialogMessage::serialize(Writer *output)
{
  this->serializeAs_PauseDialogMessage(output);
}

void PauseDialogMessage::serializeAs_PauseDialogMessage(Writer *output)
{
  output->writeByte(this->dialogType);
}

void PauseDialogMessage::deserialize(Reader *input)
{
  this->deserializeAs_PauseDialogMessage(input);
}

void PauseDialogMessage::deserializeAs_PauseDialogMessage(Reader *input)
{
  this->_dialogTypeFunc(input);
}

void PauseDialogMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PauseDialogMessage(tree);
}

void PauseDialogMessage::deserializeAsyncAs_PauseDialogMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PauseDialogMessage::_dialogTypeFunc, this, std::placeholders::_1));
}

void PauseDialogMessage::_dialogTypeFunc(Reader *input)
{
  this->dialogType = input->readByte();
  if(this->dialogType < 0)
  {
    qDebug()<<"ERREUR - PauseDialogMessage -"<<"Forbidden value (" << this->dialogType << ") on element of PauseDialogMessage.dialogType.";
  }
}

PauseDialogMessage::PauseDialogMessage()
{
  m_type = MessageEnum::PAUSEDIALOGMESSAGE;
}

