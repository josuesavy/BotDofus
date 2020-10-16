#include "InteractiveUseRequestMessage.h"

void InteractiveUseRequestMessage::serialize(Writer *output)
{
  this->serializeAs_InteractiveUseRequestMessage(output);
}

void InteractiveUseRequestMessage::serializeAs_InteractiveUseRequestMessage(Writer *output)
{
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseRequestMessage -"<<"Forbidden value (" << this->elemId << ") on element elemId.";
  }
  output->writeVarInt((int)this->elemId);
  if(this->skillInstanceUid < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseRequestMessage -"<<"Forbidden value (" << this->skillInstanceUid << ") on element skillInstanceUid.";
  }
  output->writeVarInt((int)this->skillInstanceUid);
}

void InteractiveUseRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveUseRequestMessage(input);
}

void InteractiveUseRequestMessage::deserializeAs_InteractiveUseRequestMessage(Reader *input)
{
  this->_elemIdFunc(input);
  this->_skillInstanceUidFunc(input);
}

void InteractiveUseRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveUseRequestMessage(tree);
}

void InteractiveUseRequestMessage::deserializeAsyncAs_InteractiveUseRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&InteractiveUseRequestMessage::_elemIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InteractiveUseRequestMessage::_skillInstanceUidFunc, this, std::placeholders::_1));
}

void InteractiveUseRequestMessage::_elemIdFunc(Reader *input)
{
  this->elemId = input->readVarUhInt();
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseRequestMessage -"<<"Forbidden value (" << this->elemId << ") on element of InteractiveUseRequestMessage.elemId.";
  }
}

void InteractiveUseRequestMessage::_skillInstanceUidFunc(Reader *input)
{
  this->skillInstanceUid = input->readVarUhInt();
  if(this->skillInstanceUid < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseRequestMessage -"<<"Forbidden value (" << this->skillInstanceUid << ") on element of InteractiveUseRequestMessage.skillInstanceUid.";
  }
}

InteractiveUseRequestMessage::InteractiveUseRequestMessage()
{
  m_type = MessageEnum::INTERACTIVEUSEREQUESTMESSAGE;
  m_needsHash = true;
}

