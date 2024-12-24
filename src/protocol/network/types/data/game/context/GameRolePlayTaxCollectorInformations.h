#ifndef GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H
#define GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/TaxCollectorStaticInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"

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
  int taxCollectorAttack;

private:
  void _identificationtreeFunc(Reader *input);
  void _taxCollectorAttackFunc(Reader *input);

  FuncTree _identificationtree;
};

#endif // GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H