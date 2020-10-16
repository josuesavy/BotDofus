#include "LockableCodeResultMessage.h"

void LockableCodeResultMessage::serialize(Writer *output)
{
  this->serializeAs_LockableCodeResultMessage(output);
}

void LockableCodeResultMessage::serializeAs_LockableCodeResultMessage(Writer *output)
{
  output->writeByte(this->result);
}

void LockableCodeResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_LockableCodeResultMessage(input);
}

void LockableCodeResultMessage::deserializeAs_LockableCodeResultMessage(Reader *input)
{
  this->_resultFunc(input);
}

void LockableCodeResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LockableCodeResultMessage(tree);
}

void LockableCodeResultMessage::deserializeAsyncAs_LockableCodeResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LockableCodeResultMessage::_resultFunc, this, std::placeholders::_1));
}

void LockableCodeResultMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - LockableCodeResultMessage -"<<"Forbidden value (" << this->result << ") on element of LockableCodeResultMessage.result.";
  }
}

LockableCodeResultMessage::LockableCodeResultMessage()
{
  m_type = MessageEnum::LOCKABLECODERESULTMESSAGE;
}

