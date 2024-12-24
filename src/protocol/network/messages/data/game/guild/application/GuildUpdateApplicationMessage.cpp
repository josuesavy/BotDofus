#include "GuildUpdateApplicationMessage.h"

void GuildUpdateApplicationMessage::serialize(Writer *output)
{
  this->serializeAs_GuildUpdateApplicationMessage(output);
}

void GuildUpdateApplicationMessage::serializeAs_GuildUpdateApplicationMessage(Writer *output)
{
  output->writeUTF(this->applyText);
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildUpdateApplicationMessage -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  output->writeVarInt((int)this->guildId);
}

void GuildUpdateApplicationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildUpdateApplicationMessage(input);
}

void GuildUpdateApplicationMessage::deserializeAs_GuildUpdateApplicationMessage(Reader *input)
{
  this->_applyTextFunc(input);
  this->_guildIdFunc(input);
}

void GuildUpdateApplicationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildUpdateApplicationMessage(tree);
}

void GuildUpdateApplicationMessage::deserializeAsyncAs_GuildUpdateApplicationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildUpdateApplicationMessage::_applyTextFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildUpdateApplicationMessage::_guildIdFunc, this, std::placeholders::_1));
}

void GuildUpdateApplicationMessage::_applyTextFunc(Reader *input)
{
  this->applyText = input->readUTF();
}

void GuildUpdateApplicationMessage::_guildIdFunc(Reader *input)
{
  this->guildId = input->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildUpdateApplicationMessage -"<<"Forbidden value (" << this->guildId << ") on element of GuildUpdateApplicationMessage.guildId.";
  }
}

GuildUpdateApplicationMessage::GuildUpdateApplicationMessage()
{
  m_type = MessageEnum::GUILDUPDATEAPPLICATIONMESSAGE;
}

