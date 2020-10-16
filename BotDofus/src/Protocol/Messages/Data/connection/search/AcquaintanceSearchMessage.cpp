#include "AcquaintanceSearchMessage.h"

void AcquaintanceSearchMessage::serialize(Writer *output)
{
  this->serializeAs_AcquaintanceSearchMessage(output);
}

void AcquaintanceSearchMessage::serializeAs_AcquaintanceSearchMessage(Writer *output)
{
  output->writeUTF(this->nickname);
}

void AcquaintanceSearchMessage::deserialize(Reader *input)
{
  this->deserializeAs_AcquaintanceSearchMessage(input);
}

void AcquaintanceSearchMessage::deserializeAs_AcquaintanceSearchMessage(Reader *input)
{
  this->_nicknameFunc(input);
}

void AcquaintanceSearchMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AcquaintanceSearchMessage(tree);
}

void AcquaintanceSearchMessage::deserializeAsyncAs_AcquaintanceSearchMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AcquaintanceSearchMessage::_nicknameFunc, this, std::placeholders::_1));
}

void AcquaintanceSearchMessage::_nicknameFunc(Reader *input)
{
  this->nickname = input->readUTF();
}

AcquaintanceSearchMessage::AcquaintanceSearchMessage()
{
  m_type = MessageEnum::ACQUAINTANCESEARCHMESSAGE;
}

