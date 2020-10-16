#include "DocumentReadingBeginMessage.h"

void DocumentReadingBeginMessage::serialize(Writer *output)
{
  this->serializeAs_DocumentReadingBeginMessage(output);
}

void DocumentReadingBeginMessage::serializeAs_DocumentReadingBeginMessage(Writer *output)
{
  if(this->documentId < 0)
  {
    qDebug()<<"ERREUR - DocumentReadingBeginMessage -"<<"Forbidden value (" << this->documentId << ") on element documentId.";
  }
  output->writeVarShort((int)this->documentId);
}

void DocumentReadingBeginMessage::deserialize(Reader *input)
{
  this->deserializeAs_DocumentReadingBeginMessage(input);
}

void DocumentReadingBeginMessage::deserializeAs_DocumentReadingBeginMessage(Reader *input)
{
  this->_documentIdFunc(input);
}

void DocumentReadingBeginMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DocumentReadingBeginMessage(tree);
}

void DocumentReadingBeginMessage::deserializeAsyncAs_DocumentReadingBeginMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DocumentReadingBeginMessage::_documentIdFunc, this, std::placeholders::_1));
}

void DocumentReadingBeginMessage::_documentIdFunc(Reader *input)
{
  this->documentId = input->readVarUhShort();
  if(this->documentId < 0)
  {
    qDebug()<<"ERREUR - DocumentReadingBeginMessage -"<<"Forbidden value (" << this->documentId << ") on element of DocumentReadingBeginMessage.documentId.";
  }
}

DocumentReadingBeginMessage::DocumentReadingBeginMessage()
{
  m_type = MessageEnum::DOCUMENTREADINGBEGINMESSAGE;
}

