#include "HavenBagPermissionsUpdateRequestMessage.h"

void HavenBagPermissionsUpdateRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HavenBagPermissionsUpdateRequestMessage(output);
}

void HavenBagPermissionsUpdateRequestMessage::serializeAs_HavenBagPermissionsUpdateRequestMessage(Writer *output)
{
  if(this->permissions < 0)
  {
    qDebug()<<"ERREUR - HavenBagPermissionsUpdateRequestMessage -"<<"Forbidden value (" << this->permissions << ") on element permissions.";
  }
  output->writeInt((int)this->permissions);
}

void HavenBagPermissionsUpdateRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HavenBagPermissionsUpdateRequestMessage(input);
}

void HavenBagPermissionsUpdateRequestMessage::deserializeAs_HavenBagPermissionsUpdateRequestMessage(Reader *input)
{
  this->_permissionsFunc(input);
}

void HavenBagPermissionsUpdateRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HavenBagPermissionsUpdateRequestMessage(tree);
}

void HavenBagPermissionsUpdateRequestMessage::deserializeAsyncAs_HavenBagPermissionsUpdateRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HavenBagPermissionsUpdateRequestMessage::_permissionsFunc, this, std::placeholders::_1));
}

void HavenBagPermissionsUpdateRequestMessage::_permissionsFunc(Reader *input)
{
  this->permissions = input->readInt();
  if(this->permissions < 0)
  {
    qDebug()<<"ERREUR - HavenBagPermissionsUpdateRequestMessage -"<<"Forbidden value (" << this->permissions << ") on element of HavenBagPermissionsUpdateRequestMessage.permissions.";
  }
}

HavenBagPermissionsUpdateRequestMessage::HavenBagPermissionsUpdateRequestMessage()
{
  m_type = MessageEnum::HAVENBAGPERMISSIONSUPDATEREQUESTMESSAGE;
}

