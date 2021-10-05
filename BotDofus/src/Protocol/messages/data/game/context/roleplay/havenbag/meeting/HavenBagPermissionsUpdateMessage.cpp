#include "HavenBagPermissionsUpdateMessage.h"

void HavenBagPermissionsUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_HavenBagPermissionsUpdateMessage(output);
}

void HavenBagPermissionsUpdateMessage::serializeAs_HavenBagPermissionsUpdateMessage(Writer *output)
{
  if(this->permissions < 0)
  {
    qDebug()<<"ERREUR - HavenBagPermissionsUpdateMessage -"<<"Forbidden value (" << this->permissions << ") on element permissions.";
  }
  output->writeInt((int)this->permissions);
}

void HavenBagPermissionsUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_HavenBagPermissionsUpdateMessage(input);
}

void HavenBagPermissionsUpdateMessage::deserializeAs_HavenBagPermissionsUpdateMessage(Reader *input)
{
  this->_permissionsFunc(input);
}

void HavenBagPermissionsUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HavenBagPermissionsUpdateMessage(tree);
}

void HavenBagPermissionsUpdateMessage::deserializeAsyncAs_HavenBagPermissionsUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HavenBagPermissionsUpdateMessage::_permissionsFunc, this, std::placeholders::_1));
}

void HavenBagPermissionsUpdateMessage::_permissionsFunc(Reader *input)
{
  this->permissions = input->readInt();
  if(this->permissions < 0)
  {
    qDebug()<<"ERREUR - HavenBagPermissionsUpdateMessage -"<<"Forbidden value (" << this->permissions << ") on element of HavenBagPermissionsUpdateMessage.permissions.";
  }
}

HavenBagPermissionsUpdateMessage::HavenBagPermissionsUpdateMessage()
{
  m_type = MessageEnum::HAVENBAGPERMISSIONSUPDATEMESSAGE;
}

