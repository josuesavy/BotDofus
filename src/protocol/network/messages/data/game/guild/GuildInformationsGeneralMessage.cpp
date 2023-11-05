#include "GuildInformationsGeneralMessage.h"

void GuildInformationsGeneralMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInformationsGeneralMessage(output);
}

void GuildInformationsGeneralMessage::serializeAs_GuildInformationsGeneralMessage(Writer *output)
{
  output->writeBool(this->abandonnedPaddock);
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeByte(this->level);
  if(this->expLevelFloor < 0 || this->expLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->expLevelFloor << ") on element expLevelFloor.";
  }
  output->writeVarLong((double)this->expLevelFloor);
  if(this->experience < 0 || this->experience > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  output->writeVarLong((double)this->experience);
  if(this->expNextLevelFloor < 0 || this->expNextLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->expNextLevelFloor << ") on element expNextLevelFloor.";
  }
  output->writeVarLong((double)this->expNextLevelFloor);
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->creationDate << ") on element creationDate.";
  }
  output->writeInt((int)this->creationDate);
}

void GuildInformationsGeneralMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInformationsGeneralMessage(input);
}

void GuildInformationsGeneralMessage::deserializeAs_GuildInformationsGeneralMessage(Reader *input)
{
  this->_abandonnedPaddockFunc(input);
  this->_levelFunc(input);
  this->_expLevelFloorFunc(input);
  this->_experienceFunc(input);
  this->_expNextLevelFloorFunc(input);
  this->_creationDateFunc(input);
}

void GuildInformationsGeneralMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInformationsGeneralMessage(tree);
}

void GuildInformationsGeneralMessage::deserializeAsyncAs_GuildInformationsGeneralMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildInformationsGeneralMessage::_abandonnedPaddockFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInformationsGeneralMessage::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInformationsGeneralMessage::_expLevelFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInformationsGeneralMessage::_experienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInformationsGeneralMessage::_expNextLevelFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInformationsGeneralMessage::_creationDateFunc, this, std::placeholders::_1));
}

void GuildInformationsGeneralMessage::_abandonnedPaddockFunc(Reader *input)
{
  this->abandonnedPaddock = input->readBool();
}

void GuildInformationsGeneralMessage::_levelFunc(Reader *input)
{
  this->level = input->readUByte();
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->level << ") on element of GuildInformationsGeneralMessage.level.";
  }
}

void GuildInformationsGeneralMessage::_expLevelFloorFunc(Reader *input)
{
  this->expLevelFloor = input->readVarUhLong();
  if(this->expLevelFloor < 0 || this->expLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->expLevelFloor << ") on element of GuildInformationsGeneralMessage.expLevelFloor.";
  }
}

void GuildInformationsGeneralMessage::_experienceFunc(Reader *input)
{
  this->experience = input->readVarUhLong();
  if(this->experience < 0 || this->experience > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->experience << ") on element of GuildInformationsGeneralMessage.experience.";
  }
}

void GuildInformationsGeneralMessage::_expNextLevelFloorFunc(Reader *input)
{
  this->expNextLevelFloor = input->readVarUhLong();
  if(this->expNextLevelFloor < 0 || this->expNextLevelFloor > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->expNextLevelFloor << ") on element of GuildInformationsGeneralMessage.expNextLevelFloor.";
  }
}

void GuildInformationsGeneralMessage::_creationDateFunc(Reader *input)
{
  this->creationDate = input->readInt();
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->creationDate << ") on element of GuildInformationsGeneralMessage.creationDate.";
  }
}

GuildInformationsGeneralMessage::GuildInformationsGeneralMessage()
{
  m_type = MessageEnum::GUILDINFORMATIONSGENERALMESSAGE;
}

