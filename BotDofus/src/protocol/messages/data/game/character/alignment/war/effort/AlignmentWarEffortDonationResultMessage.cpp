#include "AlignmentWarEffortDonationResultMessage.h"

void AlignmentWarEffortDonationResultMessage::serialize(Writer *output)
{
  this->serializeAs_AlignmentWarEffortDonationResultMessage(output);
}

void AlignmentWarEffortDonationResultMessage::serializeAs_AlignmentWarEffortDonationResultMessage(Writer *output)
{
  output->writeByte(this->result);
}

void AlignmentWarEffortDonationResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlignmentWarEffortDonationResultMessage(input);
}

void AlignmentWarEffortDonationResultMessage::deserializeAs_AlignmentWarEffortDonationResultMessage(Reader *input)
{
  this->_resultFunc(input);
}

void AlignmentWarEffortDonationResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlignmentWarEffortDonationResultMessage(tree);
}

void AlignmentWarEffortDonationResultMessage::deserializeAsyncAs_AlignmentWarEffortDonationResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AlignmentWarEffortDonationResultMessage::_resultFunc, this, std::placeholders::_1));
}

void AlignmentWarEffortDonationResultMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
}

AlignmentWarEffortDonationResultMessage::AlignmentWarEffortDonationResultMessage()
{
  m_type = MessageEnum::ALIGNMENTWAREFFORTDONATIONRESULTMESSAGE;
}

