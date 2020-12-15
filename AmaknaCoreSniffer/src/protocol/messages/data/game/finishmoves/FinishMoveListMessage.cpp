#include "FinishMoveListMessage.h"

void FinishMoveListMessage::serialize(Writer *output)
{
  this->serializeAs_FinishMoveListMessage(output);
}

void FinishMoveListMessage::serializeAs_FinishMoveListMessage(Writer *output)
{
  output->writeShort((short)this->finishMoves.size());
  for(uint _i1 = 0; _i1 < this->finishMoves.size(); _i1++)
  {
    (this->finishMoves[_i1]).serializeAs_FinishMoveInformations(output);
  }
}

void FinishMoveListMessage::deserialize(Reader *input)
{
  this->deserializeAs_FinishMoveListMessage(input);
}

void FinishMoveListMessage::deserializeAs_FinishMoveListMessage(Reader *input)
{
  FinishMoveInformations _item1 ;
  uint _finishMovesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _finishMovesLen; _i1++)
  {
    _item1 = FinishMoveInformations();
    _item1.deserialize(input);
    this->finishMoves.append(_item1);
  }
}

void FinishMoveListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FinishMoveListMessage(tree);
}

void FinishMoveListMessage::deserializeAsyncAs_FinishMoveListMessage(FuncTree tree)
{
  this->_finishMovestree = tree.addChild(std::bind(&FinishMoveListMessage::_finishMovestreeFunc, this, std::placeholders::_1));
}

void FinishMoveListMessage::_finishMovestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_finishMovestree.addChild(std::bind(&FinishMoveListMessage::_finishMovesFunc, this, std::placeholders::_1));
  }
}

void FinishMoveListMessage::_finishMovesFunc(Reader *input)
{
  FinishMoveInformations _item = FinishMoveInformations();
  _item.deserialize(input);
  this->finishMoves.append(_item);
}

FinishMoveListMessage::FinishMoveListMessage()
{
  m_type = MessageEnum::FINISHMOVELISTMESSAGE;
}

