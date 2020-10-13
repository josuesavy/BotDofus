#ifndef GUILDCHARACSUPGRADEREQUESTMESSAGE_H
#define GUILDCHARACSUPGRADEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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