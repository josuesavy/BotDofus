#include "NotificationByServerMessage.h"

void NotificationByServerMessage::serialize(Writer *output)
{
  this->serializeAs_NotificationByServerMessage(output);
}

void NotificationByServerMessage::serializeAs_NotificationByServerMessage(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - NotificationByServerMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarShort((int)this->id);
  output->writeShort((short)this->parameters.size());
  for(uint _i2 = 0; _i2 < this->parameters.size(); _i2++)
  {
    output->writeUTF(this->parameters[_i2]);
  }
  output->writeBool(this->forceOpen);
}

void NotificationByServerMessage::deserialize(Reader *input)
{
  this->deserializeAs_NotificationByServerMessage(input);
}

void NotificationByServerMessage::deserializeAs_NotificationByServerMessage(Reader *input)
{
  QString _val2 ;
  this->_idFunc(input);
  uint _parametersLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _parametersLen; _i2++)
  {
    _val2 = String(input->readUTF());
    this->parameters.append(_val2);
  }
  this->_forceOpenFunc(input);
}

void NotificationByServerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NotificationByServerMessage(tree);
}

void NotificationByServerMessage::deserializeAsyncAs_NotificationByServerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NotificationByServerMessage::_idFunc, this, std::placeholders::_1));
  this->_parameterstree = tree.addChild(std::bind(&NotificationByServerMessage::_parameterstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&NotificationByServerMessage::_forceOpenFunc, this, std::placeholders::_1));
}

void NotificationByServerMessage::_idFunc(Reader *input)
{
  this->id = input->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - NotificationByServerMessage -"<<"Forbidden value (" << this->id << ") on element of NotificationByServerMessage.id.";
  }
}

void NotificationByServerMessage::_parameterstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_parameterstree.addChild(std::bind(&NotificationByServerMessage::_parametersFunc, this, std::placeholders::_1));
  }
}

void NotificationByServerMessage::_parametersFunc(Reader *input)
{
  QString _val = String(input->readUTF());
  this->parameters.append(_val);
}

void NotificationByServerMessage::_forceOpenFunc(Reader *input)
{
  this->forceOpen = input->readBool();
}

NotificationByServerMessage::NotificationByServerMessage()
{
  m_type = MessageEnum::NOTIFICATIONBYSERVERMESSAGE;
}

