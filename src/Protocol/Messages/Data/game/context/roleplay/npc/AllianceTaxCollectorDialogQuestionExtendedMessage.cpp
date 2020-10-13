#include "AllianceTaxCollectorDialogQuestionExtendedMessage.h"

void AllianceTaxCollectorDialogQuestionExtendedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(output);
}

void AllianceTaxCollectorDialogQuestionExtendedMessage::serializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(Writer *output)
{
  TaxCollectorDialogQuestionExtendedMessage::serializeAs_TaxCollectorDialogQuestionExtendedMessage(output);
  this->alliance->serializeAs_BasicNamedAllianceInformations(output);
}

void AllianceTaxCollectorDialogQuestionExtendedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(input);
}

void AllianceTaxCollectorDialogQuestionExtendedMessage::deserializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(Reader *input)
{
  TaxCollectorDialogQuestionExtendedMessage::deserialize(input);
  this->alliance = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->alliance->deserialize(input);
}

void AllianceTaxCollectorDialogQuestionExtendedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceTaxCollectorDialogQuestionExtendedMessage(tree);
}

void AllianceTaxCollectorDialogQuestionExtendedMessage::deserializeAsyncAs_AllianceTaxCollectorDialogQuestionExtendedMessage(FuncTree tree)
{
  TaxCollectorDialogQuestionExtendedMessage::deserializeAsync(tree);
  this->_alliancetree = tree.addChild(std::bind(&AllianceTaxCollectorDialogQuestionExtendedMessage::_alliancetreeFunc, this, std::placeholders::_1));
}

void AllianceTaxCollectorDialogQuestionExtendedMessage::_alliancetreeFunc(Reader *input)
{
  this->alliance = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->alliance->deserializeAsync(this->_alliancetree);
}

AllianceTaxCollectorDialogQuestionExtendedMessage::AllianceTaxCollectorDialogQuestionExtendedMessage()
{
  m_type = MessageEnum::ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE;
}

