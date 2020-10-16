#ifndef GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H
#define GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/TaxCollectorStaticInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameRolePlayTaxCollectorInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayTaxCollectorInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayTaxCollectorInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayTaxCollectorInformations(FuncTree tree);
  GameRolePlayTaxCollectorInformations();
  bool operator==(const GameRolePlayTaxCollectorInformations &compared);

  QSharedPointer<TaxCollectorStaticInformations> identification;
  uint guildLevel;
  int taxCollectorAttack;

private:
  void _identificationtreeFunc(Reader *input);
  void _guildLevelFunc(Reader *input);
  void _taxCollectorAttackFunc(Reader *input);

  FuncTree _identificationtree;
};

#endif // GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H