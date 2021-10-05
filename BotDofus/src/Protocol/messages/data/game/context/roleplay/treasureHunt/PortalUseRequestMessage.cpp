#include "PortalUseRequestMessage.h"

void PortalUseRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PortalUseRequestMessage(output);
}

void PortalUseRequestMessage::serializeAs_PortalUseRequestMessage(Writer *output)
{
  if(this->portalId < 0)
  {
    qDebug()<<"ERREUR - PortalUseRequestMessage -"<<"Forbidden value (" << this->portalId << ") on element portalId.";
  }
  output->writeVarInt((int)this->portalId);
}

void PortalUseRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PortalUseRequestMessage(input);
}

void PortalUseRequestMessage::deserializeAs_PortalUseRequestMessage(Reader *input)
{
  this->_portalIdFunc(input);
}

void PortalUseRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PortalUseRequestMessage(tree);
}

void PortalUseRequestMessage::deserializeAsyncAs_PortalUseRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PortalUseRequestMessage::_portalIdFunc, this, std::placeholders::_1));
}

void PortalUseRequestMessage::_portalIdFunc(Reader *input)
{
  this->portalId = input->readVarUhInt();
  if(this->portalId < 0)
  {
    qDebug()<<"ERREUR - PortalUseRequestMessage -"<<"Forbidden value (" << this->portalId << ") on element of PortalUseRequestMessage.portalId.";
  }
}

PortalUseRequestMessage::PortalUseRequestMessage()
{
  m_type = MessageEnum::PORTALUSEREQUESTMESSAGE;
}

