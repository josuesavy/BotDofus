#ifndef GAMEROLEPLAYMERCHANTINFORMATIONS_H
#define GAMEROLEPLAYMERCHANTINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOption.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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