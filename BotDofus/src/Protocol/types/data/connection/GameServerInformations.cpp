#include "GameServerInformations.h"

void GameServerInformations::serialize(Writer *output)
{
  this->serializeAs_GameServerInformations(output);
}

void GameServerInformations::serializeAs_GameServerInformations(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->isMonoAccount);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->isSelectable);
  output->writeByte(_box0);
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarShort((int)this->id);
  output->writeByte(this->type);
  output->writeByte(this->status);
  output->writeByte(this->completion);
  if(this->charactersCount < 0)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->charactersCount << ") on element charactersCount.";
  }
  output->writeByte(this->charactersCount);
  if(this->charactersSlots < 0)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->charactersSlots << ") on element charactersSlots.";
  }
  output->writeByte(this->charactersSlots);
  if(this->date < -9.007199254740992E15 || this->date > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->date << ") on element date.";
  }
  output->writeDouble(this->date);
}

void GameServerInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameServerInformations(input);
}

void GameServerInformations::deserializeAs_GameServerInformations(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_idFunc(input);
  this->_typeFunc(input);
  this->_statusFunc(input);
  this->_completionFunc(input);
  this->_charactersCountFunc(input);
  this->_charactersSlotsFunc(input);
  this->_dateFunc(input);
}

void GameServerInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameServerInformations(tree);
}

void GameServerInformations::deserializeAsyncAs_GameServerInformations(FuncTree tree)
{
  tree.addChild(std::bind(&GameServerInformations::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameServerInformations::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameServerInformations::_typeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameServerInformations::_statusFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameServerInformations::_completionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameServerInformations::_charactersCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameServerInformations::_charactersSlotsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameServerInformations::_dateFunc, this, std::placeholders::_1));
}

void GameServerInformations::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->isMonoAccount = BooleanByteWrapper::getFlag(_box0, 0);
  this->isSelectable = BooleanByteWrapper::getFlag(_box0, 1);
}

void GameServerInformations::_idFunc(Reader *input)
{
  this->id = input->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->id << ") on element of GameServerInformations.id.";
  }
}

void GameServerInformations::_typeFunc(Reader *input)
{
  this->type = input->readByte();
}

void GameServerInformations::_statusFunc(Reader *input)
{
  this->status = input->readByte();
  if(this->status < 0)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->status << ") on element of GameServerInformations.status.";
  }
}

void GameServerInformations::_completionFunc(Reader *input)
{
  this->completion = input->readByte();
  if(this->completion < 0)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->completion << ") on element of GameServerInformations.completion.";
  }
}

void GameServerInformations::_charactersCountFunc(Reader *input)
{
  this->charactersCount = input->readByte();
  if(this->charactersCount < 0)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->charactersCount << ") on element of GameServerInformations.charactersCount.";
  }
}

void GameServerInformations::_charactersSlotsFunc(Reader *input)
{
  this->charactersSlots = input->readByte();
  if(this->charactersSlots < 0)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->charactersSlots << ") on element of GameServerInformations.charactersSlots.";
  }
}

void GameServerInformations::_dateFunc(Reader *input)
{
  this->date = input->readDouble();
  if(this->date < -9.007199254740992E15 || this->date > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->date << ") on element of GameServerInformations.date.";
  }
}

GameServerInformations::GameServerInformations()
{
  m_types<<ClassEnum::GAMESERVERINFORMATIONS;
}

bool GameServerInformations::operator==(const GameServerInformations &compared)
{
  if(id == compared.id)
  if(type == compared.type)
  if(isMonoAccount == compared.isMonoAccount)
  if(status == compared.status)
  if(completion == compared.completion)
  if(isSelectable == compared.isSelectable)
  if(charactersCount == compared.charactersCount)
  if(charactersSlots == compared.charactersSlots)
  if(date == compared.date)
  return true;
  
  return false;
}

