#include "IdentificationSuccessWithLoginTokenMessage.h"

void IdentificationSuccessWithLoginTokenMessage::serialize(Writer *output)
{
  this->serializeAs_IdentificationSuccessWithLoginTokenMessage(output);
}

void IdentificationSuccessWithLoginTokenMessage::serializeAs_IdentificationSuccessWithLoginTokenMessage(Writer *output)
{
  IdentificationSuccessMessage::serializeAs_IdentificationSuccessMessage(output);
  output->writeUTF(this->loginToken);
}

void IdentificationSuccessWithLoginTokenMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdentificationSuccessWithLoginTokenMessage(input);
}

void IdentificationSuccessWithLoginTokenMessage::deserializeAs_IdentificationSuccessWithLoginTokenMessage(Reader *input)
{
  IdentificationSuccessMessage::deserialize(input);
  this->_loginTokenFunc(input);
}

void IdentificationSuccessWithLoginTokenMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdentificationSuccessWithLoginTokenMessage(tree);
}

void IdentificationSuccessWithLoginTokenMessage::deserializeAsyncAs_IdentificationSuccessWithLoginTokenMessage(FuncTree tree)
{
  IdentificationSuccessMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&IdentificationSuccessWithLoginTokenMessage::_loginTokenFunc, this, std::placeholders::_1));
}

void IdentificationSuccessWithLoginTokenMessage::_loginTokenFunc(Reader *input)
{
  this->loginToken = input->readUTF();
}

IdentificationSuccessWithLoginTokenMessage::IdentificationSuccessWithLoginTokenMessage()
{
  m_type = MessageEnum::IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE;
}

