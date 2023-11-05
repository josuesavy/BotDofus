#ifndef FRIENDSPOUSEINFORMATIONS_H
#define FRIENDSPOUSEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FriendSpouseInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendSpouseInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendSpouseInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendSpouseInformations(FuncTree tree);
  FriendSpouseInformations();
  bool operator==(const FriendSpouseInformations &compared);

  uint spouseAccountId;
  double spouseId;
  QString spouseName;
  uint spouseLevel;
  int breed;
  int sex;
  EntityLook spouseEntityLook;
  QSharedPointer<GuildInformations> guildInfo;
  int alignmentSide;

private:
  void _spouseAccountIdFunc(Reader *input);
  void _spouseIdFunc(Reader *input);
  void _spouseNameFunc(Reader *input);
  void _spouseLevelFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _spouseEntityLooktreeFunc(Reader *input);
  void _guildInfotreeFunc(Reader *input);
  void _alignmentSideFunc(Reader *input);

  FuncTree _spouseEntityLooktree;
  FuncTree _guildInfotree;
};

#endif // FRIENDSPOUSEINFORMATIONS_H