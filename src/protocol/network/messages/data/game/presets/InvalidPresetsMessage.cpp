#include "InvalidPresetsMessage.h"

void InvalidPresetsMessage::serialize(Writer *output)
{
  this->serializeAs_InvalidPresetsMessage(output);
}

void InvalidPresetsMessage::serializeAs_InvalidPresetsMessage(Writer *output)
{
  output->writeShort((short)this->presetIds.size());
  for(uint _i1 = 0; _i1 < this->presetIds.size(); _i1++)
  {
    if(this->presetIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - InvalidPresetsMessage -"<<"Forbidden value (" << this->presetIds[_i1] << ") on element 1 (starting at 1) of presetIds.";
    }
    output->writeShort((short)this->presetIds[_i1]);
  }
}

void InvalidPresetsMessage::deserialize(Reader *input)
{
  this->deserializeAs_InvalidPresetsMessage(input);
}

void InvalidPresetsMessage::deserializeAs_InvalidPresetsMessage(Reader *input)
{
  uint _val1 = 0;
  uint _presetIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _presetIdsLen; _i1++)
  {
    _val1 = uint(input->readShort());
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - InvalidPresetsMessage -"<<"Forbidden value (" << _val1 << ") on elements of presetIds.";
    }
    this->presetIds.append(_val1);
  }
}

void InvalidPresetsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InvalidPresetsMessage(tree);
}

void InvalidPresetsMessage::deserializeAsyncAs_InvalidPresetsMessage(FuncTree tree)
{
  this->_presetIdstree = tree.addChild(std::bind(&InvalidPresetsMessage::_presetIdstreeFunc, this, std::placeholders::_1));
}

void InvalidPresetsMessage::_presetIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_presetIdstree.addChild(std::bind(&InvalidPresetsMessage::_presetIdsFunc, this, std::placeholders::_1));
  }
}

void InvalidPresetsMessage::_presetIdsFunc(Reader *input)
{
  uint _val = uint(input->readShort());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - InvalidPresetsMessage -"<<"Forbidden value (" << _val << ") on elements of presetIds.";
  }
  this->presetIds.append(_val);
}

InvalidPresetsMessage::InvalidPresetsMessage()
{
  m_type = MessageEnum::INVALIDPRESETSMESSAGE;
}

