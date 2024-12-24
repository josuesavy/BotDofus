#include "GuildCharacsUpgradeRequestMessage.h"

void GuildCharacsUpgradeRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildCharacsUpgradeRequestMessage(output);
}

void GuildCharacsUpgradeRequestMessage::serializeAs_GuildCharacsUpgradeRequestMessage(Writer *output)
{
  output->writeByte(this->charaTypeTarget);
}

void GuildCharacsUpgradeRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildCharacsUpgradeRequestMessage(input);
}

void GuildCharacsUpgradeRequestMessage::deserializeAs_GuildCharacsUpgradeRequestMessage(Reader *input)
{
  this->_charaTypeTargetFunc(input);
}

void GuildCharacsUpgradeRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildCharacsUpgradeRequestMessage(tree);
}

void GuildCharacsUpgradeRequestMessage::deserializeAsyncAs_GuildCharacsUpgradeRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildCharacsUpgradeRequestMessage::_charaTypeTargetFunc, this, std::placeholders::_1));
}

void GuildCharacsUpgradeRequestMessage::_charaTypeTargetFunc(Reader *input)
{
  this->charaTypeTarget = input->readByte();
  if(this->charaTypeTarget < 0)
  {
    qDebug()<<"ERREUR - GuildCharacsUpgradeRequestMessage -"<<"Forbidden value (" << this->charaTypeTarget << ") on element of GuildCharacsUpgradeRequestMessage.charaTypeTarget.";
  }
}

GuildCharacsUpgradeRequestMessage::GuildCharacsUpgradeRequestMessage()
{
  m_type = MessageEnum::GUILDCHARACSUPGRADEREQUESTMESSAGE;
}

