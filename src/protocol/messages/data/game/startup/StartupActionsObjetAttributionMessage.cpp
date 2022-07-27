#include "StartupActionsObjetAttributionMessage.h"

void StartupActionsObjetAttributionMessage::serialize(Writer *output)
{
  this->serializeAs_StartupActionsObjetAttributionMessage(output);
}

void StartupActionsObjetAttributionMessage::serializeAs_StartupActionsObjetAttributionMessage(Writer *output)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - StartupActionsObjetAttributionMessage -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  output->writeInt((int)this->actionId);
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - StartupActionsObjetAttributionMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
}

void StartupActionsObjetAttributionMessage::deserialize(Reader *input)
{
  this->deserializeAs_StartupActionsObjetAttributionMessage(input);
}

void StartupActionsObjetAttributionMessage::deserializeAs_StartupActionsObjetAttributionMessage(Reader *input)
{
  this->_actionIdFunc(input);
  this->_characterIdFunc(input);
}

void StartupActionsObjetAttributionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StartupActionsObjetAttributionMessage(tree);
}

void StartupActionsObjetAttributionMessage::deserializeAsyncAs_StartupActionsObjetAttributionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&StartupActionsObjetAttributionMessage::_actionIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StartupActionsObjetAttributionMessage::_characterIdFunc, this, std::placeholders::_1));
}

void StartupActionsObjetAttributionMessage::_actionIdFunc(Reader *input)
{
  this->actionId = input->readInt();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - StartupActionsObjetAttributionMessage -"<<"Forbidden value (" << this->actionId << ") on element of StartupActionsObjetAttributionMessage.actionId.";
  }
}

void StartupActionsObjetAttributionMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - StartupActionsObjetAttributionMessage -"<<"Forbidden value (" << this->characterId << ") on element of StartupActionsObjetAttributionMessage.characterId.";
  }
}

StartupActionsObjetAttributionMessage::StartupActionsObjetAttributionMessage()
{
  m_type = MessageEnum::STARTUPACTIONSOBJETATTRIBUTIONMESSAGE;
}

