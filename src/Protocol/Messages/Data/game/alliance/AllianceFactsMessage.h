#ifndef ALLIANCEFACTSMESSAGE_H
#define ALLIANCEFACTSMESSAGE_H

#include "src/Protocol/Types/Data/game/social/AllianceFactSheetInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInAllianceInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AllianceFactsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFactsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFactsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFactsMessage(FuncTree tree);
  AllianceFactsMessage();

  QSharedPointer<AllianceFactSheetInformations> infos;
  QList<QSharedPointer<GuildInAllianceInformations>> guilds;
  QList<uint> controlledSubareaIds;
  double leaderCharacterId;
  QString leaderCharacterName;

private:
  void _infostreeFunc(Reader *input);
  void _guildstreeFunc(Reader *input);
  void _guildsFunc(Reader *input);
  void _controlledSubareaIdstreeFunc(Reader *input);
  void _controlledSubareaIdsFunc(Reader *input);
  void _leaderCharacterIdFunc(Reader *input);
  void _leaderCharacterNameFunc(Reader *input);

  FuncTree _infostree;
  FuncTree _guildstree;
  FuncTree _controlledSubareaIdstree;
};

#endif // ALLIANCEFACTSMESSAGE_H