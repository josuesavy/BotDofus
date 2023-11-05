#include "GameContextRemoveMultipleElementsWithEventsMessage.h"

void GameContextRemoveMultipleElementsWithEventsMessage::serialize(Writer *output)
{
  this->serializeAs_GameContextRemoveMultipleElementsWithEventsMessage(output);
}

void GameContextRemoveMultipleElementsWithEventsMessage::serializeAs_GameContextRemoveMultipleElementsWithEventsMessage(Writer *output)
{
  GameContextRemoveMultipleElementsMessage::serializeAs_GameContextRemoveMultipleElementsMessage(output);
  output->writeShort((short)this->elementEventIds.size());
  for(uint _i1 = 0; _i1 < this->elementEventIds.size(); _i1++)
  {
    if(this->elementEventIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - GameContextRemoveMultipleElementsWithEventsMessage -"<<"Forbidden value (" << this->elementEventIds[_i1] << ") on element 1 (starting at 1) of elementEventIds.";
    }
    output->writeByte(this->elementEventIds[_i1]);
  }
}

void GameContextRemoveMultipleElementsWithEventsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameContextRemoveMultipleElementsWithEventsMessage(input);
}

void GameContextRemoveMultipleElementsWithEventsMessage::deserializeAs_GameContextRemoveMultipleElementsWithEventsMessage(Reader *input)
{
  uint _val1 = 0;
  GameContextRemoveMultipleElementsMessage::deserialize(input);
  uint _elementEventIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _elementEventIdsLen; _i1++)
  {
    _val1 = uint(input->readByte());
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - GameContextRemoveMultipleElementsWithEventsMessage -"<<"Forbidden value (" << _val1 << ") on elements of elementEventIds.";
    }
    this->elementEventIds.append(_val1);
  }
}

void GameContextRemoveMultipleElementsWithEventsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextRemoveMultipleElementsWithEventsMessage(tree);
}

void GameContextRemoveMultipleElementsWithEventsMessage::deserializeAsyncAs_GameContextRemoveMultipleElementsWithEventsMessage(FuncTree tree)
{
  GameContextRemoveMultipleElementsMessage::deserializeAsync(tree);
  this->_elementEventIdstree = tree.addChild(std::bind(&GameContextRemoveMultipleElementsWithEventsMessage::_elementEventIdstreeFunc, this, std::placeholders::_1));
}

void GameContextRemoveMultipleElementsWithEventsMessage::_elementEventIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_elementEventIdstree.addChild(std::bind(&GameContextRemoveMultipleElementsWithEventsMessage::_elementEventIdsFunc, this, std::placeholders::_1));
  }
}

void GameContextRemoveMultipleElementsWithEventsMessage::_elementEventIdsFunc(Reader *input)
{
  uint _val = uint(input->readByte());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GameContextRemoveMultipleElementsWithEventsMessage -"<<"Forbidden value (" << _val << ") on elements of elementEventIds.";
  }
  this->elementEventIds.append(_val);
}

GameContextRemoveMultipleElementsWithEventsMessage::GameContextRemoveMultipleElementsWithEventsMessage()
{
  m_type = MessageEnum::GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE;
}

