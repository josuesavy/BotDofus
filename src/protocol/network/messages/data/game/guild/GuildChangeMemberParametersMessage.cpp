#include "GuildChangeMemberParametersMessage.h"

void GuildChangeMemberParametersMessage::serialize(Writer *output)
{
  this->serializeAs_GuildChangeMemberParametersMessage(output);
}

void GuildChangeMemberParametersMessage::serializeAs_GuildChangeMemberParametersMessage(Writer *output)
{
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->rankId << ") on element rankId.";
  }
  output->writeVarInt((int)this->rankId);
  if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element experienceGivenPercent.";
  }
  output->writeByte(this->experienceGivenPercent);
}

void GuildChangeMemberParametersMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildChangeMemberParametersMessage(input);
}

void GuildChangeMemberParametersMessage::deserializeAs_GuildChangeMemberParametersMessage(Reader *input)
{
  this->_memberIdFunc(input);
  this->_rankIdFunc(input);
  this->_experienceGivenPercentFunc(input);
}

void GuildChangeMemberParametersMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildChangeMemberParametersMessage(tree);
}

void GuildChangeMemberParametersMessage::deserializeAsyncAs_GuildChangeMemberParametersMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildChangeMemberParametersMessage::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildChangeMemberParametersMessage::_rankIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildChangeMemberParametersMessage::_experienceGivenPercentFunc, this, std::placeholders::_1));
}

void GuildChangeMemberParametersMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->memberId << ") on element of GuildChangeMemberParametersMessage.memberId.";
  }
}

void GuildChangeMemberParametersMessage::_rankIdFunc(Reader *input)
{
  this->rankId = input->readVarUhInt();
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->rankId << ") on element of GuildChangeMemberParametersMessage.rankId.";
  }
}

void GuildChangeMemberParametersMessage::_experienceGivenPercentFunc(Reader *input)
{
  this->experienceGivenPercent = input->readByte();
  if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element of GuildChangeMemberParametersMessage.experienceGivenPercent.";
  }
}

GuildChangeMemberParametersMessage::GuildChangeMemberParametersMessage()
{
  m_type = MessageEnum::GUILDCHANGEMEMBERPARAMETERSMESSAGE;
}

