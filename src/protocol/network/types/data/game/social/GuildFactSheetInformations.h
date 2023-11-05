#ifndef GUILDFACTSHEETINFORMATIONS_H
#define GUILDFACTSHEETINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/recruitment/GuildRecruitmentInformation.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildFactSheetInformations : public GuildInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFactSheetInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFactSheetInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFactSheetInformations(FuncTree tree);
  GuildFactSheetInformations();
  bool operator==(const GuildFactSheetInformations &compared);

  double leaderId;
  uint nbMembers;
  uint lastActivityDay;
  GuildRecruitmentInformation recruitment;
  uint nbPendingApply;

private:
  void _leaderIdFunc(Reader *input);
  void _nbMembersFunc(Reader *input);
  void _lastActivityDayFunc(Reader *input);
  void _recruitmenttreeFunc(Reader *input);
  void _nbPendingApplyFunc(Reader *input);

  FuncTree _recruitmenttree;
};

#endif // GUILDFACTSHEETINFORMATIONS_H