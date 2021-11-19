#include "CompassResetMessage.h"

void CompassResetMessage::serialize(Writer *output)
{
  this->serializeAs_CompassResetMessage(output);
}

void CompassResetMessage::serializeAs_CompassResetMessage(Writer *output)
{
  output->writeByte(this->type);
}

void CompassResetMessage::deserialize(Reader *input)
{
  this->deserializeAs_CompassResetMessage(input);
}

void CompassResetMessage::deserializeAs_CompassResetMessage(Reader *input)
{
  this->_typeFunc(input);
}

void CompassResetMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CompassResetMessage(tree);
}

void CompassResetMessage::deserializeAsyncAs_CompassResetMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CompassResetMessage::_typeFunc, this, std::placeholders::_1));
}

void CompassResetMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - CompassResetMessage -"<<"Forbidden value (" << this->type << ") on element of CompassResetMessage.type.";
  }
}

CompassResetMessage::CompassResetMessage()
{
  m_type = MessageEnum::COMPASSRESETMESSAGE;
}

