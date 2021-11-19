#include "GuildChangeMemberParametersMessage.h"

void GuildChangeMemberParametersMessage::serialize(Writer *output)
{
  this->serializeAs_GuildChangeMemberParametersMessage(output);
}

void GuildChangeMemberParametersMessage::serializeAs_GuildChangeMemberParametersMessage(Writer *output)
{
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
  if(this->rank < 0)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->rank << ") on element rank.";
  }
  output->writeVarShort((int)this->rank);
  if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element experienceGivenPercent.";
  }
  output->writeByte(this->experienceGivenPercent);
  if(this->rights < 0)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->rights << ") on element rights.";
  }
  output->writeVarInt((int)this->rights);
}

void GuildChangeMemberParametersMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildChangeMemberParametersMessage(input);
}

void GuildChangeMemberParametersMessage::deserializeAs_GuildChangeMemberParametersMessage(Reader *input)
{
  this->_memberIdFunc(input);
  this->_rankFunc(input);
  this->_experienceGivenPercentFunc(input);
  this->_rightsFunc(input);
}

void GuildChangeMemberParametersMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildChangeMemberParametersMessage(tree);
}

void GuildChangeMemberParametersMessage::deserializeAsyncAs_GuildChangeMemberParametersMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildChangeMemberParametersMessage::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildChangeMemberParametersMessage::_rankFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildChangeMemberParametersMessage::_experienceGivenPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildChangeMemberParametersMessage::_rightsFunc, this, std::placeholders::_1));
}

void GuildChangeMemberParametersMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->memberId << ") on element of GuildChangeMemberParametersMessage.memberId.";
  }
}

void GuildChangeMemberParametersMessage::_rankFunc(Reader *input)
{
  this->rank = input->readVarUhShort();
  if(this->rank < 0)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->rank << ") on element of GuildChangeMemberParametersMessage.rank.";
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

void GuildChangeMemberParametersMessage::_rightsFunc(Reader *input)
{
  this->rights = input->readVarUhInt();
  if(this->rights < 0)
  {
    qDebug()<<"ERREUR - GuildChangeMemberParametersMessage -"<<"Forbidden value (" << this->rights << ") on element of GuildChangeMemberParametersMessage.rights.";
  }
}

GuildChangeMemberParametersMessage::GuildChangeMemberParametersMessage()
{
  m_type = MessageEnum::GUILDCHANGEMEMBERPARAMETERSMESSAGE;
}

