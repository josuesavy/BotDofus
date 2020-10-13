#ifndef ALLIANCECHANGEGUILDRIGHTSMESSAGE_H
#define ALLIANCECHANGEGUILDRIGHTSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AllianceChangeGuildRightsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceChangeGuildRightsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceChangeGuildRightsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceChangeGuildRightsMessage(FuncTree tree);
  AllianceChangeGuildRightsMessage();

  uint guildId;
  uint rights;

private:
  void _guildIdFunc(Reader *input);
  void _rightsFunc(Reader *input);
};

#endif // ALLIANCECHANGEGUILDRIGHTSMESSAGE_H