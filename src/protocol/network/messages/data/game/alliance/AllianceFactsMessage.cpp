#include "AllianceFactsMessage.h"

void AllianceFactsMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceFactsMessage(output);
}

void AllianceFactsMessage::serializeAs_AllianceFactsMessage(Writer *output)
{
  output->writeShort((short)this->infos->getTypes().last());
  this->infos->serialize(output);
  output->writeShort((short)this->members.size());
  for(uint _i2 = 0; _i2 < this->members.size(); _i2++)
  {
    (this->members[_i2]).serializeAs_CharacterMinimalSocialPublicInformations(output);
  }
  output->writeShort((short)this->controlledSubareaIds.size());
  for(uint _i3 = 0; _i3 < this->controlledSubareaIds.size(); _i3++)
  {
    if(this->controlledSubareaIds[_i3] < 0)
    {
      qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << this->controlledSubareaIds[_i3] << ") on element 3 (starting at 1) of controlledSubareaIds.";
    }
    output->writeVarShort((int)this->controlledSubareaIds[_i3]);
  }
  if(this->leaderCharacterId < 0 || this->leaderCharacterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << this->leaderCharacterId << ") on element leaderCharacterId.";
  }
  output->writeVarLong((double)this->leaderCharacterId);
  output->writeUTF(this->leaderCharacterName);
}

void AllianceFactsMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFactsMessage(input);
}

void AllianceFactsMessage::deserializeAs_AllianceFactsMessage(Reader *input)
{
  CharacterMinimalSocialPublicInformations _item2 ;
  uint _val3 = 0;
  uint _id1 = uint(input->readUShort());
  this->infos = qSharedPointerCast<AllianceFactSheetInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->infos->deserialize(input);
  uint _membersLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _membersLen; _i2++)
  {
    _item2 = CharacterMinimalSocialPublicInformations();
    _item2.deserialize(input);
    this->members.append(_item2);
  }
  uint _controlledSubareaIdsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _controlledSubareaIdsLen; _i3++)
  {
    _val3 = input->readVarUhShort();
    if(_val3 < 0)
    {
      qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << _val3 << ") on elements of controlledSubareaIds.";
    }
    this->controlledSubareaIds.append(_val3);
  }
  this->_leaderCharacterIdFunc(input);
  this->_leaderCharacterNameFunc(input);
}

void AllianceFactsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFactsMessage(tree);
}

void AllianceFactsMessage::deserializeAsyncAs_AllianceFactsMessage(FuncTree tree)
{
  this->_infostree = tree.addChild(std::bind(&AllianceFactsMessage::_infostreeFunc, this, std::placeholders::_1));
  this->_memberstree = tree.addChild(std::bind(&AllianceFactsMessage::_memberstreeFunc, this, std::placeholders::_1));
  this->_controlledSubareaIdstree = tree.addChild(std::bind(&AllianceFactsMessage::_controlledSubareaIdstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFactsMessage::_leaderCharacterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFactsMessage::_leaderCharacterNameFunc, this, std::placeholders::_1));
}

void AllianceFactsMessage::_infostreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->infos = qSharedPointerCast<AllianceFactSheetInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->infos->deserializeAsync(this->_infostree);
}

void AllianceFactsMessage::_memberstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_memberstree.addChild(std::bind(&AllianceFactsMessage::_membersFunc, this, std::placeholders::_1));
  }
}

void AllianceFactsMessage::_membersFunc(Reader *input)
{
  CharacterMinimalSocialPublicInformations _item = CharacterMinimalSocialPublicInformations();
  _item.deserialize(input);
  this->members.append(_item);
}

void AllianceFactsMessage::_controlledSubareaIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_controlledSubareaIdstree.addChild(std::bind(&AllianceFactsMessage::_controlledSubareaIdsFunc, this, std::placeholders::_1));
  }
}

void AllianceFactsMessage::_controlledSubareaIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << _val << ") on elements of controlledSubareaIds.";
  }
  this->controlledSubareaIds.append(_val);
}

void AllianceFactsMessage::_leaderCharacterIdFunc(Reader *input)
{
  this->leaderCharacterId = input->readVarUhLong();
  if(this->leaderCharacterId < 0 || this->leaderCharacterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << this->leaderCharacterId << ") on element of AllianceFactsMessage.leaderCharacterId.";
  }
}

void AllianceFactsMessage::_leaderCharacterNameFunc(Reader *input)
{
  this->leaderCharacterName = input->readUTF();
}

AllianceFactsMessage::AllianceFactsMessage()
{
  m_type = MessageEnum::ALLIANCEFACTSMESSAGE;
}

