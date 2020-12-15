#include "TreasureHuntStepFollowDirectionToPOI.h"

void TreasureHuntStepFollowDirectionToPOI::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntStepFollowDirectionToPOI(output);
}

void TreasureHuntStepFollowDirectionToPOI::serializeAs_TreasureHuntStepFollowDirectionToPOI(Writer *output)
{
  TreasureHuntStep::serializeAs_TreasureHuntStep(output);
  output->writeByte(this->direction);
  if(this->poiLabelId < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToPOI -"<<"Forbidden value (" << this->poiLabelId << ") on element poiLabelId.";
  }
  output->writeVarShort((int)this->poiLabelId);
}

void TreasureHuntStepFollowDirectionToPOI::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntStepFollowDirectionToPOI(input);
}

void TreasureHuntStepFollowDirectionToPOI::deserializeAs_TreasureHuntStepFollowDirectionToPOI(Reader *input)
{
  TreasureHuntStep::deserialize(input);
  this->_directionFunc(input);
  this->_poiLabelIdFunc(input);
}

void TreasureHuntStepFollowDirectionToPOI::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntStepFollowDirectionToPOI(tree);
}

void TreasureHuntStepFollowDirectionToPOI::deserializeAsyncAs_TreasureHuntStepFollowDirectionToPOI(FuncTree tree)
{
  TreasureHuntStep::deserializeAsync(tree);
  tree.addChild(std::bind(&TreasureHuntStepFollowDirectionToPOI::_directionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntStepFollowDirectionToPOI::_poiLabelIdFunc, this, std::placeholders::_1));
}

void TreasureHuntStepFollowDirectionToPOI::_directionFunc(Reader *input)
{
  this->direction = input->readByte();
  if(this->direction < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToPOI -"<<"Forbidden value (" << this->direction << ") on element of TreasureHuntStepFollowDirectionToPOI.direction.";
  }
}

void TreasureHuntStepFollowDirectionToPOI::_poiLabelIdFunc(Reader *input)
{
  this->poiLabelId = input->readVarUhShort();
  if(this->poiLabelId < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToPOI -"<<"Forbidden value (" << this->poiLabelId << ") on element of TreasureHuntStepFollowDirectionToPOI.poiLabelId.";
  }
}

TreasureHuntStepFollowDirectionToPOI::TreasureHuntStepFollowDirectionToPOI()
{
  m_types<<ClassEnum::TREASUREHUNTSTEPFOLLOWDIRECTIONTOPOI;
}

bool TreasureHuntStepFollowDirectionToPOI::operator==(const TreasureHuntStepFollowDirectionToPOI &compared)
{
  if(direction == compared.direction)
  if(poiLabelId == compared.poiLabelId)
  return true;
  
  return false;
}

