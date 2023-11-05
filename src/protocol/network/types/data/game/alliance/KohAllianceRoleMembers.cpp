#include "KohAllianceRoleMembers.h"

void KohAllianceRoleMembers::serialize(Writer *output)
{
  this->serializeAs_KohAllianceRoleMembers(output);
}

void KohAllianceRoleMembers::serializeAs_KohAllianceRoleMembers(Writer *output)
{
  if(this->memberCount < 0 || this->memberCount > 9007199254740992)
  {
    qDebug()<<"ERREUR - KohAllianceRoleMembers -"<<"Forbidden value (" << this->memberCount << ") on element memberCount.";
  }
  output->writeVarLong((double)this->memberCount);
  output->writeInt((int)this->roleAvAId);
}

void KohAllianceRoleMembers::deserialize(Reader *input)
{
  this->deserializeAs_KohAllianceRoleMembers(input);
}

void KohAllianceRoleMembers::deserializeAs_KohAllianceRoleMembers(Reader *input)
{
  this->_memberCountFunc(input);
  this->_roleAvAIdFunc(input);
}

void KohAllianceRoleMembers::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_KohAllianceRoleMembers(tree);
}

void KohAllianceRoleMembers::deserializeAsyncAs_KohAllianceRoleMembers(FuncTree tree)
{
  tree.addChild(std::bind(&KohAllianceRoleMembers::_memberCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&KohAllianceRoleMembers::_roleAvAIdFunc, this, std::placeholders::_1));
}

void KohAllianceRoleMembers::_memberCountFunc(Reader *input)
{
  this->memberCount = input->readVarUhLong();
  if(this->memberCount < 0 || this->memberCount > 9007199254740992)
  {
    qDebug()<<"ERREUR - KohAllianceRoleMembers -"<<"Forbidden value (" << this->memberCount << ") on element of KohAllianceRoleMembers.memberCount.";
  }
}

void KohAllianceRoleMembers::_roleAvAIdFunc(Reader *input)
{
  this->roleAvAId = input->readInt();
}

KohAllianceRoleMembers::KohAllianceRoleMembers()
{
  m_types<<ClassEnum::KOHALLIANCEROLEMEMBERS;
}

bool KohAllianceRoleMembers::operator==(const KohAllianceRoleMembers &compared)
{
  if(memberCount == compared.memberCount)
  if(roleAvAId == compared.roleAvAId)
  return true;
  
  return false;
}

