#include "AlignmentWarEffortDonatePreviewMessage.h"

void AlignmentWarEffortDonatePreviewMessage::serialize(Writer *output)
{
  this->serializeAs_AlignmentWarEffortDonatePreviewMessage(output);
}

void AlignmentWarEffortDonatePreviewMessage::serializeAs_AlignmentWarEffortDonatePreviewMessage(Writer *output)
{
  if(this->xp < -9007199254740992 || this->xp > 9007199254740992)
  {
    qDebug()<<"ERREUR - AlignmentWarEffortDonatePreviewMessage -"<<"Forbidden value (" << this->xp << ") on element xp.";
  }
  output->writeDouble(this->xp);
}

void AlignmentWarEffortDonatePreviewMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlignmentWarEffortDonatePreviewMessage(input);
}

void AlignmentWarEffortDonatePreviewMessage::deserializeAs_AlignmentWarEffortDonatePreviewMessage(Reader *input)
{
  this->_xpFunc(input);
}

void AlignmentWarEffortDonatePreviewMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlignmentWarEffortDonatePreviewMessage(tree);
}

void AlignmentWarEffortDonatePreviewMessage::deserializeAsyncAs_AlignmentWarEffortDonatePreviewMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AlignmentWarEffortDonatePreviewMessage::_xpFunc, this, std::placeholders::_1));
}

void AlignmentWarEffortDonatePreviewMessage::_xpFunc(Reader *input)
{
  this->xp = input->readDouble();
  if(this->xp < -9007199254740992 || this->xp > 9007199254740992)
  {
    qDebug()<<"ERREUR - AlignmentWarEffortDonatePreviewMessage -"<<"Forbidden value (" << this->xp << ") on element of AlignmentWarEffortDonatePreviewMessage.xp.";
  }
}

AlignmentWarEffortDonatePreviewMessage::AlignmentWarEffortDonatePreviewMessage()
{
  m_type = MessageEnum::ALIGNMENTWAREFFORTDONATEPREVIEWMESSAGE;
}

