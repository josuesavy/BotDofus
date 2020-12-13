#ifndef GUILDPADDOCKBOUGHTMESSAGE_H
#define GUILDPADDOCKBOUGHTMESSAGE_H

#include "src/protocol/types/data/game/paddock/PaddockContentInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildPaddockBoughtMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildPaddockBoughtMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildPaddockBoughtMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildPaddockBoughtMessage(FuncTree tree);
  GuildPaddockBoughtMessage();

  PaddockContentInformations paddockInfo;

private:
  void _paddockInfotreeFunc(Reader *input);

  FuncTree _paddockInfotree;
};

#endif // GUILDPADDOCKBOUGHTMESSAGE_H