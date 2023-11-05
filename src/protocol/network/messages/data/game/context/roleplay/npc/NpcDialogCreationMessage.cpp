#include "NpcDialogCreationMessage.h"

void NpcDialogCreationMessage::serialize(Writer *output)
{
  this->serializeAs_NpcDialogCreationMessage(output);
}

void NpcDialogCreationMessage::serializeAs_NpcDialogCreationMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - NpcDialogCreationMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  output->writeInt((int)this->npcId);
}

void NpcDialogCreationMessage::deserialize(Reader *input)
{
  this->deserializeAs_NpcDialogCreationMessage(input);
}

void NpcDialogCreationMessage::deserializeAs_NpcDialogCreationMessage(Reader *input)
{
  this->_mapIdFunc(input);
  this->_npcIdFunc(input);
}

void NpcDialogCreationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NpcDialogCreationMessage(tree);
}

void NpcDialogCreationMessage::deserializeAsyncAs_NpcDialogCreationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NpcDialogCreationMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&NpcDialogCreationMessage::_npcIdFunc, this, std::placeholders::_1));
}

void NpcDialogCreationMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - NpcDialogCreationMessage -"<<"Forbidden value (" << this->mapId << ") on element of NpcDialogCreationMessage.mapId.";
  }
}

void NpcDialogCreationMessage::_npcIdFunc(Reader *input)
{
  this->npcId = input->readInt();
}

NpcDialogCreationMessage::NpcDialogCreationMessage()
{
  m_type = MessageEnum::NPCDIALOGCREATIONMESSAGE;
}

