#include "NpcGenericActionRequestMessage.h"

void NpcGenericActionRequestMessage::serialize(Writer *output)
{
  this->serializeAs_NpcGenericActionRequestMessage(output);
}

void NpcGenericActionRequestMessage::serializeAs_NpcGenericActionRequestMessage(Writer *output)
{
  output->writeInt((int)this->npcId);
  if(this->npcActionId < 0)
  {
    qDebug()<<"ERREUR - NpcGenericActionRequestMessage -"<<"Forbidden value (" << this->npcActionId << ") on element npcActionId.";
  }
  output->writeByte(this->npcActionId);
  if(this->npcMapId < 0 || this->npcMapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - NpcGenericActionRequestMessage -"<<"Forbidden value (" << this->npcMapId << ") on element npcMapId.";
  }
  output->writeDouble(this->npcMapId);
}

void NpcGenericActionRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_NpcGenericActionRequestMessage(input);
}

void NpcGenericActionRequestMessage::deserializeAs_NpcGenericActionRequestMessage(Reader *input)
{
  this->_npcIdFunc(input);
  this->_npcActionIdFunc(input);
  this->_npcMapIdFunc(input);
}

void NpcGenericActionRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NpcGenericActionRequestMessage(tree);
}

void NpcGenericActionRequestMessage::deserializeAsyncAs_NpcGenericActionRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NpcGenericActionRequestMessage::_npcIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&NpcGenericActionRequestMessage::_npcActionIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&NpcGenericActionRequestMessage::_npcMapIdFunc, this, std::placeholders::_1));
}

void NpcGenericActionRequestMessage::_npcIdFunc(Reader *input)
{
  this->npcId = input->readInt();
}

void NpcGenericActionRequestMessage::_npcActionIdFunc(Reader *input)
{
  this->npcActionId = input->readByte();
  if(this->npcActionId < 0)
  {
    qDebug()<<"ERREUR - NpcGenericActionRequestMessage -"<<"Forbidden value (" << this->npcActionId << ") on element of NpcGenericActionRequestMessage.npcActionId.";
  }
}

void NpcGenericActionRequestMessage::_npcMapIdFunc(Reader *input)
{
  this->npcMapId = input->readDouble();
  if(this->npcMapId < 0 || this->npcMapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - NpcGenericActionRequestMessage -"<<"Forbidden value (" << this->npcMapId << ") on element of NpcGenericActionRequestMessage.npcMapId.";
  }
}

NpcGenericActionRequestMessage::NpcGenericActionRequestMessage()
{
  m_type = MessageEnum::NPCGENERICACTIONREQUESTMESSAGE;
  m_needsHash = true;
}

