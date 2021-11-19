#include "AlignmentWarEffortInformation.h"

void AlignmentWarEffortInformation::serialize(Writer *output)
{
  this->serializeAs_AlignmentWarEffortInformation(output);
}

void AlignmentWarEffortInformation::serializeAs_AlignmentWarEffortInformation(Writer *output)
{
  output->writeByte(this->alignmentSide);
  if(this->alignmentWarEffort < 0 || this->alignmentWarEffort > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AlignmentWarEffortInformation -"<<"Forbidden value (" << this->alignmentWarEffort << ") on element alignmentWarEffort.";
  }
  output->writeVarLong((double)this->alignmentWarEffort);
}

void AlignmentWarEffortInformation::deserialize(Reader *input)
{
  this->deserializeAs_AlignmentWarEffortInformation(input);
}

void AlignmentWarEffortInformation::deserializeAs_AlignmentWarEffortInformation(Reader *input)
{
  this->_alignmentSideFunc(input);
  this->_alignmentWarEffortFunc(input);
}

void AlignmentWarEffortInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlignmentWarEffortInformation(tree);
}

void AlignmentWarEffortInformation::deserializeAsyncAs_AlignmentWarEffortInformation(FuncTree tree)
{
  tree.addChild(std::bind(&AlignmentWarEffortInformation::_alignmentSideFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AlignmentWarEffortInformation::_alignmentWarEffortFunc, this, std::placeholders::_1));
}

void AlignmentWarEffortInformation::_alignmentSideFunc(Reader *input)
{
  this->alignmentSide = input->readByte();
}

void AlignmentWarEffortInformation::_alignmentWarEffortFunc(Reader *input)
{
  this->alignmentWarEffort = input->readVarUhLong();
  if(this->alignmentWarEffort < 0 || this->alignmentWarEffort > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AlignmentWarEffortInformation -"<<"Forbidden value (" << this->alignmentWarEffort << ") on element of AlignmentWarEffortInformation.alignmentWarEffort.";
  }
}

AlignmentWarEffortInformation::AlignmentWarEffortInformation()
{
  m_types<<ClassEnum::ALIGNMENTWAREFFORTINFORMATION;
}

bool AlignmentWarEffortInformation::operator==(const AlignmentWarEffortInformation &compared)
{
  if(alignmentSide == compared.alignmentSide)
  if(alignmentWarEffort == compared.alignmentWarEffort)
  return true;
  
  return false;
}

