#ifndef FRIENDSPOUSEONLINEINFORMATIONS_H
#define FRIENDSPOUSEONLINEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/friend/FriendSpouseInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FriendSpouseOnlineInformations : public FriendSpouseInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendSpouseOnlineInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendSpouseOnlineInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendSpouseOnlineInformations(FuncTree tree);
  FriendSpouseOnlineInformations();
  bool operator==(const FriendSpouseOnlineInformations &compared);

  double mapId;
  uint subAreaId;
  bool inFight;
  bool followSpouse;

private:
  void deserializeByteBoxes(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
};

#endif // FRIENDSPOUSEONLINEINFORMATIONS_H