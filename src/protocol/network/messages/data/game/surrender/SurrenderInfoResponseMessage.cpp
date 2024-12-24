#include "SurrenderInfoResponseMessage.h"

void SurrenderInfoResponseMessage::serialize(Writer *output)
{
  this->serializeAs_SurrenderInfoResponseMessage(output);
}

void SurrenderInfoResponseMessage::serializeAs_SurrenderInfoResponseMessage(Writer *output)
{
  output->writeBool(this->hasSanction);
  output->writeShort((short)this->surrenderResponse->getTypes().last());
  this->surrenderResponse->serialize(output);
  output->writeShort((short)this->surrenderVoteResponse->getTypes().last());
  this->surrenderVoteResponse->serialize(output);
}

void SurrenderInfoResponseMessage::deserialize(Reader *input)
{
  this->deserializeAs_SurrenderInfoResponseMessage(input);
}

void SurrenderInfoResponseMessage::deserializeAs_SurrenderInfoResponseMessage(Reader *input)
{
  this->_hasSanctionFunc(input);
  uint _id2 = uint(input->readUShort());
  this->surrenderResponse = qSharedPointerCast<SurrenderResponse>(ClassManagerSingleton::get()->getClass(_id2));
  this->surrenderResponse->deserialize(input);
  uint _id3 = uint(input->readUShort());
  this->surrenderVoteResponse = qSharedPointerCast<SurrenderVoteResponse>(ClassManagerSingleton::get()->getClass(_id3));
  this->surrenderVoteResponse->deserialize(input);
}

void SurrenderInfoResponseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SurrenderInfoResponseMessage(tree);
}

void SurrenderInfoResponseMessage::deserializeAsyncAs_SurrenderInfoResponseMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SurrenderInfoResponseMessage::_hasSanctionFunc, this, std::placeholders::_1));
  this->_surrenderResponsetree = tree.addChild(std::bind(&SurrenderInfoResponseMessage::_surrenderResponsetreeFunc, this, std::placeholders::_1));
  this->_surrenderVoteResponsetree = tree.addChild(std::bind(&SurrenderInfoResponseMessage::_surrenderVoteResponsetreeFunc, this, std::placeholders::_1));
}

void SurrenderInfoResponseMessage::_hasSanctionFunc(Reader *input)
{
  this->hasSanction = input->readBool();
}

void SurrenderInfoResponseMessage::_surrenderResponsetreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->surrenderResponse = qSharedPointerCast<SurrenderResponse>(ClassManagerSingleton::get()->getClass(_id));
  this->surrenderResponse->deserializeAsync(this->_surrenderResponsetree);
}

void SurrenderInfoResponseMessage::_surrenderVoteResponsetreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->surrenderVoteResponse = qSharedPointerCast<SurrenderVoteResponse>(ClassManagerSingleton::get()->getClass(_id));
  this->surrenderVoteResponse->deserializeAsync(this->_surrenderVoteResponsetree);
}

SurrenderInfoResponseMessage::SurrenderInfoResponseMessage()
{
  m_type = MessageEnum::SURRENDERINFORESPONSEMESSAGE;
}

