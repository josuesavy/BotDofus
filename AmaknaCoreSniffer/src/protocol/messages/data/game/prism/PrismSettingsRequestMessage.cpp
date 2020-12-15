#include "PrismSettingsRequestMessage.h"

void PrismSettingsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PrismSettingsRequestMessage(output);
}

void PrismSettingsRequestMessage::serializeAs_PrismSettingsRequestMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSettingsRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  if(this->startDefenseTime < 0)
  {
    qDebug()<<"ERREUR - PrismSettingsRequestMessage -"<<"Forbidden value (" << this->startDefenseTime << ") on element startDefenseTime.";
  }
  output->writeByte(this->startDefenseTime);
}

void PrismSettingsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismSettingsRequestMessage(input);
}

void PrismSettingsRequestMessage::deserializeAs_PrismSettingsRequestMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_startDefenseTimeFunc(input);
}

void PrismSettingsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismSettingsRequestMessage(tree);
}

void PrismSettingsRequestMessage::deserializeAsyncAs_PrismSettingsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismSettingsRequestMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismSettingsRequestMessage::_startDefenseTimeFunc, this, std::placeholders::_1));
}

void PrismSettingsRequestMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSettingsRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismSettingsRequestMessage.subAreaId.";
  }
}

void PrismSettingsRequestMessage::_startDefenseTimeFunc(Reader *input)
{
  this->startDefenseTime = input->readByte();
  if(this->startDefenseTime < 0)
  {
    qDebug()<<"ERREUR - PrismSettingsRequestMessage -"<<"Forbidden value (" << this->startDefenseTime << ") on element of PrismSettingsRequestMessage.startDefenseTime.";
  }
}

PrismSettingsRequestMessage::PrismSettingsRequestMessage()
{
  m_type = MessageEnum::PRISMSETTINGSREQUESTMESSAGE;
}

