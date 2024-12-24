#include "AlignmentRankUpdateMessage.h"

void AlignmentRankUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_AlignmentRankUpdateMessage(output);
}

void AlignmentRankUpdateMessage::serializeAs_AlignmentRankUpdateMessage(Writer *output)
{
  if(this->alignmentRank < 0)
  {
    qDebug()<<"ERREUR - AlignmentRankUpdateMessage -"<<"Forbidden value (" << this->alignmentRank << ") on element alignmentRank.";
  }
  output->writeByte(this->alignmentRank);
  output->writeBool(this->verbose);
}

void AlignmentRankUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlignmentRankUpdateMessage(input);
}

void AlignmentRankUpdateMessage::deserializeAs_AlignmentRankUpdateMessage(Reader *input)
{
  this->_alignmentRankFunc(input);
  this->_verboseFunc(input);
}

void AlignmentRankUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlignmentRankUpdateMessage(tree);
}

void AlignmentRankUpdateMessage::deserializeAsyncAs_AlignmentRankUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AlignmentRankUpdateMessage::_alignmentRankFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AlignmentRankUpdateMessage::_verboseFunc, this, std::placeholders::_1));
}

void AlignmentRankUpdateMessage::_alignmentRankFunc(Reader *input)
{
  this->alignmentRank = input->readByte();
  if(this->alignmentRank < 0)
  {
    qDebug()<<"ERREUR - AlignmentRankUpdateMessage -"<<"Forbidden value (" << this->alignmentRank << ") on element of AlignmentRankUpdateMessage.alignmentRank.";
  }
}

void AlignmentRankUpdateMessage::_verboseFunc(Reader *input)
{
  this->verbose = input->readBool();
}

AlignmentRankUpdateMessage::AlignmentRankUpdateMessage()
{
  m_type = MessageEnum::ALIGNMENTRANKUPDATEMESSAGE;
}

