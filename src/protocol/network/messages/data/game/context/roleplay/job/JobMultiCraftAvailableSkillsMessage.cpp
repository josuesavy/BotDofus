#include "JobMultiCraftAvailableSkillsMessage.h"

void JobMultiCraftAvailableSkillsMessage::serialize(Writer *output)
{
  this->serializeAs_JobMultiCraftAvailableSkillsMessage(output);
}

void JobMultiCraftAvailableSkillsMessage::serializeAs_JobMultiCraftAvailableSkillsMessage(Writer *output)
{
  JobAllowMultiCraftRequestMessage::serializeAs_JobAllowMultiCraftRequestMessage(output);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobMultiCraftAvailableSkillsMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeShort((short)this->skills.size());
  for(uint _i2 = 0; _i2 < this->skills.size(); _i2++)
  {
    if(this->skills[_i2] < 0)
    {
      qDebug()<<"ERREUR - JobMultiCraftAvailableSkillsMessage -"<<"Forbidden value (" << this->skills[_i2] << ") on element 2 (starting at 1) of skills.";
    }
    output->writeVarShort((int)this->skills[_i2]);
  }
}

void JobMultiCraftAvailableSkillsMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobMultiCraftAvailableSkillsMessage(input);
}

void JobMultiCraftAvailableSkillsMessage::deserializeAs_JobMultiCraftAvailableSkillsMessage(Reader *input)
{
  uint _val2 = 0;
  JobAllowMultiCraftRequestMessage::deserialize(input);
  this->_playerIdFunc(input);
  uint _skillsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _skillsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - JobMultiCraftAvailableSkillsMessage -"<<"Forbidden value (" << _val2 << ") on elements of skills.";
    }
    this->skills.append(_val2);
  }
}

void JobMultiCraftAvailableSkillsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobMultiCraftAvailableSkillsMessage(tree);
}

void JobMultiCraftAvailableSkillsMessage::deserializeAsyncAs_JobMultiCraftAvailableSkillsMessage(FuncTree tree)
{
  JobAllowMultiCraftRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&JobMultiCraftAvailableSkillsMessage::_playerIdFunc, this, std::placeholders::_1));
  this->_skillstree = tree.addChild(std::bind(&JobMultiCraftAvailableSkillsMessage::_skillstreeFunc, this, std::placeholders::_1));
}

void JobMultiCraftAvailableSkillsMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobMultiCraftAvailableSkillsMessage -"<<"Forbidden value (" << this->playerId << ") on element of JobMultiCraftAvailableSkillsMessage.playerId.";
  }
}

void JobMultiCraftAvailableSkillsMessage::_skillstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_skillstree.addChild(std::bind(&JobMultiCraftAvailableSkillsMessage::_skillsFunc, this, std::placeholders::_1));
  }
}

void JobMultiCraftAvailableSkillsMessage::_skillsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - JobMultiCraftAvailableSkillsMessage -"<<"Forbidden value (" << _val << ") on elements of skills.";
  }
  this->skills.append(_val);
}

JobMultiCraftAvailableSkillsMessage::JobMultiCraftAvailableSkillsMessage()
{
  m_type = MessageEnum::JOBMULTICRAFTAVAILABLESKILLSMESSAGE;
}

