#include "BreachInvitationRequestMessage.h"

void BreachInvitationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_BreachInvitationRequestMessage(output);
}

void BreachInvitationRequestMessage::serializeAs_BreachInvitationRequestMessage(Writer *output)
{
  output->writeShort((short)this->guests.size());
  for(uint _i1 = 0; _i1 < this->guests.size(); _i1++)
  {
    if(this->guests[_i1] < 0 || this->guests[_i1] > 9007199254740992)
    {
      qDebug()<<"ERREUR - BreachInvitationRequestMessage -"<<"Forbidden value (" << this->guests[_i1] << ") on element 1 (starting at 1) of guests.";
    }
    output->writeVarLong((double)this->guests[_i1]);
  }
}

void BreachInvitationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachInvitationRequestMessage(input);
}

void BreachInvitationRequestMessage::deserializeAs_BreachInvitationRequestMessage(Reader *input)
{
  double _val1 = NULL;
  uint _guestsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _guestsLen; _i1++)
  {
    _val1 = input->readVarUhLong();
    if(_val1 < 0 || _val1 > 9007199254740992)
    {
      qDebug()<<"ERREUR - BreachInvitationRequestMessage -"<<"Forbidden value (" << _val1 << ") on elements of guests.";
    }
    this->guests.append(_val1);
  }
}

void BreachInvitationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachInvitationRequestMessage(tree);
}

void BreachInvitationRequestMessage::deserializeAsyncAs_BreachInvitationRequestMessage(FuncTree tree)
{
  this->_gueststree = tree.addChild(std::bind(&BreachInvitationRequestMessage::_gueststreeFunc, this, std::placeholders::_1));
}

void BreachInvitationRequestMessage::_gueststreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_gueststree.addChild(std::bind(&BreachInvitationRequestMessage::_guestsFunc, this, std::placeholders::_1));
  }
}

void BreachInvitationRequestMessage::_guestsFunc(Reader *input)
{
  double _val = input->readVarUhLong();
  if(_val < 0 || _val > 9007199254740992)
  {
    qDebug()<<"ERREUR - BreachInvitationRequestMessage -"<<"Forbidden value (" << _val << ") on elements of guests.";
  }
  this->guests.append(_val);
}

BreachInvitationRequestMessage::BreachInvitationRequestMessage()
{
  m_type = MessageEnum::BREACHINVITATIONREQUESTMESSAGE;
}

