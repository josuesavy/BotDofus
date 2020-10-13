#include "GameEntitiesDispositionMessage.h"

void GameEntitiesDispositionMessage::serialize(Writer *output)
{
  this->serializeAs_GameEntitiesDispositionMessage(output);
}

void GameEntitiesDispositionMessage::serializeAs_GameEntitiesDispositionMessage(Writer *output)
{
  output->writeShort((short)this->dispositions.size());
  for(uint _i1 = 0; _i1 < this->dispositions.size(); _i1++)
  {
    qSharedPointerCast<IdentifiedEntityDispositionInformations>(this->dispositions[_i1])->serializeAs_IdentifiedEntityDispositionInformations(output);
  }
}

void GameEntitiesDispositionMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameEntitiesDispositionMessage(input);
}

void GameEntitiesDispositionMessage::deserializeAs_GameEntitiesDispositionMessage(Reader *input)
{
  QSharedPointer<IdentifiedEntityDispositionInformations> _item1 ;
  uint _dispositionsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _dispositionsLen; _i1++)
  {
    _item1 = QSharedPointer<IdentifiedEntityDispositionInformations>(new IdentifiedEntityDispositionInformations() );
    _item1->deserialize(input);
    this->dispositions.append(_item1);
  }
}

void GameEntitiesDispositionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameEntitiesDispositionMessage(tree);
}

void GameEntitiesDispositionMessage::deserializeAsyncAs_GameEntitiesDispositionMessage(FuncTree tree)
{
  this->_dispositionstree = tree.addChild(std::bind(&GameEntitiesDispositionMessage::_dispositionstreeFunc, this, std::placeholders::_1));
}

void GameEntitiesDispositionMessage::_dispositionstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_dispositionstree.addChild(std::bind(&GameEntitiesDispositionMessage::_dispositionsFunc, this, std::placeholders::_1));
  }
}

void GameEntitiesDispositionMessage::_dispositionsFunc(Reader *input)
{
  QSharedPointer<IdentifiedEntityDispositionInformations> _item = QSharedPointer<IdentifiedEntityDispositionInformations>(new IdentifiedEntityDispositionInformations() );
  _item->deserialize(input);
  this->dispositions.append(_item);
}

GameEntitiesDispositionMessage::GameEntitiesDispositionMessage()
{
  m_type = MessageEnum::GAMEENTITIESDISPOSITIONMESSAGE;
}

