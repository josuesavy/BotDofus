#include "HouseKickRequestMessage.h"

void HouseKickRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HouseKickRequestMessage(output);
}

void HouseKickRequestMessage::serializeAs_HouseKickRequestMessage(Writer *output)
{
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseKickRequestMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarLong((double)this->id);
}

void HouseKickRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseKickRequestMessage(input);
}

void HouseKickRequestMessage::deserializeAs_HouseKickRequestMessage(Reader *input)
{
  this->_idFunc(input);
}

void HouseKickRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseKickRequestMessage(tree);
}

void HouseKickRequestMessage::deserializeAsyncAs_HouseKickRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseKickRequestMessage::_idFunc, this, std::placeholders::_1));
}

void HouseKickRequestMessage::_idFunc(Reader *input)
{
  this->id = input->readVarUhLong();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseKickRequestMessage -"<<"Forbidden value (" << this->id << ") on element of HouseKickRequestMessage.id.";
  }
}

HouseKickRequestMessage::HouseKickRequestMessage()
{
  m_type = MessageEnum::HOUSEKICKREQUESTMESSAGE;
}

