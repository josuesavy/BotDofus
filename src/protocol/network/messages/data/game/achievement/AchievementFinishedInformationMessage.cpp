#include "AchievementFinishedInformationMessage.h"

void AchievementFinishedInformationMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementFinishedInformationMessage(output);
}

void AchievementFinishedInformationMessage::serializeAs_AchievementFinishedInformationMessage(Writer *output)
{
  AchievementFinishedMessage::serializeAs_AchievementFinishedMessage(output);
  output->writeUTF(this->name);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AchievementFinishedInformationMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void AchievementFinishedInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementFinishedInformationMessage(input);
}

void AchievementFinishedInformationMessage::deserializeAs_AchievementFinishedInformationMessage(Reader *input)
{
  AchievementFinishedMessage::deserialize(input);
  this->_nameFunc(input);
  this->_playerIdFunc(input);
}

void AchievementFinishedInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementFinishedInformationMessage(tree);
}

void AchievementFinishedInformationMessage::deserializeAsyncAs_AchievementFinishedInformationMessage(FuncTree tree)
{
  AchievementFinishedMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&AchievementFinishedInformationMessage::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AchievementFinishedInformationMessage::_playerIdFunc, this, std::placeholders::_1));
}

void AchievementFinishedInformationMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void AchievementFinishedInformationMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AchievementFinishedInformationMessage -"<<"Forbidden value (" << this->playerId << ") on element of AchievementFinishedInformationMessage.playerId.";
  }
}

AchievementFinishedInformationMessage::AchievementFinishedInformationMessage()
{
  m_type = MessageEnum::ACHIEVEMENTFINISHEDINFORMATIONMESSAGE;
}

