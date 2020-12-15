#include "MoodSmileyRequestMessage.h"

void MoodSmileyRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MoodSmileyRequestMessage(output);
}

void MoodSmileyRequestMessage::serializeAs_MoodSmileyRequestMessage(Writer *output)
{
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyRequestMessage -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
  }
  output->writeVarShort((int)this->smileyId);
}

void MoodSmileyRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MoodSmileyRequestMessage(input);
}

void MoodSmileyRequestMessage::deserializeAs_MoodSmileyRequestMessage(Reader *input)
{
  this->_smileyIdFunc(input);
}

void MoodSmileyRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MoodSmileyRequestMessage(tree);
}

void MoodSmileyRequestMessage::deserializeAsyncAs_MoodSmileyRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MoodSmileyRequestMessage::_smileyIdFunc, this, std::placeholders::_1));
}

void MoodSmileyRequestMessage::_smileyIdFunc(Reader *input)
{
  this->smileyId = input->readVarUhShort();
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyRequestMessage -"<<"Forbidden value (" << this->smileyId << ") on element of MoodSmileyRequestMessage.smileyId.";
  }
}

MoodSmileyRequestMessage::MoodSmileyRequestMessage()
{
  m_type = MessageEnum::MOODSMILEYREQUESTMESSAGE;
}

