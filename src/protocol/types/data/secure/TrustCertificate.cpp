#include "TrustCertificate.h"

void TrustCertificate::serialize(Writer *output)
{
  this->serializeAs_TrustCertificate(output);
}

void TrustCertificate::serializeAs_TrustCertificate(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - TrustCertificate -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeInt((int)this->id);
  output->writeUTF(this->hash);
}

void TrustCertificate::deserialize(Reader *input)
{
  this->deserializeAs_TrustCertificate(input);
}

void TrustCertificate::deserializeAs_TrustCertificate(Reader *input)
{
  this->_idFunc(input);
  this->_hashFunc(input);
}

void TrustCertificate::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TrustCertificate(tree);
}

void TrustCertificate::deserializeAsyncAs_TrustCertificate(FuncTree tree)
{
  tree.addChild(std::bind(&TrustCertificate::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TrustCertificate::_hashFunc, this, std::placeholders::_1));
}

void TrustCertificate::_idFunc(Reader *input)
{
  this->id = input->readInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - TrustCertificate -"<<"Forbidden value (" << this->id << ") on element of TrustCertificate.id.";
  }
}

void TrustCertificate::_hashFunc(Reader *input)
{
  this->hash = input->readUTF();
}

TrustCertificate::TrustCertificate()
{
  m_types<<ClassEnum::TRUSTCERTIFICATE;
}

bool TrustCertificate::operator==(const TrustCertificate &compared)
{
  if(id == compared.id)
  if(hash == compared.hash)
  return true;
  
  return false;
}

