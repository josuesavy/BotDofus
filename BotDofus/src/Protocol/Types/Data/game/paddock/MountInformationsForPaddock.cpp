#include "MountInformationsForPaddock.h"

void MountInformationsForPaddock::serialize(Writer *output)
{
  this->serializeAs_MountInformationsForPaddock(output);
}

void MountInformationsForPaddock::serializeAs_MountInformationsForPaddock(Writer *output)
{
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - MountInformationsForPaddock -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
  }
  output->writeVarShort((int)this->modelId);
  output->writeUTF(this->name);
  output->writeUTF(this->ownerName);
}

void MountInformationsForPaddock::deserialize(Reader *input)
{
  this->deserializeAs_MountInformationsForPaddock(input);
}

void MountInformationsForPaddock::deserializeAs_MountInformationsForPaddock(Reader *input)
{
  this->_modelIdFunc(input);
  this->_nameFunc(input);
  this->_ownerNameFunc(input);
}

void MountInformationsForPaddock::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountInformationsForPaddock(tree);
}

void MountInformationsForPaddock::deserializeAsyncAs_MountInformationsForPaddock(FuncTree tree)
{
  tree.addChild(std::bind(&MountInformationsForPaddock::_modelIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountInformationsForPaddock::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountInformationsForPaddock::_ownerNameFunc, this, std::placeholders::_1));
}

void MountInformationsForPaddock::_modelIdFunc(Reader *input)
{
  this->modelId = input->readVarUhShort();
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - MountInformationsForPaddock -"<<"Forbidden value (" << this->modelId << ") on element of MountInformationsForPaddock.modelId.";
  }
}

void MountInformationsForPaddock::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void MountInformationsForPaddock::_ownerNameFunc(Reader *input)
{
  this->ownerName = input->readUTF();
}

MountInformationsForPaddock::MountInformationsForPaddock()
{
  m_types<<ClassEnum::MOUNTINFORMATIONSFORPADDOCK;
}

bool MountInformationsForPaddock::operator==(const MountInformationsForPaddock &compared)
{
  if(modelId == compared.modelId)
  if(name == compared.name)
  if(ownerName == compared.ownerName)
  return true;
  
  return false;
}

