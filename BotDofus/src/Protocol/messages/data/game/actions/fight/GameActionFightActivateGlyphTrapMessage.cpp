#include "GameActionFightActivateGlyphTrapMessage.h"

void GameActionFightActivateGlyphTrapMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightActivateGlyphTrapMessage(output);
}

void GameActionFightActivateGlyphTrapMessage::serializeAs_GameActionFightActivateGlyphTrapMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  output->writeShort((short)this->markId);
  output->writeBool(this->active);
}

void GameActionFightActivateGlyphTrapMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightActivateGlyphTrapMessage(input);
}

void GameActionFightActivateGlyphTrapMessage::deserializeAs_GameActionFightActivateGlyphTrapMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_markIdFunc(input);
  this->_activeFunc(input);
}

void GameActionFightActivateGlyphTrapMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightActivateGlyphTrapMessage(tree);
}

void GameActionFightActivateGlyphTrapMessage::deserializeAsyncAs_GameActionFightActivateGlyphTrapMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightActivateGlyphTrapMessage::_markIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightActivateGlyphTrapMessage::_activeFunc, this, std::placeholders::_1));
}

void GameActionFightActivateGlyphTrapMessage::_markIdFunc(Reader *input)
{
  this->markId = input->readShort();
}

void GameActionFightActivateGlyphTrapMessage::_activeFunc(Reader *input)
{
  this->active = input->readBool();
}

GameActionFightActivateGlyphTrapMessage::GameActionFightActivateGlyphTrapMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTACTIVATEGLYPHTRAPMESSAGE;
}

