#include "InteractiveUsedMessage.h"

void InteractiveUsedMessage::serialize(Writer *output)
{
  this->serializeAs_InteractiveUsedMessage(output);
}

void InteractiveUsedMessage::serializeAs_InteractiveUsedMessage(Writer *output)
{
  if(this->entityId < 0 || this->entityId > 9007199254740992)
  {
    qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->entityId << ") on element entityId.";
  }
  output->writeVarLong((double)this->entityId);
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->elemId << ") on element elemId.";
  }
  output->writeVarInt((int)this->elemId);
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  output->writeVarShort((int)this->skillId);
  if(this->duration < 0)
  {
    qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->duration << ") on element duration.";
  }
  output->writeVarShort((int)this->duration);
  output->writeBool(this->canMove);
}

void InteractiveUsedMessage::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveUsedMessage(input);
}

void InteractiveUsedMessage::deserializeAs_InteractiveUsedMessage(Reader *input)
{
  this->_entityIdFunc(input);
  this->_elemIdFunc(input);
  this->_skillIdFunc(input);
  this->_durationFunc(input);
  this->_canMoveFunc(input);
}

void InteractiveUsedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveUsedMessage(tree);
}

void InteractiveUsedMessage::deserializeAsyncAs_InteractiveUsedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&InteractiveUsedMessage::_entityIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InteractiveUsedMessage::_elemIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InteractiveUsedMessage::_skillIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InteractiveUsedMessage::_durationFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InteractiveUsedMessage::_canMoveFunc, this, std::placeholders::_1));
}

void InteractiveUsedMessage::_entityIdFunc(Reader *input)
{
  this->entityId = input->readVarUhLong();
  if(this->entityId < 0 || this->entityId > 9007199254740992)
  {
    qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->entityId << ") on element of InteractiveUsedMessage.entityId.";
  }
}

void InteractiveUsedMessage::_elemIdFunc(Reader *input)
{
  this->elemId = input->readVarUhInt();
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->elemId << ") on element of InteractiveUsedMessage.elemId.";
  }
}

void InteractiveUsedMessage::_skillIdFunc(Reader *input)
{
  this->skillId = input->readVarUhShort();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->skillId << ") on element of InteractiveUsedMessage.skillId.";
  }
}

void InteractiveUsedMessage::_durationFunc(Reader *input)
{
  this->duration = input->readVarUhShort();
  if(this->duration < 0)
  {
    qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->duration << ") on element of InteractiveUsedMessage.duration.";
  }
}

void InteractiveUsedMessage::_canMoveFunc(Reader *input)
{
  this->canMove = input->readBool();
}

InteractiveUsedMessage::InteractiveUsedMessage()
{
  m_type = MessageEnum::INTERACTIVEUSEDMESSAGE;
}

