#include "AbstractGameActionMessage.h"

void AbstractGameActionMessage::serialize(Writer *output)
{
  this->serializeAs_AbstractGameActionMessage(output);
}

void AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(Writer *output)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - AbstractGameActionMessage -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  output->writeVarShort((int)this->actionId);
  if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractGameActionMessage -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
  }
  output->writeDouble(this->sourceId);
}

void AbstractGameActionMessage::deserialize(Reader *input)
{
  this->deserializeAs_AbstractGameActionMessage(input);
}

void AbstractGameActionMessage::deserializeAs_AbstractGameActionMessage(Reader *input)
{
  this->_actionIdFunc(input);
  this->_sourceIdFunc(input);
}

void AbstractGameActionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractGameActionMessage(tree);
}

void AbstractGameActionMessage::deserializeAsyncAs_AbstractGameActionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AbstractGameActionMessage::_actionIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractGameActionMessage::_sourceIdFunc, this, std::placeholders::_1));
}

void AbstractGameActionMessage::_actionIdFunc(Reader *input)
{
  this->actionId = input->readVarUhShort();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - AbstractGameActionMessage -"<<"Forbidden value (" << this->actionId << ") on element of AbstractGameActionMessage.actionId.";
  }
}

void AbstractGameActionMessage::_sourceIdFunc(Reader *input)
{
  this->sourceId = input->readDouble();
  if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractGameActionMessage -"<<"Forbidden value (" << this->sourceId << ") on element of AbstractGameActionMessage.sourceId.";
  }
}

AbstractGameActionMessage::AbstractGameActionMessage()
{
  m_type = MessageEnum::ABSTRACTGAMEACTIONMESSAGE;
}

