#include "AllianceJoinedMessage.h"

void AllianceJoinedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceJoinedMessage(output);
}

void AllianceJoinedMessage::serializeAs_AllianceJoinedMessage(Writer *output)
{
  this->allianceInfo->serializeAs_AllianceInformations(output);
  output->writeBool(this->enabled);
  if(this->leadingGuildId < 0)
  {
    qDebug()<<"ERREUR - AllianceJoinedMessage -"<<"Forbidden value (" << this->leadingGuildId << ") on element leadingGuildId.";
  }
  output->writeVarInt((int)this->leadingGuildId);
}

void AllianceJoinedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceJoinedMessage(input);
}

void AllianceJoinedMessage::deserializeAs_AllianceJoinedMessage(Reader *input)
{
  this->allianceInfo = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->allianceInfo->deserialize(input);
  this->_enabledFunc(input);
  this->_leadingGuildIdFunc(input);
}

void AllianceJoinedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceJoinedMessage(tree);
}

void AllianceJoinedMessage::deserializeAsyncAs_AllianceJoinedMessage(FuncTree tree)
{
  this->_allianceInfotree = tree.addChild(std::bind(&AllianceJoinedMessage::_allianceInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceJoinedMessage::_enabledFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceJoinedMessage::_leadingGuildIdFunc, this, std::placeholders::_1));
}

void AllianceJoinedMessage::_allianceInfotreeFunc(Reader *input)
{
  this->allianceInfo = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->allianceInfo->deserializeAsync(this->_allianceInfotree);
}

void AllianceJoinedMessage::_enabledFunc(Reader *input)
{
  this->enabled = input->readBool();
}

void AllianceJoinedMessage::_leadingGuildIdFunc(Reader *input)
{
  this->leadingGuildId = input->readVarUhInt();
  if(this->leadingGuildId < 0)
  {
    qDebug()<<"ERREUR - AllianceJoinedMessage -"<<"Forbidden value (" << this->leadingGuildId << ") on element of AllianceJoinedMessage.leadingGuildId.";
  }
}

AllianceJoinedMessage::AllianceJoinedMessage()
{
  m_type = MessageEnum::ALLIANCEJOINEDMESSAGE;
}

