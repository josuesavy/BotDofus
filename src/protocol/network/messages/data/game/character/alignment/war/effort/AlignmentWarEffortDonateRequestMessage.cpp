#include "AlignmentWarEffortDonateRequestMessage.h"

void AlignmentWarEffortDonateRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AlignmentWarEffortDonateRequestMessage(output);
}

void AlignmentWarEffortDonateRequestMessage::serializeAs_AlignmentWarEffortDonateRequestMessage(Writer *output)
{
  if(this->donation < 0 || this->donation > 9007199254740992)
  {
    qDebug()<<"ERREUR - AlignmentWarEffortDonateRequestMessage -"<<"Forbidden value (" << this->donation << ") on element donation.";
  }
  output->writeVarLong((double)this->donation);
}

void AlignmentWarEffortDonateRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlignmentWarEffortDonateRequestMessage(input);
}

void AlignmentWarEffortDonateRequestMessage::deserializeAs_AlignmentWarEffortDonateRequestMessage(Reader *input)
{
  this->_donationFunc(input);
}

void AlignmentWarEffortDonateRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlignmentWarEffortDonateRequestMessage(tree);
}

void AlignmentWarEffortDonateRequestMessage::deserializeAsyncAs_AlignmentWarEffortDonateRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AlignmentWarEffortDonateRequestMessage::_donationFunc, this, std::placeholders::_1));
}

void AlignmentWarEffortDonateRequestMessage::_donationFunc(Reader *input)
{
  this->donation = input->readVarUhLong();
  if(this->donation < 0 || this->donation > 9007199254740992)
  {
    qDebug()<<"ERREUR - AlignmentWarEffortDonateRequestMessage -"<<"Forbidden value (" << this->donation << ") on element of AlignmentWarEffortDonateRequestMessage.donation.";
  }
}

AlignmentWarEffortDonateRequestMessage::AlignmentWarEffortDonateRequestMessage()
{
  m_type = MessageEnum::ALIGNMENTWAREFFORTDONATEREQUESTMESSAGE;
}

