#include "LeaveDialogMessage.h"

void LeaveDialogMessage::serialize(Writer *output)
{
  this->serializeAs_LeaveDialogMessage(output);
}

void LeaveDialogMessage::serializeAs_LeaveDialogMessage(Writer *output)
{
  output->writeByte(this->dialogType);
}

void LeaveDialogMessage::deserialize(Reader *input)
{
  this->deserializeAs_LeaveDialogMessage(input);
}

void LeaveDialogMessage::deserializeAs_LeaveDialogMessage(Reader *input)
{
  this->_dialogTypeFunc(input);
}

void LeaveDialogMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LeaveDialogMessage(tree);
}

void LeaveDialogMessage::deserializeAsyncAs_LeaveDialogMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LeaveDialogMessage::_dialogTypeFunc, this, std::placeholders::_1));
}

void LeaveDialogMessage::_dialogTypeFunc(Reader *input)
{
  this->dialogType = input->readByte();
  if(this->dialogType < 0)
  {
    qDebug()<<"ERREUR - LeaveDialogMessage -"<<"Forbidden value (" << this->dialogType << ") on element of LeaveDialogMessage.dialogType.";
  }
}

LeaveDialogMessage::LeaveDialogMessage()
{
  m_type = MessageEnum::LEAVEDIALOGMESSAGE;
}

