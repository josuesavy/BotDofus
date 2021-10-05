#include "StartupActionFinishedMessage.h"

void StartupActionFinishedMessage::serialize(Writer *output)
{
  this->serializeAs_StartupActionFinishedMessage(output);
}

void StartupActionFinishedMessage::serializeAs_StartupActionFinishedMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->success);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->automaticAction);
  output->writeByte(_box0);
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - StartupActionFinishedMessage -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  output->writeInt((int)this->actionId);
}

void StartupActionFinishedMessage::deserialize(Reader *input)
{
  this->deserializeAs_StartupActionFinishedMessage(input);
}

void StartupActionFinishedMessage::deserializeAs_StartupActionFinishedMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_actionIdFunc(input);
}

void StartupActionFinishedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StartupActionFinishedMessage(tree);
}

void StartupActionFinishedMessage::deserializeAsyncAs_StartupActionFinishedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&StartupActionFinishedMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&StartupActionFinishedMessage::_actionIdFunc, this, std::placeholders::_1));
}

void StartupActionFinishedMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->success = BooleanByteWrapper::getFlag(_box0, 0);
  this->automaticAction = BooleanByteWrapper::getFlag(_box0, 1);
}

void StartupActionFinishedMessage::_actionIdFunc(Reader *input)
{
  this->actionId = input->readInt();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - StartupActionFinishedMessage -"<<"Forbidden value (" << this->actionId << ") on element of StartupActionFinishedMessage.actionId.";
  }
}

StartupActionFinishedMessage::StartupActionFinishedMessage()
{
  m_type = MessageEnum::STARTUPACTIONFINISHEDMESSAGE;
}

