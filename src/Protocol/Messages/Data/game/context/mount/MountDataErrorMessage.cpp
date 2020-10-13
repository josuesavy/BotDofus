#include "MountDataErrorMessage.h"

void MountDataErrorMessage::serialize(Writer *output)
{
  this->serializeAs_MountDataErrorMessage(output);
}

void MountDataErrorMessage::serializeAs_MountDataErrorMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void MountDataErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountDataErrorMessage(input);
}

void MountDataErrorMessage::deserializeAs_MountDataErrorMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void MountDataErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountDataErrorMessage(tree);
}

void MountDataErrorMessage::deserializeAsyncAs_MountDataErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountDataErrorMessage::_reasonFunc, this, std::placeholders::_1));
}

void MountDataErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - MountDataErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of MountDataErrorMessage.reason.";
  }
}

MountDataErrorMessage::MountDataErrorMessage()
{
  m_type = MessageEnum::MOUNTDATAERRORMESSAGE;
}

