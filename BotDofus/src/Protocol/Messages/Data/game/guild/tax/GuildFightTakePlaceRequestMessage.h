#ifndef GUILDFIGHTTAKEPLACEREQUESTMESSAGE_H
#define GUILDFIGHTTAKEPLACEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/guild/tax/GuildFightJoinRequestMessage.h"

class GuildFightTakePlaceRequestMessage : public GuildFightJoinRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFightTakePlaceRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFightTakePlaceRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFightTakePlaceRequestMessage(FuncTree tree);
  GuildFightTakePlaceRequestMessage();

  int replacedCharacterId;

private:
  void _replacedCharacterIdFunc(Reader *input);
};

#endif // GUILDFIGHTTAKEPLACEREQUESTMESSAGE_H