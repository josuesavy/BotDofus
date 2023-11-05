#include "GameActionFightDispellableEffectMessage.h"

void GameActionFightDispellableEffectMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightDispellableEffectMessage(output);
}

void GameActionFightDispellableEffectMessage::serializeAs_GameActionFightDispellableEffectMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  output->writeShort((short)this->effect->getTypes().last());
  this->effect->serialize(output);
}

void GameActionFightDispellableEffectMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightDispellableEffectMessage(input);
}

void GameActionFightDispellableEffectMessage::deserializeAs_GameActionFightDispellableEffectMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  uint _id1 = uint(input->readUShort());
  this->effect = qSharedPointerCast<AbstractFightDispellableEffect>(ClassManagerSingleton::get()->getClass(_id1));
  this->effect->deserialize(input);
}

void GameActionFightDispellableEffectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightDispellableEffectMessage(tree);
}

void GameActionFightDispellableEffectMessage::deserializeAsyncAs_GameActionFightDispellableEffectMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  this->_effecttree = tree.addChild(std::bind(&GameActionFightDispellableEffectMessage::_effecttreeFunc, this, std::placeholders::_1));
}

void GameActionFightDispellableEffectMessage::_effecttreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->effect = qSharedPointerCast<AbstractFightDispellableEffect>(ClassManagerSingleton::get()->getClass(_id));
  this->effect->deserializeAsync(this->_effecttree);
}

GameActionFightDispellableEffectMessage::GameActionFightDispellableEffectMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE;
}

