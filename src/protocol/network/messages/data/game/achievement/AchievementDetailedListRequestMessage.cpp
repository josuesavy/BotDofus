#include "AchievementDetailedListRequestMessage.h"

void AchievementDetailedListRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementDetailedListRequestMessage(output);
}

void AchievementDetailedListRequestMessage::serializeAs_AchievementDetailedListRequestMessage(Writer *output)
{
  if(this->categoryId < 0)
  {
    qDebug()<<"ERREUR - AchievementDetailedListRequestMessage -"<<"Forbidden value (" << this->categoryId << ") on element categoryId.";
  }
  output->writeVarShort((int)this->categoryId);
}

void AchievementDetailedListRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementDetailedListRequestMessage(input);
}

void AchievementDetailedListRequestMessage::deserializeAs_AchievementDetailedListRequestMessage(Reader *input)
{
  this->_categoryIdFunc(input);
}

void AchievementDetailedListRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementDetailedListRequestMessage(tree);
}

void AchievementDetailedListRequestMessage::deserializeAsyncAs_AchievementDetailedListRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AchievementDetailedListRequestMessage::_categoryIdFunc, this, std::placeholders::_1));
}

void AchievementDetailedListRequestMessage::_categoryIdFunc(Reader *input)
{
  this->categoryId = input->readVarUhShort();
  if(this->categoryId < 0)
  {
    qDebug()<<"ERREUR - AchievementDetailedListRequestMessage -"<<"Forbidden value (" << this->categoryId << ") on element of AchievementDetailedListRequestMessage.categoryId.";
  }
}

AchievementDetailedListRequestMessage::AchievementDetailedListRequestMessage()
{
  m_type = MessageEnum::ACHIEVEMENTDETAILEDLISTREQUESTMESSAGE;
}

