#include "MimicryObjectPreviewMessage.h"

void MimicryObjectPreviewMessage::serialize(Writer *output)
{
  this->serializeAs_MimicryObjectPreviewMessage(output);
}

void MimicryObjectPreviewMessage::serializeAs_MimicryObjectPreviewMessage(Writer *output)
{
  this->result->serializeAs_ObjectItem(output);
}

void MimicryObjectPreviewMessage::deserialize(Reader *input)
{
  this->deserializeAs_MimicryObjectPreviewMessage(input);
}

void MimicryObjectPreviewMessage::deserializeAs_MimicryObjectPreviewMessage(Reader *input)
{
  this->result = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->result->deserialize(input);
}

void MimicryObjectPreviewMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MimicryObjectPreviewMessage(tree);
}

void MimicryObjectPreviewMessage::deserializeAsyncAs_MimicryObjectPreviewMessage(FuncTree tree)
{
  this->_resulttree = tree.addChild(std::bind(&MimicryObjectPreviewMessage::_resulttreeFunc, this, std::placeholders::_1));
}

void MimicryObjectPreviewMessage::_resulttreeFunc(Reader *input)
{
  this->result = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->result->deserializeAsync(this->_resulttree);
}

MimicryObjectPreviewMessage::MimicryObjectPreviewMessage()
{
  m_type = MessageEnum::MIMICRYOBJECTPREVIEWMESSAGE;
}

