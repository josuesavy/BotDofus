#include "SpouseStatusMessage.h"

void SpouseStatusMessage::serialize(Writer *output)
{
  this->serializeAs_SpouseStatusMessage(output);
}

void SpouseStatusMessage::serializeAs_SpouseStatusMessage(Writer *output)
{
  output->writeBool(this->hasSpouse);
}

void SpouseStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_SpouseStatusMessage(input);
}

void SpouseStatusMessage::deserializeAs_SpouseStatusMessage(Reader *input)
{
  this->_hasSpouseFunc(input);
}

void SpouseStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpouseStatusMessage(tree);
}

void SpouseStatusMessage::deserializeAsyncAs_SpouseStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SpouseStatusMessage::_hasSpouseFunc, this, std::placeholders::_1));
}

void SpouseStatusMessage::_hasSpouseFunc(Reader *input)
{
  this->hasSpouse = input->readBool();
}

SpouseStatusMessage::SpouseStatusMessage()
{
  m_type = MessageEnum::SPOUSESTATUSMESSAGE;
}

