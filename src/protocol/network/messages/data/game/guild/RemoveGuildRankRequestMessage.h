#ifndef REMOVEGUILDRANKREQUESTMESSAGE_H
#define REMOVEGUILDRANKREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class RemoveGuildRankRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RemoveGuildRankRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RemoveGuildRankRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RemoveGuildRankRequestMessage(FuncTree tree);
  RemoveGuildRankRequestMessage();

  uint rankId;
  uint newRankId;

private:
  void _rankIdFunc(Reader *input);
  void _newRankIdFunc(Reader *input);
};

#endif // REMOVEGUILDRANKREQUESTMESSAGE_H