#include "GameContextRemoveMultipleElementsMessage.h"

void GameContextRemoveMultipleElementsMessage::serialize(Writer *output)
{
  this->serializeAs_GameContextRemoveMultipleElementsMessage(output);
}

void GameContextRemoveMultipleElementsMessage::serializeAs_GameContextRemoveMultipleElementsMessage(Writer *output)
{
  output->writeShort((short)this->elementsIds.size());
  for(uint _i1 = 0; _i1 < this->elementsIds.size(); _i1++)
  {
    if(this->elementsIds[_i1] < -9007199254740992 || this->elementsIds[_i1] > 9007199254740992)
    {
      qDebug()<<"ERREUR - GameContextRemoveMultipleElementsMessage -"<<"Forbidden value (" << this->elementsIds[_i1] << ") on element 1 (starting at 1) of elementsIds.";
    }
    output->writeDouble(this->elementsIds[_i1]);
  }
}

void GameContextRemoveMultipleElementsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameContextRemoveMultipleElementsMessage(input);
}

void GameContextRemoveMultipleElementsMessage::deserializeAs_GameContextRemoveMultipleElementsMessage(Reader *input)
{
  double _val1 = NULL;
  uint _elementsIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _elementsIdsLen; _i1++)
  {
    _val1 = double(input->readDouble());
    if(_val1 < -9007199254740992 || _val1 > 9007199254740992)
    {
      qDebug()<<"ERREUR - GameContextRemoveMultipleElementsMessage -"<<"Forbidden value (" << _val1 << ") on elements of elementsIds.";
    }
    this->elementsIds.append(_val1);
  }
}

void GameContextRemoveMultipleElementsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextRemoveMultipleElementsMessage(tree);
}

void GameContextRemoveMultipleElementsMessage::deserializeAsyncAs_GameContextRemoveMultipleElementsMessage(FuncTree tree)
{
  this->_elementsIdstree = tree.addChild(std::bind(&GameContextRemoveMultipleElementsMessage::_elementsIdstreeFunc, this, std::placeholders::_1));
}

void GameContextRemoveMultipleElementsMessage::_elementsIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_elementsIdstree.addChild(std::bind(&GameContextRemoveMultipleElementsMessage::_elementsIdsFunc, this, std::placeholders::_1));
  }
}

void GameContextRemoveMultipleElementsMessage::_elementsIdsFunc(Reader *input)
{
  double _val = double(input->readDouble());
  if(_val < -9007199254740992 || _val > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameContextRemoveMultipleElementsMessage -"<<"Forbidden value (" << _val << ") on elements of elementsIds.";
  }
  this->elementsIds.append(_val);
}

GameContextRemoveMultipleElementsMessage::GameContextRemoveMultipleElementsMessage()
{
  m_type = MessageEnum::GAMECONTEXTREMOVEMULTIPLEELEMENTSMESSAGE;
}

