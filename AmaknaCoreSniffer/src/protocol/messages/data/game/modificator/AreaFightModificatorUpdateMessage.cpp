#include "AreaFightModificatorUpdateMessage.h"

void AreaFightModificatorUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_AreaFightModificatorUpdateMessage(output);
}

void AreaFightModificatorUpdateMessage::serializeAs_AreaFightModificatorUpdateMessage(Writer *output)
{
  output->writeInt((int)this->spellPairId);
}

void AreaFightModificatorUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_AreaFightModificatorUpdateMessage(input);
}

void AreaFightModificatorUpdateMessage::deserializeAs_AreaFightModificatorUpdateMessage(Reader *input)
{
  this->_spellPairIdFunc(input);
}

void AreaFightModificatorUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AreaFightModificatorUpdateMessage(tree);
}

void AreaFightModificatorUpdateMessage::deserializeAsyncAs_AreaFightModificatorUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AreaFightModificatorUpdateMessage::_spellPairIdFunc, this, std::placeholders::_1));
}

void AreaFightModificatorUpdateMessage::_spellPairIdFunc(Reader *input)
{
  this->spellPairId = input->readInt();
}

AreaFightModificatorUpdateMessage::AreaFightModificatorUpdateMessage()
{
  m_type = MessageEnum::AREAFIGHTMODIFICATORUPDATEMESSAGE;
}

