#include "AllianceApplicationDeletedMessage.h"

void AllianceApplicationDeletedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceApplicationDeletedMessage(output);
}

void AllianceApplicationDeletedMessage::serializeAs_AllianceApplicationDeletedMessage(Writer *output)
{
  output->writeBool(this->deleted);
}

void AllianceApplicationDeletedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceApplicationDeletedMessage(input);
}

void AllianceApplicationDeletedMessage::deserializeAs_AllianceApplicationDeletedMessage(Reader *input)
{
  this->_deletedFunc(input);
}

void AllianceApplicationDeletedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceApplicationDeletedMessage(tree);
}

void AllianceApplicationDeletedMessage::deserializeAsyncAs_AllianceApplicationDeletedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceApplicationDeletedMessage::_deletedFunc, this, std::placeholders::_1));
}

void AllianceApplicationDeletedMessage::_deletedFunc(Reader *input)
{
  this->deleted = input->readBool();
}

AllianceApplicationDeletedMessage::AllianceApplicationDeletedMessage()
{
  m_type = MessageEnum::ALLIANCEAPPLICATIONDELETEDMESSAGE;
}

