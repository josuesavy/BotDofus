#include "SpellVariantActivationRequestMessage.h"

void SpellVariantActivationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_SpellVariantActivationRequestMessage(output);
}

void SpellVariantActivationRequestMessage::serializeAs_SpellVariantActivationRequestMessage(Writer *output)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellVariantActivationRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
}

void SpellVariantActivationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_SpellVariantActivationRequestMessage(input);
}

void SpellVariantActivationRequestMessage::deserializeAs_SpellVariantActivationRequestMessage(Reader *input)
{
  this->_spellIdFunc(input);
}

void SpellVariantActivationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpellVariantActivationRequestMessage(tree);
}

void SpellVariantActivationRequestMessage::deserializeAsyncAs_SpellVariantActivationRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SpellVariantActivationRequestMessage::_spellIdFunc, this, std::placeholders::_1));
}

void SpellVariantActivationRequestMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellVariantActivationRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element of SpellVariantActivationRequestMessage.spellId.";
  }
}

SpellVariantActivationRequestMessage::SpellVariantActivationRequestMessage()
{
  m_type = MessageEnum::SPELLVARIANTACTIVATIONREQUESTMESSAGE;
}

