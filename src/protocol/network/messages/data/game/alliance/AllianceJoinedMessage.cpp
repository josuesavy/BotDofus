#include "AllianceJoinedMessage.h"

void AllianceJoinedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceJoinedMessage(output);
}

void AllianceJoinedMessage::serializeAs_AllianceJoinedMessage(Writer *output)
{
  this->allianceInfo->serializeAs_AllianceInformation(output);
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - AllianceJoinedMessage -"<<"Forbidden value (" << this->rankId << ") on element rankId.";
  }
  output->writeVarInt((int)this->rankId);
}

void AllianceJoinedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceJoinedMessage(input);
}

void AllianceJoinedMessage::deserializeAs_AllianceJoinedMessage(Reader *input)
{
  this->allianceInfo = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceInfo->deserialize(input);
  this->_rankIdFunc(input);
}

void AllianceJoinedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceJoinedMessage(tree);
}

void AllianceJoinedMessage::deserializeAsyncAs_AllianceJoinedMessage(FuncTree tree)
{
  this->_allianceInfotree = tree.addChild(std::bind(&AllianceJoinedMessage::_allianceInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceJoinedMessage::_rankIdFunc, this, std::placeholders::_1));
}

void AllianceJoinedMessage::_allianceInfotreeFunc(Reader *input)
{
  this->allianceInfo = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceInfo->deserializeAsync(this->_allianceInfotree);
}

void AllianceJoinedMessage::_rankIdFunc(Reader *input)
{
  this->rankId = input->readVarUhInt();
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - AllianceJoinedMessage -"<<"Forbidden value (" << this->rankId << ") on element of AllianceJoinedMessage.rankId.";
  }
}

AllianceJoinedMessage::AllianceJoinedMessage()
{
  m_type = MessageEnum::ALLIANCEJOINEDMESSAGE;
}

