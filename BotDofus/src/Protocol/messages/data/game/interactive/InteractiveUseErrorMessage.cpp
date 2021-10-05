#include "InteractiveUseErrorMessage.h"

void InteractiveUseErrorMessage::serialize(Writer *output)
{
  this->serializeAs_InteractiveUseErrorMessage(output);
}

void InteractiveUseErrorMessage::serializeAs_InteractiveUseErrorMessage(Writer *output)
{
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseErrorMessage -"<<"Forbidden value (" << this->elemId << ") on element elemId.";
  }
  output->writeVarInt((int)this->elemId);
  if(this->skillInstanceUid < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseErrorMessage -"<<"Forbidden value (" << this->skillInstanceUid << ") on element skillInstanceUid.";
  }
  output->writeVarInt((int)this->skillInstanceUid);
}

void InteractiveUseErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveUseErrorMessage(input);
}

void InteractiveUseErrorMessage::deserializeAs_InteractiveUseErrorMessage(Reader *input)
{
  this->_elemIdFunc(input);
  this->_skillInstanceUidFunc(input);
}

void InteractiveUseErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveUseErrorMessage(tree);
}

void InteractiveUseErrorMessage::deserializeAsyncAs_InteractiveUseErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&InteractiveUseErrorMessage::_elemIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InteractiveUseErrorMessage::_skillInstanceUidFunc, this, std::placeholders::_1));
}

void InteractiveUseErrorMessage::_elemIdFunc(Reader *input)
{
  this->elemId = input->readVarUhInt();
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseErrorMessage -"<<"Forbidden value (" << this->elemId << ") on element of InteractiveUseErrorMessage.elemId.";
  }
}

void InteractiveUseErrorMessage::_skillInstanceUidFunc(Reader *input)
{
  this->skillInstanceUid = input->readVarUhInt();
  if(this->skillInstanceUid < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseErrorMessage -"<<"Forbidden value (" << this->skillInstanceUid << ") on element of InteractiveUseErrorMessage.skillInstanceUid.";
  }
}

InteractiveUseErrorMessage::InteractiveUseErrorMessage()
{
  m_type = MessageEnum::INTERACTIVEUSEERRORMESSAGE;
}

