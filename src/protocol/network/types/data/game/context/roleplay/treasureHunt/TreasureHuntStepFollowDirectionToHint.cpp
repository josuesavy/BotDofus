#include "TreasureHuntStepFollowDirectionToHint.h"

void TreasureHuntStepFollowDirectionToHint::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntStepFollowDirectionToHint(output);
}

void TreasureHuntStepFollowDirectionToHint::serializeAs_TreasureHuntStepFollowDirectionToHint(Writer *output)
{
  TreasureHuntStep::serializeAs_TreasureHuntStep(output);
  output->writeByte(this->direction);
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToHint -"<<"Forbidden value (" << this->npcId << ") on element npcId.";
  }
  output->writeVarShort((int)this->npcId);
}

void TreasureHuntStepFollowDirectionToHint::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntStepFollowDirectionToHint(input);
}

void TreasureHuntStepFollowDirectionToHint::deserializeAs_TreasureHuntStepFollowDirectionToHint(Reader *input)
{
  TreasureHuntStep::deserialize(input);
  this->_directionFunc(input);
  this->_npcIdFunc(input);
}

void TreasureHuntStepFollowDirectionToHint::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntStepFollowDirectionToHint(tree);
}

void TreasureHuntStepFollowDirectionToHint::deserializeAsyncAs_TreasureHuntStepFollowDirectionToHint(FuncTree tree)
{
  TreasureHuntStep::deserializeAsync(tree);
  tree.addChild(std::bind(&TreasureHuntStepFollowDirectionToHint::_directionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntStepFollowDirectionToHint::_npcIdFunc, this, std::placeholders::_1));
}

void TreasureHuntStepFollowDirectionToHint::_directionFunc(Reader *input)
{
  this->direction = input->readByte();
  if(this->direction < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToHint -"<<"Forbidden value (" << this->direction << ") on element of TreasureHuntStepFollowDirectionToHint.direction.";
  }
}

void TreasureHuntStepFollowDirectionToHint::_npcIdFunc(Reader *input)
{
  this->npcId = input->readVarUhShort();
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToHint -"<<"Forbidden value (" << this->npcId << ") on element of TreasureHuntStepFollowDirectionToHint.npcId.";
  }
}

TreasureHuntStepFollowDirectionToHint::TreasureHuntStepFollowDirectionToHint()
{
  m_types<<ClassEnum::TREASUREHUNTSTEPFOLLOWDIRECTIONTOHINT;
}

bool TreasureHuntStepFollowDirectionToHint::operator==(const TreasureHuntStepFollowDirectionToHint &compared)
{
  if(direction == compared.direction)
  if(npcId == compared.npcId)
  return true;
  
  return false;
}

