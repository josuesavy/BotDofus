#include "ChallengeBonusChoiceMessage.h"

void ChallengeBonusChoiceMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeBonusChoiceMessage(output);
}

void ChallengeBonusChoiceMessage::serializeAs_ChallengeBonusChoiceMessage(Writer *output)
{
  output->writeByte(this->challengeBonus);
}

void ChallengeBonusChoiceMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeBonusChoiceMessage(input);
}

void ChallengeBonusChoiceMessage::deserializeAs_ChallengeBonusChoiceMessage(Reader *input)
{
  this->_challengeBonusFunc(input);
}

void ChallengeBonusChoiceMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeBonusChoiceMessage(tree);
}

void ChallengeBonusChoiceMessage::deserializeAsyncAs_ChallengeBonusChoiceMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeBonusChoiceMessage::_challengeBonusFunc, this, std::placeholders::_1));
}

void ChallengeBonusChoiceMessage::_challengeBonusFunc(Reader *input)
{
  this->challengeBonus = input->readByte();
  if(this->challengeBonus < 0)
  {
    qDebug()<<"ERREUR - ChallengeBonusChoiceMessage -"<<"Forbidden value (" << this->challengeBonus << ") on element of ChallengeBonusChoiceMessage.challengeBonus.";
  }
}

ChallengeBonusChoiceMessage::ChallengeBonusChoiceMessage()
{
  m_type = MessageEnum::CHALLENGEBONUSCHOICEMESSAGE;
}

