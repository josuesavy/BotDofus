#include "DebugInClientMessage.h"

void DebugInClientMessage::serialize(Writer *output)
{
  this->serializeAs_DebugInClientMessage(output);
}

void DebugInClientMessage::serializeAs_DebugInClientMessage(Writer *output)
{
  output->writeByte(this->level);
  output->writeUTF(this->message);
}

void DebugInClientMessage::deserialize(Reader *input)
{
  this->deserializeAs_DebugInClientMessage(input);
}

void DebugInClientMessage::deserializeAs_DebugInClientMessage(Reader *input)
{
  this->_levelFunc(input);
  this->_messageFunc(input);
}

void DebugInClientMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DebugInClientMessage(tree);
}

void DebugInClientMessage::deserializeAsyncAs_DebugInClientMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DebugInClientMessage::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DebugInClientMessage::_messageFunc, this, std::placeholders::_1));
}

void DebugInClientMessage::_levelFunc(Reader *input)
{
  this->level = input->readByte();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - DebugInClientMessage -"<<"Forbidden value (" << this->level << ") on element of DebugInClientMessage.level.";
  }
}

void DebugInClientMessage::_messageFunc(Reader *input)
{
  this->message = input->readUTF();
}

DebugInClientMessage::DebugInClientMessage()
{
  m_type = MessageEnum::DEBUGINCLIENTMESSAGE;
}

