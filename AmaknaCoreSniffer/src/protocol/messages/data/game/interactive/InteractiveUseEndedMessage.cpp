#include "InteractiveUseEndedMessage.h"

void InteractiveUseEndedMessage::serialize(Writer *output)
{
  this->serializeAs_InteractiveUseEndedMessage(output);
}

void InteractiveUseEndedMessage::serializeAs_InteractiveUseEndedMessage(Writer *output)
{
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseEndedMessage -"<<"Forbidden value (" << this->elemId << ") on element elemId.";
  }
  output->writeVarInt((int)this->elemId);
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseEndedMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  output->writeVarShort((int)this->skillId);
}

void InteractiveUseEndedMessage::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveUseEndedMessage(input);
}

void InteractiveUseEndedMessage::deserializeAs_InteractiveUseEndedMessage(Reader *input)
{
  this->_elemIdFunc(input);
  this->_skillIdFunc(input);
}

void InteractiveUseEndedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveUseEndedMessage(tree);
}

void InteractiveUseEndedMessage::deserializeAsyncAs_InteractiveUseEndedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&InteractiveUseEndedMessage::_elemIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InteractiveUseEndedMessage::_skillIdFunc, this, std::placeholders::_1));
}

void InteractiveUseEndedMessage::_elemIdFunc(Reader *input)
{
  this->elemId = input->readVarUhInt();
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseEndedMessage -"<<"Forbidden value (" << this->elemId << ") on element of InteractiveUseEndedMessage.elemId.";
  }
}

void InteractiveUseEndedMessage::_skillIdFunc(Reader *input)
{
  this->skillId = input->readVarUhShort();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseEndedMessage -"<<"Forbidden value (" << this->skillId << ") on element of InteractiveUseEndedMessage.skillId.";
  }
}

InteractiveUseEndedMessage::InteractiveUseEndedMessage()
{
  m_type = MessageEnum::INTERACTIVEUSEENDEDMESSAGE;
}

