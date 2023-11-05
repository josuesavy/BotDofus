#include "AllianceMemberInfo.h"

void AllianceMemberInfo::serialize(Writer *output)
{
  this->serializeAs_AllianceMemberInfo(output);
}

void AllianceMemberInfo::serializeAs_AllianceMemberInfo(Writer *output)
{
  SocialMember::serializeAs_SocialMember(output);
  output->writeInt((int)this->avaRoleId);
}

void AllianceMemberInfo::deserialize(Reader *input)
{
  this->deserializeAs_AllianceMemberInfo(input);
}

void AllianceMemberInfo::deserializeAs_AllianceMemberInfo(Reader *input)
{
  SocialMember::deserialize(input);
  this->_avaRoleIdFunc(input);
}

void AllianceMemberInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceMemberInfo(tree);
}

void AllianceMemberInfo::deserializeAsyncAs_AllianceMemberInfo(FuncTree tree)
{
  SocialMember::deserializeAsync(tree);
  tree.addChild(std::bind(&AllianceMemberInfo::_avaRoleIdFunc, this, std::placeholders::_1));
}

void AllianceMemberInfo::_avaRoleIdFunc(Reader *input)
{
  this->avaRoleId = input->readInt();
}

AllianceMemberInfo::AllianceMemberInfo()
{
  m_types<<ClassEnum::ALLIANCEMEMBERINFO;
}

bool AllianceMemberInfo::operator==(const AllianceMemberInfo &compared)
{
  if(avaRoleId == compared.avaRoleId)
  return true;
  
  return false;
}

