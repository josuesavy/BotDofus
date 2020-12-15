#ifndef GAMEROLEPLAYMERCHANTINFORMATIONS_H
#define GAMEROLEPLAYMERCHANTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOption.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameRolePlayMerchantInformations : public GameRolePlayNamedActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayMerchantInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayMerchantInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayMerchantInformations(FuncTree tree);
  GameRolePlayMerchantInformations();
  bool operator==(const GameRolePlayMerchantInformations &compared);

  uint sellType;
  QList<QSharedPointer<HumanOption>> options;

private:
  void _sellTypeFunc(Reader *input);
  void _optionstreeFunc(Reader *input);
  void _optionsFunc(Reader *input);

  FuncTree _optionstree;
};

#endif // GAMEROLEPLAYMERCHANTINFORMATIONS_H