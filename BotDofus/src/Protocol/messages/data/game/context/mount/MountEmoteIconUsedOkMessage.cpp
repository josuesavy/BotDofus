#include "MountEmoteIconUsedOkMessage.h"

void MountEmoteIconUsedOkMessage::serialize(Writer *output)
{
  this->serializeAs_MountEmoteIconUsedOkMessage(output);
}

void MountEmoteIconUsedOkMessage::serializeAs_MountEmoteIconUsedOkMessage(Writer *output)
{
  output->writeVarInt((int)this->mountId);
  if(this->reactionType < 0)
  {
    qDebug()<<"ERREUR - MountEmoteIconUsedOkMessage -"<<"Forbidden value (" << this->reactionType << ") on element reactionType.";
  }
  output->writeByte(this->reactionType);
}

void MountEmoteIconUsedOkMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountEmoteIconUsedOkMessage(input);
}

void MountEmoteIconUsedOkMessage::deserializeAs_MountEmoteIconUsedOkMessage(Reader *input)
{
  this->_mountIdFunc(input);
  this->_reactionTypeFunc(input);
}

void MountEmoteIconUsedOkMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountEmoteIconUsedOkMessage(tree);
}

void MountEmoteIconUsedOkMessage::deserializeAsyncAs_MountEmoteIconUsedOkMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountEmoteIconUsedOkMessage::_mountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountEmoteIconUsedOkMessage::_reactionTypeFunc, this, std::placeholders::_1));
}

void MountEmoteIconUsedOkMessage::_mountIdFunc(Reader *input)
{
  this->mountId = input->readVarInt();
}

void MountEmoteIconUsedOkMessage::_reactionTypeFunc(Reader *input)
{
  this->reactionType = input->readByte();
  if(this->reactionType < 0)
  {
    qDebug()<<"ERREUR - MountEmoteIconUsedOkMessage -"<<"Forbidden value (" << this->reactionType << ") on element of MountEmoteIconUsedOkMessage.reactionType.";
  }
}

MountEmoteIconUsedOkMessage::MountEmoteIconUsedOkMessage()
{
  m_type = MessageEnum::MOUNTEMOTEICONUSEDOKMESSAGE;
}

