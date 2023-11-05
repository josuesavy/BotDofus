#include "TeleportOnSameMapMessage.h"

void TeleportOnSameMapMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportOnSameMapMessage(output);
}

void TeleportOnSameMapMessage::serializeAs_TeleportOnSameMapMessage(Writer *output)
{
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportOnSameMapMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - TeleportOnSameMapMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
}

void TeleportOnSameMapMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportOnSameMapMessage(input);
}

void TeleportOnSameMapMessage::deserializeAs_TeleportOnSameMapMessage(Reader *input)
{
  this->_targetIdFunc(input);
  this->_cellIdFunc(input);
}

void TeleportOnSameMapMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportOnSameMapMessage(tree);
}

void TeleportOnSameMapMessage::deserializeAsyncAs_TeleportOnSameMapMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportOnSameMapMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportOnSameMapMessage::_cellIdFunc, this, std::placeholders::_1));
}

void TeleportOnSameMapMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportOnSameMapMessage -"<<"Forbidden value (" << this->targetId << ") on element of TeleportOnSameMapMessage.targetId.";
  }
}

void TeleportOnSameMapMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - TeleportOnSameMapMessage -"<<"Forbidden value (" << this->cellId << ") on element of TeleportOnSameMapMessage.cellId.";
  }
}

TeleportOnSameMapMessage::TeleportOnSameMapMessage()
{
  m_type = MessageEnum::TELEPORTONSAMEMAPMESSAGE;
}

