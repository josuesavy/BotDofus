#include "TaxCollectorDialogQuestionBasicMessage.h"

void TaxCollectorDialogQuestionBasicMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorDialogQuestionBasicMessage(output);
}

void TaxCollectorDialogQuestionBasicMessage::serializeAs_TaxCollectorDialogQuestionBasicMessage(Writer *output)
{
  this->guildInfo->serializeAs_BasicGuildInformations(output);
}

void TaxCollectorDialogQuestionBasicMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorDialogQuestionBasicMessage(input);
}

void TaxCollectorDialogQuestionBasicMessage::deserializeAs_TaxCollectorDialogQuestionBasicMessage(Reader *input)
{
  this->guildInfo = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guildInfo->deserialize(input);
}

void TaxCollectorDialogQuestionBasicMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorDialogQuestionBasicMessage(tree);
}

void TaxCollectorDialogQuestionBasicMessage::deserializeAsyncAs_TaxCollectorDialogQuestionBasicMessage(FuncTree tree)
{
  this->_guildInfotree = tree.addChild(std::bind(&TaxCollectorDialogQuestionBasicMessage::_guildInfotreeFunc, this, std::placeholders::_1));
}

void TaxCollectorDialogQuestionBasicMessage::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

TaxCollectorDialogQuestionBasicMessage::TaxCollectorDialogQuestionBasicMessage()
{
  m_type = MessageEnum::TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE;
}

