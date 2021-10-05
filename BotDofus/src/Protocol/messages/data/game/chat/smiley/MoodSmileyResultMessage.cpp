#include "MoodSmileyResultMessage.h"

void MoodSmileyResultMessage::serialize(Writer *output)
{
  this->serializeAs_MoodSmileyResultMessage(output);
}

void MoodSmileyResultMessage::serializeAs_MoodSmileyResultMessage(Writer *output)
{
  output->writeByte(this->resultCode);
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyResultMessage -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
  }
  output->writeVarShort((int)this->smileyId);
}

void MoodSmileyResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_MoodSmileyResultMessage(input);
}

void MoodSmileyResultMessage::deserializeAs_MoodSmileyResultMessage(Reader *input)
{
  this->_resultCodeFunc(input);
  this->_smileyIdFunc(input);
}

void MoodSmileyResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MoodSmileyResultMessage(tree);
}

void MoodSmileyResultMessage::deserializeAsyncAs_MoodSmileyResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MoodSmileyResultMessage::_resultCodeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MoodSmileyResultMessage::_smileyIdFunc, this, std::placeholders::_1));
}

void MoodSmileyResultMessage::_resultCodeFunc(Reader *input)
{
  this->resultCode = input->readByte();
  if(this->resultCode < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyResultMessage -"<<"Forbidden value (" << this->resultCode << ") on element of MoodSmileyResultMessage.resultCode.";
  }
}

void MoodSmileyResultMessage::_smileyIdFunc(Reader *input)
{
  this->smileyId = input->readVarUhShort();
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyResultMessage -"<<"Forbidden value (" << this->smileyId << ") on element of MoodSmileyResultMessage.smileyId.";
  }
}

MoodSmileyResultMessage::MoodSmileyResultMessage()
{
  m_type = MessageEnum::MOODSMILEYRESULTMESSAGE;
}

