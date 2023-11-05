#include "CharacterExperienceGainMessage.h"

void CharacterExperienceGainMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterExperienceGainMessage(output);
}

void CharacterExperienceGainMessage::serializeAs_CharacterExperienceGainMessage(Writer *output)
{
  if(this->experienceCharacter < 0 || this->experienceCharacter > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceCharacter << ") on element experienceCharacter.";
  }
  output->writeVarLong((double)this->experienceCharacter);
  if(this->experienceMount < 0 || this->experienceMount > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceMount << ") on element experienceMount.";
  }
  output->writeVarLong((double)this->experienceMount);
  if(this->experienceGuild < 0 || this->experienceGuild > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceGuild << ") on element experienceGuild.";
  }
  output->writeVarLong((double)this->experienceGuild);
  if(this->experienceIncarnation < 0 || this->experienceIncarnation > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceIncarnation << ") on element experienceIncarnation.";
  }
  output->writeVarLong((double)this->experienceIncarnation);
}

void CharacterExperienceGainMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterExperienceGainMessage(input);
}

void CharacterExperienceGainMessage::deserializeAs_CharacterExperienceGainMessage(Reader *input)
{
  this->_experienceCharacterFunc(input);
  this->_experienceMountFunc(input);
  this->_experienceGuildFunc(input);
  this->_experienceIncarnationFunc(input);
}

void CharacterExperienceGainMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterExperienceGainMessage(tree);
}

void CharacterExperienceGainMessage::deserializeAsyncAs_CharacterExperienceGainMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterExperienceGainMessage::_experienceCharacterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterExperienceGainMessage::_experienceMountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterExperienceGainMessage::_experienceGuildFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterExperienceGainMessage::_experienceIncarnationFunc, this, std::placeholders::_1));
}

void CharacterExperienceGainMessage::_experienceCharacterFunc(Reader *input)
{
  this->experienceCharacter = input->readVarUhLong();
  if(this->experienceCharacter < 0 || this->experienceCharacter > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceCharacter << ") on element of CharacterExperienceGainMessage.experienceCharacter.";
  }
}

void CharacterExperienceGainMessage::_experienceMountFunc(Reader *input)
{
  this->experienceMount = input->readVarUhLong();
  if(this->experienceMount < 0 || this->experienceMount > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceMount << ") on element of CharacterExperienceGainMessage.experienceMount.";
  }
}

void CharacterExperienceGainMessage::_experienceGuildFunc(Reader *input)
{
  this->experienceGuild = input->readVarUhLong();
  if(this->experienceGuild < 0 || this->experienceGuild > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceGuild << ") on element of CharacterExperienceGainMessage.experienceGuild.";
  }
}

void CharacterExperienceGainMessage::_experienceIncarnationFunc(Reader *input)
{
  this->experienceIncarnation = input->readVarUhLong();
  if(this->experienceIncarnation < 0 || this->experienceIncarnation > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceIncarnation << ") on element of CharacterExperienceGainMessage.experienceIncarnation.";
  }
}

CharacterExperienceGainMessage::CharacterExperienceGainMessage()
{
  m_type = MessageEnum::CHARACTEREXPERIENCEGAINMESSAGE;
}

