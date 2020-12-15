#include "PartyEntityUpdateLightMessage.h"

void PartyEntityUpdateLightMessage::serialize(Writer *output)
{
  this->serializeAs_PartyEntityUpdateLightMessage(output);
}

void PartyEntityUpdateLightMessage::serializeAs_PartyEntityUpdateLightMessage(Writer *output)
{
  PartyUpdateLightMessage::serializeAs_PartyUpdateLightMessage(output);
  if(this->indexId < 0)
  {
    qDebug()<<"ERREUR - PartyEntityUpdateLightMessage -"<<"Forbidden value (" << this->indexId << ") on element indexId.";
  }
  output->writeByte(this->indexId);
}

void PartyEntityUpdateLightMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyEntityUpdateLightMessage(input);
}

void PartyEntityUpdateLightMessage::deserializeAs_PartyEntityUpdateLightMessage(Reader *input)
{
  PartyUpdateLightMessage::deserialize(input);
  this->_indexIdFunc(input);
}

void PartyEntityUpdateLightMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyEntityUpdateLightMessage(tree);
}

void PartyEntityUpdateLightMessage::deserializeAsyncAs_PartyEntityUpdateLightMessage(FuncTree tree)
{
  PartyUpdateLightMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyEntityUpdateLightMessage::_indexIdFunc, this, std::placeholders::_1));
}

void PartyEntityUpdateLightMessage::_indexIdFunc(Reader *input)
{
  this->indexId = input->readByte();
  if(this->indexId < 0)
  {
    qDebug()<<"ERREUR - PartyEntityUpdateLightMessage -"<<"Forbidden value (" << this->indexId << ") on element of PartyEntityUpdateLightMessage.indexId.";
  }
}

PartyEntityUpdateLightMessage::PartyEntityUpdateLightMessage()
{
  m_type = MessageEnum::PARTYENTITYUPDATELIGHTMESSAGE;
}

