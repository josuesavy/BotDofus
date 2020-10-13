#ifndef FRIENDSPOUSEONLINEINFORMATIONS_H
#define FRIENDSPOUSEONLINEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/friend/FriendSpouseInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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