#include "CharacterAlignmentWarEffortProgressionMessage.h"

void CharacterAlignmentWarEffortProgressionMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterAlignmentWarEffortProgressionMessage(output);
}

void CharacterAlignmentWarEffortProgressionMessage::serializeAs_CharacterAlignmentWarEffortProgressionMessage(Writer *output)
{
  if(this->alignmentWarEffortDailyLimit < 0 || this->alignmentWarEffortDailyLimit > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterAlignmentWarEffortProgressionMessage -"<<"Forbidden value (" << this->alignmentWarEffortDailyLimit << ") on element alignmentWarEffortDailyLimit.";
  }
  output->writeVarLong((double)this->alignmentWarEffortDailyLimit);
  if(this->alignmentWarEffortDailyDonation < 0 || this->alignmentWarEffortDailyDonation > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterAlignmentWarEffortProgressionMessage -"<<"Forbidden value (" << this->alignmentWarEffortDailyDonation << ") on element alignmentWarEffortDailyDonation.";
  }
  output->writeVarLong((double)this->alignmentWarEffortDailyDonation);
  if(this->alignmentWarEffortPersonalDonation < 0 || this->alignmentWarEffortPersonalDonation > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterAlignmentWarEffortProgressionMessage -"<<"Forbidden value (" << this->alignmentWarEffortPersonalDonation << ") on element alignmentWarEffortPersonalDonation.";
  }
  output->writeVarLong((double)this->alignmentWarEffortPersonalDonation);
}

void CharacterAlignmentWarEffortProgressionMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterAlignmentWarEffortProgressionMessage(input);
}

void CharacterAlignmentWarEffortProgressionMessage::deserializeAs_CharacterAlignmentWarEffortProgressionMessage(Reader *input)
{
  this->_alignmentWarEffortDailyLimitFunc(input);
  this->_alignmentWarEffortDailyDonationFunc(input);
  this->_alignmentWarEffortPersonalDonationFunc(input);
}

void CharacterAlignmentWarEffortProgressionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterAlignmentWarEffortProgressionMessage(tree);
}

void CharacterAlignmentWarEffortProgressionMessage::deserializeAsyncAs_CharacterAlignmentWarEffortProgressionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterAlignmentWarEffortProgressionMessage::_alignmentWarEffortDailyLimitFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterAlignmentWarEffortProgressionMessage::_alignmentWarEffortDailyDonationFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterAlignmentWarEffortProgressionMessage::_alignmentWarEffortPersonalDonationFunc, this, std::placeholders::_1));
}

void CharacterAlignmentWarEffortProgressionMessage::_alignmentWarEffortDailyLimitFunc(Reader *input)
{
  this->alignmentWarEffortDailyLimit = input->readVarUhLong();
  if(this->alignmentWarEffortDailyLimit < 0 || this->alignmentWarEffortDailyLimit > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterAlignmentWarEffortProgressionMessage -"<<"Forbidden value (" << this->alignmentWarEffortDailyLimit << ") on element of CharacterAlignmentWarEffortProgressionMessage.alignmentWarEffortDailyLimit.";
  }
}

void CharacterAlignmentWarEffortProgressionMessage::_alignmentWarEffortDailyDonationFunc(Reader *input)
{
  this->alignmentWarEffortDailyDonation = input->readVarUhLong();
  if(this->alignmentWarEffortDailyDonation < 0 || this->alignmentWarEffortDailyDonation > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterAlignmentWarEffortProgressionMessage -"<<"Forbidden value (" << this->alignmentWarEffortDailyDonation << ") on element of CharacterAlignmentWarEffortProgressionMessage.alignmentWarEffortDailyDonation.";
  }
}

void CharacterAlignmentWarEffortProgressionMessage::_alignmentWarEffortPersonalDonationFunc(Reader *input)
{
  this->alignmentWarEffortPersonalDonation = input->readVarUhLong();
  if(this->alignmentWarEffortPersonalDonation < 0 || this->alignmentWarEffortPersonalDonation > 9007199254740992)
  {
    qDebug()<<"ERREUR - CharacterAlignmentWarEffortProgressionMessage -"<<"Forbidden value (" << this->alignmentWarEffortPersonalDonation << ") on element of CharacterAlignmentWarEffortProgressionMessage.alignmentWarEffortPersonalDonation.";
  }
}

CharacterAlignmentWarEffortProgressionMessage::CharacterAlignmentWarEffortProgressionMessage()
{
  m_type = MessageEnum::CHARACTERALIGNMENTWAREFFORTPROGRESSIONMESSAGE;
}

