#ifndef KOHALLIANCEINFO_H
#define KOHALLIANCEINFO_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/protocol/network/types/data/game/alliance/KohAllianceRoleMembers.h"
#include "src/protocol/network/types/data/game/alliance/KohScore.h"
#include "src/utils/io/type/FuncTree.h"

class KohAllianceInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KohAllianceInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KohAllianceInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KohAllianceInfo(FuncTree tree);
  KohAllianceInfo();
  bool operator==(const KohAllianceInfo &compared);

  QSharedPointer<AllianceInformation> alliance;
  double memberCount;
  QList<KohAllianceRoleMembers> kohAllianceRoleMembers;
  QList<KohScore> scores;
  uint matchDominationScores;

private:
  void _alliancetreeFunc(Reader *input);
  void _memberCountFunc(Reader *input);
  void _kohAllianceRoleMemberstreeFunc(Reader *input);
  void _kohAllianceRoleMembersFunc(Reader *input);
  void _scorestreeFunc(Reader *input);
  void _scoresFunc(Reader *input);
  void _matchDominationScoresFunc(Reader *input);

  FuncTree _alliancetree;
  FuncTree _kohAllianceRoleMemberstree;
  FuncTree _scorestree;
};

#endif // KOHALLIANCEINFO_H