#ifndef GUILDSPELLUPGRADEREQUESTMESSAGE_H
#define GUILDSPELLUPGRADEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildSpellUpgradeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildSpellUpgradeRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildSpellUpgradeRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildSpellUpgradeRequestMessage(FuncTree tree);
  GuildSpellUpgradeRequestMessage();

  uint spellId;

private:
  void _spellIdFunc(Reader *input);
};

#endif // GUILDSPELLUPGRADEREQUESTMESSAGE_H