#include "JobDescription.h"

void JobDescription::serialize(Writer *output)
{
  this->serializeAs_JobDescription(output);
}

void JobDescription::serializeAs_JobDescription(Writer *output)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobDescription -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  output->writeByte(this->jobId);
  output->writeShort((short)this->skills.size());
  for(uint _i2 = 0; _i2 < this->skills.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<SkillActionDescription>(this->skills[_i2])->getTypes().last());
    qSharedPointerCast<SkillActionDescription>(this->skills[_i2])->serialize(output);
  }
}

void JobDescription::deserialize(Reader *input)
{
  this->deserializeAs_JobDescription(input);
}

void JobDescription::deserializeAs_JobDescription(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<SkillActionDescription> _item2 ;
  this->_jobIdFunc(input);
  uint _skillsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _skillsLen; _i2++)
  {
    _id2 = input->readUShort();
    _item2 = qSharedPointerCast<SkillActionDescription>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->skills.append(_item2);
  }
}

void JobDescription::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobDescription(tree);
}

void JobDescription::deserializeAsyncAs_JobDescription(FuncTree tree)
{
  tree.addChild(std::bind(&JobDescription::_jobIdFunc, this, std::placeholders::_1));
  this->_skillstree = tree.addChild(std::bind(&JobDescription::_skillstreeFunc, this, std::placeholders::_1));
}

void JobDescription::_jobIdFunc(Reader *input)
{
  this->jobId = input->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobDescription -"<<"Forbidden value (" << this->jobId << ") on element of JobDescription.jobId.";
  }
}

void JobDescription::_skillstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_skillstree.addChild(std::bind(&JobDescription::_skillsFunc, this, std::placeholders::_1));
  }
}

void JobDescription::_skillsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<SkillActionDescription> _item = qSharedPointerCast<SkillActionDescription>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->skills.append(_item);
}

JobDescription::JobDescription()
{
  m_types<<ClassEnum::JOBDESCRIPTION;
}

bool JobDescription::operator==(const JobDescription &compared)
{
  if(jobId == compared.jobId)
  if(skills == compared.skills)
  if(_skillstree == compared._skillstree)
  return true;
  
  return false;
}

