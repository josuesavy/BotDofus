#include "AllianceSubmitApplicationMessage.h"

void AllianceSubmitApplicationMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceSubmitApplicationMessage(output);
}

void AllianceSubmitApplicationMessage::serializeAs_AllianceSubmitApplicationMessage(Writer *output)
{
  output->writeUTF(this->applyText);
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceSubmitApplicationMessage -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  output->writeVarInt((int)this->allianceId);
}

void AllianceSubmitApplicationMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceSubmitApplicationMessage(input);
}

void AllianceSubmitApplicationMessage::deserializeAs_AllianceSubmitApplicationMessage(Reader *input)
{
  this->_applyTextFunc(input);
  this->_allianceIdFunc(input);
}

void AllianceSubmitApplicationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceSubmitApplicationMessage(tree);
}

void AllianceSubmitApplicationMessage::deserializeAsyncAs_AllianceSubmitApplicationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceSubmitApplicationMessage::_applyTextFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceSubmitApplicationMessage::_allianceIdFunc, this, std::placeholders::_1));
}

void AllianceSubmitApplicationMessage::_applyTextFunc(Reader *input)
{
  this->applyText = input->readUTF();
}

void AllianceSubmitApplicationMessage::_allianceIdFunc(Reader *input)
{
  this->allianceId = input->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceSubmitApplicationMessage -"<<"Forbidden value (" << this->allianceId << ") on element of AllianceSubmitApplicationMessage.allianceId.";
  }
}

AllianceSubmitApplicationMessage::AllianceSubmitApplicationMessage()
{
  m_type = MessageEnum::ALLIANCESUBMITAPPLICATIONMESSAGE;
}

