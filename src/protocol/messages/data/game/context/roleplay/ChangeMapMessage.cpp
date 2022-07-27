#include "ChangeMapMessage.h"

void ChangeMapMessage::serialize(Writer *output)
{
  this->serializeAs_ChangeMapMessage(output);
}

void ChangeMapMessage::serializeAs_ChangeMapMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChangeMapMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  output->writeBool(this->autopilot);
}

void ChangeMapMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChangeMapMessage(input);
}

void ChangeMapMessage::deserializeAs_ChangeMapMessage(Reader *input)
{
  this->_mapIdFunc(input);
  this->_autopilotFunc(input);
}

void ChangeMapMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChangeMapMessage(tree);
}

void ChangeMapMessage::deserializeAsyncAs_ChangeMapMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChangeMapMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChangeMapMessage::_autopilotFunc, this, std::placeholders::_1));
}

void ChangeMapMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChangeMapMessage -"<<"Forbidden value (" << this->mapId << ") on element of ChangeMapMessage.mapId.";
  }
}

void ChangeMapMessage::_autopilotFunc(Reader *input)
{
  this->autopilot = input->readBool();
}

ChangeMapMessage::ChangeMapMessage()
{
  m_type = MessageEnum::CHANGEMAPMESSAGE;
}

