#include "GuildLevelUpMessage.h"

void GuildLevelUpMessage::serialize(Writer *output)
{
  this->serializeAs_GuildLevelUpMessage(output);
}

void GuildLevelUpMessage::serializeAs_GuildLevelUpMessage(Writer *output)
{
  if(this->newLevel < 2 || this->newLevel > 200)
  {
    qDebug()<<"ERREUR - GuildLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element newLevel.";
  }
  output->writeByte(this->newLevel);
}

void GuildLevelUpMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildLevelUpMessage(input);
}

void GuildLevelUpMessage::deserializeAs_GuildLevelUpMessage(Reader *input)
{
  this->_newLevelFunc(input);
}

void GuildLevelUpMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildLevelUpMessage(tree);
}

void GuildLevelUpMessage::deserializeAsyncAs_GuildLevelUpMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildLevelUpMessage::_newLevelFunc, this, std::placeholders::_1));
}

void GuildLevelUpMessage::_newLevelFunc(Reader *input)
{
  this->newLevel = input->readUByte();
  if(this->newLevel < 2 || this->newLevel > 200)
  {
    qDebug()<<"ERREUR - GuildLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element of GuildLevelUpMessage.newLevel.";
  }
}

GuildLevelUpMessage::GuildLevelUpMessage()
{
  m_type = MessageEnum::GUILDLEVELUPMESSAGE;
}

