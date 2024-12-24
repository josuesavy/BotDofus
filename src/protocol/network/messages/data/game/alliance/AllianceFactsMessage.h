#ifndef ALLIANCEFACTSMESSAGE_H
#define ALLIANCEFACTSMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/character/CharacterMinimalSocialPublicInformations.h"
#include "src/protocol/network/types/data/game/social/AllianceFactSheetInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  QSharedPointer<AllianceFactSheetInformation> infos;
  QList<CharacterMinimalSocialPublicInformations> members;
  QList<uint> controlledSubareaIds;
  double leaderCharacterId;
  QString leaderCharacterName;

private:
  void _infostreeFunc(Reader *input);
  void _memberstreeFunc(Reader *input);
  void _membersFunc(Reader *input);
  void _controlledSubareaIdstreeFunc(Reader *input);
  void _controlledSubareaIdsFunc(Reader *input);
  void _leaderCharacterIdFunc(Reader *input);
  void _leaderCharacterNameFunc(Reader *input);

  FuncTree _infostree;
  FuncTree _memberstree;
  FuncTree _controlledSubareaIdstree;
};

#endif // ALLIANCEFACTSMESSAGE_H