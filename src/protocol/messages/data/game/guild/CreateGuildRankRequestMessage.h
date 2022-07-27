#ifndef CREATEGUILDRANKREQUESTMESSAGE_H
#define CREATEGUILDRANKREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CreateGuildRankRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CreateGuildRankRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CreateGuildRankRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CreateGuildRankRequestMessage(FuncTree tree);
  CreateGuildRankRequestMessage();

  uint parentRankId;
  uint gfxId;
  QString name;

private:
  void _parentRankIdFunc(Reader *input);
  void _gfxIdFunc(Reader *input);
  void _nameFunc(Reader *input);
};

#endif // CREATEGUILDRANKREQUESTMESSAGE_H