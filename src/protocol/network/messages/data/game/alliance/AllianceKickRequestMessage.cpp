#include "AllianceKickRequestMessage.h"

void AllianceKickRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceKickRequestMessage(output);
}

void AllianceKickRequestMessage::serializeAs_AllianceKickRequestMessage(Writer *output)
{
  if(this->kickedId < -9007199254740992 || this->kickedId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceKickRequestMessage -"<<"Forbidden value (" << this->kickedId << ") on element kickedId.";
  }
  output->writeVarLong((double)this->kickedId);
}

void AllianceKickRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceKickRequestMessage(input);
}

void AllianceKickRequestMessage::deserializeAs_AllianceKickRequestMessage(Reader *input)
{
  this->_kickedIdFunc(input);
}

void AllianceKickRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceKickRequestMessage(tree);
}

void AllianceKickRequestMessage::deserializeAsyncAs_AllianceKickRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceKickRequestMessage::_kickedIdFunc, this, std::placeholders::_1));
}

void AllianceKickRequestMessage::_kickedIdFunc(Reader *input)
{
  this->kickedId = input->readVarLong();
  if(this->kickedId < -9007199254740992 || this->kickedId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceKickRequestMessage -"<<"Forbidden value (" << this->kickedId << ") on element of AllianceKickRequestMessage.kickedId.";
  }
}

AllianceKickRequestMessage::AllianceKickRequestMessage()
{
  m_type = MessageEnum::ALLIANCEKICKREQUESTMESSAGE;
}

