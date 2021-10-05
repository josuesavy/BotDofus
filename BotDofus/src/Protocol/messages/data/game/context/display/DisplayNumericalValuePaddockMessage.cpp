#include "DisplayNumericalValuePaddockMessage.h"

void DisplayNumericalValuePaddockMessage::serialize(Writer *output)
{
  this->serializeAs_DisplayNumericalValuePaddockMessage(output);
}

void DisplayNumericalValuePaddockMessage::serializeAs_DisplayNumericalValuePaddockMessage(Writer *output)
{
  output->writeInt((int)this->rideId);
  output->writeInt((int)this->value);
  output->writeByte(this->type);
}

void DisplayNumericalValuePaddockMessage::deserialize(Reader *input)
{
  this->deserializeAs_DisplayNumericalValuePaddockMessage(input);
}

void DisplayNumericalValuePaddockMessage::deserializeAs_DisplayNumericalValuePaddockMessage(Reader *input)
{
  this->_rideIdFunc(input);
  this->_valueFunc(input);
  this->_typeFunc(input);
}

void DisplayNumericalValuePaddockMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DisplayNumericalValuePaddockMessage(tree);
}

void DisplayNumericalValuePaddockMessage::deserializeAsyncAs_DisplayNumericalValuePaddockMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DisplayNumericalValuePaddockMessage::_rideIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DisplayNumericalValuePaddockMessage::_valueFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DisplayNumericalValuePaddockMessage::_typeFunc, this, std::placeholders::_1));
}

void DisplayNumericalValuePaddockMessage::_rideIdFunc(Reader *input)
{
  this->rideId = input->readInt();
}

void DisplayNumericalValuePaddockMessage::_valueFunc(Reader *input)
{
  this->value = input->readInt();
}

void DisplayNumericalValuePaddockMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - DisplayNumericalValuePaddockMessage -"<<"Forbidden value (" << this->type << ") on element of DisplayNumericalValuePaddockMessage.type.";
  }
}

DisplayNumericalValuePaddockMessage::DisplayNumericalValuePaddockMessage()
{
  m_type = MessageEnum::DISPLAYNUMERICALVALUEPADDOCKMESSAGE;
}

