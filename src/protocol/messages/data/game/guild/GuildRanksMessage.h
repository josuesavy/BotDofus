#ifndef GUILDRANKSMESSAGE_H
#define GUILDRANKSMESSAGE_H

#include "src/protocol/types/data/game/guild/GuildRankInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildRanksMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildRanksMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildRanksMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildRanksMessage(FuncTree tree);
  GuildRanksMessage();

  QList<GuildRankInformation> ranks;

private:
  void _rankstreeFunc(Reader *input);
  void _ranksFunc(Reader *input);

  FuncTree _rankstree;
};

#endif // GUILDRANKSMESSAGE_H