#include "NicknameRefusedMessage.h"

void NicknameRefusedMessage::serialize(Writer *output)
{
  this->serializeAs_NicknameRefusedMessage(output);
}

void NicknameRefusedMessage::serializeAs_NicknameRefusedMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void NicknameRefusedMessage::deserialize(Reader *input)
{
  this->deserializeAs_NicknameRefusedMessage(input);
}

void NicknameRefusedMessage::deserializeAs_NicknameRefusedMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void NicknameRefusedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NicknameRefusedMessage(tree);
}

void NicknameRefusedMessage::deserializeAsyncAs_NicknameRefusedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NicknameRefusedMessage::_reasonFunc, this, std::placeholders::_1));
}

void NicknameRefusedMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - NicknameRefusedMessage -"<<"Forbidden value (" << this->reason << ") on element of NicknameRefusedMessage.reason.";
  }
}

NicknameRefusedMessage::NicknameRefusedMessage()
{
  m_type = MessageEnum::NICKNAMEREFUSEDMESSAGE;
}

