#ifndef ALLIANCEMEMBERINFO_H
#define ALLIANCEMEMBERINFO_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/social/SocialMember.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AllianceMemberInfo : public SocialMember
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceMemberInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceMemberInfo(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceMemberInfo(FuncTree tree);
  AllianceMemberInfo();
  bool operator==(const AllianceMemberInfo &compared);

  int avaRoleId;

private:
  void _avaRoleIdFunc(Reader *input);
};

#endif // ALLIANCEMEMBERINFO_H