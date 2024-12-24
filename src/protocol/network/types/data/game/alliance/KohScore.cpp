#include "KohScore.h"

void KohScore::serialize(Writer *output)
{
  this->serializeAs_KohScore(output);
}

void KohScore::serializeAs_KohScore(Writer *output)
{
  output->writeByte(this->avaScoreTypeEnum);
  output->writeInt((int)this->roundScores);
  output->writeInt((int)this->cumulScores);
}

void KohScore::deserialize(Reader *input)
{
  this->deserializeAs_KohScore(input);
}

void KohScore::deserializeAs_KohScore(Reader *input)
{
  this->_avaScoreTypeEnumFunc(input);
  this->_roundScoresFunc(input);
  this->_cumulScoresFunc(input);
}

void KohScore::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_KohScore(tree);
}

void KohScore::deserializeAsyncAs_KohScore(FuncTree tree)
{
  tree.addChild(std::bind(&KohScore::_avaScoreTypeEnumFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&KohScore::_roundScoresFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&KohScore::_cumulScoresFunc, this, std::placeholders::_1));
}

void KohScore::_avaScoreTypeEnumFunc(Reader *input)
{
  this->avaScoreTypeEnum = input->readByte();
  if(this->avaScoreTypeEnum < 0)
  {
    qDebug()<<"ERREUR - KohScore -"<<"Forbidden value (" << this->avaScoreTypeEnum << ") on element of KohScore.avaScoreTypeEnum.";
  }
}

void KohScore::_roundScoresFunc(Reader *input)
{
  this->roundScores = input->readInt();
}

void KohScore::_cumulScoresFunc(Reader *input)
{
  this->cumulScores = input->readInt();
}

KohScore::KohScore()
{
  m_types<<ClassEnum::KOHSCORE;
}

bool KohScore::operator==(const KohScore &compared)
{
  if(avaScoreTypeEnum == compared.avaScoreTypeEnum)
  if(roundScores == compared.roundScores)
  if(cumulScores == compared.cumulScores)
  return true;
  
  return false;
}

