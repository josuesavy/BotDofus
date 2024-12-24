#include "CompassUpdatePvpSeekMessage.h"

void CompassUpdatePvpSeekMessage::serialize(Writer *output)
{
  this->serializeAs_CompassUpdatePvpSeekMessage(output);
}

void CompassUpdatePvpSeekMessage::serializeAs_CompassUpdatePvpSeekMessage(Writer *output)
{
  CompassUpdateMessage::serializeAs_CompassUpdateMessage(output);
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - CompassUpdatePvpSeekMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
  output->writeUTF(this->memberName);
}

void CompassUpdatePvpSeekMessage::deserialize(Reader *input)
{
  this->deserializeAs_CompassUpdatePvpSeekMessage(input);
}

void CompassUpdatePvpSeekMessage::deserializeAs_CompassUpdatePvpSeekMessage(Reader *input)
{
  CompassUpdateMessage::deserialize(input);
  this->_memberIdFunc(input);
  this->_memberNameFunc(input);
}

void CompassUpdatePvpSeekMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CompassUpdatePvpSeekMessage(tree);
}

void CompassUpdatePvpSeekMessage::deserializeAsyncAs_CompassUpdatePvpSeekMessage(FuncTree tree)
{
  CompassUpdateMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&CompassUpdatePvpSeekMessage::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CompassUpdatePvpSeekMessage::_memberNameFunc, this, std::placeholders::_1));
}

void CompassUpdatePvpSeekMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - CompassUpdatePvpSeekMessage -"<<"Forbidden value (" << this->memberId << ") on element of CompassUpdatePvpSeekMessage.memberId.";
  }
}

void CompassUpdatePvpSeekMessage::_memberNameFunc(Reader *input)
{
  this->memberName = input->readUTF();
}

CompassUpdatePvpSeekMessage::CompassUpdatePvpSeekMessage()
{
  m_type = MessageEnum::COMPASSUPDATEPVPSEEKMESSAGE;
}

