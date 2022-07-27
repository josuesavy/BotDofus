#include "DiceRollRequestMessage.h"

void DiceRollRequestMessage::serialize(Writer *output)
{
  this->serializeAs_DiceRollRequestMessage(output);
}

void DiceRollRequestMessage::serializeAs_DiceRollRequestMessage(Writer *output)
{
  if(this->dice < 0)
  {
    qDebug()<<"ERREUR - DiceRollRequestMessage -"<<"Forbidden value (" << this->dice << ") on element dice.";
  }
  output->writeVarInt((int)this->dice);
  if(this->faces < 0)
  {
    qDebug()<<"ERREUR - DiceRollRequestMessage -"<<"Forbidden value (" << this->faces << ") on element faces.";
  }
  output->writeVarInt((int)this->faces);
  output->writeByte(this->channel);
}

void DiceRollRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_DiceRollRequestMessage(input);
}

void DiceRollRequestMessage::deserializeAs_DiceRollRequestMessage(Reader *input)
{
  this->_diceFunc(input);
  this->_facesFunc(input);
  this->_channelFunc(input);
}

void DiceRollRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DiceRollRequestMessage(tree);
}

void DiceRollRequestMessage::deserializeAsyncAs_DiceRollRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DiceRollRequestMessage::_diceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DiceRollRequestMessage::_facesFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DiceRollRequestMessage::_channelFunc, this, std::placeholders::_1));
}

void DiceRollRequestMessage::_diceFunc(Reader *input)
{
  this->dice = input->readVarUhInt();
  if(this->dice < 0)
  {
    qDebug()<<"ERREUR - DiceRollRequestMessage -"<<"Forbidden value (" << this->dice << ") on element of DiceRollRequestMessage.dice.";
  }
}

void DiceRollRequestMessage::_facesFunc(Reader *input)
{
  this->faces = input->readVarUhInt();
  if(this->faces < 0)
  {
    qDebug()<<"ERREUR - DiceRollRequestMessage -"<<"Forbidden value (" << this->faces << ") on element of DiceRollRequestMessage.faces.";
  }
}

void DiceRollRequestMessage::_channelFunc(Reader *input)
{
  this->channel = input->readByte();
  if(this->channel < 0)
  {
    qDebug()<<"ERREUR - DiceRollRequestMessage -"<<"Forbidden value (" << this->channel << ") on element of DiceRollRequestMessage.channel.";
  }
}

DiceRollRequestMessage::DiceRollRequestMessage()
{
  m_type = MessageEnum::DICEROLLREQUESTMESSAGE;
}

