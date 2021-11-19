#include "CurrentMapMessage.h"

void CurrentMapMessage::serialize(Writer *output)
{
  this->serializeAs_CurrentMapMessage(output);
}

void CurrentMapMessage::serializeAs_CurrentMapMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CurrentMapMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  output->writeUTF(this->mapKey);
}

void CurrentMapMessage::deserialize(Reader *input)
{
  this->deserializeAs_CurrentMapMessage(input);
}

void CurrentMapMessage::deserializeAs_CurrentMapMessage(Reader *input)
{
  this->_mapIdFunc(input);
  this->_mapKeyFunc(input);
}

void CurrentMapMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CurrentMapMessage(tree);
}

void CurrentMapMessage::deserializeAsyncAs_CurrentMapMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CurrentMapMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CurrentMapMessage::_mapKeyFunc, this, std::placeholders::_1));
}

void CurrentMapMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CurrentMapMessage -"<<"Forbidden value (" << this->mapId << ") on element of CurrentMapMessage.mapId.";
  }
}

void CurrentMapMessage::_mapKeyFunc(Reader *input)
{
  this->mapKey = input->readUTF();
}

CurrentMapMessage::CurrentMapMessage()
{
  m_type = MessageEnum::CURRENTMAPMESSAGE;
}

