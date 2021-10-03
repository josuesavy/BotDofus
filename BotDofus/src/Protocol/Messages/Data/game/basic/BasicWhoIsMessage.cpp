#include "BasicWhoIsMessage.h"

void BasicWhoIsMessage::serialize(Writer *output)
{
  this->serializeAs_BasicWhoIsMessage(output);
}

void BasicWhoIsMessage::serializeAs_BasicWhoIsMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->self);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->verbose);
  output->writeByte(_box0);
  output->writeByte(this->position);
  this->accountTag.serializeAs_AccountTagInformation(output);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - BasicWhoIsMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
  output->writeUTF(this->playerName);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BasicWhoIsMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeShort((short)this->areaId);
  output->writeShort((short)this->serverId);
  output->writeShort((short)this->originServerId);
  output->writeShort((short)this->socialGroups.size());
  for(uint _i10 = 0; _i10 < this->socialGroups.size(); _i10++)
  {
    output->writeShort((short)qSharedPointerCast<AbstractSocialGroupInfos>(this->socialGroups[_i10])->getTypes().last());
    qSharedPointerCast<AbstractSocialGroupInfos>(this->socialGroups[_i10])->serialize(output);
  }
  output->writeByte(this->playerState);
}

void BasicWhoIsMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicWhoIsMessage(input);
}

void BasicWhoIsMessage::deserializeAs_BasicWhoIsMessage(Reader *input)
{
  uint _id10 = 0;
  QSharedPointer<AbstractSocialGroupInfos> _item10 ;
  this->deserializeByteBoxes(input);
  this->_positionFunc(input);
  this->accountTag = AccountTagInformation();
  this->accountTag.deserialize(input);
  this->_accountIdFunc(input);
  this->_playerNameFunc(input);
  this->_playerIdFunc(input);
  this->_areaIdFunc(input);
  this->_serverIdFunc(input);
  this->_originServerIdFunc(input);
  uint _socialGroupsLen = input->readUShort();
  for(uint _i10 = 0; _i10 < _socialGroupsLen; _i10++)
  {
    _id10 = input->readUShort();
    _item10 = qSharedPointerCast<AbstractSocialGroupInfos>(ClassManagerSingleton::get()->getClass(_id10));
    _item10->deserialize(input);
    this->socialGroups.append(_item10);
  }
  this->_playerStateFunc(input);
}

void BasicWhoIsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicWhoIsMessage(tree);
}

void BasicWhoIsMessage::deserializeAsyncAs_BasicWhoIsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicWhoIsMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicWhoIsMessage::_positionFunc, this, std::placeholders::_1));
  this->_accountTagtree = tree.addChild(std::bind(&BasicWhoIsMessage::_accountTagtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicWhoIsMessage::_accountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicWhoIsMessage::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicWhoIsMessage::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicWhoIsMessage::_areaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicWhoIsMessage::_serverIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicWhoIsMessage::_originServerIdFunc, this, std::placeholders::_1));
  this->_socialGroupstree = tree.addChild(std::bind(&BasicWhoIsMessage::_socialGroupstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicWhoIsMessage::_playerStateFunc, this, std::placeholders::_1));
}

void BasicWhoIsMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->self = BooleanByteWrapper::getFlag(_box0, 0);
  this->verbose = BooleanByteWrapper::getFlag(_box0, 1);
}

void BasicWhoIsMessage::_positionFunc(Reader *input)
{
  this->position = input->readByte();
}

void BasicWhoIsMessage::_accountTagtreeFunc(Reader *input)
{
  this->accountTag = AccountTagInformation();
  this->accountTag.deserializeAsync(this->_accountTagtree);
}

void BasicWhoIsMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - BasicWhoIsMessage -"<<"Forbidden value (" << this->accountId << ") on element of BasicWhoIsMessage.accountId.";
  }
}

void BasicWhoIsMessage::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void BasicWhoIsMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BasicWhoIsMessage -"<<"Forbidden value (" << this->playerId << ") on element of BasicWhoIsMessage.playerId.";
  }
}

void BasicWhoIsMessage::_areaIdFunc(Reader *input)
{
  this->areaId = input->readShort();
}

void BasicWhoIsMessage::_serverIdFunc(Reader *input)
{
  this->serverId = input->readShort();
}

void BasicWhoIsMessage::_originServerIdFunc(Reader *input)
{
  this->originServerId = input->readShort();
}

void BasicWhoIsMessage::_socialGroupstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_socialGroupstree.addChild(std::bind(&BasicWhoIsMessage::_socialGroupsFunc, this, std::placeholders::_1));
  }
}

void BasicWhoIsMessage::_socialGroupsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<AbstractSocialGroupInfos> _item = qSharedPointerCast<AbstractSocialGroupInfos>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->socialGroups.append(_item);
}

void BasicWhoIsMessage::_playerStateFunc(Reader *input)
{
  this->playerState = input->readByte();
  if(this->playerState < 0)
  {
    qDebug()<<"ERREUR - BasicWhoIsMessage -"<<"Forbidden value (" << this->playerState << ") on element of BasicWhoIsMessage.playerState.";
  }
}

BasicWhoIsMessage::BasicWhoIsMessage()
{
  m_type = MessageEnum::BASICWHOISMESSAGE;
}

