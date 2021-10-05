#include "LockableShowCodeDialogMessage.h"

void LockableShowCodeDialogMessage::serialize(Writer *output)
{
  this->serializeAs_LockableShowCodeDialogMessage(output);
}

void LockableShowCodeDialogMessage::serializeAs_LockableShowCodeDialogMessage(Writer *output)
{
  output->writeBool(this->changeOrUse);
  if(this->codeSize < 0)
  {
    qDebug()<<"ERREUR - LockableShowCodeDialogMessage -"<<"Forbidden value (" << this->codeSize << ") on element codeSize.";
  }
  output->writeByte(this->codeSize);
}

void LockableShowCodeDialogMessage::deserialize(Reader *input)
{
  this->deserializeAs_LockableShowCodeDialogMessage(input);
}

void LockableShowCodeDialogMessage::deserializeAs_LockableShowCodeDialogMessage(Reader *input)
{
  this->_changeOrUseFunc(input);
  this->_codeSizeFunc(input);
}

void LockableShowCodeDialogMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LockableShowCodeDialogMessage(tree);
}

void LockableShowCodeDialogMessage::deserializeAsyncAs_LockableShowCodeDialogMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LockableShowCodeDialogMessage::_changeOrUseFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LockableShowCodeDialogMessage::_codeSizeFunc, this, std::placeholders::_1));
}

void LockableShowCodeDialogMessage::_changeOrUseFunc(Reader *input)
{
  this->changeOrUse = input->readBool();
}

void LockableShowCodeDialogMessage::_codeSizeFunc(Reader *input)
{
  this->codeSize = input->readByte();
  if(this->codeSize < 0)
  {
    qDebug()<<"ERREUR - LockableShowCodeDialogMessage -"<<"Forbidden value (" << this->codeSize << ") on element of LockableShowCodeDialogMessage.codeSize.";
  }
}

LockableShowCodeDialogMessage::LockableShowCodeDialogMessage()
{
  m_type = MessageEnum::LOCKABLESHOWCODEDIALOGMESSAGE;
}

