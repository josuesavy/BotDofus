#include "GuildSubmitApplicationMessage.h"

void GuildSubmitApplicationMessage::serialize(Writer *output)
{
  this->serializeAs_GuildSubmitApplicationMessage(output);
}

void GuildSubmitApplicationMessage::serializeAs_GuildSubmitApplicationMessage(Writer *output)
{
  output->writeUTF(this->applyText);
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildSubmitApplicationMessage -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  output->writeVarInt((int)this->guildId);
  if(this->timeSpent < 0)
  {
    qDebug()<<"ERREUR - GuildSubmitApplicationMessage -"<<"Forbidden value (" << this->timeSpent << ") on element timeSpent.";
  }
  output->writeVarInt((int)this->timeSpent);
  output->writeUTF(this->filterLanguage);
  output->writeUTF(this->filterAmbiance);
  output->writeUTF(this->filterPlaytime);
  output->writeUTF(this->filterInterest);
  output->writeUTF(this->filterMinMaxGuildLevel);
  output->writeUTF(this->filterRecruitmentType);
  output->writeUTF(this->filterMinMaxCharacterLevel);
  output->writeUTF(this->filterMinMaxAchievement);
  output->writeUTF(this->filterSearchName);
  output->writeUTF(this->filterLastSort);
}

void GuildSubmitApplicationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildSubmitApplicationMessage(input);
}

void GuildSubmitApplicationMessage::deserializeAs_GuildSubmitApplicationMessage(Reader *input)
{
  this->_applyTextFunc(input);
  this->_guildIdFunc(input);
  this->_timeSpentFunc(input);
  this->_filterLanguageFunc(input);
  this->_filterAmbianceFunc(input);
  this->_filterPlaytimeFunc(input);
  this->_filterInterestFunc(input);
  this->_filterMinMaxGuildLevelFunc(input);
  this->_filterRecruitmentTypeFunc(input);
  this->_filterMinMaxCharacterLevelFunc(input);
  this->_filterMinMaxAchievementFunc(input);
  this->_filterSearchNameFunc(input);
  this->_filterLastSortFunc(input);
}

void GuildSubmitApplicationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildSubmitApplicationMessage(tree);
}

void GuildSubmitApplicationMessage::deserializeAsyncAs_GuildSubmitApplicationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_applyTextFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_guildIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_timeSpentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_filterLanguageFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_filterAmbianceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_filterPlaytimeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_filterInterestFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_filterMinMaxGuildLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_filterRecruitmentTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_filterMinMaxCharacterLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_filterMinMaxAchievementFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_filterSearchNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSubmitApplicationMessage::_filterLastSortFunc, this, std::placeholders::_1));
}

void GuildSubmitApplicationMessage::_applyTextFunc(Reader *input)
{
  this->applyText = input->readUTF();
}

void GuildSubmitApplicationMessage::_guildIdFunc(Reader *input)
{
  this->guildId = input->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildSubmitApplicationMessage -"<<"Forbidden value (" << this->guildId << ") on element of GuildSubmitApplicationMessage.guildId.";
  }
}

void GuildSubmitApplicationMessage::_timeSpentFunc(Reader *input)
{
  this->timeSpent = input->readVarUhInt();
  if(this->timeSpent < 0)
  {
    qDebug()<<"ERREUR - GuildSubmitApplicationMessage -"<<"Forbidden value (" << this->timeSpent << ") on element of GuildSubmitApplicationMessage.timeSpent.";
  }
}

void GuildSubmitApplicationMessage::_filterLanguageFunc(Reader *input)
{
  this->filterLanguage = input->readUTF();
}

void GuildSubmitApplicationMessage::_filterAmbianceFunc(Reader *input)
{
  this->filterAmbiance = input->readUTF();
}

void GuildSubmitApplicationMessage::_filterPlaytimeFunc(Reader *input)
{
  this->filterPlaytime = input->readUTF();
}

void GuildSubmitApplicationMessage::_filterInterestFunc(Reader *input)
{
  this->filterInterest = input->readUTF();
}

void GuildSubmitApplicationMessage::_filterMinMaxGuildLevelFunc(Reader *input)
{
  this->filterMinMaxGuildLevel = input->readUTF();
}

void GuildSubmitApplicationMessage::_filterRecruitmentTypeFunc(Reader *input)
{
  this->filterRecruitmentType = input->readUTF();
}

void GuildSubmitApplicationMessage::_filterMinMaxCharacterLevelFunc(Reader *input)
{
  this->filterMinMaxCharacterLevel = input->readUTF();
}

void GuildSubmitApplicationMessage::_filterMinMaxAchievementFunc(Reader *input)
{
  this->filterMinMaxAchievement = input->readUTF();
}

void GuildSubmitApplicationMessage::_filterSearchNameFunc(Reader *input)
{
  this->filterSearchName = input->readUTF();
}

void GuildSubmitApplicationMessage::_filterLastSortFunc(Reader *input)
{
  this->filterLastSort = input->readUTF();
}

GuildSubmitApplicationMessage::GuildSubmitApplicationMessage()
{
  m_type = MessageEnum::GUILDSUBMITAPPLICATIONMESSAGE;
}

