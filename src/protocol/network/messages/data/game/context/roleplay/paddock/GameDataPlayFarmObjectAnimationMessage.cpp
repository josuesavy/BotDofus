#include "GameDataPlayFarmObjectAnimationMessage.h"

void GameDataPlayFarmObjectAnimationMessage::serialize(Writer *output)
{
  this->serializeAs_GameDataPlayFarmObjectAnimationMessage(output);
}

void GameDataPlayFarmObjectAnimationMessage::serializeAs_GameDataPlayFarmObjectAnimationMessage(Writer *output)
{
  output->writeShort((short)this->cellId.size());
  for(uint _i1 = 0; _i1 < this->cellId.size(); _i1++)
  {
    if(this->cellId[_i1] < 0 || this->cellId[_i1] > 559)
    {
      qDebug()<<"ERREUR - GameDataPlayFarmObjectAnimationMessage -"<<"Forbidden value (" << this->cellId[_i1] << ") on element 1 (starting at 1) of cellId.";
    }
    output->writeVarShort((int)this->cellId[_i1]);
  }
}

void GameDataPlayFarmObjectAnimationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameDataPlayFarmObjectAnimationMessage(input);
}

void GameDataPlayFarmObjectAnimationMessage::deserializeAs_GameDataPlayFarmObjectAnimationMessage(Reader *input)
{
  uint _val1 = 0;
  uint _cellIdLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _cellIdLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0 || _val1 > 559)
    {
      qDebug()<<"ERREUR - GameDataPlayFarmObjectAnimationMessage -"<<"Forbidden value (" << _val1 << ") on elements of cellId.";
    }
    this->cellId.append(_val1);
  }
}

void GameDataPlayFarmObjectAnimationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameDataPlayFarmObjectAnimationMessage(tree);
}

void GameDataPlayFarmObjectAnimationMessage::deserializeAsyncAs_GameDataPlayFarmObjectAnimationMessage(FuncTree tree)
{
  this->_cellIdtree = tree.addChild(std::bind(&GameDataPlayFarmObjectAnimationMessage::_cellIdtreeFunc, this, std::placeholders::_1));
}

void GameDataPlayFarmObjectAnimationMessage::_cellIdtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_cellIdtree.addChild(std::bind(&GameDataPlayFarmObjectAnimationMessage::_cellIdFunc, this, std::placeholders::_1));
  }
}

void GameDataPlayFarmObjectAnimationMessage::_cellIdFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0 || _val > 559)
  {
    qDebug()<<"ERREUR - GameDataPlayFarmObjectAnimationMessage -"<<"Forbidden value (" << _val << ") on elements of cellId.";
  }
  this->cellId.append(_val);
}

GameDataPlayFarmObjectAnimationMessage::GameDataPlayFarmObjectAnimationMessage()
{
  m_type = MessageEnum::GAMEDATAPLAYFARMOBJECTANIMATIONMESSAGE;
}

