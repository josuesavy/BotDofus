#include "PortalInformation.h"

void PortalInformation::serialize(Writer *output)
{
  this->serializeAs_PortalInformation(output);
}

void PortalInformation::serializeAs_PortalInformation(Writer *output)
{
  output->writeInt((int)this->portalId);
  output->writeShort((short)this->areaId);
}

void PortalInformation::deserialize(Reader *input)
{
  this->deserializeAs_PortalInformation(input);
}

void PortalInformation::deserializeAs_PortalInformation(Reader *input)
{
  this->_portalIdFunc(input);
  this->_areaIdFunc(input);
}

void PortalInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PortalInformation(tree);
}

void PortalInformation::deserializeAsyncAs_PortalInformation(FuncTree tree)
{
  tree.addChild(std::bind(&PortalInformation::_portalIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PortalInformation::_areaIdFunc, this, std::placeholders::_1));
}

void PortalInformation::_portalIdFunc(Reader *input)
{
  this->portalId = input->readInt();
}

void PortalInformation::_areaIdFunc(Reader *input)
{
  this->areaId = input->readShort();
}

PortalInformation::PortalInformation()
{
  m_types<<ClassEnum::PORTALINFORMATION;
}

bool PortalInformation::operator==(const PortalInformation &compared)
{
  if(portalId == compared.portalId)
  if(areaId == compared.areaId)
  return true;
  
  return false;
}

