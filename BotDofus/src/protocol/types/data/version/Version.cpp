#include "Version.h"

void Version::serialize(Writer *output)
{
  this->serializeAs_Version(output);
}

void Version::serializeAs_Version(Writer *output)
{
  if(this->major < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->major << ") on element major.";
  }
  output->writeByte(this->major);
  if(this->minor < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->minor << ") on element minor.";
  }
  output->writeByte(this->minor);
  if(this->code < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->code << ") on element code.";
  }
  output->writeByte(this->code);
  if(this->build < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->build << ") on element build.";
  }
  output->writeInt((int)this->build);
  output->writeByte(this->buildType);
}

void Version::deserialize(Reader *input)
{
  this->deserializeAs_Version(input);
}

void Version::deserializeAs_Version(Reader *input)
{
  this->_majorFunc(input);
  this->_minorFunc(input);
  this->_codeFunc(input);
  this->_buildFunc(input);
  this->_buildTypeFunc(input);
}

void Version::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_Version(tree);
}

void Version::deserializeAsyncAs_Version(FuncTree tree)
{
  tree.addChild(std::bind(&Version::_majorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&Version::_minorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&Version::_codeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&Version::_buildFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&Version::_buildTypeFunc, this, std::placeholders::_1));
}

void Version::_majorFunc(Reader *input)
{
  this->major = input->readByte();
  if(this->major < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->major << ") on element of Version.major.";
  }
}

void Version::_minorFunc(Reader *input)
{
  this->minor = input->readByte();
  if(this->minor < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->minor << ") on element of Version.minor.";
  }
}

void Version::_codeFunc(Reader *input)
{
  this->code = input->readByte();
  if(this->code < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->code << ") on element of Version.code.";
  }
}

void Version::_buildFunc(Reader *input)
{
  this->build = input->readInt();
  if(this->build < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->build << ") on element of Version.build.";
  }
}

void Version::_buildTypeFunc(Reader *input)
{
  this->buildType = input->readByte();
  if(this->buildType < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->buildType << ") on element of Version.buildType.";
  }
}

Version::Version()
{
  m_types<<ClassEnum::VERSION;
}

bool Version::operator==(const Version &compared)
{
  if(major == compared.major)
  if(minor == compared.minor)
  if(code == compared.code)
  if(build == compared.build)
  if(buildType == compared.buildType)
  return true;
  
  return false;
}

