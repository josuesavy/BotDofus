#include "AllianceFactsRequestMessage.h"

void AllianceFactsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceFactsRequestMessage(output);
}

void AllianceFactsRequestMessage::serializeAs_AllianceFactsRequestMessage(Writer *output)
{
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceFactsRequestMessage -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  output->writeVarInt((int)this->allianceId);
}

void AllianceFactsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFactsRequestMessage(input);
}

void AllianceFactsRequestMessage::deserializeAs_AllianceFactsRequestMessage(Reader *input)
{
  this->_allianceIdFunc(input);
}

void AllianceFactsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFactsRequestMessage(tree);
}

void AllianceFactsRequestMessage::deserializeAsyncAs_AllianceFactsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceFactsRequestMessage::_allianceIdFunc, this, std::placeholders::_1));
}

void AllianceFactsRequestMessage::_allianceIdFunc(Reader *input)
{
  this->allianceId = input->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceFactsRequestMessage -"<<"Forbidden value (" << this->allianceId << ") on element of AllianceFactsRequestMessage.allianceId.";
  }
}

AllianceFactsRequestMessage::AllianceFactsRequestMessage()
{
  m_type = MessageEnum::ALLIANCEFACTSREQUESTMESSAGE;
}

