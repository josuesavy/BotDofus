#include "ServerSettingsMessage.h"

void ServerSettingsMessage::serialize(Writer *output)
{
  this->serializeAs_ServerSettingsMessage(output);
}

void ServerSettingsMessage::serializeAs_ServerSettingsMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->isMonoAccount);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->hasFreeAutopilot);
  output->writeByte(_box0);
  output->writeUTF(this->lang);
  if(this->community < 0)
  {
    qDebug()<<"ERREUR - ServerSettingsMessage -"<<"Forbidden value (" << this->community << ") on element community.";
  }
  output->writeByte(this->community);
  output->writeByte(this->gameType);
  if(this->arenaLeaveBanTime < 0)
  {
    qDebug()<<"ERREUR - ServerSettingsMessage -"<<"Forbidden value (" << this->arenaLeaveBanTime << ") on element arenaLeaveBanTime.";
  }
  output->writeVarShort((int)this->arenaLeaveBanTime);
  if(this->itemMaxLevel < 0)
  {
    qDebug()<<"ERREUR - ServerSettingsMessage -"<<"Forbidden value (" << this->itemMaxLevel << ") on element itemMaxLevel.";
  }
  output->writeInt((int)this->itemMaxLevel);
}

void ServerSettingsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ServerSettingsMessage(input);
}

void ServerSettingsMessage::deserializeAs_ServerSettingsMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_langFunc(input);
  this->_communityFunc(input);
  this->_gameTypeFunc(input);
  this->_arenaLeaveBanTimeFunc(input);
  this->_itemMaxLevelFunc(input);
}

void ServerSettingsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServerSettingsMessage(tree);
}

void ServerSettingsMessage::deserializeAsyncAs_ServerSettingsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ServerSettingsMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&ServerSettingsMessage::_langFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ServerSettingsMessage::_communityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ServerSettingsMessage::_gameTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ServerSettingsMessage::_arenaLeaveBanTimeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ServerSettingsMessage::_itemMaxLevelFunc, this, std::placeholders::_1));
}

void ServerSettingsMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->isMonoAccount = BooleanByteWrapper::getFlag(_box0, 0);
  this->hasFreeAutopilot = BooleanByteWrapper::getFlag(_box0, 1);
}

void ServerSettingsMessage::_langFunc(Reader *input)
{
  this->lang = input->readUTF();
}

void ServerSettingsMessage::_communityFunc(Reader *input)
{
  this->community = input->readByte();
  if(this->community < 0)
  {
    qDebug()<<"ERREUR - ServerSettingsMessage -"<<"Forbidden value (" << this->community << ") on element of ServerSettingsMessage.community.";
  }
}

void ServerSettingsMessage::_gameTypeFunc(Reader *input)
{
  this->gameType = input->readByte();
}

void ServerSettingsMessage::_arenaLeaveBanTimeFunc(Reader *input)
{
  this->arenaLeaveBanTime = input->readVarUhShort();
  if(this->arenaLeaveBanTime < 0)
  {
    qDebug()<<"ERREUR - ServerSettingsMessage -"<<"Forbidden value (" << this->arenaLeaveBanTime << ") on element of ServerSettingsMessage.arenaLeaveBanTime.";
  }
}

void ServerSettingsMessage::_itemMaxLevelFunc(Reader *input)
{
  this->itemMaxLevel = input->readInt();
  if(this->itemMaxLevel < 0)
  {
    qDebug()<<"ERREUR - ServerSettingsMessage -"<<"Forbidden value (" << this->itemMaxLevel << ") on element of ServerSettingsMessage.itemMaxLevel.";
  }
}

ServerSettingsMessage::ServerSettingsMessage()
{
  m_type = MessageEnum::SERVERSETTINGSMESSAGE;
}

