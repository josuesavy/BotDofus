#include "PortalDialogCreationMessage.h"

void PortalDialogCreationMessage::serialize(Writer *output)
{
  this->serializeAs_PortalDialogCreationMessage(output);
}

void PortalDialogCreationMessage::serializeAs_PortalDialogCreationMessage(Writer *output)
{
  NpcDialogCreationMessage::serializeAs_NpcDialogCreationMessage(output);
  output->writeInt((int)this->type);
}

void PortalDialogCreationMessage::deserialize(Reader *input)
{
  this->deserializeAs_PortalDialogCreationMessage(input);
}

void PortalDialogCreationMessage::deserializeAs_PortalDialogCreationMessage(Reader *input)
{
  NpcDialogCreationMessage::deserialize(input);
  this->_typeFunc(input);
}

void PortalDialogCreationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PortalDialogCreationMessage(tree);
}

void PortalDialogCreationMessage::deserializeAsyncAs_PortalDialogCreationMessage(FuncTree tree)
{
  NpcDialogCreationMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PortalDialogCreationMessage::_typeFunc, this, std::placeholders::_1));
}

void PortalDialogCreationMessage::_typeFunc(Reader *input)
{
  this->type = input->readInt();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - PortalDialogCreationMessage -"<<"Forbidden value (" << this->type << ") on element of PortalDialogCreationMessage.type.";
  }
}

PortalDialogCreationMessage::PortalDialogCreationMessage()
{
  m_type = MessageEnum::PORTALDIALOGCREATIONMESSAGE;
}

