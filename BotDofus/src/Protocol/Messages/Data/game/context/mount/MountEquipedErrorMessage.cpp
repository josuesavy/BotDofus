#include "MountEquipedErrorMessage.h"

void MountEquipedErrorMessage::serialize(Writer *output)
{
  this->serializeAs_MountEquipedErrorMessage(output);
}

void MountEquipedErrorMessage::serializeAs_MountEquipedErrorMessage(Writer *output)
{
  output->writeByte(this->errorType);
}

void MountEquipedErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountEquipedErrorMessage(input);
}

void MountEquipedErrorMessage::deserializeAs_MountEquipedErrorMessage(Reader *input)
{
  this->_errorTypeFunc(input);
}

void MountEquipedErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountEquipedErrorMessage(tree);
}

void MountEquipedErrorMessage::deserializeAsyncAs_MountEquipedErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountEquipedErrorMessage::_errorTypeFunc, this, std::placeholders::_1));
}

void MountEquipedErrorMessage::_errorTypeFunc(Reader *input)
{
  this->errorType = input->readByte();
  if(this->errorType < 0)
  {
    qDebug()<<"ERREUR - MountEquipedErrorMessage -"<<"Forbidden value (" << this->errorType << ") on element of MountEquipedErrorMessage.errorType.";
  }
}

MountEquipedErrorMessage::MountEquipedErrorMessage()
{
  m_type = MessageEnum::MOUNTEQUIPEDERRORMESSAGE;
}

