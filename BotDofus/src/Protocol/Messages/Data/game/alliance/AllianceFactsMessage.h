#ifndef ALLIANCEFACTSMESSAGE_H
#define ALLIANCEFACTSMESSAGE_H

#include "src/protocol/types/data/game/social/AllianceFactSheetInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInAllianceInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

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