#include "GameActionUpdateEffectTriggerCountMessage.h"

void GameActionUpdateEffectTriggerCountMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionUpdateEffectTriggerCountMessage(output);
}

void GameActionUpdateEffectTriggerCountMessage::serializeAs_GameActionUpdateEffectTriggerCountMessage(Writer *output)
{
  output->writeShort((short)this->targetIds.size());
  for(uint _i1 = 0; _i1 < this->targetIds.size(); _i1++)
  {
    (this->targetIds[_i1]).serializeAs_GameFightEffectTriggerCount(output);
  }
}

void GameActionUpdateEffectTriggerCountMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionUpdateEffectTriggerCountMessage(input);
}

void GameActionUpdateEffectTriggerCountMessage::deserializeAs_GameActionUpdateEffectTriggerCountMessage(Reader *input)
{
  GameFightEffectTriggerCount _item1 ;
  uint _targetIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _targetIdsLen; _i1++)
  {
    _item1 = GameFightEffectTriggerCount();
    _item1.deserialize(input);
    this->targetIds.append(_item1);
  }
}

void GameActionUpdateEffectTriggerCountMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionUpdateEffectTriggerCountMessage(tree);
}

void GameActionUpdateEffectTriggerCountMessage::deserializeAsyncAs_GameActionUpdateEffectTriggerCountMessage(FuncTree tree)
{
  this->_targetIdstree = tree.addChild(std::bind(&GameActionUpdateEffectTriggerCountMessage::_targetIdstreeFunc, this, std::placeholders::_1));
}

void GameActionUpdateEffectTriggerCountMessage::_targetIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_targetIdstree.addChild(std::bind(&GameActionUpdateEffectTriggerCountMessage::_targetIdsFunc, this, std::placeholders::_1));
  }
}

void GameActionUpdateEffectTriggerCountMessage::_targetIdsFunc(Reader *input)
{
  GameFightEffectTriggerCount _item = GameFightEffectTriggerCount();
  _item.deserialize(input);
  this->targetIds.append(_item);
}

GameActionUpdateEffectTriggerCountMessage::GameActionUpdateEffectTriggerCountMessage()
{
  m_type = MessageEnum::GAMEACTIONUPDATEEFFECTTRIGGERCOUNTMESSAGE;
}

