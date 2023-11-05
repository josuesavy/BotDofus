#include "ChallengeTargetsListMessage.h"

void ChallengeTargetsListMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeTargetsListMessage(output);
}

void ChallengeTargetsListMessage::serializeAs_ChallengeTargetsListMessage(Writer *output)
{
  output->writeShort((short)this->targetIds.size());
  for(uint _i1 = 0; _i1 < this->targetIds.size(); _i1++)
  {
    if(this->targetIds[_i1] < -9007199254740992 || this->targetIds[_i1] > 9007199254740992)
    {
      qDebug()<<"ERREUR - ChallengeTargetsListMessage -"<<"Forbidden value (" << this->targetIds[_i1] << ") on element 1 (starting at 1) of targetIds.";
    }
    output->writeDouble(this->targetIds[_i1]);
  }
  output->writeShort((short)this->targetCells.size());
  for(uint _i2 = 0; _i2 < this->targetCells.size(); _i2++)
  {
    if(this->targetCells[_i2] < -1 || this->targetCells[_i2] > 559)
    {
      qDebug()<<"ERREUR - ChallengeTargetsListMessage -"<<"Forbidden value (" << this->targetCells[_i2] << ") on element 2 (starting at 1) of targetCells.";
    }
    output->writeShort((short)this->targetCells[_i2]);
  }
}

void ChallengeTargetsListMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeTargetsListMessage(input);
}

void ChallengeTargetsListMessage::deserializeAs_ChallengeTargetsListMessage(Reader *input)
{
  double _val1 = NULL;
  int _val2 = 0;
  uint _targetIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _targetIdsLen; _i1++)
  {
    _val1 = Number(input->readDouble());
    if(_val1 < -9007199254740992 || _val1 > 9007199254740992)
    {
      qDebug()<<"ERREUR - ChallengeTargetsListMessage -"<<"Forbidden value (" << _val1 << ") on elements of targetIds.";
    }
    this->targetIds.append(_val1);
  }
  uint _targetCellsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _targetCellsLen; _i2++)
  {
    _val2 = int(input->readShort());
    if(_val2 < -1 || _val2 > 559)
    {
      qDebug()<<"ERREUR - ChallengeTargetsListMessage -"<<"Forbidden value (" << _val2 << ") on elements of targetCells.";
    }
    this->targetCells.append(_val2);
  }
}

void ChallengeTargetsListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeTargetsListMessage(tree);
}

void ChallengeTargetsListMessage::deserializeAsyncAs_ChallengeTargetsListMessage(FuncTree tree)
{
  this->_targetIdstree = tree.addChild(std::bind(&ChallengeTargetsListMessage::_targetIdstreeFunc, this, std::placeholders::_1));
  this->_targetCellstree = tree.addChild(std::bind(&ChallengeTargetsListMessage::_targetCellstreeFunc, this, std::placeholders::_1));
}

void ChallengeTargetsListMessage::_targetIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_targetIdstree.addChild(std::bind(&ChallengeTargetsListMessage::_targetIdsFunc, this, std::placeholders::_1));
  }
}

void ChallengeTargetsListMessage::_targetIdsFunc(Reader *input)
{
  double _val = Number(input->readDouble());
  if(_val < -9007199254740992 || _val > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChallengeTargetsListMessage -"<<"Forbidden value (" << _val << ") on elements of targetIds.";
  }
  this->targetIds.append(_val);
}

void ChallengeTargetsListMessage::_targetCellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_targetCellstree.addChild(std::bind(&ChallengeTargetsListMessage::_targetCellsFunc, this, std::placeholders::_1));
  }
}

void ChallengeTargetsListMessage::_targetCellsFunc(Reader *input)
{
  int _val = int(input->readShort());
  if(_val < -1 || _val > 559)
  {
    qDebug()<<"ERREUR - ChallengeTargetsListMessage -"<<"Forbidden value (" << _val << ") on elements of targetCells.";
  }
  this->targetCells.append(_val);
}

ChallengeTargetsListMessage::ChallengeTargetsListMessage()
{
  m_type = MessageEnum::CHALLENGETARGETSLISTMESSAGE;
}

