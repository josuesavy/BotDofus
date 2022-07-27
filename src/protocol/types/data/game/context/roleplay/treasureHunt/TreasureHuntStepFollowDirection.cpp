#include "TreasureHuntStepFollowDirection.h"

void TreasureHuntStepFollowDirection::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntStepFollowDirection(output);
}

void TreasureHuntStepFollowDirection::serializeAs_TreasureHuntStepFollowDirection(Writer *output)
{
  TreasureHuntStep::serializeAs_TreasureHuntStep(output);
  output->writeByte(this->direction);
  if(this->mapCount < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirection -"<<"Forbidden value (" << this->mapCount << ") on element mapCount.";
  }
  output->writeVarShort((int)this->mapCount);
}

void TreasureHuntStepFollowDirection::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntStepFollowDirection(input);
}

void TreasureHuntStepFollowDirection::deserializeAs_TreasureHuntStepFollowDirection(Reader *input)
{
  TreasureHuntStep::deserialize(input);
  this->_directionFunc(input);
  this->_mapCountFunc(input);
}

void TreasureHuntStepFollowDirection::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntStepFollowDirection(tree);
}

void TreasureHuntStepFollowDirection::deserializeAsyncAs_TreasureHuntStepFollowDirection(FuncTree tree)
{
  TreasureHuntStep::deserializeAsync(tree);
  tree.addChild(std::bind(&TreasureHuntStepFollowDirection::_directionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntStepFollowDirection::_mapCountFunc, this, std::placeholders::_1));
}

void TreasureHuntStepFollowDirection::_directionFunc(Reader *input)
{
  this->direction = input->readByte();
  if(this->direction < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirection -"<<"Forbidden value (" << this->direction << ") on element of TreasureHuntStepFollowDirection.direction.";
  }
}

void TreasureHuntStepFollowDirection::_mapCountFunc(Reader *input)
{
  this->mapCount = input->readVarUhShort();
  if(this->mapCount < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirection -"<<"Forbidden value (" << this->mapCount << ") on element of TreasureHuntStepFollowDirection.mapCount.";
  }
}

TreasureHuntStepFollowDirection::TreasureHuntStepFollowDirection()
{
  m_types<<ClassEnum::TREASUREHUNTSTEPFOLLOWDIRECTION;
}

bool TreasureHuntStepFollowDirection::operator==(const TreasureHuntStepFollowDirection &compared)
{
  if(direction == compared.direction)
  if(mapCount == compared.mapCount)
  return true;
  
  return false;
}

