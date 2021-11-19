#include "SystemMessageDisplayMessage.h"

void SystemMessageDisplayMessage::serialize(Writer *output)
{
  this->serializeAs_SystemMessageDisplayMessage(output);
}

void SystemMessageDisplayMessage::serializeAs_SystemMessageDisplayMessage(Writer *output)
{
  output->writeBool(this->hangUp);
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - SystemMessageDisplayMessage -"<<"Forbidden value (" << this->msgId << ") on element msgId.";
  }
  output->writeVarShort((int)this->msgId);
  output->writeShort((short)this->parameters.size());
  for(uint _i3 = 0; _i3 < this->parameters.size(); _i3++)
  {
    output->writeUTF(this->parameters[_i3]);
  }
}

void SystemMessageDisplayMessage::deserialize(Reader *input)
{
  this->deserializeAs_SystemMessageDisplayMessage(input);
}

void SystemMessageDisplayMessage::deserializeAs_SystemMessageDisplayMessage(Reader *input)
{
  QString _val3 ;
  this->_hangUpFunc(input);
  this->_msgIdFunc(input);
  uint _parametersLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _parametersLen; _i3++)
  {
    _val3 = input->readUTF();
    this->parameters.append(_val3);
  }
}

void SystemMessageDisplayMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SystemMessageDisplayMessage(tree);
}

void SystemMessageDisplayMessage::deserializeAsyncAs_SystemMessageDisplayMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SystemMessageDisplayMessage::_hangUpFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SystemMessageDisplayMessage::_msgIdFunc, this, std::placeholders::_1));
  this->_parameterstree = tree.addChild(std::bind(&SystemMessageDisplayMessage::_parameterstreeFunc, this, std::placeholders::_1));
}

void SystemMessageDisplayMessage::_hangUpFunc(Reader *input)
{
  this->hangUp = input->readBool();
}

void SystemMessageDisplayMessage::_msgIdFunc(Reader *input)
{
  this->msgId = input->readVarUhShort();
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - SystemMessageDisplayMessage -"<<"Forbidden value (" << this->msgId << ") on element of SystemMessageDisplayMessage.msgId.";
  }
}

void SystemMessageDisplayMessage::_parameterstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_parameterstree.addChild(std::bind(&SystemMessageDisplayMessage::_parametersFunc, this, std::placeholders::_1));
  }
}

void SystemMessageDisplayMessage::_parametersFunc(Reader *input)
{
  QString _val = input->readUTF();
  this->parameters.append(_val);
}

SystemMessageDisplayMessage::SystemMessageDisplayMessage()
{
  m_type = MessageEnum::SYSTEMMESSAGEDISPLAYMESSAGE;
}

