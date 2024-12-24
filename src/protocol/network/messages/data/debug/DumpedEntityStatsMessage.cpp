#include "DumpedEntityStatsMessage.h"

void DumpedEntityStatsMessage::serialize(Writer *output)
{
  this->serializeAs_DumpedEntityStatsMessage(output);
}

void DumpedEntityStatsMessage::serializeAs_DumpedEntityStatsMessage(Writer *output)
{
  if(this->actorId < -9007199254740992 || this->actorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - DumpedEntityStatsMessage -"<<"Forbidden value (" << this->actorId << ") on element actorId.";
  }
  output->writeDouble(this->actorId);
  this->stats->serializeAs_CharacterCharacteristics(output);
}

void DumpedEntityStatsMessage::deserialize(Reader *input)
{
  this->deserializeAs_DumpedEntityStatsMessage(input);
}

void DumpedEntityStatsMessage::deserializeAs_DumpedEntityStatsMessage(Reader *input)
{
  this->_actorIdFunc(input);
  this->stats = QSharedPointer<CharacterCharacteristics>(new CharacterCharacteristics() );
  this->stats->deserialize(input);
}

void DumpedEntityStatsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DumpedEntityStatsMessage(tree);
}

void DumpedEntityStatsMessage::deserializeAsyncAs_DumpedEntityStatsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DumpedEntityStatsMessage::_actorIdFunc, this, std::placeholders::_1));
  this->_statstree = tree.addChild(std::bind(&DumpedEntityStatsMessage::_statstreeFunc, this, std::placeholders::_1));
}

void DumpedEntityStatsMessage::_actorIdFunc(Reader *input)
{
  this->actorId = input->readDouble();
  if(this->actorId < -9007199254740992 || this->actorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - DumpedEntityStatsMessage -"<<"Forbidden value (" << this->actorId << ") on element of DumpedEntityStatsMessage.actorId.";
  }
}

void DumpedEntityStatsMessage::_statstreeFunc(Reader *input)
{
  this->stats = QSharedPointer<CharacterCharacteristics>(new CharacterCharacteristics() );
  this->stats->deserializeAsync(this->_statstree);
}

DumpedEntityStatsMessage::DumpedEntityStatsMessage()
{
  m_type = MessageEnum::DUMPEDENTITYSTATSMESSAGE;
}

