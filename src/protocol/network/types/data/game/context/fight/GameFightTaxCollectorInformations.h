#ifndef GAMEFIGHTTAXCOLLECTORINFORMATIONS_H
#define GAMEFIGHTTAXCOLLECTORINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/GameFightAIInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightTaxCollectorInformations : public GameFightAIInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightTaxCollectorInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightTaxCollectorInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightTaxCollectorInformations(FuncTree tree);
  GameFightTaxCollectorInformations();
  bool operator==(const GameFightTaxCollectorInformations &compared);

  uint firstNameId;
  uint lastNameId;

private:
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
};

#endif // GAMEFIGHTTAXCOLLECTORINFORMATIONS_H