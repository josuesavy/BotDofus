#ifndef GUILDCHARACSUPGRADEREQUESTMESSAGE_H
#define GUILDCHARACSUPGRADEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildCharacsUpgradeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildCharacsUpgradeRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildCharacsUpgradeRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildCharacsUpgradeRequestMessage(FuncTree tree);
  GuildCharacsUpgradeRequestMessage();

  uint charaTypeTarget;

private:
  void _charaTypeTargetFunc(Reader *input);
};

#endif // GUILDCHARACSUPGRADEREQUESTMESSAGE_H