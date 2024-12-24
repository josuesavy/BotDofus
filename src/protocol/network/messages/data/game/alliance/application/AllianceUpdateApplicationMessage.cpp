#include "AllianceUpdateApplicationMessage.h"

void AllianceUpdateApplicationMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceUpdateApplicationMessage(output);
}

void AllianceUpdateApplicationMessage::serializeAs_AllianceUpdateApplicationMessage(Writer *output)
{
  output->writeUTF(this->applyText);
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceUpdateApplicationMessage -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  output->writeVarInt((int)this->allianceId);
}

void AllianceUpdateApplicationMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceUpdateApplicationMessage(input);
}

void AllianceUpdateApplicationMessage::deserializeAs_AllianceUpdateApplicationMessage(Reader *input)
{
  this->_applyTextFunc(input);
  this->_allianceIdFunc(input);
}

void AllianceUpdateApplicationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceUpdateApplicationMessage(tree);
}

void AllianceUpdateApplicationMessage::deserializeAsyncAs_AllianceUpdateApplicationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceUpdateApplicationMessage::_applyTextFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceUpdateApplicationMessage::_allianceIdFunc, this, std::placeholders::_1));
}

void AllianceUpdateApplicationMessage::_applyTextFunc(Reader *input)
{
  this->applyText = input->readUTF();
}

void AllianceUpdateApplicationMessage::_allianceIdFunc(Reader *input)
{
  this->allianceId = input->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceUpdateApplicationMessage -"<<"Forbidden value (" << this->allianceId << ") on element of AllianceUpdateApplicationMessage.allianceId.";
  }
}

AllianceUpdateApplicationMessage::AllianceUpdateApplicationMessage()
{
  m_type = MessageEnum::ALLIANCEUPDATEAPPLICATIONMESSAGE;
}

