#include "GameFightResumeWithSlavesMessage.h"

void GameFightResumeWithSlavesMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightResumeWithSlavesMessage(output);
}

void GameFightResumeWithSlavesMessage::serializeAs_GameFightResumeWithSlavesMessage(Writer *output)
{
  GameFightResumeMessage::serializeAs_GameFightResumeMessage(output);
  output->writeShort((short)this->slavesInfo.size());
  for(uint _i1 = 0; _i1 < this->slavesInfo.size(); _i1++)
  {
    (this->slavesInfo[_i1]).serializeAs_GameFightResumeSlaveInfo(output);
  }
}

void GameFightResumeWithSlavesMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightResumeWithSlavesMessage(input);
}

void GameFightResumeWithSlavesMessage::deserializeAs_GameFightResumeWithSlavesMessage(Reader *input)
{
  GameFightResumeSlaveInfo _item1 ;
  GameFightResumeMessage::deserialize(input);
  uint _slavesInfoLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _slavesInfoLen; _i1++)
  {
    _item1 = GameFightResumeSlaveInfo();
    _item1.deserialize(input);
    this->slavesInfo.append(_item1);
  }
}

void GameFightResumeWithSlavesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightResumeWithSlavesMessage(tree);
}

void GameFightResumeWithSlavesMessage::deserializeAsyncAs_GameFightResumeWithSlavesMessage(FuncTree tree)
{
  GameFightResumeMessage::deserializeAsync(tree);
  this->_slavesInfotree = tree.addChild(std::bind(&GameFightResumeWithSlavesMessage::_slavesInfotreeFunc, this, std::placeholders::_1));
}

void GameFightResumeWithSlavesMessage::_slavesInfotreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_slavesInfotree.addChild(std::bind(&GameFightResumeWithSlavesMessage::_slavesInfoFunc, this, std::placeholders::_1));
  }
}

void GameFightResumeWithSlavesMessage::_slavesInfoFunc(Reader *input)
{
  GameFightResumeSlaveInfo _item = GameFightResumeSlaveInfo();
  _item.deserialize(input);
  this->slavesInfo.append(_item);
}

GameFightResumeWithSlavesMessage::GameFightResumeWithSlavesMessage()
{
  m_type = MessageEnum::GAMEFIGHTRESUMEWITHSLAVESMESSAGE;
}

