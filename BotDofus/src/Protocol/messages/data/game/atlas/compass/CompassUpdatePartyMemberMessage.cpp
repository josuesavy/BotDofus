#include "CompassUpdatePartyMemberMessage.h"

void CompassUpdatePartyMemberMessage::serialize(Writer *output)
{
  this->serializeAs_CompassUpdatePartyMemberMessage(output);
}

void CompassUpdatePartyMemberMessage::serializeAs_CompassUpdatePartyMemberMessage(Writer *output)
{
  CompassUpdateMessage::serializeAs_CompassUpdateMessage(output);
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CompassUpdatePartyMemberMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
  output->writeBool(this->active);
}

void CompassUpdatePartyMemberMessage::deserialize(Reader *input)
{
  this->deserializeAs_CompassUpdatePartyMemberMessage(input);
}

void CompassUpdatePartyMemberMessage::deserializeAs_CompassUpdatePartyMemberMessage(Reader *input)
{
  CompassUpdateMessage::deserialize(input);
  this->_memberIdFunc(input);
  this->_activeFunc(input);
}

void CompassUpdatePartyMemberMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CompassUpdatePartyMemberMessage(tree);
}

void CompassUpdatePartyMemberMessage::deserializeAsyncAs_CompassUpdatePartyMemberMessage(FuncTree tree)
{
  CompassUpdateMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&CompassUpdatePartyMemberMessage::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CompassUpdatePartyMemberMessage::_activeFunc, this, std::placeholders::_1));
}

void CompassUpdatePartyMemberMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CompassUpdatePartyMemberMessage -"<<"Forbidden value (" << this->memberId << ") on element of CompassUpdatePartyMemberMessage.memberId.";
  }
}

void CompassUpdatePartyMemberMessage::_activeFunc(Reader *input)
{
  this->active = input->readBool();
}

CompassUpdatePartyMemberMessage::CompassUpdatePartyMemberMessage()
{
  m_type = MessageEnum::COMPASSUPDATEPARTYMEMBERMESSAGE;
}

