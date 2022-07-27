#include "ArenaFighterLeaveMessage.h"

void ArenaFighterLeaveMessage::serialize(Writer *output)
{
  this->serializeAs_ArenaFighterLeaveMessage(output);
}

void ArenaFighterLeaveMessage::serializeAs_ArenaFighterLeaveMessage(Writer *output)
{
  this->leaver.serializeAs_CharacterBasicMinimalInformations(output);
}

void ArenaFighterLeaveMessage::deserialize(Reader *input)
{
  this->deserializeAs_ArenaFighterLeaveMessage(input);
}

void ArenaFighterLeaveMessage::deserializeAs_ArenaFighterLeaveMessage(Reader *input)
{
  this->leaver = CharacterBasicMinimalInformations();
  this->leaver.deserialize(input);
}

void ArenaFighterLeaveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ArenaFighterLeaveMessage(tree);
}

void ArenaFighterLeaveMessage::deserializeAsyncAs_ArenaFighterLeaveMessage(FuncTree tree)
{
  this->_leavertree = tree.addChild(std::bind(&ArenaFighterLeaveMessage::_leavertreeFunc, this, std::placeholders::_1));
}

void ArenaFighterLeaveMessage::_leavertreeFunc(Reader *input)
{
  this->leaver = CharacterBasicMinimalInformations();
  this->leaver.deserializeAsync(this->_leavertree);
}

ArenaFighterLeaveMessage::ArenaFighterLeaveMessage()
{
  m_type = MessageEnum::ARENAFIGHTERLEAVEMESSAGE;
}

