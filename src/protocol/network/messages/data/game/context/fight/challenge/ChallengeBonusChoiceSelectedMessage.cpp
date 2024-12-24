#include "ChallengeBonusChoiceSelectedMessage.h"

void ChallengeBonusChoiceSelectedMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeBonusChoiceSelectedMessage(output);
}

void ChallengeBonusChoiceSelectedMessage::serializeAs_ChallengeBonusChoiceSelectedMessage(Writer *output)
{
  output->writeByte(this->challengeBonus);
}

void ChallengeBonusChoiceSelectedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeBonusChoiceSelectedMessage(input);
}

void ChallengeBonusChoiceSelectedMessage::deserializeAs_ChallengeBonusChoiceSelectedMessage(Reader *input)
{
  this->_challengeBonusFunc(input);
}

void ChallengeBonusChoiceSelectedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeBonusChoiceSelectedMessage(tree);
}

void ChallengeBonusChoiceSelectedMessage::deserializeAsyncAs_ChallengeBonusChoiceSelectedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeBonusChoiceSelectedMessage::_challengeBonusFunc, this, std::placeholders::_1));
}

void ChallengeBonusChoiceSelectedMessage::_challengeBonusFunc(Reader *input)
{
  this->challengeBonus = input->readByte();
  if(this->challengeBonus < 0)
  {
    qDebug()<<"ERREUR - ChallengeBonusChoiceSelectedMessage -"<<"Forbidden value (" << this->challengeBonus << ") on element of ChallengeBonusChoiceSelectedMessage.challengeBonus.";
  }
}

ChallengeBonusChoiceSelectedMessage::ChallengeBonusChoiceSelectedMessage()
{
  m_type = MessageEnum::CHALLENGEBONUSCHOICESELECTEDMESSAGE;
}

