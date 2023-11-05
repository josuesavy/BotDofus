#include "TaxCollectorDialogQuestionBasicMessage.h"

void TaxCollectorDialogQuestionBasicMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorDialogQuestionBasicMessage(output);
}

void TaxCollectorDialogQuestionBasicMessage::serializeAs_TaxCollectorDialogQuestionBasicMessage(Writer *output)
{
  this->allianceInfo->serializeAs_BasicAllianceInformations(output);
}

void TaxCollectorDialogQuestionBasicMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorDialogQuestionBasicMessage(input);
}

void TaxCollectorDialogQuestionBasicMessage::deserializeAs_TaxCollectorDialogQuestionBasicMessage(Reader *input)
{
  this->allianceInfo = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->allianceInfo->deserialize(input);
}

void TaxCollectorDialogQuestionBasicMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorDialogQuestionBasicMessage(tree);
}

void TaxCollectorDialogQuestionBasicMessage::deserializeAsyncAs_TaxCollectorDialogQuestionBasicMessage(FuncTree tree)
{
  this->_allianceInfotree = tree.addChild(std::bind(&TaxCollectorDialogQuestionBasicMessage::_allianceInfotreeFunc, this, std::placeholders::_1));
}

void TaxCollectorDialogQuestionBasicMessage::_allianceInfotreeFunc(Reader *input)
{
  this->allianceInfo = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->allianceInfo->deserializeAsync(this->_allianceInfotree);
}

TaxCollectorDialogQuestionBasicMessage::TaxCollectorDialogQuestionBasicMessage()
{
  m_type = MessageEnum::TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE;
}

