#include "EntityTalkMessage.h"

void EntityTalkMessage::serialize(Writer *output)
{
  this->serializeAs_EntityTalkMessage(output);
}

void EntityTalkMessage::serializeAs_EntityTalkMessage(Writer *output)
{
  if(this->entityId < -9007199254740992 || this->entityId > 9007199254740992)
  {
    qDebug()<<"ERREUR - EntityTalkMessage -"<<"Forbidden value (" << this->entityId << ") on element entityId.";
  }
  output->writeDouble(this->entityId);
  if(this->textId < 0)
  {
    qDebug()<<"ERREUR - EntityTalkMessage -"<<"Forbidden value (" << this->textId << ") on element textId.";
  }
  output->writeVarShort((int)this->textId);
  output->writeShort((short)this->parameters.size());
  for(uint _i3 = 0; _i3 < this->parameters.size(); _i3++)
  {
    output->writeUTF(this->parameters[_i3]);
  }
}

void EntityTalkMessage::deserialize(Reader *input)
{
  this->deserializeAs_EntityTalkMessage(input);
}

void EntityTalkMessage::deserializeAs_EntityTalkMessage(Reader *input)
{
  QString _val3 ;
  this->_entityIdFunc(input);
  this->_textIdFunc(input);
  uint _parametersLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _parametersLen; _i3++)
  {
    _val3 = input->readUTF();
    this->parameters.append(_val3);
  }
}

void EntityTalkMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EntityTalkMessage(tree);
}

void EntityTalkMessage::deserializeAsyncAs_EntityTalkMessage(FuncTree tree)
{
  tree.addChild(std::bind(&EntityTalkMessage::_entityIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&EntityTalkMessage::_textIdFunc, this, std::placeholders::_1));
  this->_parameterstree = tree.addChild(std::bind(&EntityTalkMessage::_parameterstreeFunc, this, std::placeholders::_1));
}

void EntityTalkMessage::_entityIdFunc(Reader *input)
{
  this->entityId = input->readDouble();
  if(this->entityId < -9007199254740992 || this->entityId > 9007199254740992)
  {
    qDebug()<<"ERREUR - EntityTalkMessage -"<<"Forbidden value (" << this->entityId << ") on element of EntityTalkMessage.entityId.";
  }
}

void EntityTalkMessage::_textIdFunc(Reader *input)
{
  this->textId = input->readVarUhShort();
  if(this->textId < 0)
  {
    qDebug()<<"ERREUR - EntityTalkMessage -"<<"Forbidden value (" << this->textId << ") on element of EntityTalkMessage.textId.";
  }
}

void EntityTalkMessage::_parameterstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_parameterstree.addChild(std::bind(&EntityTalkMessage::_parametersFunc, this, std::placeholders::_1));
  }
}

void EntityTalkMessage::_parametersFunc(Reader *input)
{
  QString _val = input->readUTF();
  this->parameters.append(_val);
}

EntityTalkMessage::EntityTalkMessage()
{
  m_type = MessageEnum::ENTITYTALKMESSAGE;
}

