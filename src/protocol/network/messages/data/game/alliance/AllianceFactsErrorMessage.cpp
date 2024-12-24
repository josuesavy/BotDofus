#include "AllianceFactsErrorMessage.h"

void AllianceFactsErrorMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceFactsErrorMessage(output);
}

void AllianceFactsErrorMessage::serializeAs_AllianceFactsErrorMessage(Writer *output)
{
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceFactsErrorMessage -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  output->writeVarInt((int)this->allianceId);
}

void AllianceFactsErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFactsErrorMessage(input);
}

void AllianceFactsErrorMessage::deserializeAs_AllianceFactsErrorMessage(Reader *input)
{
  this->_allianceIdFunc(input);
}

void AllianceFactsErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFactsErrorMessage(tree);
}

void AllianceFactsErrorMessage::deserializeAsyncAs_AllianceFactsErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceFactsErrorMessage::_allianceIdFunc, this, std::placeholders::_1));
}

void AllianceFactsErrorMessage::_allianceIdFunc(Reader *input)
{
  this->allianceId = input->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceFactsErrorMessage -"<<"Forbidden value (" << this->allianceId << ") on element of AllianceFactsErrorMessage.allianceId.";
  }
}

AllianceFactsErrorMessage::AllianceFactsErrorMessage()
{
  m_type = MessageEnum::ALLIANCEFACTSERRORMESSAGE;
}

