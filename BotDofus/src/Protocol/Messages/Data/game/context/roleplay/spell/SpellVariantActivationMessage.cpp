#include "SpellVariantActivationMessage.h"

void SpellVariantActivationMessage::serialize(Writer *output)
{
  this->serializeAs_SpellVariantActivationMessage(output);
}

void SpellVariantActivationMessage::serializeAs_SpellVariantActivationMessage(Writer *output)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellVariantActivationMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
  output->writeBool(this->result);
}

void SpellVariantActivationMessage::deserialize(Reader *input)
{
  this->deserializeAs_SpellVariantActivationMessage(input);
}

void SpellVariantActivationMessage::deserializeAs_SpellVariantActivationMessage(Reader *input)
{
  this->_spellIdFunc(input);
  this->_resultFunc(input);
}

void SpellVariantActivationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpellVariantActivationMessage(tree);
}

void SpellVariantActivationMessage::deserializeAsyncAs_SpellVariantActivationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SpellVariantActivationMessage::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SpellVariantActivationMessage::_resultFunc, this, std::placeholders::_1));
}

void SpellVariantActivationMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellVariantActivationMessage -"<<"Forbidden value (" << this->spellId << ") on element of SpellVariantActivationMessage.spellId.";
  }
}

void SpellVariantActivationMessage::_resultFunc(Reader *input)
{
  this->result = input->readBool();
}

SpellVariantActivationMessage::SpellVariantActivationMessage()
{
  m_type = MessageEnum::SPELLVARIANTACTIVATIONMESSAGE;
}

